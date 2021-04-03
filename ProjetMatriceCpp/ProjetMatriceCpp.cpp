#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<int> MATMatrice1(3,3);
	int k = 1;
	for (unsigned int i = 1; i <= MATMatrice1.MATLireNombreLigne(); i++)
	{
		for (unsigned int j = 1; j <= MATMatrice1.MATLireNombreColonne(); j++, k++)
		{
			MATMatrice1.MATModifierElement(i, j, k);
		}
	}
	MATMatrice1.MATAfficherMatrice();
	std::cout << std::endl << std::endl;
	CMatrice<int> MATMatrice2(MATMatrice1);
	MATMatrice2.MATAfficherMatrice();

}