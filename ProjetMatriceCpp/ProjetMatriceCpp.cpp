#include <iostream>
#include "CException.h"
#include "CMatrice.h"

int main()
{
	CMatrice<char> Mat(3,2);
	Mat.MATModifierElement(1, 1, 1);
	Mat.MATModifierElement(1, 2, 2);
	Mat.MATModifierElement(2, 1, 3);
	Mat.MATModifierElement(2, 2, 4);
	Mat.MATModifierElement(3, 1, 5);
	Mat.MATModifierElement(3, 2, 6);
	Mat.MATAfficherMatrice();

	CMatrice<char> MatTrans = Mat.MATTranspose();
	MatTrans.MATAfficherMatrice();

}