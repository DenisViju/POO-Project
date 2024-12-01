#include "Carousel.h"
#include <fstream>

// Constructor pentru Carousel
Carousel::Carousel(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor, int numberOfHorses)
    : Attraction(std::move(name), status, capacity, constructionCost, maintenanceCost, incomePerVisitor), numberOfHorses(numberOfHorses) {}

// Calcularea venitului pentru Carousel
double Carousel::calculateIncome(int visitors) const {
    return visitors * incomePerVisitor;  // Venitul este direct proporțional cu numărul de vizitatori
}

// Afișarea informațiilor pentru Carousel
void Carousel::displayInfo(std::ostream& os) const {
    os << "Tip: " << attractionTypeToString(getType()) << "\n";
    Attraction::displayInfo(os);  // Afișăm informațiile comune
    os << "Numar de cai pe carusel: " << numberOfHorses << "\n";
}

// Tipul atracției
AttractionType Carousel::getType() const {
    return AttractionType::Carousel;
}
