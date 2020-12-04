#include "Chambre.h"
#include <ostream>

using namespace std;
/*Constructeur par defaut de la classe Chambre*/
Chambre::Chambre()
{
}

/*Constructeur par param�tres de la classe*/
Chambre::Chambre(string id, TypeChambre type, int prix)
{
	this->_id = id;
	this->_type = type;
	this->_prix = prix;
}

/*Retourne l'id de la chambre*/
string Chambre::getId() const
{
	return this->_id;
}

/*retourne le type de la chambre*/
TypeChambre Chambre::getType() const
{
	return this->_type;
}

string Chambre::getStringType() const
{
	switch (this->getType()) {
	case TypeChambre::Double:
		return "Double";
	break;
	case TypeChambre::Single:
		return "Single";
	break;
	case TypeChambre::Suite:
		return "Suite";
	break;
	default:
		return "UNDEFINED";
	}
}

/*retourne le prix de la chambre*/
int Chambre::getPrix() const
{
	return this->_prix;
}

/*setter de l'id de la chambre*/
void Chambre::setId(string id)
{
	this->_id = id;
}

/*setter du type de la chambre*/
void Chambre::setType(TypeChambre type)
{
	this->_type = type;
}

/*setter du prix de la chambre*/
void Chambre::setPrix(int prix)
{
	this->_prix = prix;
}

string Chambre::toString() const
{
	string str = "";
	str += "La chambre numero : " + this->getId() + "\n"
		+ "Ayant le type : " + this->getStringType() + "\n"
		+ "est proposee au prix de : " + to_string(this->getPrix()) + "euros \n";
	return str;
}

ostream& operator << (ostream& os, const Chambre& chambre){
	os << "ID: " <<chambre._id << endl;
	os << "Type: " << chambre.getStringType() << endl ;
	os << "Prix: " <<  chambre._prix << endl;
	return os;
}