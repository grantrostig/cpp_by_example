#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct balance {    // note: Name and capitalization is specified by problem statement and required by the calling code.
   int account_id; ///< the name of the account
   int balance;    ///< the balance of the account
};
struct transfer {   // note: Capitalization is specified by problem statement and required by the calling code.
   int from;    ///< the account to transfer from
   int to;      ///< the account to transfer to
   int amount;  ///< the amount to transfer
};
using transaction      = vector<transfer>;  ///< Invariant: Must be atomic. Note: Capitalization is specified by problem statement and required by the calling code.
/* ===== above code cannot be modified, as required by testing development environment ===== */


/* copyright (c) Grant Rostig 2019, all rights reserved
 * grant.copyright@emailmeinfo.com
 * Permission granted to 'Block.one LLC' for use as a
 * "pre-employment screening test".
 *
 * Programming Style/Convention Notes:
 * + User defined types (UDTs) are capitalized, except those given in the problem statement code.  The problem definition provides lower case types and those are used in that form where needed.
 * + UDT container types are plural. (for example, a vector of 'Account' elements is 'Accounts'.
 * + A named type library is not used, but such is partly simulated by using the "using" statment (AKA typedef).
 * + Longer variable names are used to make the code extremely easy to read without too much commenting.
 * + Comments are used whenever they may be helpful to understand intent, or even less obvious C++ syntax.
 * + All variables/objects are initialized with '{}', whether or not they are default initialized so as to impose the discipline of initializing variables, except in rare cases where this would impact performance.
 * + Coding and debugging is done in "Qt Creator" a free opensource C++ IDE editor.
 * + Code formatting/spacing is done to optimizing readability while retaining compactness in total number of blank and non-blank lines.
 * + Code line breaks are optimized for viewing/editing on a large wide screen monitor.  The testing tool may have reformatted the code significantly, reducing readability.  Please ask for a zip file of project if you wish to view the code in the comfort of an IDE.
 * + Comments are placed before the referenced code, or are appended to the line of code being referenced.
 *
 * + >>>NOTE: We are perfectly happy to adopt any naming, code formatting, documentation standard required by you, the employer.<<<
 */

/**
 *
 * @param initial_balances - the initial balances in the database, see the above datastructures.
 * @return an instantiated database type of your creation which has the following member methods:
 *
 *    // push a transaction to the database
 *    //
 *    void push_transaction( const transaction&t )
 *
 *    // settle the database such that the invariant is maintained and the best state of the database is present
 *    //
 *    void settle()
 *
 *    // return a listing of all the balances in any order
 *    //
 *    vector<balance> get_balances() const
 *
 *    // return the 0-based indices of the applied transactions after settle in any order
 *    //
 *    vector<size_t> get_applied_transactions() const
 *
 * The automated test cases will call create_database with a set of initial balances
 * They will then feed a number of transactions to your class
 * They will then call settle
 * They will then call get_applied_transactions and inspect the results
 * They will then call get_balances and inspect the results
 */

class Database {

    /* Invariants:
     * + transactions must retain the ordering in which they were created.
     * + account balances must be non-zero after settlement.
     */

    static constexpr size_t NUM_TRANSACTIONS_EM = 30;  ///< The commonly encountered minumum number of transactions in a database.
    static constexpr size_t NUM_BALANCES_EM = 1000;    ///< The commonly encountered minumum number of accounts in a database.

    using Transaction_id      =	size_t;  ///< Holds the zero-based sequence number/counter (AKA index) of the transactions as they are initially loaded, and when they are quiered. // This type is much larger than needed in this problem since we cannot store that many transactions (2^32 or 2^42) in memory.
    using Account_id          =	int;  ///< Holds the account number/id for the account holding entity, for example a person.
    using Amount              =	int;  ///< Holds the amount in value units, for example dollars.
    using Balance_amount      =	Amount;  ///< Holds the amount in value units, for example dollars.

    struct Netted_trf_struc {	///< trf = transaction, holds the effect of one transaction on one account.
        Transaction_id tr_id {};
        Account_id     account_id {};
        Amount         amount {};	///< positive value for transfer in and negative for transfer out.
    };

    struct Low_balance_struc { 	///< used to pass information about which account is tentatively below zero.
        Account_id     account_id {};
        Balance_amount balance {};  ///< postive or negative.
    };

    using Accounts = unordered_map<Account_id, Balance_amount>;  ///< An account has an 'id' and an 'amount'. Accounts hold 'account entities' (AKA) which are similar to the problem supplied type:'balance'.
    Accounts  accounts {};

    using Transaction_ids = set<Transaction_id>; ///< NOTE: Since unordered_set<> was not provided in the includes, std::set<> was used. Yes, a std::bitmap<> could have been used, but that would complicate the understanability of the code and likely not provide a major speed improvement over unordered_map<> (or even map<>).  Also a vector<> could have been used and might be very fast, but vector<> would require more complex code and reduce maintainability. Assumption:  Only the provided library includes were permissible.
    Transaction_ids current_transaction_ids {};  ///< hold the id/index of transactions that might be included in the batch.
    Transaction_id  transaction_count {};        ///< zero-based, counts number of transactions recieved from client.

