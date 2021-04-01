#include "Cexception.h"

/*********************************************************
Constructeur par défaut de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec uiEXCValeur = 0
*********************************************************/
CException::CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Constructeur de recopie de la classe CException 
prenant en paramètre un objet de la classe CException
*********************************************************
Entrée: CException& EXCobjet : L'objet à recopier
Nécessite:	EXCobjet doit être initialisé
Sortie: (rien)
Entraîne :	L'objet est initialisé avec this.uiEXCValeur = EXCobjet.uiEXCValeur
*********************************************************/
CException::CException(CException& EXCobjet)
{
	EXCmodifier_valeur(EXCobjet.EXClire_valeur());
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est pret à être détruit
*********************************************************/
CException::~CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: unsigned int uiValeur : le code de l'exception à levé
Nécessite:	uiValeur > 0
Sortie: (rien)
Entraîne :	this.uiEXCValeur = uiValeur
*********************************************************/
void CException::EXCmodifier_valeur(unsigned int uiValeur)
{
	uiEXCvaleur = uiValeur;
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: int : le code de l'exception à levé
Entraîne :	(rien)
*********************************************************/
int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}