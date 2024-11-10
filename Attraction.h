#ifndef ATTRACTION_H
#define ATTRACTION_H

#include <string>

class Attraction {
protected:
  std::string name;
  int capacity;
  double constructionCost;
  double maintenanceCost;
  double incomePerVisitor;
  //status = "running" / "maintenance" / "closed"
  std::string status; 
  
public:
  Attraction(std::string name, int capacity, double constructionCost, double maintenanceCost, double incomePerVisitor);
  virtual ~Attraction() = default;
  virtual void displayInfo() const;
  virtual double calculateIncome(int visitors) const;
  
  
  std::string getName() const;
  std::status getStatus() const;
  void setStatus(const std::string& newStatus);
  
};

#endif


