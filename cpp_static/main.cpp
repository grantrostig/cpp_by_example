// Not done yet!! :)
// Copyright 2023 Grant Rostig .com
// License Boost 1.0
// See also:
// Headington 94;
// Sacks:https://www.youtube.com/watch?v=0kgTuWkyorc&pp=ygUWZHVyYW50aW9uIGxpbmthZ2Ugc2Frcw%3D%3D
#include "cpp_static_example.hpp"
#include "scope.hpp"
#include "scope_test.hpp"
#include <bits/stdc++.h>
using namespace std;
/* Document Key: "===ditto; //"===ditto; [.*]===not covered here; ~.*~===type comment only

   Scope types 11:              Function_parameter_scope
                                Template_parameter_scope
                                Point_of_declartion_scope (many subtypes see cppref)
                                Block                       //(local?)
                                Block.nested
                                Enumeration
                                Class
                                Namespace
                                Namespace.unnamed
                                Namespace.global           // file scope in C
                                Concepts_scope??

  Storage Class Specifiers:
                                extern
                                static
                                static_internal
                                static_thread_local
                                dynamic
                                [mutable]
                                [auto-OLD-deprecated]
                                [register-OLD-deprecated]

   Linkage types 3:
    extern              linkage required   in hpp, prohibited in cpp
    static ie. internal linkage prohibited in hpp, prohibited mention in cpp, even though it is static if so in hpp.
    internal            linkage unavailabe in hpp, but can be expressed in cpp.
    ???none???          TODO??: can't remember why I mentined this?!?:prohibited in hpp, except the CONST special linkage exception

Rules for Header Files          hpp  Mostly Decl    (Headington p67)
YES + External Var              Decl
    + Fn Prototypes             Decl
    + Class Prototypes??        Decl
    + Type                      Decl
    + Constant Var              Defn
    + Preprocessor Directives   Defn
-> YES: extern, static, inline.

NO  - Fn                        Defn
    - Var                       Defn

Rules for Implementation Files  cpp All Defn (+some hpp stuff)       (Rostig 2023)
YES + Static Class Var Init     Init
    + Fn impl of hpp            Defn
    + Class Fn impl of hpp      Defn
    + Main Fn                   Defn
    + Preprocessor Directives   Defn
    + All of hpp content
        + ????
-> NO: extern, static, inline??

Both YES: namespace, using namesapce, using/typedef, ...??

Static:
+ static_linkage:       hidden variable from linker
+ static_storage:       variable in ELF.data for both fundamental types and Classes
                        + static implied for all vars and fn's in various namespaces? TODO??:  I suppose the warning was about storage, not scope or linkage.
+ static_fn_guard:      entire fn run threadsafe due to guard lock??.
-> only in hpp

Extern:
+external_linkage:      promise     to linker that name/var/fn is elsewhere, but "extern" is NOT allowed for class, even though it is IMPLICIT.
+external_ABI:          instruction to linker to use "C" ABI.??
-> both hpp/cpp??





KEY INSIGHT 1) Objects and Funtions have: Scope, Storage_Duration & Linkage.  memory too: S,SD,L === SSDL  (and "name" also)
            1.b) also initialization ordering.
            2) extern & static:         linkage and storage,        DON'T affect scope.
            3) static:                  "Can" affect function type, NO "this" implicit parameter.
            4) SCOPE is just for one TU. Linker requires external linkage to see globals and namespaced objects and funtions.

Object File Format (LDF/ELF):  code/text (machine instructions) &  literal/rodata (const vars) ) & data (init'ed vars) & bss (non-init'ed vars). https://en.wikipedia.org/wiki/Executable_and_Linkable_Format  https://en.wikipedia.org/wiki/Object_file
One Definition Rule (ODR).
Object File:     Defn === Definition that has a Declaration also. IE. has { ... }; "Definition"
                 Decl === Declaration that does not have the Definition.           "Non-defining declaration"

External_linkage:Def === Linker Definition
                 Ref === Linker Reference
                 TU  === Translation Unit.

Objects & Functions & Labels have Attributes:                                                                                                                   */
///                                             StorageDuration/////////////_LINKAGE/////////////////_SCOPE////////////////////////NAME/////////////////////////TYPE
/*                                                                                                  function_parameter_SCOPEy
                                               ?extern_StorageDur           external_l extern2       block_SCOPEy
                                                static1_StorageDur          internal_l static2      class_SCOPE (+struct/union)
                                                dynamic_StorageDur          static2                 namespace_SCOPEy - TU, But linker can see, if same namespace in other file it is external linkage.
                                                [mutable_Storage]           extern2                 global_namespace_SCOPEy TU
                                                [thread_local_StorageDur]                           unnamed_namespace_SCOPE
                                                [auto-OLD-deprecated]  */
///                                             +Object                     +Object                 +Object                       +Object                     +Object
///                                                                         +Function               +Function                     +Function                   +Function
///                                                                                                 +Label                        +Label                      +Label
/* Code_Example                                 StorageDuration             Linkage                 Scope                   Name    Type            Compiler_Sugar               Usage/location
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

extern int f() {return 0;};     // extern here does nothing but is allowed and is extern.
static int m();                 // don't do this sort of forward definition?
extern int n() {return 0;};

namespace ns {
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
    extern int n();  //

    //auto int a1 {};
    auto     a2 {"my_auto_a"};

    scope_test();

    //Row my_row;
    //Cpp_static_example ret_default_constructed {};
    clog.flush();
    cerr.flush();
    cout.flush();
    cout << "###" << endl;
    return 0;
}
