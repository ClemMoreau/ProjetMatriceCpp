#include "CParser.h"

CParser::CParser()
{
	psPARNomFichier = NULL;
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

template <class MType>
CMatrice<MType> CParser::PARLireFichier()
{

}