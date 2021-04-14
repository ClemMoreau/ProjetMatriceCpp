#include "CParser.h"
#include <string>
#include "CException.h"

#define nom_null 201
#define mauvais_type 202

CParser::CParser()
{
	PARModifierNomFichier(NULL);
}

CParser::CParser(CParser &PARParser)
{
	PARModifierNomFichier(PARParser.PARLireNomFichier());
}


CParser::~CParser()
{
	free(psPARNomFichier);
}


char* CParser::PARLireNomFichier()
{
	if (psPARNomFichier == NULL)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(nom_null);
		throw(EXCObjet);

	}
	return psPARNomFichier;
}


void CParser::PARModifierNomFichier(const char* sNomFichier)
{
	if (sNomFichier)
	{
		if (psPARNomFichier)
		{
			free(psPARNomFichier);
		}

		int iConteur = strlen(sNomFichier);
		psPARNomFichier = (char*)malloc(iConteur + 1);
		int iBoucleCopie;
		for (iBoucleCopie = 0; iBoucleCopie < iConteur; iBoucleCopie++)
		{
			psPARNomFichier[iBoucleCopie] = sNomFichier[iBoucleCopie];
		}
		psPARNomFichier[iBoucleCopie] = '\0';
	}
	else 
	{
		psPARNomFichier = NULL;
	}
}

CMatrice<double>& CParser::PARLireFichier()
{
	/* Ouverture du fichier */
	ifstream fFichier(PARLireNomFichier());
	if (!fFichier)
	{
		/* On teste si l'ouverture c'est bien déroulé */
	}
	
	/* 
		cdelim est notre séparateur
		Utilisé pour la fonction strtok() 	   
	*/
	char cdelim[] = "=";

	/*
		on initialise des tableaux de caractère pour y stocker les lignes de notre fichier
	*/
	char cType[100], cNbLignes[100], cNbColonnes[100], cIgnore[200], cMatElement[200];

	/*
		pointeur sur des chaine de caracyère qui vont contenir les infos importantes extraites
	*/
	char *pcType = NULL, *pcNbLignes = NULL, *pcNbColonnes = NULL;

	/*
		spécifie le contexte
		Utilisé pour la fonction strtok_s
	*/
	char *pcElementsuivT = NULL, *pcElementsuivL = NULL, *pcElementsuivC= NULL;

	/*
		Récupération des 4 premières lignes du fichier	
	*/
	fFichier >> cType; 
	fFichier >> cNbLignes;
	fFichier >> cNbColonnes;
	fFichier >> cIgnore;
	
	/*
		pointeurs temporaires qui permettent de récupérer nos infos du fichier
		/!\ Utilisé car strtok retourne NULL comme dernier caractère
	*/
	char *pctempType = strtok_s(cType, cdelim, &pcElementsuivT);
	char *pctempNbLignes = strtok_s(cNbLignes, cdelim, &pcElementsuivL);
	char *pctempNbColonnes = strtok_s(cNbColonnes, cdelim, &pcElementsuivC);

	/*
		Boucle parcourant chaque chaine de caractère et séparant les mots au niveau du "="	
	*/
	while (pctempType != NULL)
	{
		if (pctempType != NULL)
		{
			pcType = pctempType;
			pctempType = strtok_s(NULL, cdelim, &pcElementsuivT);
			
		}
		if (pctempNbLignes != NULL)
		{
			pcNbLignes = pctempNbLignes;
			pctempNbLignes = strtok_s(NULL, cdelim, &pcElementsuivL);
		}
		if (pctempNbColonnes != NULL)
		{
			pcNbColonnes = pctempNbColonnes;
			pctempNbColonnes = strtok_s(NULL, cdelim, &pcElementsuivC);
		}
	}

	/*
		On lève l'exception sur le Type	
	*/
	/*if (pcType != "double")
	{
		cout << "Vous avez rentre un type invalide" << endl;
		CException EXCType;
		EXCType.EXCmodifier_valeur(mauvais_type);
		throw(EXCType);
	}
	*/
	/******Si type est valide on récupère les composant de la matrice*******/

	/*
		Conversion de nos chaînes de caractère
	*/
	unsigned int uiNbLignes = atoi(pcNbLignes);
	unsigned int uiNbColonnes = atoi(pcNbColonnes);
	
	CMatrice<double>* pMATMatrice = new CMatrice<double>(uiNbLignes,uiNbColonnes);

	/*
		Lecture des éléments et remplissage de l'objet matrice
	*/
	for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiNbLignes; ++uiBoucleLigne)
	{
		for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiNbColonnes; ++uiBoucleColonne)
		{
			fFichier >> cMatElement;
			double dMatElement = atoi(cMatElement);
			pMATMatrice->MATModifierElement(uiBoucleLigne,uiBoucleColonne, dMatElement);
		}
	}
	pMATMatrice->MATAfficherMatrice();

	return *pMATMatrice;

}