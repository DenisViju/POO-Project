#ifndef PARK_H
#define PARK_H

#include "RollerCoaster.h"
#include "Carousel.h"
#include "HauntedHouse.h"
#include "WaterSlide.h"
#include "FerrisWheel.h"
#include "Visitor.h"
#include <vector>
#include <string>
#include <memory>
#include <fstream> 

class Park {
private:
    double budget;
    std::vector<std::unique_ptr<Attraction>> attractions;

public:
    // Constructor pentru Park
    Park(double budget);

    // Destructor implicit
    ~Park() = default;

    // Adaugă o atracție în parc
    void addAttraction(std::unique_ptr<Attraction> attraction);

    // Simulează vizitele vizitatorilor și scrie informațiile într-un fișier de ieșire
    void simulateVisitors(int numberOfVisitors, std::ostream& os);

    // Afișează statistici despre parc într-un fișier
    void displayStatistics(std::ofstream& os);

    // Încarcă informațiile despre atracții dintr-un fișier
    void loadFromFile(const std::string& filename);

    // Salvează informațiile despre atracții într-un fișier
    void saveToFile(const std::string& filename);

    // Modifică statusul unei atracții
    void updateAttractionStatus(const std::string& attractionName, Status status);

    // Șterge o atracție din parc
    void removeAttraction(const std::string& attractionName);
};

#endif
