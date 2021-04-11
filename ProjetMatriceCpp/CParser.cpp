#include "CParser.h"
#include "CMatrice.h"
#include "CException.h"

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


