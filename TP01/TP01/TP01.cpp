// TP01.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include "Hotel.h"
#include "Chambre.h"
#include "Client.h"

using namespace std;

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
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
