#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include "pch.h"

class Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(std::shared_ptr<Observer> observer);
    void removeObserver(std::shared_ptr<Observer> observer);

protected:
    void notifyObservers(const std::string& event);
};

#endif // SUBJECT_H
