#include <iostream>
#include <vector>
#include "Hotel.h"
#include "Chambre.h"
#include "Client.h"
#include "Date.h"
#include "Reservation.h"

using namespace std;

//définition après le main
int duree(Date debut, Date fin);
Chambre verifierDispo(Date debut, Date fin, Hotel hotel, vector<Reservation> reservations);
Client gestionHomonymes(string nom, vector<Client> clients);
void afficherReservations(vector<Reservation> reservations);
void afficherReservation(string ID, vector<Reservation> reservations);
void afficherReservationsClient(string ID, vector<Reservation> reservations);
void afficherReservationsClient(string nom, vector<Reservation> reservations, vector<Client> clients);
void modifierReservation(Reservation &reservation, Hotel hotel, vector<Reservation> reservations, vector<Client> clients);
void annulerReservation(vector<Reservation> &reservations);

int main()
{
    //vector collectionant toutes les réservations.
    vector<Reservation> reservations{
        Reservation("1111", *new Date(1928,4,22), *new Date(1928,4,25), "ARD11", "CL1", "0"),

        // en décommentant les deux lignes ci dessous, on bloque toutes les chambres simples du 22/4/1928 au 25/4/1928 
        //Reservation("1111", *new Date(1928,4,22), *new Date(1928,4,25), "ARD11", "CL2", "1"),
        //Reservation("1111", *new Date(1928,4,22), *new Date(1928,4,25), "ARD11", "CL3", "2")
    };

    // DEBUT QUESTIONS 6.a à 6.b
	//création de l'hotel
    Hotel adriano("ADR11","Adriano","Bari");
	
    //ajout des chambres de différents types dans l'hotel
	TypeChambre type;
	for (int i = 0; i < 10; i++)
	{
		if (i < 3)
		{
			type = Single;
			adriano.addChambre(Chambre(to_string(i), type, 100));
		}
		else if (i < 8)
		{
			type = Double;
			adriano.addChambre(Chambre(to_string(i), type, 125));
		}
		else if (i < 10)
		{
			type = Suite;
			adriano.addChambre(Chambre(to_string(i), type, 210));
		}
	}
	cout << endl << "**** DEBUT AFFICHAGE INFOS HOTEL****" << endl << endl;
    cout << adriano;
	cout << endl << "**** FIN AFFICHAGE INFOS HOTEL****" << endl << endl;
    //FIN QUESTIONS 6.a à 6.b

    //DEBUT QUESTIONS 6.c à 6.d
    vector<Client> adrianoClients{
        Client("CL1","Pagot","Marco",150),
        Client("CL2","Piccolo","Fio",0),
        Client("CL3","Curtis","Donald",3),
        Client("CL4","Piccolo","Paolo",0)
    };

    cout << endl << "**** DEBUT AFFICHAGE DES CLIENTS ****" << endl << endl;
    for(const auto& client: adrianoClients){
        cout << client;
    }
	cout << endl << "**** FIN AFFICHAGE DES CLIENTS ****" << endl << endl;
    //FIN QUESTIONS 6.c à 6.d

    //DEBUT QUESTION 7
	//saisie des dates de reservation et verification de celle-ci + affichage duree de sejour
    bool dateValid= false;
    Date debut, fin;
    int d,m,y;
    string temp;
    while(!dateValid){
        cout << "Entrez le jour du debut de la reservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois du debut de la reservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année du debut de la reservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(debut.checkDate(y,m,d)){
            dateValid = true;
            debut = Date(y,m,d);
        }

        cout << "Entrez le jour de la fin de la reservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois de la fin de la reservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année de la fin de la reservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(fin.checkDate(y,m,d)){
            fin = Date(y,m,d);
            if(fin < debut) dateValid = false;
        }
        else dateValid = false;

        if(!dateValid) cout << "Au moins l'une des deux dates n'est pas valide, recommencez." << endl;
    }

    cout << "Le nombre de nuits est: " << duree(debut,fin) << endl;
   
    //FIN QUESTION 7

	//DEBUT QUESTION 8
    
    Chambre chambreReservee = verifierDispo(debut, fin, adriano, reservations);

    //FIN QUESTION 8
	
	//DEBUT QUESTION 9

    cout << "Entrez le nom de famille du client qui effectuera la réservation." << endl;
    cin >> temp;

    Client clientFinal = gestionHomonymes(temp, adrianoClients);
    // FIN QUESTION 9
    
    //DEBUT QUESTION 10
    cout << endl << "le prix total du séjour sera de " << duree(debut, fin)*chambreReservee.getPrix() << " Lires."<<endl;
    reservations.push_back(*new Reservation("1112", debut, fin, "ADR11", clientFinal.getId(), chambreReservee.getId()));
    //FIN QUESTION 10

    //DEBUT QUESTION 11
    afficherReservations(reservations);

    cout << "Entrez un ID de réservation à consulter : ";
    cin >> temp;
    afficherReservation(temp, reservations);

    cout << "Entrez le nom du client à consulter : ";
    cin >> temp;
    afficherReservationsClient(temp,reservations,adrianoClients);

    cout << "Demonstration de modification d'une réservation :" << endl;
    modifierReservation(reservations[0],adriano, reservations, adrianoClients); 
    afficherReservations(reservations);

    cout << "Demonstration de l'annulation d'une réservation :" << endl;
    annulerReservation(reservations);
    afficherReservations(reservations);
    //FIN QUESTION 11

    return 0;
}

