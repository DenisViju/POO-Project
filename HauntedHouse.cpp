#include "HauntedHouse.h"
#include <fstream>

// Constructor pentru HauntedHouse
HauntedHouse::HauntedHouse(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor, bool isScary)
    : Attraction(std::move(name), status, capacity, constructionCost, maintenanceCost, incomePerVisitor), isScary(isScary) {}

// Calcularea venitului pentru HauntedHouse
double HauntedHouse::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;  // Venitul este direct proporțional cu numărul de vizitatori
}

// Afișarea informațiilor pentru HauntedHouse
void HauntedHouse::displayInfo(std::ostream& os) const {
    os << "Tip: " << attractionTypeToString(getType()) << "\n";
    Attraction::displayInfo(os);  // Afișăm informațiile comune
    os << "Este infricosatoare: " << (isScary ? "Da" : "Nu") << "\n";
}

// Tipul atracției
AttractionType HauntedHouse::getType() const {
    return AttractionType::HauntedHouse;
}
