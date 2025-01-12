#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>
#include <fstream>

// Enumerarea pentru tipurile de atracții
enum class AttractionType {
    RollerCoaster,
    Carousel,
    HauntedHouse,
    WaterSlide,
    FerrisWheel
};

// Enumerarea pentru stările atracțiilor
enum class Status {
    Running,
    Closed,
    Maintenance
};

std::string attractionTypeToString(AttractionType type);

class Attraction {
protected:
    std::string name;                // Numele atracției
    Status status;                   // Starea atracției (Running, Closed, Maintenance)
    int capacity;                    // Capacitatea atracției (de ex. nr. vizitatori pe oră)
    double constructionCost;         // Costul de construcție al atracției
    double maintenanceCost;          // Costul de întreținere
    double incomePerVisitor;         // Venitul per vizitator

public:
    // Constructor
    Attraction(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor);

    // Virtual methods
    virtual double calculateIncome(int visitors) const = 0;  // Metodă virtuală pură pentru calcularea venitului
    virtual void displayInfo(std::ostream& os) const;        // Afișează informațiile atracției
    virtual AttractionType getType() const = 0;               // Metodă virtuală pură pentru a obține tipul atracției

    // Getter și setter pentru status
    Status getStatus() const;
    void setStatus(Status newStatus);

    // Getter pentru nume
    std::string getName() const;

    double getConstructionCost() const;
    
    friend class Park;
};

#endif // ATTRACTION_H
