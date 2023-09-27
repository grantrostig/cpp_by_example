#include <iostream>
#include <iterator>
#include <functional>
#include <any>
#include <vector>
#include <string>
#include <stack>
#include <typeinfo>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;
template<typename T>            // utility to print vectors
std::ostream & operator<<( std::ostream &out, const std::vector<T> &v) {
    //if ( ! v.empty() ) {
        out << '<';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ","));
        // out << "\b\b]";
        if ( ! v.empty() ) out << "\b";
        out << ">";
    //}
    return out;
}

short 	f( short );
int   	f2( int );
long 	g( long i ) { return i; }
float 	h( float s ) { return s; }
string 	k( string s ) { return s; }

std::vector<string> my_functions { typeid (k).name() };

void print_my_functions() { cout << "The Functions Container: \n"; for (auto & i : my_functions ) cout << i << ", "; cout << "\b\b .\n"; }
using Dialog_types 		= std::vector<std::string>;
using Dialog_specifics 	= std::vector<std::string>;
using FC_hot_keys 		= std::vector<std::string>;
using Intent 			= int;

struct Intent_key { 		// todo:?? maybe not. std::optional< Dialog_type > 	 dialog_type 	 {}; //std::optional< Dialog_specific > dialog_specific {};
    Dialog_types  	 dialog_type 	 {};
    Dialog_specifics dialog_specific {};
    FC_hot_keys 	 fc_hot_keys 	 {};
};

struct Intent_key_equal {
    bool operator()( Intent_key const lhs, Intent_key const rhs ) const {
        auto dt = std::search( lhs.dialog_type.begin(),     lhs.dialog_type.end(), 	   rhs.dialog_type.begin(),     rhs.dialog_type.end() );
        auto ds = std::search( lhs.dialog_specific.begin(), lhs.dialog_specific.end(), rhs.dialog_specific.begin(), rhs.dialog_specific.end() ); // this may be unnecessary depending on prior line result.
        auto hk = std::search( lhs.fc_hot_keys.begin(),     lhs.fc_hot_keys.end(),     rhs.fc_hot_keys.begin(),     rhs.fc_hot_keys.end() );
        if ( dt != lhs.dialog_type.end() || ds != lhs.dialog_specific.end() ) {		// found: either dialog
            cerr << "got dialog.\n";
            if ( hk != lhs.fc_hot_keys.end() ) {										// AND a hot_key
                cerr << "also got fchk.\n";
                return true;
            }
        }
        return false;  // yes I could have done it one line, but without debugging code.
    }
};

struct Intent_key_hash {
    size_t operator() ( Intent_key const key ) const { 		// junk:size_t operator() ( Dialog_types dtypes, Dialog_specifics dspecifics, FC_hot_keys fchks ) {
        size_t hash_value {};
        for ( auto & i : key.dialog_type )     hash_value ^= std::hash< string >()(i);     // todo:?? why no type deduction?
        for ( auto & i : key.dialog_specific ) hash_value ^= std::hash< string >()(i);		// would/which an algorithm be better (excluding the benefit of parallelism)?
        for ( auto & i : key.fc_hot_keys )     hash_value ^= std::hash< string >()(i);
        return hash_value;
    }
};

Intent_key intent_key1
        {   { "Dialog_Type1", "Dialog_Type2" 	},
            { "Dialog_Specific_Function" 	},
            { "fchk1", "fchk2", "fchk3", "fchk4" }
        };

std::unordered_map< Intent_key, Intent, Intent_key_hash, Intent_key_equal > my_map {
    {
        intent_key1
        , 20
    },
    {
        {   { "dt1"	  },
            { "ds1"	  },
            { "fchk1" }
        }
        , 21
    },
    {
        {   {},
            { "f2" },
            { "fchk2" }
        }
        , 22
    },
    {
        {   {},
            { typeid(f).name() },  // load the string for "f".  todo:?? is there a potential initialization ordering problem with this?
            { "fchk3"  }
        }
        , 23
    },
    {
        {   { typeid(k).name() },
            {},
            { "fchk4"  }
        }
        , 23  						// just for fun a previously used intent.
    },
    {
        {   { "dt5"   },
            {},
            { "fchk5" }
        }
        , 29
    },
};

void print_map() { for (auto & i : my_map ) { cout << "An Entry: key:" << i.first.dialog_type << i.first.dialog_specific  << i.first.fc_hot_keys <<" value:" << i.second << std::endl; } }

short f(short i) {
    my_functions.push_back( typeid (f).name() ); cout << "Running in: " << __func__ << " AKA: " << typeid (f).name() << endl;
    // do other work....
    f2(42);
    // do other work....
    Intent v {99}, w {99};
    v = my_map.at( { { "dt5" },
                     {},
                     {"fchk5"}
                   });
    w = my_map[    { {  my_functions.back() },
                     {},
                     //{"fchk99"}
                     {"junk"}
                   }];
    cout << __func__ << ": process this at() intent: " << v << endl; cout << __func__ << ": process this   [] intent: " << w << endl;
    my_functions.pop_back();  	// removes one element only.
    return i;
}

int f2(int i) {
    my_functions.push_back( typeid (f).name() ); cout << "Running in: " << __func__ << " AKA: " << typeid (f2).name() << endl;
    // do other work....
                    // auto v = my_map[ my_functions.back() ];
                    //    cout << "f2 process this: " << v << endl;
                    //    switch ( v ) {
                    //    case 90:
                    //        cout << "switching on 90\n";
                    //        break;
                    //    case 91:
                    //        cout << "switching on 91\n";
                    //        break;
                    //    }
    my_functions.pop_back();
    return i;
}

std::function<string * (string) > 	f6 = k; 			// todo: what about?? std::mem_fn, std::reference_wrapper
std::function 	f6b = k; 			// todo: what about?? std::mem_fn, std::reference_wrapper
std::any 		f7 = k;  			// actually want to limit variable to "any" function, not any object.
void * 			f9 = (void *) k;  	// todo:?? why not this type?

int main() {
    print_map();
    std::type_info const & 	stuff1  { typeid( k ) };  // todo??: why can't I remove the & reference modifier?? ?

    f( 2 );
    print_my_functions();
    f2( 3 );
    if ( my_functions.at(my_functions.size() - 1) == typeid(k).name() ) cout << "We have a k()." << endl; else cout << "We don't have a k()." << endl;
    print_map();
    std::cout << "###" << endl;
    return 0;
}
