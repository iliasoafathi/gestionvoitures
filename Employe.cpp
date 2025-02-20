#include "Employe.hpp"
#include <iostream>

// Constructeur
Employe::Employe(const std::string& nom) : nom(nom) {}

// Getters
std::string Employe::getNom() const { return nom; }
std::vector<std::string> Employe::getVehiculesReserves() const { return vehiculesReserves; }

//Setters
void Employe::setVehiculesReserves(const std::vector<std::string>& vehicules) {
    vehiculesReserves = vehicules;
}
void Employe::setNom(const std::string& nouveauNom) {
    nom = nouveauNom;
}
    

// Méthodes
void Employe::reserverVehicule(const std::string& modele) {
    vehiculesReserves.push_back(modele);
}

void Employe::afficherReservations() const {
    if(this->getVehiculesReserves().size() == 0){
        std::cout << "Employé: " << nom << ", Véhicules réservés: Aucune";
        std::cout << std::endl; 
    }else{
        std::cout << "Employé: " << nom << ", Véhicules réservés: ";
        for (const auto& vehicule : vehiculesReserves) {
            std::cout << vehicule << " ";
        }
        std::cout << std::endl;
    }
}
