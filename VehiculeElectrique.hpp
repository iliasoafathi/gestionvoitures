#ifndef VEHICULEELECTRIQUE_H
#define VEHICULEELECTRIQUE_H

#include "Vehicule.hpp"

class VehiculeElectrique : public Vehicule {
private:
    int autonomie;

public:
    // Constructeur
    VehiculeElectrique(const std::string& marque, const std::string& modele, int kilometrage, bool disponible, int autonomie);

    // Méthode spécifique
    void afficherAutonomie() const;
    
    //Méthode virtuelle
    void afficherType() const override; 
};

#endif // VEHICULEELECTRIQUE_H
