#ifndef WATERSLIDE_H
#define WATERSLIDE_H

#include "Attraction.h"

// Clasa derivată WaterSlide
class WaterSlide : public Attraction {

public:
    // Constructor pentru WaterSlide
    WaterSlide(std::string name, Status status, int capacity, double constructionCost, 
               double maintenanceCost, double incomePerVisitor);

    // Implementare calculateIncome
    double calculateIncome(int visitors) const override;

    // Implementare displayInfo
    void displayInfo(std::ostream& os) const override;

    // Implementare getType
    AttractionType getType() const override;
};

#endif // WATERSLIDE_H
