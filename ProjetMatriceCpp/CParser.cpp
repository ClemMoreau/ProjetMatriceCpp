#include "CParser.h"


/*********************************************************
Constructeur par défaut de la classe CParser
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec psNomdeFichier = NULL
*********************************************************/
CParser::CParser()
{
	PARModifierNomFichier(NULL);
}

/*********************************************************
Constructeur de recopie de la classe CParser
prenant en paramètre un CParser
*********************************************************
Entrée: CParser &PARParser : L 'objet parser à recopier
Nécessite:	CParser &PARParser doit être initialisé
Sortie: (rien)
Entraîne :	Modification du nom du fichier
*********************************************************/
CParser::CParser(CParser &PARParser)
{
	PARModifierNomFichier(PARParser.PARLireNomFichier());
}

/*********************************************************
Destructeur de la classe CParser
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est prêt à être détruit
*********************************************************/
CParser::~CParser()
{
	free(psPARNomFichier);
}

/*********************************************************
Renvoie le nom du fichier
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: psPARNomFichier : le nom du fichier
Entraîne :	(rien)
*********************************************************/
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

/*********************************************************
Modifie le nom du fichier si déja existant 
*********************************************************
Entrée: const char* sNomFichier : le nouveau nom de notre fichier
Nécessite:	(rien)
Sortie: (rien)
Entraîne : Entraine "libération" de psPARNomFichier
et psPARNomFichier = sNomFichier
*********************************************************/
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

/*********************************************************
Lecture du fichier
*********************************************************
Entrée: (rien)
Nécessite: Un chemin de fichier a été spécifié
Sortie: CMatrice<double> : la matrice de double extraite du fichier
Entraîne : Récupération des informations du fichier, création d'une matrice
de type double rempli avec le contenu du fichier
*********************************************************/
CMatrice<double>& CParser::PARLireFichier()
{
	// Ouverture du fichier
	ifstream fFichier(PARLireNomFichier());
	if (!fFichier)
	{
		//On teste si l'ouverture c'est bien déroulé
		CException EXCFichier;
		EXCFichier.EXCmodifier_valeur(ouverture_fichier_impossible);
		throw(EXCFichier);
	}
	
	// variable utilisé pour léver une execption si le type n'est pas du bon type
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
			cerr << "Vous avez rentre un type invalide" << endl;
			CException EXCType;
			EXCType.EXCmodifier_valeur(mauvais_type);
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
	//pMATMatrice->MATAfficherMatrice();

	return *pMATMatrice;

}