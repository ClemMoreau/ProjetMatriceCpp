#include "CParser.h"

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
	PARModifierNomFichier(NULL);
}

char* CParser::PARLireNomFichier()
{
	return psPARNomFichier;
}

void CParser::PARModifierNomFichier(char* sNomFichier)
{
	psPARNomFichier = sNomFichier;
}

CMatrice<MType> CParser::PARLireFichier()
{

}