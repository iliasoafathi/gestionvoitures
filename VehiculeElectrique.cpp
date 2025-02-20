#include "VehiculeElectrique.hpp"
#include <iostream>

// Constructeur
VehiculeElectrique::VehiculeElectrique(const std::string& marque, const std::string& modele, int kilometrage, bool disponible, int autonomie)
    : Vehicule(marque, modele, kilometrage, disponible), autonomie(autonomie) {}

// Méthode spécifique
void VehiculeElectrique::afficherAutonomie() const {
    afficherDetails();
    std::cout << "Autonomie: " << autonomie << " km" << std::endl;
}

//Méthode virtuelle
void VehiculeElectrique::afficherType() const {
    std::cout << "Type : Véhicule électrique" << std::endl;
}

