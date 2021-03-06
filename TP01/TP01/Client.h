#pragma once
#include <string>

using namespace std;
class Client
{
    private:
        string _id;
        string _nom;
        string _prenom;
        int _nbReservations;
    
    public:
        Client(string id, string nom, string prenom, int nbReservations);

        //getters
        string getId() const;
        string getNom() const;
        string getPrenom() const;
        int getNbReservations() const;

        //setters
        void setId(string id);
        void setNom(string nom);
        void setPrenom(string prenom);
        void setNbReservations(int nbReservations);

        //affichage
        friend ostream& operator << (ostream& os, const Client& client);
};

