#include <iostream>
#include "CParser.h"

using namespace std;

int main(int argc, char *argv[])
{
	/* Fonction principale */
	char a[] = "C:/Users/cleme/Downloads/TestExe/test2.txt";
	char b[] = "C:/Users/cleme/Downloads/TestExe/testPasAssezDeLigne.txt";
	char c[] = "C:/Users/cleme/Downloads/TestExe/testgrandeligne.txt";
	argv[1] = a;
	argv[2] = b;
	argv[3] = a;
	argv[4] = c;
	argv[5] = a;
	argc = 6;

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

	
	int iNbErreur = 0;
	// Pour fichier, on créer la matrice correspondantes et l'affiche à l'écran
	for (int iBoucleInit = 1; iBoucleInit < argc; iBoucleInit++)
	{
		PARParser.PARModifierNomFichier(argv[iBoucleInit]);
		try
		{
			pMATTableauMatrice[iBoucleInit - 1 - iNbErreur] = PARParser.PARLireFichier();
			cout << "Matrice du fichier " << PARParser.PARLireNomFichier() << " :" << endl;
			pMATTableauMatrice[iBoucleInit - 1 - iNbErreur].MATAfficherMatrice();
		}
		catch (CException EXCObjet)
		{
			cerr << "L'exception " << EXCObjet.EXClire_valeur() << " a ete levee pour la matrice " << iBoucleInit << endl << endl;
			iNbErreur++;
		}
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
	for (int iBoucleMultiplication = 0; iBoucleMultiplication < argc - 1 - iNbErreur; iBoucleMultiplication++)
	{
		MATResultats = pMATTableauMatrice[iBoucleMultiplication] * dConstante;
		cout << "Matrice" << iBoucleMultiplication << " * " << dConstante << " :" << endl;
		MATResultats.MATAfficherMatrice();
	}

	// Affichage du résultat de la division de chaque matrice par dConstante
	cout << "DIVISION PAR " << dConstante << " DES MATRICES :" << endl;
	try 
	{
		for (int iBoucleDivision = 0; iBoucleDivision < argc - 1 - iNbErreur; iBoucleDivision++)
		{
			MATResultats = pMATTableauMatrice[iBoucleDivision] / dConstante;
			cout << "Matrice" << iBoucleDivision << " / " << dConstante << " :" << endl;
			MATResultats.MATAfficherMatrice();
		}
	}
	catch (CException EXCLevee)
	{
		cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee." << endl << endl;
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
		
		cout << "SOMME DES MATRICES :  M1 + M2 + ..." << endl;
		for (int iBoucleAddition = 1; iBoucleAddition < argc - 1 - iNbErreur; iBoucleAddition++)
		{
			try
			{
				MATCalculs = MATCalculs + pMATTableauMatrice[iBoucleAddition];
			}
			catch (CException EXCLevee)
			{
				cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee." << endl;
				cerr << "La matrice " << iBoucleAddition << " n'est pas pris en compte dans le calcul de la somme " << endl << endl;
			}
		}
		MATCalculs.MATAfficherMatrice();
		
		
		// Affichage du résultat de la somme alternée de toutes les matrices (-1)^n
		
		MATCalculs = pMATTableauMatrice[0];
		cout << "SOMME ALTERNEE DES MATRICES : M1-M2+..." << endl;
		MATCalculs = pMATTableauMatrice[0];
		int iBool = 1;
		for (int iBoucleSommeAlt = 1; iBoucleSommeAlt < argc - 1 - iNbErreur; iBoucleSommeAlt++, iBool++)
		{
			// si iBoucleSommeAlt est pair
			if (iBool % 2 == 0)
			{
				try
				{
					MATCalculs = MATCalculs + pMATTableauMatrice[iBoucleSommeAlt];
				}
				catch (CException EXCLevee)
				{
					cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee." << endl;
					cout << "La matrice " << iBoucleSommeAlt << " n'est pas pris en compte dans le calcul de la somme alternee" << endl << endl;
					iBool--;
				}
			}
			// sinon iBoucleSommeAlt est impair
			else
			{
				try
				{
					MATCalculs = MATCalculs - pMATTableauMatrice[iBoucleSommeAlt];
				}
				catch (CException EXCLevee)
				{
					cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee." << endl;
					cout << "La matrice " << iBoucleSommeAlt << " n'est pas pris en compte dans le calcul de la somme alternée" << endl << endl;
					iBool--;
				}
			}
		}
		MATCalculs.MATAfficherMatrice();
		

		// Affichage du résultat des produits matricielles
		cout << "PRODUIT DES MATRICES : M1*M2*..." << endl;
		MATCalculs = pMATTableauMatrice[0];
		for (int iBoucleAddition = 1; iBoucleAddition < argc - 1 - iNbErreur; iBoucleAddition++)
		{
			try
			{
			MATCalculs = MATCalculs * pMATTableauMatrice[iBoucleAddition];
			}
			catch (CException EXCLevee)
			{
				cerr << "L'exception " << EXCLevee.EXClire_valeur() << " a ete levee." << endl;
				cout << "La matrice " << iBoucleAddition << " n'est pas pris en compte dans le calcul du produit matricielle" << endl << endl;
			}
		}
		MATCalculs.MATAfficherMatrice();
		

		// Fin du programme
		cout << "Toutes les operations sont terminees !" << endl;
		cout << "Veuillez entrer quelque chose puis appuyer sur entree pour quitter..." << endl;
		cin >> dFin;
	}
	return 0;
}					