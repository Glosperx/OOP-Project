#ifndef OBSERVER_H
#define OBSERVER_H

#include "pch.h"

class Observer {
public:
    virtual void onNotify(const std::string& event) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_H
