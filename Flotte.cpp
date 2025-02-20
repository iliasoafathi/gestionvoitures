#include "Flotte.hpp"
#include "VehiculeElectrique.hpp"
#include <iostream>

//// Initialisation de la variable statique
int Flotte::instanceCount = 0;

// Constructeur : Initialise une flotte vide
Flotte::Flotte() {
    instanceCount++;
}

// Ajouter un véhicule
void Flotte::ajouterVehicule(std::unique_ptr<Vehicule> vehicule) {
    vehicules.push_back(std::move(vehicule));
}

// Ajouter un employé
void Flotte::ajouterEmploye(std::unique_ptr<Employe> employe) {
    employes.push_back(std::move(employe));
}

// Réserver un véhicule
void Flotte::reserverVehicule(const std::string& modele, const std::string& nomEmploye) {
    for (auto& vehicule : vehicules) {
        if (vehicule->getModele() == modele && vehicule->getDisponible()) {
            vehicule->setDisponibilite(false);
            for (auto& employe : employes) {
                if (employe->getNom() == nomEmploye) {
                    employe->reserverVehicule(modele);
                    std::cout << "Véhicule réservé avec succès." << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "Réservation échouée. Véhicule indisponible ou employé introuvable." << std::endl;
}

// Met à jour le kilométrage d'un véhicule
void Flotte::miseAJourKilometrage(const std::string& modele, int nouveauKilometrage) {
    for (auto& vehicule : vehicules) {
        if (vehicule->getModele() == modele) {
            vehicule->setKilometrage(nouveauKilometrage);
            std::cout << "Kilométrage mis à jour pour le véhicule : " << modele << std::endl;
            return;
        }
    }
    std::cout << "Véhicule non trouvé pour mise à jour du kilométrage." << std::endl;
}

// Afficher les véhicules disponibles
void Flotte::afficherVehiculesDisponibles() const {
    std::cout << "Véhicules disponibles :" << std::endl;
    for (const auto& vehicule : vehicules) {
        if (vehicule->getDisponible()) {
            vehicule->afficherDetails();
            vehicule->afficherType();
        }
    }
}

// Afficher les employes
void Flotte::afficherEmployes() const {
    std::cout << "Employes :" << std::endl;
    for (const auto& employe : employes) {
        std::cout << employe->getNom() << " ";
    }
    std::cout << std::endl;
}

//Afficher les employes sans reservation
void Flotte::afficherEmployesWithoutReservation() const {
    std::cout << "Employes sans reservation :" << std::endl;
    for(const auto& employe : employes){
        if(employe->getVehiculesReserves().size() == 0){
            std::cout << employe->getNom() << " ";
        }
    }
    std::cout << std::endl;
}



// Afficher toute la flotte
void Flotte::afficherFlotte() const {
    std::cout << "Tous les véhicules de la flotte :" << std::endl;
    for (const auto& vehicule : vehicules) {
        vehicule->afficherDetails();
    }
}

// Afficher les employés et leurs réservations
void Flotte::afficherReservationsEmployes() const {
    std::cout << "Réservations des employés :" << std::endl;
    for (const auto& employe : employes) {
            employe->afficherReservations();
    }
   
}

//Chercher Vehicule

void Flotte::chercherVehicule(const std::string& critere) const {
    bool trouve = false;
    for (const auto& vehicule : vehicules) {
        if (vehicule->getMarque() == critere || vehicule->getModele() == critere) {
            vehicule->afficherDetails();
            trouve = true;
        }
    }
    if (!trouve) {
        std::cout << "Aucun véhicule trouvé pour le critère : " << critere << std::endl;
    }
}

//Afficher les reservations d'un employe donné
void Flotte::afficherReservationsEmploye(const std::string& nomEmploye) const {
    for (const auto& employe : employes) {
        if (employe->getNom() == nomEmploye) {
            employe->afficherReservations();
            return;
        }
    }
    std::cout << "Aucun employé trouvé avec le nom : " << nomEmploye << std::endl;
}

//Rapport
void Flotte::genererRapportFlotte() const {
    int disponibles = 0, reserves = 0;
    int totalVehicule = vehicules.size();
    int empReserves = 0, empNonReserves = 0;
    int totalEmpolyes = employes.size();
    for (const auto& vehicule : vehicules) {
        if (vehicule->getDisponible()) {
            disponibles++;
        } else {
            reserves++;
        }
    }
    for(const auto& employe : employes){
        if(employe->getVehiculesReserves().size() != 0){
            empReserves++;
        }else{
            empNonReserves++;
        }
    }

   
    std::cout << "Total Véhicules : " << totalVehicule << std::endl;
    std::cout << "Véhicules disponibles : " << disponibles << std::endl;
    std::cout << "Véhicules réservés : " << reserves << std::endl;
    std::cout << "Total Employes : " << totalEmpolyes << std::endl;
    std::cout << "Employes avec réservation : " << empReserves << std::endl;
    std::cout << "Employes sans réservation : " << empNonReserves << std::endl;
}

//annuler reservation
void Flotte::annulerReservation(const std::string& modele, const std::string& nomEmploye) {
    for (auto& vehicule : vehicules) {
        if (vehicule->getModele() == modele && !vehicule->getDisponible()) {
            for (auto& employe : employes) {
                if (employe->getNom() == nomEmploye) {
                    // Vérifie si l'employé a bien réservé ce véhicule
                    auto reservations = employe->getVehiculesReserves();
                    auto it = std::find(reservations.begin(), reservations.end(), modele);

                    if (it != reservations.end()) {
                        reservations.erase(it); // Supprime la réservation
                        employe->setVehiculesReserves(reservations);
                        vehicule->setDisponibilite(true); // Rend le véhicule disponible
                        std::cout << "Réservation annulée avec succès pour " << modele
                                  << " par " << nomEmploye << "." << std::endl;
                        return;
                    } else {
                        std::cout << nomEmploye << " n'a pas réservé le véhicule " << modele << "." << std::endl;
                        return;
                    }
                }
            }
            std::cout << "Employé " << nomEmploye << " introuvable." << std::endl;
            return;
        }
    }
    std::cout << "Véhicule " << modele << " introuvable ou déjà disponible." << std::endl;
}
//Retourner tous les vehicules
const std::vector<std::unique_ptr<Vehicule>>& Flotte::getVehicules() const {
        return vehicules;
    }

//Static methode
int Flotte::getInstanceCount() {
    return instanceCount;
}


//Destrucetur
Flotte::~Flotte() {
    std::cout << "Destruction de la flotte et libération des ressources..." << std::endl;
}
