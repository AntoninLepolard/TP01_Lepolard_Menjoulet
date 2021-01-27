#include "Reservation.h"
#include <stdexcept>


Reservation::Reservation(string id, Date debut, Date fin, string hotelId, string clientId, string chambreId) : _id(id), _debut(debut), _fin(fin), _hotelId(hotelId), _clientId(clientId), _chambreId(chambreId)
{
	if (debut > fin) {
		throw std::invalid_argument("La date de fin de la réservation doit être après celle du début");
	}
}

string Reservation::getId() const
{
	return this->_id;
}

string Reservation::getHotelId() const
{
	return this->_hotelId;
}

string Reservation::getChambreId() const
{
	return this->_chambreId;
}

string Reservation::getClientId() const
{
	return this->_clientId;
}

Date Reservation::getDebut() const
{
	return this->_debut;
}

Date Reservation::getFin() const
{
	return this->_fin;
}

void Reservation::setDebut(Date d)
{
	this->_debut = d;
}

void Reservation::setFin(Date d)
{
	if (d > this->getDebut()) {
		this->_fin = d;
	}
}

void Reservation::setId(string id){
	this->_id = id;
}
void Reservation::setHotelId(string hotelId){
	this->_hotelId = hotelId;
}
void Reservation::setClientId(string clientId){
	this->_clientId = clientId;
}

void Reservation::setChambreId(string chambreId){
	this->_chambreId = chambreId;
}