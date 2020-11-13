#pragma once
#include <string>

enum class TypeChambre {
	Single, Double, Suite
};


class Chambre
{

public: 
	// constructeur / destructeur
	Chambre();
	Chambre(int id, TypeChambre type, int prix);

	//getters
	int getId();
	TypeChambre getType();
	std::string getStringType();
	int getPrix();

	//setters
	void setId(int id);
	void setType(TypeChambre type);
	void setPrix(int prix);

	//methode d'affichage
	std::string toString();


private:
	int _id, _prix;
	TypeChambre _type;
};

