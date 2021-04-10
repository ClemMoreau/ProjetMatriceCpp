#ifndef PAR
#define PAR 0
#include <stdio.h>
#include "CMatrice.h"
#include <iostream>
#include <cstring>

using namespace std;

class CParser
{
private:
	char* psPARNomFichier;

public:

	/*
		Contructeur par d�faut
		Initilaise Le nom du fichier � NULL
		Ne renvoie rien
	*/
	CParser();
	
	/*
		Constructeur de Recopie 
	*/
	CParser(CParser &PARParser);


	/*
		Destructeur
	*/
	~CParser();

	/*
		Lecture du nom du fichier, permet de tester si il est correcte
		Param�tre en entr�� : aucun
		Param�tre en sortie : Nom du fichier
		C'est un getter 
	*/
	char* PARLireNomFichier();

	/*
		modification du nom du fichier
		Param�tre en entr�e : sNomFichier --> Le nom du fichier
		Param�tre en sortie : Le nom du fichier modifi�
	*/
	void PARModifierNomFichier(char* sNomFichier);

	/*
		Lecture du fichier
		V�rification du typage
		V�rification Taille
		Stockage des infos essentiel dans un objet CMatrice
	*/
	template <class MType> CMatrice<MType> PARLireFichier();
};

template <class MType>
CMatrice<MType> CParser::PARLireFichier()
{
	
	cout << "laisse moi dormir zeubi";
	if (psPARNomFichier == NULL)
	{
		std::cout << "Erreur fichier inexistant !" << std::endl;
	}
	FILE* pfFichier = NULL;
	// On ouvre notre fichier en mode lecture
	pfFichier = fopen(psPARNomFichier, "r");

	//D�claration des variables
	char cType[];
	char cNbLignes[];
	char cNbColonnes[];
	char cIgnore[];
	unsigned int uiNbColonnes;
	unsigned int uiNbLignes;
	char* pcType;
	char cdelim[] = "=";
	double* dValeur;


	/*
		Sortie : Donn� r�cup�r� depuis le fichier si fichier respecte la nomenclature
		But : On r�cup�re le type et le nb de lignes et de colonnes avec fscanf
			On utilise strtok pour r�cup�rer ce qu'il y a apr�s les espaces.
	*/
	
	if (pfFichier == NULL)
	{
		std::cout << "Erreur d'ouverture du fichier en lecture" << std::endl;
	}
	else
	{
		//fscanf(notrefichier, "format donn� � r�cup�rer", lieu stockage donn�e)
		fscanf(pfFichier, "%s", cType);
		std::cout << "type :" << cType;

		fscanf(pfFichier, "%s", cNbLignes );
		std::cout << "nblignes :" << cNbLignes;

		fscanf(pfFichier, "%s", cNbColonnes);
		std::cout << "nbcol :" << cNbColonnes;

		//strtok(la chaine de caract�re que l'on va traiter, l'op�rateur d�limitant)
		/*strtok(cType,cdelim);
		pcType = strtok(cType, cdelim);

		if (pcType != "double")
		{
			std::cout << "Erreur Mauvais type" << std::endl;
			//On appelle CExeption
		}
		strtok(cType, cdelim);
		pcType = strtok(cType, cdelim);

		strtok(cNbLignes, delim);
		uiNbLignes = strtok(cNbLignes, cdelim);

		strtok(cNbColonnes, cdelim);
		uiNbColonnes = strtok(cNbColonnes, cdelim);

		CMatrice<MType>(uiNbLignes, uiNbColonnes);

		//on ignore la ligne
		fscanf(pfFichier, '%s', cIgnore);

		//boucle permettant la r�cup�ration et le stockage des valeurs de la matrice
		// strcpy(destination de la copie, source de la copie)
		for (unsigned int uiIndiceBoucleScan; uiIndiceBoucleScan <= uiNbLignes;++uiIndiceBoucleScan) 
		{
			fscanf(pfFichier, '%s', dValeur);
		}
		for (unsigned int uiIndiceBoucleCopy; uiIndiceBoucleCopy < uiNbLignes; uiIndiceBoucleCopy += uiIndiceBoucleCopy)
		{
			// � revoir comment d�finir une matrice comme destinataire 
			strcpy(CMatrice, dValeur);
		}
		
		//fermeture du fichier
		fclose(pfFichier);*/
	}

	//on veut r�cup�rer les lignes du fichier et les stocker dans une matrice CMatrice

	//fscanf(fichier, %s, )
	return NULL; 
}

#endif //PAR