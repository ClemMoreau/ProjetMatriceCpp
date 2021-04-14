#ifndef EXC
#define EXC 0

#define valeur_negative 100

class CException
{
private:
	unsigned int uiEXCvaleur;

public:
	/*CONSTRUCTEURS*/
	
	/*********************************************************
	Constructeur par d�faut de la classe CException
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: (rien)
	Entra�ne :	L'objet est initialis� avec uiEXCValeur = 0
	*********************************************************/
	CException();

	/*********************************************************
	Constructeur de recopie de la classe CException
	prenant en param�tre un objet de la classe CException
	*********************************************************
	Entr�e: CException& EXCobjet : L'objet � recopier
	N�cessite:	EXCobjet doit �tre initialis�
	Sortie: (rien)
	Entra�ne :	L'objet est initialis� avec this.uiEXCValeur = EXCobjet.uiEXCValeur
	*********************************************************/
	CException(CException &EXCobjet);

	/*DESTRUCTEUR*/

	/*********************************************************
	Destructeur de la classe CException
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: (rien)
	Entra�ne :	L'objet est pret � �tre d�truit
	*********************************************************/
	~CException();

	/*SETTER*/

	/*********************************************************
	Destructeur de la classe CException
	*********************************************************
	Entr�e: unsigned int uiValeur : le code de l'exception � lev�
	N�cessite:	uiValeur > 0
	Sortie: (rien)
	Entra�ne :	this.uiEXCValeur = uiValeur
	*********************************************************/
	void EXCmodifier_valeur(int iValeur);

	/*GETTER*/

	/*********************************************************
	Destructeur de la classe CException
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: unsigned int : le code de l'exception � lev�
	Entra�ne :	(rien)
	*********************************************************/
	unsigned int EXClire_valeur();
};
#endif //EXC