#include "Reservation.h"
#include <stdexcept>

Reservation::Reservation(Date debut, Date fin, string id, string hotelId, string clientId, string chambreId, float montant) {
    if(debut > fin){
        throw std::invalid_argument("La date de fin de la réservation doit être après celle du début");
    }
    _debut = debut;
    _fin = fin;
    _id = id;
    _hotelId = hotelId;
    _chambreId = chambreId;
    _clientId = clientId;
    _montant = montant;
}
