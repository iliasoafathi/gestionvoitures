#include "Vehicule.hpp"

// Constructeur
Vehicule::Vehicule(const std::string& marque, const std::string& modele, int kilometrage, bool disponible)
    : marque(marque), modele(modele), kilometrage(kilometrage), disponible(disponible) {}

// Getters
std::string Vehicule::getMarque() const { return marque; }
std::string Vehicule::getModele() const { return modele; }
int Vehicule::getKilometrage() const { return kilometrage; }
bool Vehicule::getDisponible() const { return disponible; }

// Setters
void Vehicule::setMarque(const std::string& nouvelleMarque) {marque = nouvelleMarque; }
void Vehicule::setModele(const std::string& nouveauModele) {modele = nouveauModele;}
void Vehicule::setKilometrage(int nouveauKilometrage) { kilometrage = nouveauKilometrage; }
void Vehicule::setDisponibilite(bool etat) { disponible = etat; }

// Méthodes supplémentaires
void Vehicule::afficherDetails() const {
    std::cout << "Marque: " << marque
              << ", Modèle: " << modele
              << ", Kilométrage: " << kilometrage
              << ", Disponible: " << (disponible ? "Oui" : "Non") << std::endl;
}
//Methode virtuelle
void Vehicule::afficherType() const {
    std::cout << "Type : Véhicule classique" << std::endl;
}

// Surcharge d'opérateur
std::ostream& operator<<(std::ostream& os, const Vehicule& v) {
    os << "Marque: " << v.marque << ", Modèle: " << v.modele
       << ", Kilométrage: " << v.kilometrage << ", Disponible: " << (v.disponible ? "Oui" : "Non");
    return os;
}
