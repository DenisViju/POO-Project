#include "RollerCoaster.h"
#include <fstream>

// Constructor pentru RollerCoaster
RollerCoaster::RollerCoaster(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor, int numberOfLoops)
    : Attraction(std::move(name), status, capacity, constructionCost, maintenanceCost, incomePerVisitor), numberOfLoops(numberOfLoops) {}

// Calcularea venitului pentru RollerCoaster
double RollerCoaster::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;  // Venitul este direct proporțional cu numărul de vizitatori
}

// Afișarea informațiilor pentru RollerCoaster
void RollerCoaster::displayInfo(std::ostream& os) const {
    os << "Tip: " << attractionTypeToString(getType()) << "\n";
    Attraction::displayInfo(os);  // Afișăm informațiile comune
    os << "Numar de bucle: " << numberOfLoops << "\n";
}

// Tipul atracției
AttractionType RollerCoaster::getType() const {
    return AttractionType::RollerCoaster;
}
