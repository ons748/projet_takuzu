#pragma once
#include "grille.h"
#include <string>
#include<vector>
#include<fstream>
using namespace std;
    

class takuzu :public grille
{
public:
    takuzu();
    takuzu(int a) { taille = a; }
    bool takuzutermine(bool a);
    bool CaseExiste(int x, int y);
    bool CaseModifiable(int x, int y);
    bool verif_voisin_horizontale(int x, int y, int num_entre);
    bool verif_voisin_verticale(int x, int y, int num_entre);
    bool verif_ligne_identiquue(int num_ligne);
    bool verif_colonne_identique(int num_colonne);
    int trouvercodecolonne(int colonne);
    int trouvercodeligne(int ligne);
    bool verif_nb_zero_unsligne(int ligne);
    bool verif_nb_unscolonne(int colonne);
    long score(long temps);
    void  sauvegarder();
    void reprendre();
    bool  lignecomplete(int ligne) const;
    bool colonnecomplete(int colonne) const;
    void initializeGrille(int x);
    void modifiercase(int x, int y, int num);
    void affiche_dix_meilleursscores();
    void updatescore(long score);
    void supprimercase(int x, int y);
    virtual ~takuzu();

protected:

private:
    
    



};