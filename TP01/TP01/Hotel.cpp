#include "Hotel.h"

Hotel::Hotel::Hotel(string id, string nom, string ville, int nbChambres) {
    _id = id;
    _nom = nom;
    _ville = ville;
    _chambres.resize(nbChambres);    
}

string Hotel::getId() {
    return _id;
}   

string Hotel::getNom() {
    return _nom;    
}

string Hotel::getVille() {
    return _ville;    
}

vector<Chambre> Hotel::getChambres() {
    return _chambres;    
}