//nécéssaire à la question 7
int duree(Date debut, Date fin){
    //gere les années bissextiles et les 28 fevriers
    int y=debut.year(), m=debut.month(), d=debut.day();
    int nbJoursDebut, nbJoursFin;
    if(m < 3) y--, m += 12;
    nbJoursDebut = 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306; 

    y=fin.year(), m=fin.month(), d=fin.day();
    if(m < 3) y--, m += 12;
    nbJoursFin = 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;

    return nbJoursFin - nbJoursDebut;
}

Chambre verifierDispo(Date debut, Date fin, Hotel hotel, vector<Reservation> reservations){
    string temp;
    TypeChambre type8;
    bool reservationValide = true;
    Chambre chambreReservable;

    do{
        bool typeValide = true;
        do{
            typeValide = true;
            cout << "Sélectionnez le type de chambre : 0 pour seule, 1 pour double ou 2 pour suite" << endl;
            cin >> temp;
            switch (stoi(temp))
            {
            case 0:
                type8 = Single;
                break;
            
            case 1:
                type8 = Double;
                break;

            case 2:
                type8 = Suite;
                break;

            default:
                typeValide = false;
                break;
            }
        }while(!typeValide);
        
        /* 
        La logique est :
            - On parcourt toutes les chambres du type sélectionné,
            - La réservation pour la chambre est bonne jusqu'à ce qu'on trouve une réservation qui la bloque
            - si une chambre n'a pas de réservation bloquée, on sort de la boucle de parcours des chambres, car on a trouvé une chambre dispo, pas besoin de chercher plus.
        */

        for(const auto& chambre: hotel.getChambres()){
            if(chambre.getType() == type8){
                reservationValide = true;
                for(const auto& reservation: reservations){
                    if(chambre.getId() == reservation.getChambreId()){
                        //vérification des croisements de dates pour les réservations de la chambre
                        if((debut <= reservation.getDebut() && reservation.getDebut() <= fin)||(debut <= reservation.getFin() && reservation.getFin() <= fin)){
                            reservationValide = false;
                        }
                    }
                }
                if(reservationValide == true){
                    chambreReservable = chambre;
                    break;
                }
            }
        }

        if(reservationValide == false){
            cout << "Désolé mais il n'y a pas chambres disponibles à ces dates, veuillez reeffectuer la procédure de réservation." << endl << endl;
        }
    }while(!reservationValide);

    cout << endl << "Voici la chambre qui sera réservée :" << endl << chambreReservable << endl;
    return chambreReservable;
}

Client gestionHomonymes(string nom, vector<Client> clients){
    string temp;
    vector<Client> matchingClients{};
    for(const auto& client: clients){
        if(client.getNom() == nom) matchingClients.push_back(client);
    }

    bool clientSelectionne = false;
    while(!clientSelectionne){
        cout << endl <<"Voici la liste des clients aux noms correspondants: " << endl << endl;

        for(const auto& client: matchingClients){
            cout << client.getId() << " : " << client.getPrenom() << " " << client.getNom() << endl;
        }
        cout << endl <<"Entrez l'ID de celui qui correspond : ";

        cin >> temp;
        for(const auto& client: matchingClients){
            if(client.getId() == temp) {
                cout << endl << "Le client Sélectionné est : " << endl << endl << client << endl;
                return client;
            }
        }

        cout << endl <<"L'ID entré ne correspond a aucun des IDs en mémoire, veuillez reessayer."<< endl;
    }
}

