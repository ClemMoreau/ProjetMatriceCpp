#include "Cexception.h"

CException::CException()
{
	EXCmodifier_valeur(0);
}

CException::CException(CException& EXCobjet)
{
	EXCmodifier_valeur(EXCobjet.EXClire_valeur());
}

CException::~CException()
{
	EXCmodifier_valeur(0);
}
void CException::EXCmodifier_valeur(unsigned int uiValeur)
{
	uiEXCvaleur = uiValeur;
}

int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}