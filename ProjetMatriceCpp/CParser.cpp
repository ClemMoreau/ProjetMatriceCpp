#include "CParser.h"
#include "CMatrice.h"
#include "CException.h"


CParser::CParser()
{
	psPARNomFichier = NULL;
}

CParser::CParser(CParser &PARParser)
{

}


CParser::~CParser()
{
	delete psPARNomFichier;
}


char* CParser::PARLireNomFichier()
{
	if (psPARNomFichier == NULL)
	{
		CException EXCObjet;

	}
	else
	{
		return psPARNomFichier;
	}
}


void CParser::PARModifierNomFichier(char* sNomFichier)
{

}


