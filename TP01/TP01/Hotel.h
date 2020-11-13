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
        vector<Chambre> _chambres;
    public:
        Hotel(string id, string nom, string ville, int nbChambres);
        string getId();
        string getNom();
        string getVille();
        vector<Chambre> getChambres();
};

