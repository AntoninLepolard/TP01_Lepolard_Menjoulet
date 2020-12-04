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
