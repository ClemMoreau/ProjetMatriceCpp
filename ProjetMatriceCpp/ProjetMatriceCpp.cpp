#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<double> MATMatriceId(3,3);
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			MATMatriceId.MATModifierElement(i, j, 0);
		}
	}
	MATMatriceId.MATModifierElement(1, 1, 1);
	MATMatriceId.MATModifierElement(2, 2, 1);
	MATMatriceId.MATModifierElement(3, 3, 1);
	std::cout << "Matrice Id :" << std::endl;
	MATMatriceId.MATAfficherMatrice();

	CMatrice<double> Mati(3, 3);
	double k = 0.0;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			Mati.MATModifierElement(i, j, k);
			k++;
		}
	}

	std::cout << "Mati :" << std::endl;
	Mati.MATAfficherMatrice();
	CMatrice<double> MATMatrice;
	MATMatrice = Mati / 2;
	std::cout << "Division constante :" << std::endl;
	MATMatrice.MATAfficherMatrice();
	CMatrice<double> MATMatrice2;
	MATMatrice2 = Mati * 2;
	std::cout << "Multiplication constante :" << std::endl;
	MATMatrice2.MATAfficherMatrice();

	CMatrice<double> MATMatriceCopie(Mati);

	CMatrice<double> MATMatrice3;
	MATMatrice3 = Mati + MATMatriceCopie;
	std::cout << "Addition :" << std::endl;
	MATMatrice3.MATAfficherMatrice();
	CMatrice<double> MATMatrice4;
	MATMatrice4 = Mati - MATMatriceCopie;
	std::cout << "Différence :" << std::endl;
	MATMatrice4.MATAfficherMatrice();
	CMatrice<double> MATMatrice5;
	std::cout << "Produit matricielle :" << std::endl;
	MATMatrice5 = Mati * MATMatriceCopie;
	MATMatrice5.MATAfficherMatrice();

}
/* mettre des return 1 à chaque erreur, puis tester avec des boucles whiles et mettres des messages pour guider utilisateur (ce qu'il se passe/ ce qu'il doit faire)
using namespace std;
	//Lecture fichier
	CMatrice<double>* pMATTableauMatrice = new CMatrice<double>[argc - 1];

	//Demander utilisateur valeur

		double dConstante;
		cout << "Veuillez entrer une valeur ";
		cin >> dConstante;
		while(cin.fail())
		{

		///initialiser la matrice de résultats par consteur de base (si galère pas faire de stockage)
	// Affichage du résultat de la multiplication de chaque matrice par dConstante

		///Boucle pour i allant de 0 à argc - 1
			///resultat = tabMat[i] * dConstante;
			///resultat.afficher

	// Affichage du résultat de la division de chaque matrice par dConstante
		///try catch si la constante est nulle (contenant la ligne de calcul)
			///Boucle pour i allant de 0 à argc - 1
				///resultat = tabMat[i] / dConstante;
				///resultat.afficher

		/// si argc == 2 alors message car suite programme impossible puis return

	// Affichage du résultat de la somme de toutes les matrices
		///try catch si les dimensions ne sont pas identiques (contenant la ligne de calcul)
			///Boucle pour i allant de 0 à argc - 1
				///resultat += tabMat[i];
				///resultat.afficher

	// Affichage du résultat de la somme alternée de toutes les matrices (-1)^n
		///try catch si les dimensions ne sont pas identiques (contenant la ligne de calcul)
			///Boucle pour i allant de 0 à argc - 1
				/// si i est pair
					///resultat += tabMat[i];
					///resultat.afficher
				/// si i est impair
					///resultat -= tabMat[i];
					///resultat.afficher

	// Affichage du résultat des produits matricielles (demandez si faut faire toutes les combinaisons possibles ou un seul gros produit mat)
		///try catch si les produits ne sont pas possible (contenant la ligne de calcul)
			///( si combinaison)
				///Boucle pour i allant de 0 à argc - 1
					///Boucle pour j allant de 0 à argc - 1
						///resultat = tabMat[i] * tabMat[j];
						///resultat.afficher
			///( si produit totale)
				///Boucle pour i allant de 0 à argc - 1
					///resultat *= tabMat[i];
					///resultat.afficher
		

//

*/