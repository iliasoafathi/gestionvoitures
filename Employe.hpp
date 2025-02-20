#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <iostream>

#include <string>
#include <vector>

class Employe {
private:
    std::string nom;
    std::vector<std::string> vehiculesReserves;

public:
    // Constructeur
    Employe(const std::string& nom);

    // Getters
    std::string getNom() const;
    std::vector<std::string> getVehiculesReserves() const;
    
    //Setters
    void setVehiculesReserves(const std::vector<std::string>& vehicules);
    void setNom(const std::string& nouveauNom); 
    // Méthodes
    void reserverVehicule(const std::string& modele);
    void afficherReservations() const;
};

#endif // EMPLOYE_H
