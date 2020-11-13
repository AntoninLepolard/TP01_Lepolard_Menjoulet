#include <iostream>
#include <vector>
#include "Hotel.h"
#include "Chambre.h"
#include "Client.h"
#include "Date.h"

using namespace std;

//définition après le main
int duree(Date debut, Date fin);


int main()
{
    // DEBUT QUESTIONS 6.a à 6.b
    vector<Chambre> adrianoChambres;

    for (int i = 0; i < 10; i++)
    {
        TypeChambre type;
        type = Single;
        if (i < 3)
        {
            type = Single;
            adrianoChambres.push_back(Chambre(to_string(i), type, 100));
        }
        else if (i < 8)
        {
            type = Double;
            adrianoChambres.push_back(Chambre(to_string(i), type, 125));
        }
        else if (i < 10)
        {
            type = Suite;
            adrianoChambres.push_back(Chambre(to_string(i), type, 210));
        }
        
    }

    Hotel adriano("ADR11","Adriano","Bari", adrianoChambres);
    cout << endl << "AFFICHAGE DES INFORMATIONS DE L'HOTEL" << endl << endl;
    cout << adriano;
    //FIN QUESTIONS 6.a à 6.b

    //DEBUT QUESTIONS 6.c à 6.d
    vector<Client> adrianoClients{
        Client("CL1","Pagot","Marco",150),
        Client("CL2","Piccolo","Fio",0),
        Client("CL3","Curtis","Donald",3),
        Client("CL4","Paolo","Piccolo",0)
    };

    cout << endl << "AFFICHAGE DES CLIENTS" << endl << endl;
    for(const auto& client: adrianoClients){
        cout << client;
    }
    //FIN QUESTIONS 6.c à 6.d

    //DEBUT QUESTION 7
    bool dateValid= false;
    Date debut, fin;
    int d,m,y;
    string temp;
    while(!dateValid){
        cout << "Entrez le jour du début de la réservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois du début de la réservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année du début de la réservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(debut.checkDate(y,m,d)){
            dateValid = true;
            debut = Date(y,m,d);
        }

        cout << "Entrez le jour de la fin de la réservation" << endl;
        cin >> temp;
        d = stoi(temp);
        cout << "Entrez le mois de la fin de la réservation" << endl;
        cin >> temp;
        m = stoi(temp);
        cout << "Entrez l'année de la fin de la réservation" << endl;
        cin >> temp;
        y = stoi(temp);
        
        if(fin.checkDate(y,m,d)){
            fin = Date(y,m,d);
        }
        else dateValid = false;

        if(!dateValid) cout << "Au moins l'une des deux dates n'est pas valide, recommencez." << endl;
    }

    cout << "Le nombre de nuits est: " << duree(debut,fin) << endl;
   
    //FIN QUESTION 7
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

    return nbJoursFin - nbJoursDebut - 1;
}
