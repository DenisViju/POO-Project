#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Visitor {
private:
    double budget;
    std::string preferredAttraction;
    int timeInPark;
public:
    Visitor(double budget, std::string preferredAttraction, int timeInPark);
    bool visitAttraction(double cost);
};

#endif