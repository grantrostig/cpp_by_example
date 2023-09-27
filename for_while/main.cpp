#include <iostream>

using namespace std;

int main() { {
    int var_test_pre {1}, var_test_post {1}, test_pre {1}, test_post {1}, incrmnt_pre {1}, incrmnt_post {1};
    for ( int var_declare {1};  		// starting value, only evaluated once.
          ++var_test_pre, var_test_post++, ++test_pre < 99, true, test_post++ < 4; // evaluation and then test done before top of loop.
          ++incrmnt_pre, incrmnt_post++, var_declare++, true 		// increment done after bottom of loop before top eval and test.
        ) { cout  << "var_declare: "<<var_declare
              << " var_test_pre: "<<var_test_pre<<" var_test_post: "<<var_test_post
              << " test_pre: "<<test_pre<<" test_post "<<test_post
              << " incrmnt_pre: "<<incrmnt_pre<<" incrmnt_post: "<<incrmnt_post<<endl; } }

    int var_test_pre {1}, var_test_post {1}, test_pre {1}, test_post {1}, incrmnt_pre {1}, incrmnt_post {1};
    for ( int var_declare {1};  		// starting value, only evaluated once.
          ++var_test_pre, var_test_post++, test_post++ < 99, true, ++test_pre < 4; // evaluation and then test done before top of loop.
          ++incrmnt_pre, incrmnt_post++, var_declare++, true 		// increment done after bottom of loop before top eval and test.
        ) { cout  << "var_declare: "<<var_declare
              << " var_test_pre: "<<var_test_pre<<" var_test_post: "<<var_test_post
              << " test_pre: "<<test_pre<<" test_post "<<test_post
              << " incrmnt_pre: "<<incrmnt_pre<<" incrmnt_post: "<<incrmnt_post<<endl; }
    cout << "###" << endl;
    return 0;
}
