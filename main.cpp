#include "Flotte.hpp"
#include "VehiculeElectrique.hpp"
#include <memory>
#include <iostream>

int main() {
    {
        //Nombre d'instances de Flotte créées
        std::cout << "Nombre d'instances de Flotte créées : "
                      << Flotte::getInstanceCount() << std::endl;
        
        // Initialiser la flotte
        Flotte flotte;

        // Création de véhicules (véhicules classiques)
        flotte.ajouterVehicule(std::make_unique<Vehicule>("Toyota", "Corolla", 50000, true));
        flotte.ajouterVehicule(std::make_unique<Vehicule>("Honda", "Civic", 40000, true));
        flotte.ajouterVehicule(std::make_unique<Vehicule>("Ford", "Fiesta", 80000, true));

        // Création de véhicules électriques
        flotte.ajouterVehicule(std::make_unique<VehiculeElectrique>("Tesla", "Model S", 30000, true, 500));
        flotte.ajouterVehicule(std::make_unique<VehiculeElectrique>("Nissan", "Leaf", 20000, true, 300));


        // Création d'employés
        flotte.ajouterEmploye(std::make_unique<Employe>("Anass"));
        flotte.ajouterEmploye(std::make_unique<Employe>("Ilyass"));
        flotte.ajouterEmploye(std::make_unique<Employe>("Yasser"));
        flotte.ajouterEmploye(std::make_unique<Employe>("Oussama"));
        
        // Affichage initial : véhicules disponibles et employes
        std::cout << "\n=== Véhicules disponibles ===" << std::endl;
        flotte.afficherVehiculesDisponibles();
        
        //Affichage des employes
        std::cout << "\n=== Employes ===" << std::endl;
        flotte.afficherEmployes();
        
        //Affichages des employes sans reservation
        std::cout << "\n=== Employes sans reservation ===" << std::endl;
        flotte.afficherEmployesWithoutReservation();


        // Réservations par les employés
        std::cout << "\n=== Réservations de véhicules ===" << std::endl;
        flotte.reserverVehicule("Corolla", "Anass");
        flotte.reserverVehicule("Model S", "Ilyass");
        flotte.reserverVehicule("Civic", "Yasser");
        flotte.reserverVehicule("Leaf", "Anass");
        
        //Affichages des employes sans reservation
        std::cout << "\n=== Employes sans reservation ===" << std::endl;
        flotte.afficherEmployesWithoutReservation();
        
        // Mise à jour du kilométrage
        std::cout << "\n=== Mise à jour du kilométrage ===" << std::endl;
        flotte.miseAJourKilometrage("Corolla", 55000);
        flotte.miseAJourKilometrage("Model S", 31000);

        // Affichage final : état complet de la flotte
        std::cout << "\n=== État complet de la flotte ===" << std::endl;
        flotte.afficherFlotte();

        // Afficher les réservations des employés
        std::cout << "\n=== Réservations des employés ===" << std::endl;
        flotte.afficherReservationsEmployes();
        
        //Rechercher Vehicule
        std::cout << "\n=== Recherche de véhicule par critère ===" << std::endl;
        flotte.chercherVehicule("Tesla");
        
        //Rechercher les reservations d'un employe donné
        std::cout << "\n=== Réservations d'un employé ===" << std::endl;
        flotte.afficherReservationsEmploye("Anass");
        
        //Annuler reservation
        std::cout << "\n=== Annulation d'une réservation ===" << std::endl;
        flotte.annulerReservation("Corolla", "Anass");
        
        //Rechercher les reservations d'un employe donné
        std::cout << "\n=== Réservations d'un employé ===" << std::endl;
        flotte.afficherReservationsEmploye("Anass");
        
       //Rapprot
        std::cout << "\n=== Rapport de la flotte ===" << std::endl;
        flotte.genererRapportFlotte();
        
        // Afficher les détails des véhicules électriques
        std::cout << "\n=== Détails des véhicules électriques === :\n";
        for (const auto& vehicule : flotte.getVehicules()) {
            if (auto vehiculeElectrique = dynamic_cast<VehiculeElectrique*>(vehicule.get())) {
                vehiculeElectrique->afficherAutonomie();  // Affiche les détails des véhicules électriques
            } 
        }
        //Nombre d'instances de Flotte créées
        std::cout << "\n=== Nombre d'instances de Flotte créées ===  : "
                      << Flotte::getInstanceCount() << std::endl;

    }


    return 0;
}
