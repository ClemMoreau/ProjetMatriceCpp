#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<int> Mati(3, 3);
	
	int k = 0;
	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			Mati.MATModifierElement(i, j, k);
			k++;
		}
	}
	Mati.MATAfficherMatrice();
	Mati.MATModifierNombreLigne(4);
	Mati.MATAfficherMatrice();
	Mati.MATModifierNombreLigne(2);
	Mati.MATAfficherMatrice();
}