#include "Hotel.h"
#include <ostream>

Hotel::Hotel(string id, string nom, string ville) {
    _id = id;
    _nom = nom;
    _ville = ville;
	_listeChambres = vector<Chambre> ();
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
    return _listeChambres;    
}

/*Méthode pour ajouter une chambre dans la liste de chambres de l'hotel*/
void Hotel::addChambre(Chambre chambre)
{
	this->_listeChambres.push_back(chambre);
}

/*renvoie l'index de l'instance de chambre dans le tableau*/
int Hotel::getIndex(Chambre chambre)
{
	int i = 0;
	int index = -1;
	bool found = false;
	while (i < this->_listeChambres.size() && found == false)
	{
		if (this->getChambres().at(i).getId() == chambre.getId())
		{
			index = i;
			found = true;
		}
		i++;
	}
	return index;
}

/*supprime la chambre souhaitee de la liste*/
void Hotel::removeChambre(Chambre chambre)
{
	
	this->_listeChambres.erase(_listeChambres.begin() + getIndex(chambre));
}

ostream& operator << (ostream& os, const Hotel& hotel){
    os << "ID: "<< hotel._id << endl;
    os << "Nom: "<< hotel._nom << endl;
    os << "Ville: " << hotel._ville << endl;
    os << endl <<  "Chambres: " << endl;
    for (const auto& chambre: hotel._listeChambres){
        os << chambre;
		os << "_______________" << endl;
    } 
	

    return os; 
}