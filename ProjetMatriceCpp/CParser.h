#ifndef PAR
#define PAR 0
#include <stdio.h>
#include "CMatrice.h"


class CParser
{
private:
	char* psPARNomFichier;

public:
	CParser();
	CParser(CParser &PARParser);
	~CParser();

	char* PARLireNomFichier();
	
	void PARModifierNomFichier(char* sNomFichier);

	template <class MType> CMatrice<MType> PARLireFichier();
};

#endif //PAR