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

    public:
		/*constructeur*/
        Reservation(string id, Date debut, Date fin,  string hotelId, string clientId, string chambreId);

		//getters
		string getId() const;
        string getClientId() const;
        string getHotelId() const;
        string getChambreId() const;
		Date getDebut() const;
		Date getFin() const;

		//setters
		void setDebut(Date d);
		void setFin(Date d);
        void setId(string id);
        void setHotelId(string hotelId);
        void setClientId(string clientId);
        void setChambreId(string chambreId);
		

};

