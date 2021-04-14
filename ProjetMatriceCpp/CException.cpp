#include "Cexception.h"

/*********************************************************
Constructeur par d�faut de la classe CException
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec uiEXCValeur = 0
*********************************************************/
CException::CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Constructeur de recopie de la classe CException 
prenant en param�tre un objet de la classe CException
*********************************************************
Entr�e: CException& EXCobjet : L'objet � recopier
N�cessite:	EXCobjet doit �tre initialis�
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec this.uiEXCValeur = EXCobjet.uiEXCValeur
*********************************************************/
CException::CException(CException& EXCobjet)
{
	if (EXCobjet.EXClire_valeur() < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(valeur_negative);
		throw(EXCObjet);
	}
	EXCmodifier_valeur(EXCobjet.EXClire_valeur());
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est pret � �tre d�truit
*********************************************************/
CException::~CException()
{
	EXCmodifier_valeur(0);
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entr�e: unsigned int uiValeur : le code de l'exception � lev�
N�cessite:	uiValeur > 0
Sortie: (rien)
Entra�ne :	this.uiEXCValeur = uiValeur
*********************************************************/
void CException::EXCmodifier_valeur(int iValeur)
{
	if (iValeur < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(valeur_negative);
		throw(EXCObjet);
	}
	uiEXCvaleur = iValeur;
}

/*********************************************************
Destructeur de la classe CException
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: int : le code de l'exception � lev�
Entra�ne :	(rien)
*********************************************************/
unsigned int CException::EXClire_valeur()
{
	return uiEXCvaleur;
}