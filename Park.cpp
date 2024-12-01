#include "Park.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <algorithm>

// Constructor pentru Park
Park::Park(double budget) : budget(budget) {}

void Park::addAttraction(std::unique_ptr<Attraction> attraction) {
    budget -= attraction->constructionCost;
    attractions.push_back(std::move(attraction));
}

void Park::simulateVisitors(int numberOfVisitors, std::ostream& os) {
    os << "Simularea parcului de distractii\n\n";

    double totalIncome = 0;
    int successfulVisitors = 0;  // Contor pentru vizitatori care au reușit să viziteze cel puțin o atracție
    std::vector<int> attractionVisitCount(attractions.size(), 0);  // Număr de vizite pentru fiecare atracție
    std::vector<double> visitorBudgets;

    // Creăm un vector de vizitatori
    srand(time(0));  // Seed pentru generarea numerelor aleatorii
    for (int i = 0; i < numberOfVisitors; ++i) {
        double visitorBudget = 100 + rand() % 500;
        visitorBudgets.push_back(visitorBudget);
        std::string preferredAttraction = attractions[rand() % attractions.size()]->getName();
        int timeInPark = rand() % 120 + 30;  // Timp între 30 și 120 minute

        Visitor visitor(visitorBudget, preferredAttraction, timeInPark);

        os << "Vizitatorul " << i + 1 << " a intrat in parc cu bugetul " << visitorBudget
           << " si prefera atractia '" << preferredAttraction << "'\n";

        bool visited = false;
        for (size_t j = 0; j < attractions.size(); ++j) {
            auto& attraction = attractions[j];
            if (attraction->getStatus() == Status::Running && visitor.visitAttraction(attraction->incomePerVisitor)) {
                visited = true;
                successfulVisitors++;
                attractionVisitCount[j]++;  // Incrementăm numărul de vizite pentru atracția respectivă
                os << "Vizitatorul cu bugetul " << visitorBudget << " a vizitat atractia '"
                   << attraction->getName() << "' cu succes. Bugetul ramas: " << visitorBudget << "\n";
                totalIncome += attraction->incomePerVisitor;
                break;
            }
        }

        if (!visited) {
            os << "Vizitatorul nu a reusit sa viziteze nici o atractie.\n";
        }
    }

    budget += totalIncome;
    os << "\nVenitul total generat: " << totalIncome << "\n";
    os << "Bugetul final al parcului: " << budget << "\n";
    os << "Numarul total de vizitatori in parc: " << numberOfVisitors << "\n";
    os << "Numarul vizitatorilor care au vizitat cel putin o atractie: " << successfulVisitors << "\n\n";

    // Determinarea celei mai vizitate și celei mai puțin vizitate atracții
    int mostVisitedIndex = std::distance(attractionVisitCount.begin(), std::max_element(attractionVisitCount.begin(), attractionVisitCount.end()));
    int leastVisitedIndex = std::distance(attractionVisitCount.begin(), std::min_element(attractionVisitCount.begin(), attractionVisitCount.end()));

    os << "Atractia cea mai vizitata: " << attractions[mostVisitedIndex]->getName() << " ("
       << attractionVisitCount[mostVisitedIndex] << " vizite)\n";
    os << "Atractia cea mai putin vizitata: " << attractions[leastVisitedIndex]->getName() << " ("
       << attractionVisitCount[leastVisitedIndex] << " vizite)\n";

    // Detalii despre atracții
    os << "\nDetalii despre atracții:\n";
    for (const auto& attraction : attractions) {
        attraction->displayInfo(os);
    }
}



void Park::displayStatistics(std::ofstream& os) {
    os << "Statistici despre parc:\n";

    // Afiseaza numarul total de atractii
    os << "Numar total de atractii: " << attractions.size() << "\n";

    // Afiseaza statistici pentru fiecare atractie
    double totalIncome = 0.0;
    for (const auto& attraction : attractions) {
        // Afisam informatiile despre fiecare atractie
        attraction->displayInfo(os);

        // Calculăm venitul total
        totalIncome += attraction->calculateIncome(100);  // Presupunem 100 de vizitatori
    }

    // Afișează venitul total generat
    os << "Venit total generat: " << totalIncome << " lei\n";
}

void Park::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Nu s-a putut deschide fisierul " + filename);
    }

    attractions.clear();
    std::string type, name, status;
    int capacity;
    double constructionCost, maintenanceCost, incomePerVisitor;
    while (file >> type >> name >> capacity >> constructionCost >> maintenanceCost >> incomePerVisitor >> status) {
        std::unique_ptr<Attraction> attraction = nullptr;
        Status attractionStatus = (status == "running") ? Status::Running : (status == "closed") ? Status::Closed : Status::Maintenance;

        if (type == "RollerCoaster") {
            attraction = std::unique_ptr<RollerCoaster>(new RollerCoaster(name, attractionStatus, capacity, constructionCost, maintenanceCost, incomePerVisitor, 5));
        } else if (type == "Carousel") {
            attraction = std::unique_ptr<Carousel>(new Carousel(name, attractionStatus, capacity, constructionCost, maintenanceCost, incomePerVisitor, 20));
        } else if (type == "HauntedHouse") {
            attraction = std::unique_ptr<HauntedHouse>(new HauntedHouse(name, attractionStatus, capacity, constructionCost, maintenanceCost, incomePerVisitor, true));
        } else if (type == "WaterSlide") {
            attraction = std::unique_ptr<WaterSlide>(new WaterSlide(name, attractionStatus, capacity, constructionCost, maintenanceCost, incomePerVisitor));
        } else if (type == "FerrisWheel") {
            attraction = std::unique_ptr<FerrisWheel>(new FerrisWheel(name, attractionStatus, capacity, constructionCost, maintenanceCost, incomePerVisitor));
        }

        if (attraction) {
            attractions.push_back(std::move(attraction));
        }
    }
}

void Park::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Nu s-a putut deschide fisierul " + filename);
    }

    for (const auto& attraction : attractions) {
        file << attraction->getName() << " "
             << attraction->capacity << " "
             << attraction->constructionCost << " "
             << attraction->maintenanceCost << " "
             << attraction->incomePerVisitor << " "
             << (attraction->getStatus() == Status::Running ? "running" : "closed") << "\n";
    }
}
