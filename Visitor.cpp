#include "Visitor.h"

Visitor::Visitor(double budget, std::string preferredAttraction, int timeInPark)
    : budget(budget), preferredAttraction(preferredAttraction), timeInPark(timeInPark) {}

bool Visitor::visitAttraction(double cost) {
    if (budget >= cost) {
        budget -= cost;
        return true;
    }
    return false;
}
