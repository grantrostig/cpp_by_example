#pragma once

class D;  // forward declare

class C {
    D * c1 {}; // this works because it is a pointer and doesn't need to know the full structure of the object pointed too.
  //  D   c2 {}; // todo: Is it possible to make this work?  // ERROR: field has incomplete type 'D'
};
