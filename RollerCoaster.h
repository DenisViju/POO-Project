#ifndef ROLLERCOASTER_H
#define ROLLERCOASTER_H

#include "Attraction.h"

// Clasa derivată RollerCoaster
class RollerCoaster : public Attraction {
private:
    int numberOfLoops; // Numarul de bucle

public:
    // Constructor pentru RollerCoaster
    RollerCoaster(std::string name, Status status, int capacity, double constructionCost, 
                  double maintenanceCost, double incomePerVisitor, int numberOfLoops);

    // Implementare calculateIncome
    double calculateIncome(int visitors) const override;

    // Implementare displayInfo
    void displayInfo(std::ostream& os) const override;

    // Implementare getType
    AttractionType getType() const override;
};

#endif // ROLLERCOASTER_H
