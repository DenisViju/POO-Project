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

    // Încarcă atracțiile din fișierul input.txt
    try {
        park.loadFromFile("input.txt");
    } catch (const std::exception& e) {
        std::cerr << "Eroare la incarcarea fisierului: " << e.what() << std::endl;
        return 1;
    }

    // Afișează statistici inițiale în fișier
    outputFile << "Statistici initiale ale parcului:\n";
    park.displayStatistics(outputFile);  // Scrie informațiile despre parc în fișier

    // Simulează vizitele vizitatorilor
    int numberOfVisitors = 100;  // Număr de vizitatori pentru simulare
    outputFile << "\nSimulare vizitatori:\n";
    park.simulateVisitors(numberOfVisitors, outputFile);

    // Afișează statistici după simulare în fișier
    outputFile << "\nStatistici dupa simulare:\n";
    park.displayStatistics(outputFile);  // Scrie informațiile după simulare în fișier

    // Închide fișierul output.txt
    outputFile.close();

    return 0;
}

