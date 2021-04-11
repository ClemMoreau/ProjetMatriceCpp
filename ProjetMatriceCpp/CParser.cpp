#include "CParser.h"


#define nom_null 201

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
	ifstream fFichier(PARLireNomFichier());
	if (!fFichier)
	{

	}
	///Permet de lire un mot (donc need espace entre les mots)
	/*char cIgnore[5];
	fFichier >> cIgnore; 
	cout << cIgnore << endl;*/

	// et avec ça tu récupe le début du fichier : c'est pas trop génie log par contre faudra plutot un truc qui se déplace jusqu'au =
	char* pointeur = (char*)malloc(13);
	fFichier.getline(pointeur, 13);
	printf("%s\n" ,pointeur);

	CMatrice<double>* pMATMatrice = new CMatrice<double>(3,3);
	return *pMATMatrice;
}