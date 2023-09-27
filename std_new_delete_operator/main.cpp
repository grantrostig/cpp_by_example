/** NOT PRODUCTION QUALITY CODE, just shows learning/teaching example, not real programming, don't copy this style, just playing around

// Copyright Grant Rostig 2015 - 2021. Distributed under the Boost Software License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt)

   Author: 		Grant Rostig
   Inspired by:
   Shows how to:
    - use operator new and keyword new,
    - also delete
    - also []
    - //<CPP-CODE>  // code that does not compile is prefixed with "//".
    - //  <CPP-CODE> OR //  <ENGLISH-TEXT>  // unused code or just comments are prefixed with "//  ".
    - todo??:  // means I have an high priority question about this.
    - todo:    // means I have a question about this.
 */
//#pragma once
#include <bits/stdc++.h>
using std::cin; using std::cerr; using std::cout; using std::endl; using std::clog;

struct Fake_int {
    int i {1};
    Fake_int() {
        std::cout << "default constr" << std::endl;
    };
    Fake_int(int i): i{i} {
        std::cout << "default constr" << std::endl;
    };
    ~Fake_int() {
        std::cout << "destruc" << std::endl;
    };
};

[[maybe_unused]]  							// todo: what is this general compiler feature called?  annotation?
void new_an_int() {
  int i0    = 42;
  int i1    {42};
  int i2    (42);
  int i3    = {42};
  int i4    = (42);
  //int i5    = new int;
  int *ip1  = new int;
  int *iap2 = new int[10];
  int *iap3 = new int[10]{};
  int *iap4 = new int[10]{2, 3, 4};

  int *iap9 = new int[10]();
  //int *iap6 = new int[3](1, 2, 3); // todo: make it compile.
  //int *iap7 = new int[10](0);      // todo: make it compile.
  int *iap8 (  new int(22));
  int *iap5 {::new int{23}};

  //std::array<int, 3> ia3 = *iap3;   // todo: make it compile.
  //std::array<int, 3> ia4 = iap3[0]; // todo: make it compile.

  std::array<int, 3> ia5   {*iap3};
  std::array<int, 3> ia7   {iap3[0]};
  std::array<int, 3> ia6 = {iap3[0]};
  std::array<int, 3> ia9   {iap3[0], iap3[1], iap3[2]};
  std::array<int, 3> ia8 = {iap3[0], iap3[1], iap3[2]};
  //std::array<int, 3> iac   (*iap3); 				// todo?: why not compile.
  //std::array<int, 3> iaa   (iap3[0], iap3[1], iap3[2]);	// todo?: why not compile.
  //std::array<int, 3> iab = (iap3[0], iap3[1], iap3[2]);	// todo?: why not compile.

  delete ip1;
  ::delete ip1;
  delete[] iap2;
  ::delete[] iap3;
}

void new_a_fake_int() {
  Fake_int 	*fip4	{::new Fake_int{}}; 	Fake_int	*fip3	{::new Fake_int()};
  Fake_int 	*fip2	{::new Fake_int{32}}; 	Fake_int 	*fip1	{::new Fake_int(33)};

  //auto ret = delete fip1;		// todo??: why doesn't delete have a return value?  What if it was operator delete vs the keyword?
  ::delete fip2;
  ::delete (fip3);

  auto * fip6 {  new auto ('c') };
  //auto * fip7 {  new std::derived_from< std::basic_string<char>, std::string> auto ("ckk") };
  auto * fip8 {  new std::integral auto ('c') };
  int sum = 1 + *fip6;
  int * fip9 = {  new int (22) };

  int *my_new_var3 = new (int){22}; // note optional parens around int
}

void new_a_buffer() {
  std::byte *my_ptrD = new std::byte{4};
  // std::byte * my_ptrJ = new std::byte = {4};		// todo: why error
  // std::byte * my_ptr7 = new std::byte {300};  		// good error
  // std::byte * my_ptrA = new std::byte = 4;
  // std::byte * my_ptrE = new std::byte (4);
  std::byte *my_ptrB = new std::byte((std::byte)4);
  // std::byte * my_ptrK = (new std::byte = {4});
  // std::byte * my_ptrL = (new std::byte = (4));

  std::byte *my_ptrF = new std::byte[100];
  std::byte *my_ptrG = new std::byte[100]{};
  std::byte *my_ptrI = new std::byte[100]();
  int * my_ptrJ = new int[3]   {0x1,0x2,0x3};
  std::byte * my_ptrH = new std::byte[100] {(std::byte)1,(std::byte)2,(std::byte)3};
  std::byte * my_ptr8 = new std::byte[]    {(std::byte)4,(std::byte)3,(std::byte)2,(std::byte)1};  //std::byte * my_ptr9 = new std::byte[]    ((std::byte)4,(std::byte)3,(std::byte)2,(std::byte)1);

  // alignas (int) unsigned char buf[sizeof (int)];
  // unsigned char buf[sizeof (int)];
  // unsigned char * buf_ptr1 = new unsigned char {4.2};
  unsigned char *my_ptr2 = new unsigned char(4.4);
  unsigned char *my_ptr5 = new unsigned char[]{4, 3, 2, 1};
  // unsigned char * buf_ptr6 = new [] {4,3,2,1};
  unsigned char *my_ptr3 = new unsigned char[4];
  unsigned char *my_ptr4 = new (std::nothrow) unsigned char[4];
  // int * my_ptr1 = new(buf) int;			// placement new
  // int * my_ptr2 = std::construct_at( reinterpret_cast<int*>(buf),42);
  // my_ptr->~int();  				// todo: wrong why? not this?
  // std::destroy_at(my_ptr1);
  // std::destroy_at(my_ptr2);
  delete[] my_ptr3;
  alignas(std::string) unsigned char bufs[sizeof(std::string)];
  std::string *my_s_ptr = new (bufs) std::string;
  // my_s_ptr->~std::string();
  std::destroy_at(my_s_ptr);
}

void *operator new(std::size_t sz) { // replacement of a minimal set of functions:
  std::printf("op new called, size = %zu\n", sz);
  return std::malloc(sz);
}

void operator delete(void *ptr) noexcept {
  std::puts("op delete called");
  std::free(ptr);
}

void operator delete(void *ptr, size_t size) noexcept {
  std::puts("op delete called");
  std::free(ptr);
}

int main() {
  new_an_int();
  new_a_fake_int();
  new_a_buffer();

  cout << "###" << endl;
  return 0;
}
