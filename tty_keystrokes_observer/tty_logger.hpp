#pragma once
#include "observer.hpp"
#include <iostream>


/// Adding this Observer to code example to illustrate having more than just one,
/// also show using more typical update() as per GOF, not done yet.

class tty_logger: public Observer {
public:
    // tty_logger( ) {} ;
    Update_ret update()                                 override;
};