void afficherReservations(vector<Reservation> reservations){

    cout << endl << "Affichage de la liste des reservations:" << endl;
    for(const auto& reservation: reservations){
        cout << endl << "_____________________" << endl;
        cout << "ID: " << reservation.getId() << endl;
        cout << "ID du client : " << reservation.getClientId() << endl;
        cout << "ID de l'hôtel : " << reservation.getHotelId() << endl;
        cout << "ID de la chambre : " << reservation.getChambreId() << endl;
        cout << "Date de début du séjour: " << reservation.getDebut().toString() << endl;
        cout << "Date de fin du séjour: " << reservation.getFin().toString() << endl;
    }
    cout << endl << "_____________________" << endl;
}

void afficherReservation(string ID, vector<Reservation> reservations){
    for(const auto& reservation: reservations){
        if(reservation.getId() == ID){

            cout << "Affichage de la réservation:"; 
            cout << endl << "_____________________" << endl;
            cout << "ID: " << reservation.getId() << endl;
            cout << "ID du client : " << reservation.getClientId() << endl;
            cout << "ID de l'hôtel : " << reservation.getHotelId() << endl;
            cout << "ID de la chambre : " << reservation.getChambreId() << endl;
            cout << "Date de début du séjour: " << reservation.getDebut().toString() << endl;
            cout << "Date de fin du séjour: " << reservation.getFin().toString() << endl;
            cout << endl << "_____________________" << endl;
        }
    }
}

void afficherReservationsClient(string ID, vector<Reservation> reservations){
    for(const auto& reservation: reservations){
        if(reservation.getClientId() == ID){
            cout << "Affichage de la réservation:"; 
            cout << endl << "_____________________" << endl;
            cout << "ID: " << reservation.getId() << endl;
            cout << "ID du client : " << reservation.getClientId() << endl;
            cout << "ID de l'hôtel : " << reservation.getHotelId() << endl;
            cout << "ID de la chambre : " << reservation.getChambreId() << endl;
            cout << "Date de début du séjour: " << reservation.getDebut().toString() << endl;
            cout << "Date de fin du séjour: " << reservation.getFin().toString() << endl;
            cout << endl << "_____________________" << endl;     
        }
    }
}

void afficherReservationsClient(string nom, vector<Reservation> reservations, vector<Client> clients){
    string ID;
    ID = gestionHomonymes(nom, clients).getId();
    afficherReservationsClient(ID, reservations);
}

void modifierReservation(Reservation &reservation, Hotel hotel, vector<Reservation> reservations, vector<Client> clients){
    bool dateValid= false;
    Date debut, fin;
    int d,m,y;
    string temp;
    while(!dateValid){
        cout << "Entrez le jour du debut de la reservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois du debut de la reservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année du debut de la reservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(debut.checkDate(y,m,d)){
            dateValid = true;
            debut = Date(y,m,d);
        }

        cout << "Entrez le jour de la fin de la reservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois de la fin de la reservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année de la fin de la reservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(fin.checkDate(y,m,d)){
            fin = Date(y,m,d);
            if(fin < debut) dateValid = false;
        }
        else dateValid = false;

        if(!dateValid) cout << "Au moins l'une des deux dates n'est pas valide, recommencez." << endl;
    }

    cout << "Le nombre de nuits est: " << duree(debut,fin) << endl;
    
    Chambre chambreReservee = verifierDispo(debut, fin, hotel, reservations);

    cout << "Entrez le nom de famille du client qui effectuera la réservation." << endl;
    cin >> temp;

    Client clientFinal = gestionHomonymes(temp, clients);

    cout << endl << "le prix total du séjour sera de " << duree(debut, fin)*chambreReservee.getPrix() << " Lires."<<endl;
    reservation = *new Reservation("1112", debut, fin, "ADR11", clientFinal.getId(), chambreReservee.getId());
}


void annulerReservation(vector<Reservation> &reservations){
    string temp;
    afficherReservations(reservations);
    cout << "Entrez l'ID de la réservation à supprimer: ";
    cin >> temp;

    for (size_t i = 0; i < reservations.size(); i++)
    {
        if(reservations[i].getId() == temp){
            reservations.erase(reservations.begin()+i);
            cout << "Suppression de la reservation reussie !" << endl;
        }
    }
    

}