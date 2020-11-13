#pragma once
#include <string>
#include "Date.h"

using namespace std;
class Reservation
{
    private:
        Date _debut;
        Date _fin;
        string _id;
        string _hotelId;
        string _clientId;
        string _chambreId;
        float _montant;

    public:
        Reservation(Date debut, Date fin, string id, string hotelId, string clientId, string chambreId, float montant);
};

