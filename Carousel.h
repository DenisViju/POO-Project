#ifndef CAROUSEL_H
#define CAROUSEL_H

#include "Attraction.h"

// Clasa derivată Carousel
class Carousel : public Attraction {
private:
    int numberOfHorses; // Numarul de cai pe carusel

public:
    // Constructor pentru Carousel
    Carousel(std::string name, Status status, int capacity, double constructionCost, 
             double maintenanceCost, double incomePerVisitor, int numberOfHorses);

    // Implementare calculateIncome
    double calculateIncome(int visitors) const override;

    // Implementare displayInfo
    void displayInfo(std::ostream& os) const override;

    // Implementare getType
    AttractionType getType() const override;
};

#endif // CAROUSEL_H
