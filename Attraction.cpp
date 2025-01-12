#include "Attraction.h"

// Constructor pentru Attraction
Attraction::Attraction(std::string name, Status status, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor)
    : name(std::move(name)), status(status), capacity(capacity), constructionCost(constructionCost), maintenanceCost(maintenanceCost), incomePerVisitor(incomePerVisitor) {}

// Metoda de afișare a informațiilor atracției
void Attraction::displayInfo(std::ostream& os) const {
    os << "Atractia: " << name << "\n"
        << "Status: " << (status == Status::Running ? "Running" : status == Status::Closed ? "Closed" : "Maintenance") << "\n"
        << "Capacitate: " << capacity << "\n"
        << "Cost de constructie: " << constructionCost << " lei\n"
        << "Cost de intretinere: " << maintenanceCost << " lei\n"
        << "Venit per vizitator: " << incomePerVisitor << " lei\n\n";
}

std::string attractionTypeToString(AttractionType type) {
    switch (type) {
    case AttractionType::RollerCoaster: return "RollerCoaster";
    case AttractionType::Carousel: return "Carousel";
    case AttractionType::HauntedHouse: return "HauntedHouse";
    case AttractionType::WaterSlide: return "WaterSlide";
    case AttractionType::FerrisWheel: return "FerrisWheel";
    default: return "Unknown";
    }
}

std::string Attraction::getName() const {
    return name;
}

void Attraction::setStatus(Status newStatus) {
    status = newStatus;
}

Status Attraction::getStatus() const {
    return status;
}

double Attraction::getConstructionCost() const { return constructionCost; }
