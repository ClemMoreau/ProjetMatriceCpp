#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<float> MATMatrice1(5, 5);
	float k = 1.0;
	for (unsigned int i = 1; i <= MATMatrice1.MATLireNombreLigne(); i++)
	{
		for (unsigned int j = 1; j <= MATMatrice1.MATLireNombreColonne(); j++)
		{
			MATMatrice1.MATModifierElement(i, j, k);
		}
	}

	MATMatrice1.MATAfficherMatrice();
	std::cout << std::endl << std::endl;

	CMatrice<float> MATsomme = MATMatrice1 - MATMatrice1;
	MATsomme.MATAfficherMatrice();
	std::cout << std::endl << std::endl;
}