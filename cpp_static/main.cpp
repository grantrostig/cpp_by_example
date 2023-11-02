// Not done yet!! :)
// Copyright 2023 Grant Rostig .com
// License Boost 1.0
// See also: https://www.youtube.com/watch?v=0kgTuWkyorc&pp=ygUWZHVyYW50aW9uIGxpbmthZ2Ugc2Frcw%3D%3D
#include "cpp_static_example.h"
#include <bits/stdc++.h>
using namespace std;
/*          [.*]  === not covered here             ~.*~  === type comment only

KEY INSIGHT 1) re: Object and Funtions: Scope, Storage_Duration & Linkage.  memory too: S,SD,L === SSDL
            2) extern & static:         linkage and storage,        DON'T affect scope.
            3) static:                  "Can" affect function type, NO "this" implicit parameter.
            4) SCOPE is just for one TU.  Linker requires external linkage to see globals and namespaced objects and funtions.

Object file space layout:  text/data & const & dss & bss.

Object File:     Dcl === Definition has a Declaration also. IE. has { ... }; "Definition"
                 Dfn === Declaration does not have the Definition. "Non-defining declaration"

                 TU  === Translation Unit.
External_linkage:Def === Linker Definition
                 Ref === Linker Reference

Objects & Functions & Labels have Attributes:                   */

///                                             StorageDuration//////////LINKAGE/////////TYPE//////_SCOPE////////////////////////NAME
/*                                              extern_StorageDuration    external_ln                local_SCOPE
                                                [mutable_Storage]         internal_ln               class_SCOPE
                                                static_Storage                                      namespace_SCOPE just for TU!!  But one can see and linker can, if same namespace in other file it is external linkage.
                                                [thread_local_StorageDur]                           global_SCOPE    just for TU!!
                                                dynamic_StorageDur                                                                                                                      */
///                                             +Object   |||             +Object  |||     +Object  ||| +Object   |||               +Object
///                                                                       +Function        +Function    +Function                   +Function
///                                                                                      +Label       +Label                      +Label
/*
Code_Example                                    StorageDuration         Linkage         Type        Scope                   Name        Compiler_Sugar               Usage/location

???SCOPE:
                extern  int     i;       //Dcl  na                      external        int        Ns/Gbl              i                                       .hpp ONLY
                extern  int     i {};    //Dfn  static                  external        int        Ns/Gbl              i                                       .cpp +? // same as not using "extern" @Global
                //      int     i {};    //Dfn  static                  external        int        Ns/Gbl              i          is static, but so is above?? .cpp +? // who cares, dont do.
                //      int     i;       //Dfn  static                  external        int        Ns/Gbl              i          Init to zero by compiler     .cpp +? // who cares, dont do.
                const   int     c {};    //Dfn  static                  internal        int        Ns/Gbl              c          const makes is static?? and internal_linkage! .hpp proper place.
                static  int     i {};    //Dfn  static                  internal        int        Ns/Gbl              i
  namespace d { extern  int     i {};    //Dcl  static                  external        void       Ns/Gbl              f                                       .hpp    // external keyword is true but disallowed.
  namespace d { //"     int     i {};    //Dcl  static                  external        void       Ns/Gbl              f                                       .hpp
  namespace d { static  int     i {};    //Dcl  static                  internal        void       Ns/Gbl              f                                       .hpp

=>              //"     void    f();     //Dcl  na                      external        int        Ns/Gbl              f                                       .hpp    // same as not using "extern" @Global
                extern  void    f();     //Dcl  na                      external        void       Ns/Gbl              f                                       .hpp
                inline  void    f();     //Dcl  na                      external        void       Ns/Gbl              f                                       .hpp PUT DEFINITION IN HEADER!! so it can iline more places.
  namespace d { extern  void    g()};    //Dcl  na                      external        void       Ns/Gbl              f                                       .hpp
????=>struct d {    static  void    f()};    //Dcl  na                      external        void      Ns/GBL              f          static => external,no this   .hpp     // external keyword is true but disallowed.

         void f()     { int     i {}};   //Dfn  automatic               no_linkage      int        Ns/Gbl              f                                       .hpp
         void g()     { T     i new T;}; //Dfn  dyanmic                 no_linkage      T          Ns/Gbl              f                                       .hpp

  struct d {ERR extern  void    f()}; // ERROR event though that is what is happening!
=>struct d {    //"     void    f()};    //Dcl  na                      external        void       Class               f                                       .hpp
  struct d {    static  void    f()};    //Dcl  na                      external        void       Class               f          static => external,no this   .hpp     // external keyword is true but disallowed.

      main {    extern  int     f()};    //Dcl  na                      external        void       Local               f                                       .hpp
    static int g(); \
      main {    extern  int     g()};    //Dfn  na                      internal                   Local
      main {    static  int     h()}; // ERROR static not allowed.


STORAGE:
                static  int     i {};    //Dfn  data                                int        Ns/Gbl              i                                       .cpp +? // same as not using "extern" @Global
                thread  int     i {};    //Dfn  data                                int        Ns/Gbl              i                                       .cpp +? // same as not using "extern" @Global
~automatic~     //      int     i {};    //Dfn  stack/free_store                    int        Ns/Gbl              i                                       .cpp +? // same as not using "extern" @Global
~dynamic~       //      int     i {};    //Dfn  new/delete-free-store               int        Ns/Gbl              i                                       .cpp +? // same as not using "extern" @Global

LINKAGE:
external                                              cross TUs

internal                                              home TU
static_linkage  void f(){static int i{};}  //DEF  data

no_linkage      void f(){       int i;  }  //DEF  stack/free_store
[modules]

Name located in HPP or CPP? Factors: DEF vs REF, Linkage, Duration.

extern          only for:  objects, not members.
                Can it be used in other than namespace OR global_SCOPE?

thread_local    only with: extern & static.

extern "C" is a different use of extern.  Has to do with name mangling.

https://www.youtube.com/watch?v=0kgTuWkyorc&pp=ygUWZHVyYW50aW9uIGxpbmthZ2Ugc2Frcw%3D%3D
Q: Slide 33.2 ???

*/

       int const     max  {32};  // HPP only, In C++ is _internal_ linkage default for const. It can work as a #define literal and is the better way, because it has scope. It can act like C_lang's #define MAX 32
static int const     max2 {32};  // TODO??:
extern int const     max1 {32};  // TODO??:
       constexpr int max3 {32};  // TODO??:
       int constexpr max5 {32};  // TODO??:
inline constexpr int max4 {32};  // TODO??: Why is inline needed again?
extern inline constexpr int max6 {32};  // TODO??:
static inline constexpr int max7 {32};  // TODO??:

static int m();                 // don't do this sort of forward definition?
extern int f() {return 0;};  // extern here does nothing but is allowed and is extern.
extern int m() {return 0;};

namespace n {
    extern int f();  // TODO??: when would one do this and what does it do?
    extern int m();  // static because of static m() lines above.  // TODO??: when would one do this and what does it do?
    static int n();  //
}
class C {
    //extern int f();  // TODO??: when would one do this and what does it do?
    //extern int m();  // static because of static m() lines above.  // TODO??: when would one do this and what does it do?
    static int n();  //
           int o();  // TODO??: when would one do this and what does it do?
};
int main() {
    extern int f();  // TODO??: when would one do this and what does it do?
    extern int m();  //

    Row my_row;
    Cpp_static_example ret_default_constructed {};
    cout << "###" << endl;
    return 0;
}
