#ifndef OPM
#define OPM 0

#include "CException.h"
#include "CMatrice.h"

template <typename MType> class CMatrice;
class COperationMatrice
{
public :
	/*********************************************************
	Calcul la transposé de la matrice
	*********************************************************/
	template<class MType> static CMatrice<MType>& OPMTranspose(CMatrice<MType>& MATMatrice);

	template<class MType> static CMatrice<MType>& OPMExtraireMatrice1(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne);

	template<class MType> static CMatrice<MType>& OPMExtraireMatrice2(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne);
	template<class MType> static CMatrice<MType>* OPMExtraireMatriceCarree(CMatrice<MType>& MATMatrice, int iDimension);
};
#endif //OPM

/*********************************************************
Calcul la transposé de la matrice
*********************************************************
Entrée: (rien)
Nécessite: (la matrice doit contenir des éléments)
Sortie: CMatrice<MType> : la tranposé de la matrice
Entraîne : (la matrice en sortie est la tranposé de la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& COperationMatrice::OPMTranspose(CMatrice<MType>& MATMatrice)
{
	// Cas matrice carré : uiMATNbLigne == uiMATNbColonne
	if (MATMatrice.MATLireNombreColonne() == MATMatrice.MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreLigne(), MATMatrice.MATLireNombreColonne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carré : uiMATNbLigne < uiMATNbColonne
	else if (MATMatrice.MATLireNombreColonne() > MATMatrice.MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreColonne(), MATMatrice.MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carré : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Création de la transposé de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATMatrice.MATLireNombreColonne(), MATMatrice.MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= MATMatrice.MATLireNombreLigne(); uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= MATMatrice.MATLireNombreColonne(); uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
}

//Question 1
template <class MType>
CMatrice<MType>& COperationMatrice::OPMExtraireMatrice1(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne)
{
	//test notre de lignes/colones choisis
	if (iNombreLigne <= 0 || iNombreColonne <= 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Test si on est bien dans la matrice
	if (iIndiceLigne <= 0 || iIndiceLigne > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}
	
	
	if (iIndiceColonne <= 0 || iIndiceColonne > int(MATMatrice.MATLireNombreColonne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// on vérifie que la sous matrice ne dépasse pas
	if ((iIndiceColonne + iNombreColonne - 1) > int(MATMatrice.MATLireNombreColonne()) || (iIndiceLigne + iNombreLigne - 1) > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	CMatrice<MType>* pMATSousMatrice = new CMatrice<MType>(iNombreLigne, iNombreColonne);
	int iBoucleLigne = 1;
	for (int iBoucleIndiceLigne = iIndiceLigne; iBoucleIndiceLigne < iIndiceLigne + iNombreLigne; iBoucleIndiceLigne++, iBoucleLigne++)
	{
		int iBoucleColonne = 1;
		for (int iBoucleIndiceColonne = iIndiceColonne; iBoucleIndiceColonne < iIndiceColonne + iNombreColonne; iBoucleIndiceColonne++, iBoucleColonne++)
		{
			pMATSousMatrice->MATModifierElement(iBoucleLigne, iBoucleColonne, MATMatrice.MATLireElement(iBoucleIndiceLigne, iBoucleIndiceColonne));
		}
	}

	return *pMATSousMatrice;
}

//Question 2
template <class MType>
CMatrice<MType>& COperationMatrice::OPMExtraireMatrice2(CMatrice<MType>& MATMatrice, int iIndiceLigne, int iIndiceColonne, int iNombreLigne, int iNombreColonne)
{
	//test notre de lignes/colones choisis
	if (iNombreLigne <= 0 || iNombreColonne <= 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Test si on est bien dans la matrice
	if (iIndiceLigne <= 0 || iIndiceLigne > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}


	if (iIndiceColonne <= 0 || iIndiceColonne > int(MATMatrice.MATLireNombreColonne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// on vérifie que la sous matrice ne dépasse pas
	if ((iIndiceColonne + iNombreColonne - 1) > int(MATMatrice.MATLireNombreColonne()) || (iIndiceLigne + iNombreLigne - 1) > int(MATMatrice.MATLireNombreLigne()))
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	//condition sur i et j
	if (iIndiceLigne <= iNombreLigne && iIndiceColonne <= iNombreColonne)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	CMatrice<MType>* pMATSousMatrice = new CMatrice<MType>(iNombreLigne, iNombreColonne);
	int iBoucleLigne = 1;
	for (int iBoucleIndiceLigne = iIndiceLigne - iNombreLigne; iBoucleIndiceLigne < iIndiceLigne + iNombreLigne; iBoucleIndiceLigne++, iBoucleLigne++)
	{
		int iBoucleColonne = 1;
		for (int iBoucleIndiceColonne = iIndiceColonne - iNombreColonne; iBoucleIndiceColonne < iIndiceColonne + iNombreColonne; iBoucleIndiceColonne++, iBoucleColonne++)
		{
			pMATSousMatrice->MATModifierElement(iBoucleLigne, iBoucleColonne, MATMatrice.MATLireElement(iBoucleIndiceLigne, iBoucleIndiceColonne));
		}
	}
	return *pMATSousMatrice;
}

//Question 3
template<class MType> 
CMatrice<MType>* COperationMatrice::OPMExtraireMatriceCarree(CMatrice<MType>& MATMatrice, int iDimension)
{
	int iMinimum = (MATMatrice.MATLireNombreLigne() < MATMatrice.MATLireNombreColonne()) ? MATMatrice.MATLireNombreLigne() : MATMatrice.MATLireNombreColonne();

	if (iDimension > iMinimum)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	int iNbSousMatriceColonne = int(MATMatrice.MATLireNombreColonne()) - (iDimension - 1);
	int iNbSousMatriceLigne = int(MATMatrice.MATLireNombreLigne()) - (iDimension - 1);
	int iNbSousMatrice = iNbSousMatriceColonne * iNbSousMatriceLigne;

	CMatrice<MType>* pMATListSousMatrice = new CMatrice<MType>[iNbSousMatrice];

	int iTantQueListe = 0;

	while (iTantQueListe < iNbSousMatrice)
	{
		for (int iBoucleIndiceLigne = 1; iBoucleIndiceLigne <= iNbSousMatriceLigne; iBoucleIndiceLigne++)
		{
			for (int iBoucleIndiceColonne = 1; iBoucleIndiceColonne <= iNbSousMatriceColonne; iBoucleIndiceColonne++)
			{
				pMATListSousMatrice[iTantQueListe] = OPMExtraireMatrice1(MATMatrice, iBoucleIndiceLigne, iBoucleIndiceColonne, iDimension, iDimension);
				iTantQueListe++;
				//OPMExtraireMatrice1(MATMatrice, iBoucleIndiceLigne, iBoucleIndiceColonne, iDimension, iDimension).MATAfficherMatrice();
			}
		}
	}

	return pMATListSousMatrice;
}