#pragma once
#include <string>

using namespace std;
class Client
{
    private:
        int _id;
        string _nom;
        string _prenom;
        int _nbReservations;
    
    public:
        Client(int id, string nom, string prenom, int nbReservations);

        //getters
        int getId();
        string getNom();
        string getPrenom();
        int getNbReservations();

        //setters
        void setId(int id);
        void setNom(string nom);
        void setPrenom(string prenom);
        void setNbReservations(int nbReservations);
};

