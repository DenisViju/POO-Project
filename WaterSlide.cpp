#include "WaterSlide.h"
#include <fstream>

// Constructor pentru WaterSlide
WaterSlide::WaterSlide(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor)
    : Attraction(std::move(name), status, capacity, constructionCost, maintenanceCost, incomePerVisitor) {}

// Calcularea venitului pentru WaterSlide
double WaterSlide::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;  // Venitul este direct proporțional cu numărul de vizitatori
}

// Afișarea informațiilor pentru WaterSlide
void WaterSlide::displayInfo(std::ostream& os) const {
    os << "Tip: " << attractionTypeToString(getType()) << "\n";
    Attraction::displayInfo(os);  // Afișăm informațiile comune
}

// Tipul atracției
AttractionType WaterSlide::getType() const {
    return AttractionType::WaterSlide;
}
