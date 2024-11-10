#include "Attraction.h"
#include <iostream>

Attraction::Attraction(std::string name, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor)
    : name(name), capacity(capacity), constructionCost(constructionCost), maintenanceCost(maintenanceCost), incomePerVisitor(incomePerVisitor), status("closed") {}

void Attraction::displayInfo() const {
    std::cout << "Attraction: " << name << "\nCapacity: " << capacity << "\nStatus: " << status << "\n";
}

double Attraction::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;
}

std::string Attraction::getName() const { return name; }
void Attraction::setStatus(const std::string& newStatus) { status = newStatus; }
std::string Attraction::getStatus() const { return status; }