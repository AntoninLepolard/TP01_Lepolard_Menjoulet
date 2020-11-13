#include "Client.h"
#include <string>

using namespace std;


Client::Client(int id, string nom, string prenom, int nbReservations){
    _id = id;
    _nom = nom;
    _prenom = prenom;
    _nbReservations = nbReservations;
}

int Client::getId(){
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



void Client::setId(int id) {
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
