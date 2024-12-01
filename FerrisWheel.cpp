#include "FerrisWheel.h"
#include <fstream>

// Constructor pentru FerrisWheel
FerrisWheel::FerrisWheel(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor)
    : Attraction(std::move(name), status, capacity, constructionCost, maintenanceCost, incomePerVisitor) {}

// Calcularea venitului pentru FerrisWheel
double FerrisWheel::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;  // Venitul este direct proporțional cu numărul de vizitatori
}

// Afișarea informațiilor pentru FerrisWheel
void FerrisWheel::displayInfo(std::ostream& os) const {
    os << "Tip: " << attractionTypeToString(getType()) << "\n";
    Attraction::displayInfo(os);  // Afișăm informațiile comune
}

// Tipul atracției
AttractionType FerrisWheel::getType() const {
    return AttractionType::FerrisWheel;
}
