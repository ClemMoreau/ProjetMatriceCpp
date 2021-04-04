#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<float> MATMatrice(2, 2);
	float k = 1.0;
	for (unsigned int i = 1; i <= MATMatrice.MATLireNombreLigne(); i++)
	{
		for (unsigned int j = 1; j <= MATMatrice.MATLireNombreColonne(); j++, k++)
		{
			MATMatrice.MATModifierElement(i, j, k);
		}
	}
	MATMatrice.MATAfficherMatrice();
	std::cout << std::endl << std::endl;

	CMatrice<float> MATMatrice1(2, 2);

	MATMatrice1.MATModifierElement(1, 1, 1);
	MATMatrice1.MATModifierElement(1, 2, 0);
	MATMatrice1.MATModifierElement(2, 1, 0);
	MATMatrice1.MATModifierElement(2, 2, 1);

	MATMatrice1.MATAfficherMatrice();
	std::cout << std::endl << std::endl;

	CMatrice<float> MATProd = MATMatrice * MATMatrice;
	MATProd.MATAfficherMatrice();
	std::cout << std::endl << std::endl;
}