    using Netted_transactions = vector<Netted_trf_struc>; ///< holds rows of transaction components, one per id, per account.
    Netted_transactions netted_transactions {}; ///< a vector of transactions, where the transfers of one transaction are summarized into one record/struct per account (denormalized).
    Netted_transactions sorted_netted_trs {};   ///< sorted transactions.  see settle() for details on sort order.

    bool all_transactions_accepted { true };    ///< Using this flag allows for two less loops and one fewer container instanciation.

    //  === member methods ===

    void calc_initial_account_balances() {
        for (const auto& tr: netted_transactions ) {
            accounts[tr.account_id] += tr.amount;
        }
        return;
    }

    Low_balance_struc verify_all_balances() const {  // Returns most negative account balance.
        Account_id most_negative_account_id {};
        Amount     most_negative_balance {};
        for (const auto& account: accounts ) {
                if ( account.second < 0 && account.second < most_negative_balance ) {
                    most_negative_account_id = account.first;
                    most_negative_balance = account.second;
                }
        }
        return Low_balance_struc {most_negative_account_id, most_negative_balance};
    }

    Transaction_id select_removal (const Low_balance_struc& low_balance ) const {
        // go through transactions, looking for the transaction with the largest negative delta amount, for the the account with the most negative balance.
        for (const auto& t: sorted_netted_trs) {
            if ( current_transaction_ids.end() != current_transaction_ids.find( t.tr_id )  // remove only from still existing transactions
                 && ( t.account_id == low_balance.account_id )) {
                return t.tr_id;
            }
        }
        throw ("Logic error: Ran out of transactions to remove. Contact the programmer.");
    }

    void rollback_one_trs (const Low_balance_struc& low_account) {

        // find the optimal/better transaction to remove referencing the 'lowest'/'most negative' account.
        Transaction_id id_to_remove = select_removal( low_account );

        // find transaction in the naturally ordered transactions
        auto it = find_if( netted_transactions.begin(), netted_transactions.end(),
                           [&id_to_remove] (const Netted_trf_struc& rec) { return(id_to_remove == rec.tr_id); }); // finds first/largest negative amount for the transaction.
        if (it == netted_transactions.end()) throw ("Logic error: Didn't find the transaction we were looking to rollback. Call the programmer.");

        // reverse-out all elements of that transaction on all accounts
        Transaction_id current_tr_id { it->tr_id };
        do {
            accounts[it->account_id] -= it->amount;
            ++it;
        } while ( it != netted_transactions.end() && it->tr_id == current_tr_id );

        // remove Transaction from the list of candidate trs.
        current_transaction_ids.erase( current_tr_id );
    }

public:
    explicit Database ( const vector<balance>& initial_balance ) { // Assumption: we probably don't want to modify balances in main, so take a const parameter (and also ref) and make an internal copy for the internal storage type.
        accounts.reserve( NUM_BALANCES_EM );                       // speed loading by preparing space.
        for ( const auto& account:initial_balance ){               // load the input vector of accounts into an internal datastructure; a map<> of type 'Accounts'.  Assumption: using a vector instead of a map might be faster in some circumstances, but the map makes the code look simpler when doing artithmetic operations with it.
            accounts[account.account_id] = account.balance;
        }
        netted_transactions.reserve( NUM_TRANSACTIONS_EM );        // prepare space for use later.
    }

    void push_transaction( const transaction& tr ) { // Accept one transation at a time and summarize its transfers into one record per account delta.
        map<Account_id, Amount> tr_summarizer {};  // holds just one transaction to summarize it.
        for (const auto& transfer: tr) {
            tr_summarizer[transfer.from] -= transfer.amount;  // see: Netted_trf_struct::Amount for semantics
            tr_summarizer[transfer.to]   += transfer.amount;
        }
        for (const auto& t: tr_summarizer) {  // Net/summarize all the transfers of this one transactions into its affected accounts.
            netted_transactions.emplace_back(Netted_trf_struc {transaction_count, t.first, t.second}); // see: Netted_trf_struct::Amount for semantics
        }
        ++transaction_count;  // zero based
    }

    /*
     * Settle the database such that the invariant is maintained and the best state of the database is present.
     *
     * Design Decision:
     * We believe it is an sub-optimal approach to do the more obvious approach of simply rolling back if/when
     * any account balance goes negative.
     * Since we are tasked to find the best (or better) set of transactions, the whole set must be considered.
     * We summarize transfers into transactions.
     * We apply the transactions.
     * We look for the most negative account, if any we remove transactions until no account is negative.
     *
     * Caviat:
     * Other more creative and likely complex settlement methods were contemplated/considered and may be possible,
     * but we were prohibited from researching the mathematical and algorithmic problem space within
     * the literature (and web) by the terms of the test.
     *
     */

