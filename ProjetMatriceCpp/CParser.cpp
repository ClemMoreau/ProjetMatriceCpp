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
		/* On teste si l'ouverture c'est bien d�roul� */
	}
	
	/* 
		cdelim est notre s�parateur
		Utilis� pour la fonction strtok() 	   
	*/
	char cdelim[] = "=";

	/*
		on initialise des tableaux de caract�re pour y stocker les lignes de notre fichier
	*/
	char cType[100], cNbLignes[100], cNbColonnes[100], cIgnore[200], cMatElement[200];

	/*
		pointeur sur des chaine de caracy�re qui vont contenir les infos importantes extraites
	*/
	char *pcType = NULL, *pcNbLignes = NULL, *pcNbColonnes = NULL;

	/*
		sp�cifie le contexte
		Utilis� pour la fonction strtok_s
	*/
	char *pcElementsuivT = NULL, *pcElementsuivL = NULL, *pcElementsuivC= NULL;

	/*
		R�cup�ration des 4 premi�res lignes du fichier	
	*/
	fFichier >> cType; 
	fFichier >> cNbLignes;
	fFichier >> cNbColonnes;
	fFichier >> cIgnore;
	
	/*
		pointeurs temporaires qui permettent de r�cup�rer nos infos du fichier
		/!\ Utilis� car strtok retourne NULL comme dernier caract�re
	*/
	char *pctempType = strtok_s(cType, cdelim, &pcElementsuivT);
	char *pctempNbLignes = strtok_s(cNbLignes, cdelim, &pcElementsuivL);
	char *pctempNbColonnes = strtok_s(cNbColonnes, cdelim, &pcElementsuivC);

	/*
		Boucle parcourant chaque chaine de caract�re et s�parant les mots au niveau du "="	
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
		On l�ve l'exception sur le Type	
	*/
	/*if (pcType != "double")
	{
		cout << "Vous avez rentre un type invalide" << endl;
		CException EXCType;
		EXCType.EXCmodifier_valeur(mauvais_type);
		throw(EXCType);
	}
	*/
	/******Si type est valide on r�cup�re les composant de la matrice*******/

	/*
		Conversion de nos cha�nes de caract�re
	*/
	unsigned int uiNbLignes = atoi(pcNbLignes);
	unsigned int uiNbColonnes = atoi(pcNbColonnes);
	
	CMatrice<double>* pMATMatrice = new CMatrice<double>(uiNbLignes,uiNbColonnes);

	/*
		Lecture des �l�ments et remplissage de l'objet matrice
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