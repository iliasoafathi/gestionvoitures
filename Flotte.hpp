#ifndef FLOTTE_H
#define FLOTTE_H

#include <vector>
#include <memory>
#include "Vehicule.hpp"
#include "Employe.hpp"

class Flotte {
private:
    //Static var
    static int instanceCount ;
    std::vector<std::unique_ptr<Vehicule>> vehicules;
    std::vector<std::unique_ptr<Employe>> employes;

public:
    // Constructeur
    Flotte();

    // Méthodes de gestion des véhicules et employés
    void ajouterVehicule(std::unique_ptr<Vehicule> vehicule);
    void ajouterEmploye(std::unique_ptr<Employe> employe);

    // Réservation et mise à jour
    void reserverVehicule(const std::string& modele, const std::string& nomEmploye);
    void miseAJourKilometrage(const std::string& modele, int nouveauKilometrage);

    // Méthodes d'affichage
    void afficherVehiculesDisponibles() const;
    void afficherEmployes() const;
    void afficherEmployesWithoutReservation() const;
    void afficherFlotte() const;
    void afficherReservationsEmployes() const; // Afficher les employés avec leurs réservations
    
    //chercher Vehicule
    void chercherVehicule(const std::string& critere) const;
    
    //Afficher les reservations d'un employe donné
    void afficherReservationsEmploye(const std::string& nomEmploye) const;
    
    //Rapport
    void genererRapportFlotte() const;
    
    //annuler reservation
    void annulerReservation(const std::string& modele, const std::string& nomEmploye);
    
    //Retourner tous les vehicules
    const std::vector<std::unique_ptr<Vehicule>>& getVehicules() const ;
    //Static method
    static int getInstanceCount();
    //Desctructeur
    ~Flotte(); 
};

#endif // FLOTTE_H
