/* file used in development of lib_tty using goto - retain for history
 * Generated as part of the password manager effort.
 * Used to test lib_tty.
 *
 * Copyright 2019 Grant Rostig all rights reserved,
 * no rights granted to anyone at this time,
 * no license granted to anyone at this time,
 * except to use during CppMSG meetings during 2021.
 *
 */
#include <iostream>
#include <cassert>
#include <functional>
#include <variant>
#include <tuple>

#include <time.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#include "../lib_tty/lib_tty.h"

using std::endl, std::cin, std::cout, std::cerr, std::string;

int main()
{
    cin.sync_with_stdio(false);  	// todo: iostreams bug? Is this is required?

    // auto & [sigaction_termination_return]
    auto [action_prior1, action_prior2, action_prior3, action_prior4, action_prior5]
            = set_sigaction_for_termination( handler_termination ); //Sigaction_return_3 action3; //action3 = set_sigaction_for_termination( handler_termination );

    auto [inactivity_timer, sig_user, action_prior_inactivity ]
            = enable_inactivity_handler( 8 );
    while (true) { 					// for ( auto i = 5 ; i-->0; ) {
        string val;
        cout << "MAIN_LOOP_TOP: enter value or 'end' and <return>:"<<endl;
        cin >> val;  // NOTE: Just <CR> on this input does not create any value at all, we get inactivity timeout.
                     //	      If inactivity fires, then the handler runs HERE, and even stays on the cin input!!
        if ( cin.eof() || cin.failbit ) {
            cout << "MAIN: start of output from lib_tty_print_iostate():" ;
            print_iostate(cin);
            cout << ":." << endl;
            cin.clear();
        }
        if ( val == "end" ) break;
                    // This line didn't work, so we try next line instead??: timer_t another_ptr = enable_inactivity_handler( 5 );
        // set_a_run_inactivity_timer( inactivity_timer_ptr, 8 );  // reset timer??  is this needed even if timer did not trip?
        cout << "MAIN: Value we got:" << val <<":." << endl;
        cout << "MAIN_LOOP_BOTTOM."<<endl;
    }
    disable_inactivity_handler( inactivity_timer, sig_user, action_prior_inactivity );

    Sigaction_termination_return sigaction_termination_return { action_prior1, action_prior2, action_prior3, action_prior4, action_prior5 };
    sigaction_restore_for_termination( sigaction_termination_return );
    cout << "###" << endl;
    return 0;
}
