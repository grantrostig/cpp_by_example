#pragma once
#include <cerrno>

class Observer {
public:
    //  TODO??: what better type?: using Update_ret = decltype(errno);
    using Update_ret = int;
    virtual                 ~Observer()    =default;   // TODO??: is this required under the rule of 5/6?

    virtual Update_ret      update()      =0;          // TODO??: What better type, how better defined?
};
