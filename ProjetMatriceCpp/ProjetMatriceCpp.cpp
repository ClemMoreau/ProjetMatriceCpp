#include <iostream>
#include "CParser.h"

using namespace std;

int main(int argc, char *argv[])
{
	CParser PARParser;
	PARParser.PARModifierNomFichier("C:/Users/cleme/Downloads/new 2.txt");
	cout << "TEST : " << PARParser.PARLireNomFichier() << endl << endl;
	PARParser.PARLireFichier();
	/* test de bibi pour le parsage jarrive pas à lancer la fonction lirre fichier */

	
	





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

	// Lecture fichier
	CMatrice<double>* pMATTableauMatrice = new CMatrice<double>[argc - 1];

	try
	{
		for (int iBoucleInit = 0; iBoucleInit < argc - 1; iBoucleInit++)
		{	
			PARParser.PARModifierNomFichier(argv[iBoucleInit]);
			//pMATTableauMatrice[iBoucleInit] = PARParser.PARLireFichier();
			//Affiché matrice?
		}
	}
	catch (CException EXCLevee)
	{
		cerr << "Les matrices ne sont pas du type double" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
		return 1;
	}

		//Demander utilisateur valeur

	double dConstante;

	cout << "Veuillez entrer un nombre : ";
	cin >> dConstante;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Vous n'avez pas saisi un nombre, veuillez recommencer. " << endl << "Veuillez entrer un nombre : ";
		cin >> dConstante;
	}

	cout << endl << "Vous avez saisie " << dConstante << " pour la multiplication et la division des matrices par une constante." << endl;
	
	CMatrice<double> MATResultats;

	// Affichage du résultat de la multiplication de chaque matrice par dConstante
	cout << "MULTIPLICATION PAR " << dConstante << " DES MATRICES :" << endl;
	for (int iBoucleMultiplication = 0; iBoucleMultiplication < argc - 1; iBoucleMultiplication++)
	{
		MATResultats = pMATTableauMatrice[iBoucleMultiplication] * dConstante;
		MATResultats.MATAfficherMatrice();
	}

	// Affichage du résultat de la division de chaque matrice par dConstante
	cout << "DIVISION PAR " << dConstante << " DES MATRICES :" << endl;
	try 
	{
		for (int iBoucleDivision = 0; iBoucleDivision < argc - 1; iBoucleDivision++)
		{
			MATResultats = pMATTableauMatrice[iBoucleDivision] / dConstante;
			MATResultats.MATAfficherMatrice();
		}
	}
	catch (CException EXCLevee)
	{
		cerr << "Divsion par 0 impossible !" << endl;
	}
	
	if (argc == 2)
	{
		cout << "Vous n'avez passé qu'un seul fichier au programme, la suite du programme n'est donc pas disponible !" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
		return 1;
	}
	
	if (argc > 2)
	{
		CMatrice<double> MATCalculs = pMATTableauMatrice[0];

		// Affichage du résultat de la somme de toutes les matrices
		try
		{
			cout << "SOMME DES MATRICES : M1+M2+..." << endl;
			for (int iBoucleAddition = 1; iBoucleAddition < argc - 1; iBoucleAddition++)
			{
				MATCalculs = MATCalculs + pMATTableauMatrice[iBoucleAddition];
			}
			MATCalculs.MATAfficherMatrice();
		}
		catch (CException EXCLevee)
		{
			cout << "Somme impossible : les dimensions des matrices sont differentes !" << endl;
		}
		
		// Affichage du résultat de la somme alternée de toutes les matrices (-1)^n
		try
		{
			cout << "SOMME ALTERNEE DES MATRICES : M1+M2+..." << endl;
			MATCalculs = pMATTableauMatrice[0];
			int iBool = 0;
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
			cerr << "Somme alternee impossible : les dimensions des matrices sont differentes !" << endl;
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
			cout << "Produit matricielle impossible : les dimensions des matrices ne correspondent pas !" << endl;
		}

		cout << "Toutes les operations sont terminees !" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
	}
	return 0;
}					