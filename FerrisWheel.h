#ifndef FERRISWHEEL_H
#define FERRISWHEEL_H

#include "Attraction.h"

// Clasa derivată FerrisWheel
class FerrisWheel : public Attraction {

public:
    // Constructor pentru FerrisWheel
    FerrisWheel(std::string name, Status status, int capacity, double constructionCost, 
                double maintenanceCost, double incomePerVisitor);

    // Implementare calculateIncome
    double calculateIncome(int visitors) const override;

    // Implementare displayInfo
    void displayInfo(std::ostream& os) const override;

    // Implementare getType
    AttractionType getType() const override;
};

#endif // FERRISWHEEL_H
