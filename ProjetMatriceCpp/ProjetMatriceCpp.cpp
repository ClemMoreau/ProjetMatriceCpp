#include <iostream>
#include "CException.h"
#include "CMatrice.h"
#include "CParser.h"

int main()
{
	/* test de bibi pour le parsage jarrive pas à lancer la fonction lirre fichier */

	/*CParser();
	const char *psPARNomFichier = "ProjetMatriceCpp/Fichiers de resources/monq.txt";
	
	void PARLireFichier();
	cout << "ntm";*/
	
	//entiers
	CMatrice<float> MATMatrice(3,3);
	float k = 0;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++,k++)
		{
			MATMatrice.MATModifierElement(i, j, k);
		}
	}

	MATMatrice.MATAfficherMatrice();
	(MATMatrice / 2).MATAfficherMatrice();
	(MATMatrice * 2).MATAfficherMatrice();
	(MATMatrice + MATMatrice).MATAfficherMatrice();
	(MATMatrice - MATMatrice).MATAfficherMatrice();
	(MATMatrice * MATMatrice).MATAfficherMatrice();

	std::cout << "MATMatrice" << std::endl;
	MATMatrice.MATAfficherMatrice();
	CMatrice<float> MATMatrice2(3, 3);
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++, k++)
		{
			MATMatrice2.MATModifierElement(i, j, k);
		}
	}
	std::cout << "MATMatrice2" << std::endl;
	MATMatrice2.MATAfficherMatrice();
	CMatrice<float> MATMatrice3(3, 3);
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++, k++)
		{
			MATMatrice3.MATModifierElement(i, j, k);
		}
	}
	std::cout << "MATMatrice3" << std::endl;
	MATMatrice3.MATAfficherMatrice();

	CMatrice<float>* pMATMatriceTab = new CMatrice<float>[3];
	pMATMatriceTab[0] = MATMatrice;
	pMATMatriceTab[1] = MATMatrice2;
	pMATMatriceTab[2] = MATMatrice3;
	pMATMatriceTab[0].MATAfficherMatrice();
	pMATMatriceTab[1].MATAfficherMatrice();
	pMATMatriceTab[2].MATAfficherMatrice();
	
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