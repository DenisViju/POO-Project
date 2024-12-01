#ifndef HAUNTEDHOUSE_H
#define HAUNTEDHOUSE_H

#include "Attraction.h"

// Clasa derivată HauntedHouse
class HauntedHouse : public Attraction {
private:
    bool isScary; // Daca este sau nu infricosatoare

public:
    // Constructor pentru HauntedHouse
    HauntedHouse(std::string name, Status status, int capacity, double constructionCost, 
                 double maintenanceCost, double incomePerVisitor, bool isScary);

    // Implementare calculateIncome
    double calculateIncome(int visitors) const override;

    // Implementare displayInfo
    void displayInfo(std::ostream& os) const override;

    // Implementare getType
    AttractionType getType() const override;
};

#endif // HAUNTEDHOUSE_H
