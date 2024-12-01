#include "Visitor.h"
#include <iostream>

// Constructor pentru Visitor
Visitor::Visitor(double budget, std::string preferredAttraction, int timeInPark)
    : budget(budget), preferredAttraction(std::move(preferredAttraction)), timeInPark(timeInPark) {}

// Funcție pentru a simula vizita unui vizitator la o atracție
bool Visitor::visitAttraction(double cost) {
    if (budget >= cost) {
        budget -= cost; // Scădem din bugetul vizitatorului
        return true; // Vizitatorul poate vizita atracția
    }
    return false; // Vizitatorul nu are suficienți bani
}

// Setează atracția preferată
void Visitor::setPreferredAttraction(const std::string& attraction) {
    preferredAttraction = attraction;
}

// Obține atracția preferată
std::string Visitor::getPreferredAttraction() const {
    return preferredAttraction;
}

// Setează timpul petrecut în parc
void Visitor::setTimeInPark(int time) {
    timeInPark = time;
}

// Obține timpul petrecut în parc
int Visitor::getTimeInPark() const {
    return timeInPark;
}

// Funcție pentru a obține bugetul curent al vizitatorului
double Visitor::getBudget() const {
    return budget;
}

// Funcție pentru a salva informațiile vizitatorului într-un fișier
void Visitor::saveVisitorInfo(std::ofstream& os) const {
    os << "Vizitatorul cu bugetul initial de " << budget + 100 // presupunem un buget initial de 100
       << " lei si atracția preferată: " << preferredAttraction 
       << " a rămas cu un buget de " << budget << " lei după vizită." << std::endl;
}
