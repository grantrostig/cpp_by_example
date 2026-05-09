// cpp_c_struct_alias.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

import std;
typedef int 		   my_typedef_int;
using   my_using_int = int;
namespace seen {
	struct S;  // Forward declaration of struct S 	// C++
	struct S {  					// C++
		double my_double;
//		double f(int my_int) const { return my_int    + my_double; }; // TODO??: why warning and not below.
		double f(int my_int) const { return my_double + my_int; };
	};
	//typedef struct S S;  // Typedef for struct S (needed in c, but not at all necessary in C++)
	//typedef struct S S_typedef_alias;
	//static_assert(std::is_same_v<S, S_typedef_alias>);
	//static_assert(std::same_as  <S, S_typedef_alias>);

	S* new_up_an_S(int my_i, const char* c_string);   // Forward declaration of the function new_up_an_S
	S* new_up_an_S(int my_i, const char* c_string) {  // Definition (also a declaration) of the function new_up_an_S
	 // S* s2_ptr = new S();
		S* s1_ptr{new S()};
		s1_ptr->my_double = my_i;
		return s1_ptr;
	}
}
#ifdef UNSEEN
namespace C_lang_unseen_struct_example {
// BOOK says *.c >> 
//			struct S* new_up_an_S(int,      const char*);
			//struct S* new_up_an_S(int my_i, const char* c_string); // Forward declaration of the function new_up_an_S
			// OR Could have done
			//typedef struct S S;  // Forward declaration of struct S and typedef in one line ??

			S* new_up_an_S(int my_i, const char* c_string);  // Forward declaration of the function new_up_an_S	
}
#endif

int main() {
	auto s1 = seen::new_up_an_S(3, "hello");
	std::cout << "s1:" << s1->my_double << std::endl;

#ifdef UNSEEN
	auto s2 = C_lang_unseen_struct_example::new_up_an_S(3, "hello");
    std::cout << "s2:" << s2->my_double << std::endl;
#endif

	std::cout << "###" << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
