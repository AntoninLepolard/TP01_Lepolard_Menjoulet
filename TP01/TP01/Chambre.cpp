#include "Chambre.h"

/*Constructeur par defaut de la classe Chambre*/
Chambre::Chambre()
{
}

/*Constructeur par paramètres de la classe*/
Chambre::Chambre(int id, TypeChambre type, int prix)
{
	this->_id = id;
	this->_type = type;
	this->_prix = prix;
}

/*Retourne l'id de la chambre*/
int Chambre::getId()
{
	return this->_id;
}

/*retourne le type de la chambre*/
TypeChambre Chambre::getType()
{
	return this->_type;
}

std::string Chambre::getStringType()
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
int Chambre::getPrix()
{
	return this->_prix;
}

/*setter de l'id de la chambre*/
void Chambre::setId(int id)
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

std::string Chambre::toString()
{
	std::string str = "";
	str += "La chambre numero : " + std::to_string(this->getId()) + "\n"
		+ "Ayant le type : " + this->getStringType() + "\n"
		+ "est proposee au prix de : " + std::to_string(this->getPrix()) + "euros \n";
	return str;
}
