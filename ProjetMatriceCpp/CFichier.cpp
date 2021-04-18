#include "CFichier.h"

/*********************************************************
Constructeur par d�faut de la classe CFichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec psNomdeFichier = NULL
*********************************************************/
CFichier::CFichier()
{
	FICModifierNomFichier(NULL);
}

/*********************************************************
Constructeur de recopie de la classe CFichier
prenant en param�tre un CFichier
*********************************************************
Entr�e: CFichier &FICFichier : L 'objet fichier � recopier
N�cessite:	CFichier &FICFichier doit �tre initialis�
Sortie: (rien)
Entra�ne :	Modification du nom du fichier
*********************************************************/
CFichier::CFichier(CFichier &FICFichier)
{
	FICModifierNomFichier(FICFichier.FICLireNomFichier());
}

/*********************************************************
Destructeur de la classe CFichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est pr�t � �tre d�truit
*********************************************************/
CFichier::~CFichier()
{
	free(psFICNomFichier);
}

/*********************************************************
Renvoie le nom du fichier
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: psFICNomFichier : le nom du fichier
Entra�ne :	(rien)
*********************************************************/
char* CFichier::FICLireNomFichier()
{
	if (psFICNomFichier == NULL)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(nom_null);
		throw(EXCObjet);

	}
	return psFICNomFichier;
}

/*********************************************************
Modifie le nom du fichier si d�ja existant 
*********************************************************
Entr�e: const char* sNomFichier : le nouveau nom de notre fichier
N�cessite:	(sNomFichier ne doit pas contenir d'espace)
Sortie: (rien)
Entra�ne : Entraine "lib�ration" de psFICNomFichier
et psFICNomFichier = sNomFichier
*********************************************************/
void CFichier::FICModifierNomFichier(const char* sNomFichier)
{
	if (sNomFichier)
	{
		if (psFICNomFichier)
		{
			free(psFICNomFichier);
		}

		int iConteur = strlen(sNomFichier);
		psFICNomFichier = (char*)malloc(iConteur + 1);
		int iBoucleCopie;
		for (iBoucleCopie = 0; iBoucleCopie < iConteur; iBoucleCopie++)
		{
			psFICNomFichier[iBoucleCopie] = sNomFichier[iBoucleCopie];
		}
		psFICNomFichier[iBoucleCopie] = '\0';
	}
	else 
	{
		psFICNomFichier = NULL;
	}
}

/*********************************************************
Lecture du fichier
*********************************************************
Entr�e: (rien)
N�cessite: Un chemin de fichier a �t� sp�cifi�
Sortie: CMatrice<double> : la matrice de double extraite du fichier
Entra�ne : R�cup�ration des informations du fichier, cr�ation d'une matrice
de type double rempli avec le contenu du fichier
*********************************************************/
CMatrice<double>& CFichier::FICLireFichier()
{
	// Ouverture du fichier
	ifstream fFichier(FICLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien d�roul�
		CException EXCFichier;
		EXCFichier.EXCmodifier_valeur(ouverture_fichier_impossible);
		throw(EXCFichier);
	}
	
	// variable utilis� pour lever une execption si le type n'est pas du bon type
	char cTypeTest[] = "double";
	//cdelim est notre s�parateur, Utilis� pour la fonction strtok_s() 	   
	char cdelim[] = "=";

	//on initialise des tableaux de caract�re pour y stocker les lignes de notre fichier
	char cType[100], cNbLignes[100], cNbColonnes[100], cIgnore[200], cMatElement[200];

	
	//pointeur sur des chaine de caract�re qui vont contenir les infos importantes � extraire
	char *pcType = NULL, *pcNbLignes = NULL, *pcNbColonnes = NULL;

	
	//sp�cifie le contexte, Utilis� pour la fonction strtok_s
	char *pcElementsuivT = NULL, *pcElementsuivL = NULL, *pcElementsuivC= NULL;

	//R�cup�ration des 4 premi�res lignes du fichier	
	fFichier >> cType; 
	fFichier >> cNbLignes;
	fFichier >> cNbColonnes;
	fFichier >> cIgnore;
	
	
	//pointeurs temporaires qui permettent de r�cup�rer nos infos du fichier
	// /!\ Utilis� car strtok retourne NULL comme dernier caract�re
	char *pctempType = strtok_s(cType, cdelim, &pcElementsuivT);
	char *pctempNbLignes = strtok_s(cNbLignes, cdelim, &pcElementsuivL);
	char *pctempNbColonnes = strtok_s(cNbColonnes, cdelim, &pcElementsuivC);

	//Boucle parcourant chaque chaine de caract�re et s�parant les mots au niveau du "="	
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

	
	//On l�ve l'exception sur le Type	
	for (int iBoucleTest = 0; iBoucleTest < int(strlen(pcType)); iBoucleTest++)
		if (pcType[iBoucleTest] != cTypeTest[iBoucleTest])
		{
			CException EXCType;
			EXCType.EXCmodifier_valeur(type_incorrect);
			throw(EXCType);
		}
	
	/******Si type est valide on r�cup�re les composants de la matrice*******/

	//Conversion de nos cha�nes de caract�re
	unsigned int uiNbLignes = atoi(pcNbLignes);
	unsigned int uiNbColonnes = atoi(pcNbColonnes);
	
	CMatrice<double>* pMATMatrice = new CMatrice<double>(uiNbLignes,uiNbColonnes);

	//Lecture des �l�ments et remplissage de l'objet matrice
	for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiNbLignes; ++uiBoucleLigne)
	{
		for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiNbColonnes; ++uiBoucleColonne)
		{
			fFichier >> cMatElement;
			double dMatElement = atoi(cMatElement);
			///tester un try/catch ici
			pMATMatrice->MATModifierElement(uiBoucleLigne,uiBoucleColonne, dMatElement);
		}
	}
	free(pctempNbColonnes); free(pctempType); free(pctempNbLignes);
	return *pMATMatrice;
};