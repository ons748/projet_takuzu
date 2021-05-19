#include "takuzu.h"
#include "grille.h"
#include <cmath>
#include <fstream>
#include <string>
#include<iostream>
#include<vector>
#include <sstream>
#include<algorithm>
using namespace std;
takuzu::takuzu()
{}
void takuzu::supprimercase(int x, int y)
{
	if (((CaseExiste(x, y)) && (CaseModifiable(x, y))) == true)
	{
		a[x][y].setcaseValue(2);
	}
	else
	{
		cout << "case non supprimable" << endl;
	}
}
	
void takuzu::modifiercase(int x, int y, int num)
{
	if (((CaseExiste(x, y)) && (CaseModifiable(x, y))) == true)
	{
		a[x][y].setcaseValue(num);
	}
	else
	{
		cout << "case non modifiable"  <<  endl;
	}
}
void takuzu::initializeGrille(int x)
{
	if (x == 4)
	{
		initializeGrillequartquart();
		printGrille();
	}
	else if (x == 6)
	{
		initializeGrillesixsix();
		printGrille();
	}
	else if (x == 8)
	{
		initializeGrillehuithuit();
		printGrille();
	}
}
bool takuzu::CaseExiste(int x, int y)
{
	if (x >= 0 && x < taille && y >= 0 && y < taille) return true;
	else return false;
}
bool takuzu::CaseModifiable(int x, int y)
{   //int lentab = inittableau();
	for (int s = 0; s < (taille * taille) / 2; s++)
		if (a[x][y].getIdValue() == tableau[s])return true;
	return false;
}
bool takuzu::verif_voisin_verticale(int x, int y, int num_entre)  //objetdetypeegrille.a grille (taille ,a : cases [8][8])
{
	bool casepermis = true;
	if (CaseExiste(x, y - 1) && CaseExiste(x, y - 2)) if (a[x][y - 1].getcaseValue() == num_entre && a[x][y - 2].getcaseValue() == num_entre) casepermis = false;
	if (CaseExiste(x, y - 1) && CaseExiste(x, y + 1)) if (a[x][y - 1].getcaseValue() == num_entre && a[x][y + 1].getcaseValue() == num_entre) casepermis = false;
	if (CaseExiste(x, y + 1) && CaseExiste(x, y + 2)) if (a[x][y + 1].getcaseValue() == num_entre && a[x][y + 2].getcaseValue() == num_entre)  casepermis = false;
	return casepermis;

}
bool  takuzu::verif_voisin_horizontale(int x, int y, int num_entre)
{
	bool casepermis = true;
	if (CaseExiste(x - 1, y) && CaseExiste(x - 2, y)) if (a[x - 1][y].getcaseValue() == num_entre && a[x - 2][y].getcaseValue() == num_entre) casepermis = false;
	if (CaseExiste(x - 1, y) && CaseExiste(x + 1, y)) if (a[x - 1][y].getcaseValue() == num_entre && a[x + 1][y].getcaseValue() == num_entre) casepermis = false;
	if (CaseExiste(x + 1, y) && CaseExiste(x + 2, y)) if (a[x + 1][y].getcaseValue() == num_entre && a[x + 2][y].getcaseValue() == num_entre) casepermis = false;
	return casepermis;

}
bool takuzu::verif_ligne_identiquue(int num_ligne)
{
	for (int i = 0; i <= taille; ++i)
	{
		if (lignecomplete(i))
			if (trouvercodeligne(num_ligne) == trouvercodeligne(i) && (i != num_ligne)) return true;
	}
	return false;
}

bool takuzu::verif_colonne_identique(int num_colonne)
{
	bool Unique = true;
	for (int i = 0; i <= taille; ++i)
	{
		if (colonnecomplete(i))
		{
			if (trouvercodecolonne(num_colonne) == trouvercodecolonne(i) && (i != num_colonne))  return Unique = true;
		}
	}
	return false;
}

