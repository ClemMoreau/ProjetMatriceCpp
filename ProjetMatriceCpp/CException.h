#ifndef EXC
#define EXC 0

class CException
{
private:
	unsigned int uiEXCvaleur;

public:
	CException();
	CException(CException &EXCobjet);
	~CException();
	void EXCmodifier_valeur(unsigned int uiValeur);
	int EXClire_valeur();
};
#endif //EXC