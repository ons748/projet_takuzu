// projet2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

// projet2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include<chrono>
#include"takuzu.h"
#include <cstdlib>
#include <time.h>
#include<windows.h>
#define RAND_MAX srand

using namespace std;

int main()
{
    srand(time(NULL));
    takuzu jeu;
    int rep = 1, choix, z, x;


    cout << "************menu**********" << endl;
    cout << "1:nouvelle partie" << endl;
    cout << "2:reprendre la  partie" << endl;
    cin >> x;
    if (x == 1)
    {
        cout << "donnez la taille(4 ou 6 ou 8)" << endl;
        cin >> z;
        jeu.setTaille(z);
        jeu.initializeGrille(z);
    }
    else { jeu.reprendre(); jeu.printGrille(); }
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
    bool data = false, k = true;
    while (data == 0)
    {
        cout << "1:modifier une case" << endl; 
        cout << "2:supprimer une case" << endl;
        cout << "3:enregister la partie" << endl;
        cout << "4:quitter" << endl;
        cout << "5:affiche 10 meilleurs  score" << endl;

        do
        {
            cout << "Enter Votre Choix";
            cin >> choix;
        } while (choix < 0 || choix>5);

        switch (choix)
        {
        case 1:
        { k = true;
        int x, y, num;
        cout << "entrez num ligne " << endl;
        cin >> x;
        cout << "entrez num de colonne " << endl;
        cin >> y;
        cout << "entrez contenu de case soit 0 ou 1" << endl;
        cin >> num;

        if ((num == 0) || (num == 1))
        {
            jeu.modifiercase(x, y, num);
            if ((!jeu.verif_voisin_horizontale(x, y, num)) || (!jeu.verif_voisin_verticale(x, y, num)))
            {
                cout << "plus que 2 voisins identiques "<<endl; k = false;
            }
            for (int i = 0; i < jeu.getTaille(); i++)
            {
                if (jeu.lignecomplete(i))
                {
                    if (jeu.verif_ligne_identiquue(i))
                    {
                        cout << "existe ligne identique" << endl; k = false;
                    }
                    if (jeu.verif_nb_zero_unsligne(i))
                    {
                        cout << "erreur dans la ligne "<<i<< "nb0#nb1" << endl; k = false;
                    }
                }
            }
            for (int i = 0; i < jeu.getTaille(); i++)
            {
                if (jeu.colonnecomplete(i))
                {
                    if (jeu.verif_colonne_identique(i))
                    {
                        cout << "existe colonne identique" << endl;
                        k = false;
                    }

                    if (jeu.verif_nb_unscolonne(i))
                    {
                        cout << "erreur dans la colonne "<<i<<" nb0#nb1"  << endl;
                        k = false;
                    }
                }
            }
        }
        jeu.printGrille();
        break;
        }
        case 2:
        {   int x, y;
            cout << "entrez num ligne " << endl;
            cin >> x;
            cout << "entrez num de colonne " << endl;
            cin >> y;
            jeu.supprimercase(x, y);
            jeu.printGrille();
            break;
        }
       
        case 3:
        {
            cout << "Voulez Vous enregistrer cette partie" << endl;
            cout << "1:oui" << endl;
            cout << "0:non" << endl;
            cin >> rep;
            if (rep == 1) jeu.sauvegarder();
            else break;
            break;
        }
        case 5:
        {
            jeu.affiche_dix_meilleursscores();
        }
         case 4:
         {
             break;
         }

        }
       // system("cls");
        
         data = jeu.takuzutermine(k); 
         if ((data == 1) || (choix == 4)||(choix==3)) data = true;
      //  cout << "my data is " << data << endl;
    }
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    long score = jeu.score(elapsed_seconds);
    if (jeu.takuzutermine(k)) {
        cout << "vous avez gagne et votre score est : " << score << "merci";
        jeu.updatescore(score);
        Sleep(2000);
    }

}



        
    
    
