#pragma once
#include <string>

using namespace std;

enum TypeChambre {
	Single, Double, Suite
};


class Chambre
{

public: 
	// constructeur / destructeur
	Chambre();
	Chambre(string id, TypeChambre type, int prix);

	//getters
	string getId() const;
	TypeChambre getType() const;
	string getStringType() const;
	int getPrix() const;

	//setters
	void setId(string id);
	void setType(TypeChambre type);
	void setPrix(int prix);

	//methode d'affichage
	string toString() const;
	friend ostream& operator << (ostream& os, const Chambre& chambre);

private:
	int _prix;
	TypeChambre _type;
	string _id;
};

