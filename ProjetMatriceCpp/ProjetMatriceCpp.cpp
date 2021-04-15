#include <iostream>
#include "CParser.h"

using namespace std;

int main(int argc, char *argv[])
{
	/* Fonction principale */

	CParser PARParser;
	double dFin;
	if (argc < 2)
	{
		cerr << "Vous n'avez pas entrer de nom de fichier" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree..." << endl;
		cin >> dFin;
		return 1;
	}

	// Lecture fichiers
	CMatrice<double>* pMATTableauMatrice = new CMatrice<double>[argc - 1];

	try
	{
		// Pour fichier, on créer la matrice correspondantes et l'affiche à l'écran
		for (int iBoucleInit = 1; iBoucleInit < argc; iBoucleInit++)
		{	
			PARParser.PARModifierNomFichier(argv[iBoucleInit]);
			pMATTableauMatrice[iBoucleInit - 1] = PARParser.PARLireFichier();
			cout << "Matrice du fichier " << PARParser.PARLireNomFichier() << " :" << endl;
			pMATTableauMatrice[iBoucleInit - 1].MATAfficherMatrice();
		}
	}
	catch (CException EXCLevee)
	{
		cerr << "Les matrices ne sont pas du type double" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
		return 1;
	}

	// On demande à l'utilisateur de rentré une valeur pour la suite du programme
	double dConstante;

	cout << "Veuillez entrer un nombre : ";
	cin >> dConstante;

	// L'utilisateur recommence jusqu'à entrer un choix valide ou si il quitte le programme
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "Vous n'avez pas saisi un nombre, veuillez recommencer. " << endl << "Veuillez entrer un nombre : ";
		cin >> dConstante;
	}

	cout << "Vous avez saisie " << dConstante << " pour la multiplication et la division des matrices par une constante." << endl;
	
	// Matrice contenant le résulats des différentes opérations
	CMatrice<double> MATResultats;

	// Affichage du résultat de la multiplication de chaque matrice par dConstante
	cout << endl << "MULTIPLICATION PAR " << dConstante << " DES MATRICES :" << endl;
	for (int iBoucleMultiplication = 0; iBoucleMultiplication < argc - 1; iBoucleMultiplication++)
	{
		MATResultats = pMATTableauMatrice[iBoucleMultiplication] * dConstante;
		cout << "Matrice " << iBoucleMultiplication << " :" << endl;
		MATResultats.MATAfficherMatrice();
	}

	// Affichage du résultat de la division de chaque matrice par dConstante
	cout << "DIVISION PAR " << dConstante << " DES MATRICES :" << endl;
	try 
	{
		for (int iBoucleDivision = 0; iBoucleDivision < argc - 1; iBoucleDivision++)
		{
			MATResultats = pMATTableauMatrice[iBoucleDivision] / dConstante;
			cout << "Matrice " << iBoucleDivision << " :" << endl;
			MATResultats.MATAfficherMatrice();
		}
	}
	catch (CException EXCLevee)
	{
		cerr << "Divsion par 0 impossible !" << endl << endl;
	}
	
	if (argc == 2)
	{
		cout << "Vous n'avez passé qu'un seul fichier au programme, la suite du programme n'est donc pas disponible !" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
		return 0;
	}
	
	if (argc > 2)
	{
		CMatrice<double> MATCalculs = pMATTableauMatrice[0];

		// Affichage du résultat de la somme de toutes les matrices
		try
		{
			cout << "SOMME DES MATRICES : M1+M2+..." << endl;
			for (int iBoucleAddition = 0; iBoucleAddition < argc - 1; iBoucleAddition++)
			{
				MATCalculs = MATCalculs + pMATTableauMatrice[iBoucleAddition];
			}
			MATCalculs.MATAfficherMatrice();
		}
		catch (CException EXCLevee)
		{
			cout << "Somme impossible : les dimensions des matrices sont differentes !" << endl << endl;
		}
		
		// Affichage du résultat de la somme alternée de toutes les matrices (-1)^n
		try
		{
			cout << "SOMME ALTERNEE DES MATRICES : M1-M2+..." << endl;
			MATCalculs = pMATTableauMatrice[0];
			int iBool = 1;
			for (int iBoucleSommeAlt = 1; iBoucleSommeAlt < argc - 1; iBoucleSommeAlt++, iBool++)
			{
				// si iBoucleSommeAlt est pair
				if (iBool % 2 == 0)
				{
					MATCalculs = MATCalculs + pMATTableauMatrice[iBoucleSommeAlt];
				}
				// sinon iBoucleSommeAlt est impair
				else
				{
					MATCalculs = MATCalculs - pMATTableauMatrice[iBoucleSommeAlt];
				}
			}
			MATCalculs.MATAfficherMatrice();
		}
		catch (CException EXCLevee)
		{
			cerr << "Somme alternee impossible : les dimensions des matrices sont differentes !" << endl << endl;
		}

		// Affichage du résultat des produits matricielles
		try
		{
			cout << "PRODUIT DES MATRICES : M1*M2*..." << endl;
			MATCalculs = pMATTableauMatrice[0];
			for (int iBoucleAddition = 1; iBoucleAddition < argc - 1; iBoucleAddition++)
			{
				MATCalculs = MATCalculs * pMATTableauMatrice[iBoucleAddition];
			}
			MATCalculs.MATAfficherMatrice();
		}
		catch (CException EXCLevee)
		{
			cout << "Produit matricielle impossible : les dimensions des matrices ne correspondent pas !" << endl << endl;
		}

		// Fin du programme
		cout << "Toutes les operations sont terminees !" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
	}
	return 0;
}					