#ifndef VEHICULE_H
#define VEHICULE_H

#include <iostream>
#include <string>

class Vehicule {
protected:
    std::string marque;
    std::string modele;
    int kilometrage;
    bool disponible;

public:
    // Constructeur
    Vehicule(const std::string& marque, const std::string& modele, int kilometrage, bool disponible);

    // Getters
    std::string getMarque() const;
    std::string getModele() const;
    int getKilometrage() const;
    bool getDisponible() const;

    // Setters
    void setMarque(const std::string& nouvelleMarque);
    void setModele(const std::string& nouveauModele);
    void setKilometrage(int nouveauKilometrage);
    void setDisponibilite(bool etat);

    // Méthodes supplémentaires
    void afficherDetails() const;
    virtual ~Vehicule() = default;
    //Méthode virtuelle
    virtual void afficherType() const;
    // Surcharge d'opérateur
    friend std::ostream& operator<<(std::ostream& os, const Vehicule& v);
};

#endif // VEHICULE_H
