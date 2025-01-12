#include <iostream>
#include <fstream>
#include <memory>
#include "Park.h"
#include "Visitor.h"

int main() {
    // Deschide fișierul output.txt pentru a scrie rezultatele
    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Eroare la deschiderea fisierului pentru scriere." << std::endl;
        return 1;
    }

    // Crează un parc cu un buget inițial
    Park park(100000); // Buget inițial pentru parc
    outputFile << "Bugetul initial al parcului: " << park.getBudget() << "\n\n";

    // Încarcă atracțiile din fișierul input.txt
    try {
        park.loadFromFile("input.txt");
    } catch (const std::exception& e) {
        std::cerr << "Eroare la incarcarea fisierului: " << e.what() << std::endl;
        return 1;
    }


    //Afiseaza atractiile din planul de constructie
    outputFile << "ATRACTIILE DIN PLANUL DE CONSTRUCTIE:\n\n";
    park.displayStatistics(outputFile);  // Scrie informațiile despre parc în fișier
    park.constructAttractions();

    outputFile << "Bugetul parcului dupa construirea atractiilor: " << park.getBudget() << "\n\n";

    //afiseaza atractiile care au putut fi construite in functie de bugetul parcului
    outputFile << "ATRACTIILE CARE AU PUTUT FI CONSTRUITE IN FUNCTIE DE BUGETUL INITIAL:\n\n";
    park.displayStatistics(outputFile);

    // Simulează vizitele vizitatorilor
    int numberOfVisitors = 100;  // Număr de vizitatori pentru simulare
    park.simulateVisitors(numberOfVisitors, outputFile);

    // Afișează statistici după simulare în fișier
    outputFile << "\nStatistici dupa simulare:\n";
    park.displayStatistics(outputFile);  // Scrie informațiile după simulare în fișier

    // Închide fișierul output.txt
    outputFile.close();

    return 0;
}

