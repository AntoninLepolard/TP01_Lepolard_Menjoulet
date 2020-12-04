#pragma once
#include <string>
#include <vector>
#include "Chambre.h"

using namespace std;

class Hotel
{
    private:
        string _id;
        string _nom;
        string _ville;
        vector<Chambre> _listeChambres;
    public:
        Hotel(string id, string nom, string ville);

        //getters
        string getId();
        string getNom();
        string getVille();
        vector<Chambre> getChambres();

		//autres méthodes
		void addChambre(Chambre chambre);
		int getIndex(Chambre chambre);
		void removeChambre(Chambre chambre);

        //affichage
        friend ostream& operator << (ostream& os, const Hotel& hotel);
};

