#include "Hotel.h"
#include <ostream>

Hotel::Hotel(string id, string nom, string ville, vector<Chambre> chambres) {
    _id = id;
    _nom = nom;
    _ville = ville;
    _chambres = chambres;    
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

ostream& operator << (ostream& os, const Hotel& hotel){
    os << "ID: "<< hotel._id << endl;
    os << "Nom: "<< hotel._nom << endl;
    os << "Ville: " << hotel._ville << endl;
    os << "Chambres: " << endl;
    for (const auto& chambre: hotel._chambres){
        os << chambre;
    } 

    return os; 
}