#include "Client.h"
#include <string>
#include <ostream>

using namespace std;
Client::Client(string id, string nom, string prenom, int nbReservations){
    _id = id;
    _nom = nom;
    _prenom = prenom;
    _nbReservations = nbReservations;
}

string Client::getId(){
    return _id;
}

string Client::getNom(){
    return _nom;
}
string Client::getPrenom(){
    return _prenom;
}
int Client::getNbReservations(){
    return _nbReservations;
}



void Client::setId(string id) {
    _id = id;
}

void Client::setNom(string nom) {
    _nom = nom;
}

void Client::Client::setPrenom(string prenom) {
    _prenom = prenom;    
}

void Client::Client::setNbReservations(int nbReservations) {
    _nbReservations = nbReservations;
}

ostream& operator << (ostream& os, const Client& client){
    os << "ID: " << client._id << endl;
    os << "Nom: " << client._nom << endl;
    os << "Prénom: " << client._prenom << endl;
    os << "Nombre de réservations: " << client._nbReservations << endl;
    return os;
}