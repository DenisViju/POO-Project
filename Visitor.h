#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <fstream>

class Visitor {
private:
    double budget;               // Bugetul vizitatorului
    std::string preferredAttraction; // Atracția preferată a vizitatorului
    int timeInPark;              // Timpul petrecut în parc (în minute)

public:
    // Constructor pentru Visitor
    Visitor(double budget, std::string preferredAttraction, int timeInPark);

    // Funcție care permite vizitatorului să viziteze o atracție
    bool visitAttraction(double cost);

    // Setează și obține informațiile despre atracția preferată
    void setPreferredAttraction(const std::string& attraction);
    std::string getPreferredAttraction() const;

    // Setează și obține timpul petrecut în parc
    void setTimeInPark(int time);
    int getTimeInPark() const;

    // Obține bugetul curent al vizitatorului
    double getBudget() const;

    // Salvează informațiile vizitatorului într-un fișier
    void saveVisitorInfo(std::ofstream& os) const;
};

#endif // VISITOR_H