int takuzu::trouvercodecolonne(int colonne)
{
	int somme = 0;
	for (int i = 0; i < taille; i++) {
		somme += a[i][colonne].getcaseValue() * pow(2, i);
	}
	return somme;
}
int takuzu::trouvercodeligne(int ligne)
{
	int somme = 0;
	for (int i = 0; i < taille; i++) {
		somme += a[ligne][i].getcaseValue() * pow(2, i);
	}
	return somme;
}
bool takuzu::verif_nb_zero_unsligne(int ligne)
{
	int nb_zeros = 0, nb_uns = 0;
	for (int i = 0; i < taille; i++)
	{
		if (a[ligne][i].getcaseValue() == 1) nb_uns += 1;
		else if (a[ligne][i].getcaseValue() == 0) nb_zeros += 1;
	}
	if (nb_uns != nb_zeros)
		return true;
	else return false;
}
bool takuzu::verif_nb_unscolonne(int colonne)
{
	int nb_zeros = 0, nb_uns = 0;
	for (int i = 0; i < taille; i++)
	{
		if (a[i][colonne].getcaseValue() == 1)  nb_uns += 1;
		else if (a[i][colonne].getcaseValue() == 0) nb_zeros += 1;
	}
	if (nb_uns != nb_zeros)
		return true;
	else return false;
}

void takuzu::sauvegarder()
{
	ofstream file;
	ofstream id;
	file.open("sauvegarde.txt");
	id.open("id.txt");
	id << taille << endl;
	for (int i = 0; i < taille; i++)
		for (int j = 0; j < taille; j++)
			file << a[i][j].getcaseValue();
	file << endl;

	for (int i = 0; i < (taille * taille) / 2 ; i++)
		id << tableau[i] << endl;
	id.close();
	file.close();
}

void takuzu::reprendre()
{
	ifstream id;
	string test;
	id.open("id.txt");
	getline(id, test);
	taille = int(test[0] - 48);
	string ligne2;
	int value;
	for (int i = 1; i < ((taille * taille) / 2 + 1); i++)
	{
	getline(id, ligne2);
    tableau[i - 1] = stoi(ligne2);
	}

	id.close();
	ifstream file;
	file.open("sauvegarde.txt");
	int  k = 0;
	string ligne;
	getline(file, ligne);
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			a[i][j].setIdValue(k + 1);
			a[i][j].setcaseValue(int(ligne[k] - 48));
			k++;
		}
	}

	file.close();
}

bool takuzu::lignecomplete(int ligne) const
{
	int casevide = 0;

	for (int j = 0; j < taille; ++j)
	{
		if (a[ligne][j].getcaseValue() == 2)
			casevide++;
	}

	return casevide == 0;
}
bool takuzu::colonnecomplete(int colonne) const
{
	int casevide = 0;
	for (int j = 0; j < taille; j++)
	{
		if (a[j][colonne].getcaseValue() == 2)
			casevide++;
	}
	return casevide == 0;
}
bool takuzu::takuzutermine(bool ab) {
	int nb = 0;
	for (int i = 0; i < taille; i++)
		for (int j = 0; j < taille; j++) {
			if (a[i][j].getcaseValue() == 2)
				nb++;
		}
	if ((nb == 0) && (ab == true)) return true; else return false;
}
long  takuzu::score(long temps)
{
	int score;
	if (taille == 4) {
		if (temps <= 60) {
			score = 600;
		}
		else if (temps > 60 && temps <= 600) { score = 600 - temps; }
		else { score = 0; }
	}
	else if (taille == 6) {
		if (temps <= 1200) { score = 2400; }
		else if (temps > 1200 && temps <= 2400) { score = 2400 - temps; }
		else {
			score = 0;
		}
	}
	else {
		if (temps <= 2400) { score = 3600; }
		else if (temps > 2400 && temps <= 3600) { score = 3600 - temps; }
		else { score = 0; }
	}return(score);
}
void takuzu::updatescore(long score)
{
	ifstream in;
	ofstream out;
	in.open("score.txt");
	string ligne;
	vector<long> vect;
	vector<long> ::iterator pos;
	std::string::size_type sz;
	for (int i = 0; i < 10; i++)
	{
		getline(in, ligne);
		long li = std::stol(ligne, &sz);
		vect.push_back(li);
	}
	if (score > *(vect.end()-1))
	{
		vect.pop_back();
		vect.push_back(score);
		sort( vect.begin(),vect.end());
		reverse(vect.begin(), vect.end());
		out.open("score.txt");
		for (pos = vect.begin(); pos != vect.end(); pos++)
		  {
			std::string chaine = std::to_string(*pos);
			out << chaine;
			out << endl;
		  }
		
	}
}
void takuzu::affiche_dix_meilleursscores()
{
	ifstream in;
	in.open("score.txt");
	string ligne;
	for (int i = 0; i < 10; i++)
	{
		getline(in, ligne);
		cout << ligne << endl;
		
	}

}

takuzu::~takuzu()
{
}