    void settle() {
        calc_initial_account_balances();
        Low_balance_struc low_account = verify_all_balances();

        if ( low_account.balance < 0 ) {
            all_transactions_accepted = false;

            // Create the fundamental datastructure of the optimization and settlement algorithm, which is used to select the optimal/better transaction to rollback.
            sorted_netted_trs.reserve(netted_transactions.size());
            copy(netted_transactions.begin(), netted_transactions.end(), back_inserter(sorted_netted_trs));  // copy sequential transactions into "to be" sorted container.
            auto ascending_sort_cmp = [](const Netted_trf_struc& a, Netted_trf_struc& b){ return (a.amount < b.amount); };  // sorting ascending will give us the most negative transfer amount first.
            sort( sorted_netted_trs.begin(), sorted_netted_trs.end(), ascending_sort_cmp );

            for ( Transaction_id i = 0; i < transaction_count; ++i) {  // Make a list/set of all transactions we received and that are to be considered for rollback during settlement.
                current_transaction_ids.insert( current_transaction_ids.end(), i );  // Note: Using .end() appears to be faster, and more so as size increases.
            }

            do {
                rollback_one_trs( low_account );
                low_account = verify_all_balances();
            } while (low_account.balance < 0);
        }
    }

    // return a listing of all the balances in any order

    vector<balance> get_balances() const {  // return balances in the data structure required by specification, ie. vector<> of balances.
        vector<balance> balances {};
        balances.reserve(accounts.size());

        for (const auto& acct:accounts) {
            balance account_struc {};
            account_struc.account_id = acct.first;
            account_struc.balance    = acct.second;
            balances.push_back(account_struc);
        }
        return balances;
    }

    // return the 0-based indices of the applied transactions after settle in any order

    vector<size_t> get_applied_transactions() const  {
        vector<size_t> applied_transactions {};
        if ( all_transactions_accepted ) {  // special case where all transactions were acceptable, and the 'concurrent_transaction_ids' set<> was not initialized.
            applied_transactions.reserve( transaction_count );
            for (Transaction_id id=0; id < transaction_count ; ++id) {
                applied_transactions.push_back(id);
            }
            return applied_transactions;
        }
        applied_transactions.reserve( current_transaction_ids.size() );
        for (const auto transaction_id: current_transaction_ids) {
            applied_transactions.push_back(transaction_id);
        }
        return applied_transactions;
    }

};

auto create_database(const vector<balance>& initial_balances ) {
   return Database( initial_balances );  // return an instantiated class
}

/* ===== below code cannot be modified, as required by testing development environment ===== */

template<typename DB>
static void print_transactions( const DB& db, ofstream& fout ) {
   auto trxs = db.get_applied_transactions();
   sort(trxs.begin(), trxs.end());
   cout << trxs.size() << endl;
   for( size_t cur : trxs ) {
      cout << cur << endl;
   }
}

template<typename DB>
static void print_database( const DB& db, ofstream& fout ) {
   auto balances = db.get_balances();
   sort(balances.begin(), balances.end(), [](const auto& a, const auto& b){
      return a.account_id < b.account_id;
   });

   cout << balances.size() << endl;
   for( const auto& cur : balances ) {
      cout << cur.account_id << " " << cur.balance << endl;
   }
}

int main() {
   ofstream fout(getenv("OUTPUT_PATH"));


   ifstream fin;
   auto input_path = getenv("INPUT_PATH");
   if (input_path != nullptr) {
      fin.open(input_path);
   }

   istream& in =  input_path ? fin : cin;

   int remaining_accounts = 0;
   in >> remaining_accounts;
   in.ignore(numeric_limits<streamsize>::max(), '\n');

   vector<balance> initial_balances;
   while (remaining_accounts-- > 0) {
      int account = 0;
      int balance = 0;

      in >> account >> balance;
      in.ignore(numeric_limits<streamsize>::max(), '\n');

      initial_balances.push_back({account, balance});
   }

   auto db = create_database(initial_balances);

   int remaining_transactions = 0;
   in >> remaining_transactions;
   in.ignore(numeric_limits<streamsize>::max(), '\n');
   while (remaining_transactions-- > 0) {

      int remaining_transfers = 0;
      in >> remaining_transfers;
      in.ignore(numeric_limits<streamsize>::max(), '\n');

      transaction tx;

      while( remaining_transfers-- > 0) {
         int from = 0;
         int to = 0;
         int amount = 0;

         in >> from >> to >> amount;
         in.ignore(numeric_limits<streamsize>::max(), '\n');
         tx.push_back({from, to, amount});
      }

      db.push_transaction(tx);
   }

   db.settle();

   print_transactions(db, fout);

   print_database(db, fout);

   return 0;
}
