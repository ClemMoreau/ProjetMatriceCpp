#include "CFichier.h"

/*********************************************************
Constructeur par défaut de la classe CFichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec psNomdeFichier = NULL
*********************************************************/
CFichier::CFichier()
{
	FICModifierNomFichier(NULL);
}

/*********************************************************
Constructeur de recopie de la classe CFichier
prenant en paramètre un CFichier
*********************************************************
Entrée: CFichier &FICFichier : L 'objet fichier à recopier
Nécessite:	CFichier &FICFichier doit être initialisé
Sortie: (rien)
Entraîne :	Modification du nom du fichier
*********************************************************/
CFichier::CFichier(CFichier &FICFichier)
{
	FICModifierNomFichier(FICFichier.FICLireNomFichier());
}

/*********************************************************
Destructeur de la classe CFichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est prêt à être détruit
*********************************************************/
CFichier::~CFichier()
{
	free(psFICNomFichier);
}

/*********************************************************
Renvoie le nom du fichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: psFICNomFichier : le nom du fichier
Entraîne :	(rien)
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
Modifie le nom du fichier si déja existant 
*********************************************************
Entrée: const char* sNomFichier : le nouveau nom de notre fichier
Nécessite:	(sNomFichier ne doit pas contenir d'espace)
Sortie: (rien)
Entraîne : Entraine "libération" de psFICNomFichier
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
Entrée: (rien)
Nécessite: Un chemin de fichier a été spécifié
Sortie: CMatrice<double> : la matrice de double extraite du fichier
Entraîne : Récupération des informations du fichier, création d'une matrice
de type double rempli avec le contenu du fichier
*********************************************************/
CMatrice<double>& CFichier::FICLireFichier()
{
	// Ouverture du fichier
	ifstream fFichier(FICLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien déroulé
		CException EXCFichier;
		EXCFichier.EXCmodifier_valeur(ouverture_fichier_impossible);
		throw(EXCFichier);
	}
	
	// variable utilisé pour lever une execption si le type n'est pas du bon type
	char cTypeTest[] = "double";
	//cdelim est notre séparateur, Utilisé pour la fonction strtok_s() 	   
	char cdelim[] = "=";

	//on initialise des tableaux de caractère pour y stocker les lignes de notre fichier
	char cType[100], cNbLignes[100], cNbColonnes[100], cIgnore[200], cMatElement[200];

	
	//pointeur sur des chaine de caractère qui vont contenir les infos importantes à extraire
	char *pcType = NULL, *pcNbLignes = NULL, *pcNbColonnes = NULL;

	
	//spécifie le contexte, Utilisé pour la fonction strtok_s
	char *pcElementsuivT = NULL, *pcElementsuivL = NULL, *pcElementsuivC= NULL;

	//Récupération des 4 premières lignes du fichier	
	fFichier >> cType; 
	fFichier >> cNbLignes;
	fFichier >> cNbColonnes;
	fFichier >> cIgnore;
	
	
	//pointeurs temporaires qui permettent de récupérer nos infos du fichier
	// /!\ Utilisé car strtok retourne NULL comme dernier caractère
	char *pctempType = strtok_s(cType, cdelim, &pcElementsuivT);
	char *pctempNbLignes = strtok_s(cNbLignes, cdelim, &pcElementsuivL);
	char *pctempNbColonnes = strtok_s(cNbColonnes, cdelim, &pcElementsuivC);

	//Boucle parcourant chaque chaine de caractère et séparant les mots au niveau du "="	
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

	
	//On lève l'exception sur le Type	
	for (int iBoucleTest = 0; iBoucleTest < int(strlen(pcType)); iBoucleTest++)
		if (pcType[iBoucleTest] != cTypeTest[iBoucleTest])
		{
			CException EXCType;
			EXCType.EXCmodifier_valeur(type_incorrect);
			throw(EXCType);
		}
	
	/******Si type est valide on récupère les composants de la matrice*******/

	//Conversion de nos chaînes de caractère
	unsigned int uiNbLignes = atoi(pcNbLignes);
	unsigned int uiNbColonnes = atoi(pcNbColonnes);
	
	CMatrice<double>* pMATMatrice = new CMatrice<double>(uiNbLignes,uiNbColonnes);

	//Lecture des éléments et remplissage de l'objet matrice
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