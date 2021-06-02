#ifndef MAT
#define MAT 0

#include "CException.h"
#include <stdio.h>

#define dimension_incorrecte 201
#define dim_matrice_diff 202
#define diviseur_nul 203

template <class MType> class CMatrice
{
private:

				/*************
				 * ATTRIBUTS *
				 *************/

	/*Nombre de lignes de la matrice */
	unsigned int uiMATNbLigne; 

	/*Nombre de colonnes de la matrice*/
	unsigned int uiMATNbColonne;

	/*Contenu de la matrice : [1;uiMATNbLigne]x[1;uiMATNbColonne]*/
	///Il faut utiliser les indices math�matiques d'une matrice et non les indices d'un tableau en C 
	MType **ppMATMatrice;

public:
					/*****************
					 * CONSTRUCTEURS *
					 *****************/
	 
	/*********************************************************
	Constructeur par d�faut de la classe CMatrice
	*********************************************************/
	CMatrice<MType>();

	/*********************************************************
	Constructeur de recopie de la classe CMatrice 
	prenant en param�tre un CMatrice<MType> 
	*********************************************************/
	CMatrice<MType>(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Constructeur de recopie de la classe CMatrice
	prenant en param�tre le nombre de ligne et de colonne
	de la matrice � cr�er
	*********************************************************/
	CMatrice<MType>(int iNbLigne, int iNbColonne);

				   /***************
					* DESTRUCTEUR *
					***************/

	/*********************************************************
	Destructeur de la classe CMatrice
	*********************************************************/
	~CMatrice<MType>();

					   /***********
						* GETTERS *
						***********/

	/*********************************************************
	Renvoie le nombre de ligne de la matrice
	*********************************************************/
	unsigned int MATLireNombreLigne();

	/*********************************************************
	Renvoie le nombre de colonne de la matrice
	*********************************************************/
	unsigned int MATLireNombreColonne();

	/*********************************************************
	Renvoie l'�l�ment ligne iIndiceLigne et colonne iIndiceColonne
	*********************************************************/
	MType MATLireElement(int iIndiceLigne, int iIndiceColonne);

					   /***********
						* SETTERS *
						***********/

	/*********************************************************
	Modifie le nombre de ligne de la matrice
	*********************************************************/
	void MATModifierNombreLigne(int iNbLigne);

	/*********************************************************
	Modifie le nombre de colonne de la matrice
	*********************************************************/
	void MATModifierNombreColonne(int iNbColonne);

	/*********************************************************
	Modifie l'�l�ment ligne iIndiceLigne et colonne iIndiceColonne
	*********************************************************/
	void MATModifierElement(int iIndiceLigne, int iIndiceColonne, MType MTypeParam);

					   /************
						* METHODES *
						************/

	/*********************************************************
	Calcul la transpos� de la matrice
	*********************************************************/
	CMatrice<MType>& MATTranspose();

	/*********************************************************
	Affiche la matrice dans la console
	**********************************************************/
	void MATAfficherMatrice();

					   /**************
						* SURCHARGES *
						**************/

	/*********************************************************
	Surcharge de l'operateur = pour la classe CMatrice<MType>
	prenant un MType en param�tre
	*********************************************************/
	CMatrice<MType>& operator=(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur + pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre : addtition matricielle
	*********************************************************/
	CMatrice<MType>& operator+(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur - pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre : soustraction matricielle
	*********************************************************/
	CMatrice<MType>& operator-(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre : produit matricielle
	*********************************************************/
	CMatrice<MType>& operator*(CMatrice<MType>& MATMatrice);


	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un MType en param�tre : multiplication par constante
	*********************************************************/
	CMatrice<MType>& operator*(const MType MTypeParam);

	/*********************************************************
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un MType en param�tre : division par constante
	*********************************************************/
	CMatrice<MType>& operator/(const MType MTypeParam);

};

/*********************************************************
Constructeur par d�faut de la classe CMatrice
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec uiMATNbLigne = 0
uiMATNbColonne = 0 et ppMATMatrice = NULL
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice()
{
	uiMATNbLigne = 0;
	uiMATNbColonne = 0;
	ppMATMatrice = NULL;
}

/*********************************************************
Constructeur de recopie de la classe CMatrice
prenant en param�tre un CMatrice<MType>
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � recopier
N�cessite:	CMatrice<MType>& MATMatrice doit �tre initialis�
Sortie: (rien)
Entra�ne : L'objet est initialis� � partir des attributs
de MATMatrice en param�tre
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MATMatrice)
{
	// Recopie des dimensions de MATMatrice en param�tre
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne()); 
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	for (unsigned int uiIndiceBoucleColonne = 1; uiIndiceBoucleColonne <= uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		for (unsigned int uiIndiceBoucleLigne = 1; uiIndiceBoucleLigne <= uiMATNbLigne; uiIndiceBoucleLigne++)
		{
			// Copie du contenu de MAtMatrice en param�tre
			MATModifierElement(uiIndiceBoucleLigne, uiIndiceBoucleColonne, MATMatrice.MATLireElement(uiIndiceBoucleLigne, uiIndiceBoucleColonne));
		}
	}
}

/*********************************************************
Constructeur de recopie de la classe CMatrice
prenant en param�tre le nombre de ligne et de colonne
de la matrice � cr�er
*********************************************************
Entr�e: int iNbLigne, int iNbColonne : les dimensions de la nouvelle matrice
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet initialis� est une matrice
de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialis� par le compilateur
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(int iNbLigne, int iNbColonne)
{
	// Test du nombre de colonne et de ligne pass� en param�tre
	if (iNbLigne < 0 || iNbColonne < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Allocation du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[iNbColonne];
	for (int iIndiceBoucleColonne = 0; iIndiceBoucleColonne < iNbColonne; iIndiceBoucleColonne++)
	{
		// Allocation des lignes de la matrice
		*(ppMATMatrice + iIndiceBoucleColonne) = new MType[iNbLigne];
	}

	// Mise � jour du nombre de ligne et de colonne de la matrice
	uiMATNbColonne = iNbColonne;
	uiMATNbLigne = iNbLigne;
}

/*********************************************************
Destructeur de la classe CMatrice
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est pr�t � �tre d�truit,
les derniers traitements sont r�alis�
*********************************************************/
template <class MType>
CMatrice<MType>::~CMatrice()
{
	// Mise � jour du nombre de ligne et de colonne de la matrice
		/// La suppression du contenu de la matrice est g�r� par les setters sur les lignes/colonnes ci-dessous
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	
	// Destruction du tableau de colonnes de la matrice
	delete[] ppMATMatrice ;

}

/*********************************************************
Renvoie le nombre de ligne de la matrice
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
Entra�ne :	(rien)
*********************************************************/
template <class MType>
unsigned int CMatrice<MType>::MATLireNombreLigne()
{
	return uiMATNbLigne;
}

/*********************************************************
Renvoie le nombre de colonne de la matrice
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
Entra�ne :	(rien)
*********************************************************/
template <class MType>
unsigned int CMatrice<MType>::MATLireNombreColonne()
{
	return uiMATNbColonne;
}

/*********************************************************
Renvoie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entr�e: int iIndiceLigne, int iIndiceColonne : les indices de l'�l�ment � retourner
N�cessite:	(rien)
Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) :
l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne 
Entra�ne :	(retourne l'�l�ment) ou (exception lev� pour dimension incorrecte)
*********************************************************/
template <class MType>
 MType CMatrice<MType>::MATLireElement(int iIndiceLigne, int iIndiceColonne)
{ 
	 // V�rification indices en param�tre
	 if (iIndiceLigne <= 0 || iIndiceColonne <= 0 || iIndiceLigne > int(MATLireNombreLigne()) || iIndiceColonne > int(MATLireNombreColonne()))
	 {
		 CException EXCObjet;
		 EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		 throw(EXCObjet);
	 }

	 return *(*(ppMATMatrice + (iIndiceColonne - 1)) + (iIndiceLigne - 1));
}

/*********************************************************
Modifie le nombre de ligne de la matrice
*********************************************************
Entr�e: int iNbLigne : le nouveau nombre de ligne de la matrice
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(uiMATNbLigne = iNbLigne) et
(les �l�ments des (uiMATNbLigne - iNbLigne) derni�res lignes on �t� supprim�)
ou
(les �l�ments des (iNbLigne - uiMATNbLigne) lignes on �t� rajout� en bas de la matrice)
ou
(Exception dimension_incorrecte lev�)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(int iNbLigne)
{
	// V�rification nouveau nombre de colonnes positif
	if (iNbLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	
	/* Cr�ation de la matrice avec le nouveau nombre de ligne */
		/// utilisation du constructeur prenant un nombre ligne et de colonne en param�tre
	CMatrice<MType> *MATMatriceTempo = new CMatrice(iNbLigne, uiMATNbColonne);

	if (iNbLigne > int(uiMATNbLigne))	// Cas on rajoute des lignes
	{
		// Copie de la matrice initiale : on copie toute la matrice
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne));
			}
		}
		// Initialisation des nouvelles lignes : on ne g�re que les lignes rajouter (d�but de boucle en bas de la matrice)
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (int iBoucleIndiceLigne = uiMATNbLigne + 1; iBoucleIndiceLigne <= iNbLigne; iBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(iBoucleIndiceLigne, uiBoucleIndiceColonne, NULL);
			}
		}
	}
	else // Cas on enl�ve des lignes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de ligne que l'on veux dans le r�sultat
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (int iBoucleIndiceLigne = 1; iBoucleIndiceLigne <= iNbLigne; iBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(iBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(iBoucleIndiceLigne, uiBoucleIndiceColonne));
			}
		}
	}

	// Destruction de l'ancien tableau
	for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonne; uiBoucleIndiceColonne++)
	{
		if (*(ppMATMatrice + uiBoucleIndiceColonne) != NULL)
		{
			delete[] *(ppMATMatrice + uiBoucleIndiceColonne);
		}
	}
	delete[] ppMATMatrice;

	// R�cup�ration nouveau tableau
	ppMATMatrice = MATMatriceTempo->ppMATMatrice;
	MATMatriceTempo = NULL;

	// Mise � jour du nombre de ligne
	uiMATNbLigne = iNbLigne;
}


/*********************************************************
Modifie le nombre de colonne de la matrice
*********************************************************
Entr�e: int iNbColonne : le nouveau nombre de colonne de la matrice
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (uiMATNbColonne = iNbColonne) et
(les �l�ments des (uiMATNbColonne - iNbColonne) derni�res colonnes on �t� supprim�)
ou
(les �l�ments des (uiNbColonne - iMATNbColonne) colones on �t� rajout� � droite de la matrice)
ou
(Exception dimension_incorrecte lev�)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreColonne(int iNbColonne)
{
	// V�rification nouveau nombre de colonnes positif
	if (iNbColonne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	/* Cr�ation de la matrice avec le nouveau nombre de colonne */
		/// utilisation du constructeur prenant un nombre ligne et de colonne en param�tre
	CMatrice<MType> *MATMatriceTempo = new CMatrice(uiMATNbLigne,iNbColonne);

	if (iNbColonne > int(uiMATNbColonne))	// Cas on rajoute des colonnes
	{
		// Copie de la matrice initiale : on copie toute la matrice
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne));
			}
		}
		// Initialisation des nouvelles colonnes : on ne g�re que les colonnes rajouter (d�but de boucle � droite de la matrice)
		for (int iBoucleIndiceColonne = uiMATNbColonne + 1; iBoucleIndiceColonne <= iNbColonne; iBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, iBoucleIndiceColonne, NULL);

			}
		}
	}
	else // Cas on enl�ve des colonnes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de colonne que l'on veux dans le r�sultat
		for (int iBoucleIndiceColonne = 1; iBoucleIndiceColonne <= iNbColonne; iBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, iBoucleIndiceColonne, MATLireElement(uiBoucleIndiceLigne, iBoucleIndiceColonne));

			}
		}
	}

	// Destruction de l'ancien tableau
		///Ce bloc est utilis� par le destructeur pour la d�salocation du tableau d'une matrice
	for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonne; uiBoucleIndiceColonne++)
	{
		if (*(ppMATMatrice + uiBoucleIndiceColonne) != NULL)
		{
			delete[] *(ppMATMatrice + uiBoucleIndiceColonne);
		}
	}
	delete [] ppMATMatrice;

	// R�cup�ration nouveu tableau
	ppMATMatrice = MATMatriceTempo->ppMATMatrice;
	MATMatriceTempo = NULL;

	// Mise � jour du nombre nombre de colonne
	uiMATNbColonne = iNbColonne;
}

/*********************************************************
Modifie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entr�e: MType MTypeParam : le nouvelle �l�ment � mettre dans la matrice
int iIndiceLigne, iIndiceColonne : les indices de l'�l�ment � modifier
N�cessite: (la matrice doit �tre du m�me type que MTypeParam)
Sortie: (rien)
Entra�ne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(int iIndiceLigne, int iIndiceColonne, MType MTypeParam)
{
	// Test sur les indices pass�s en param�tre : l'�l�ment doit pouvoir �tre dans le tableau
	if (iIndiceLigne <= 0 || iIndiceLigne <= 0 || 
		iIndiceLigne > int(MATLireNombreLigne()) || iIndiceColonne > int(MATLireNombreColonne()))
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	*(*(ppMATMatrice + (iIndiceColonne - 1)) + (iIndiceLigne - 1)) = MTypeParam;
}

/*********************************************************
Calcul la transpos� de la matrice
*********************************************************
Entr�e: (rien)
N�cessite: (la matrice doit contenir des �l�ments)
Sortie: CMatrice<MType> : la tranpos� de la matrice
Entra�ne : (la matrice en sortie est la tranpos� de la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTranspose()
{
	// Cas matrice carr� : uiMATNbLigne == uiMATNbColonne
	if (MATLireNombreColonne() == MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreLigne(), MATLireNombreColonne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne < uiMATNbColonne
	else if (MATLireNombreColonne() > MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreColonne(), MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbLigne; uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbColonne; uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreColonne(), MATLireNombreLigne());
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbLigne ; uiBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbColonne; uiBoucleIndiceLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATLireElement(uiBoucleIndiceColonne, uiBoucleIndiceLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
}

/*********************************************************
Affiche la matrice dans la console
*********************************************************
Entr�e: (rien)
N�cessite: (la matrice doit contenir des �l�ments)
Sortie: (rien)
Entra�ne : (la matrice est affich� dans la console)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
	{
		std::cout << "| ";
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			// Affichage des �l�ments de la matrice
			std::cout << MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;

}

/*********************************************************
Surcharge de l'operateur = pour la classe CMatrice<MType>
prenant un MType en param�tre
*********************************************************
Entr�e: MType MTypeParam : la matrice � affecter
N�cessite: (Les matrices sont du m�me type)
Sortie: CMatrice<MType> : la matrice affecter � partir de MATMatrice en param�tre
Entra�ne : (MATMatrice est affecter � la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType>& MATMatrice)
{
	// Recopie des dimensions de MATMatrice en param�tre
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne());
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
	{
		for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
		{
			// Copie du contenu de MAtMatrice en param�tre
			MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne));
		}
	}

	return *this;
}

/*********************************************************
Surcharge de l'operateur + pour la classe CMatrice<MType>
prenant un CMatrice<MType> en param�tre
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � additionner
N�cessite: (Les matrices sont du m�me type)
Sortie: CMatrice<MType> : la somme des deux matrices
Entra�ne :(la matrice en sortie est la somme des deux matrices)
ou (Exception dim_matrice_diff lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{
	// V�rification faisabilit� somme
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne() || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

	// Allocation du r�sulat de l'addition : initialis� par recopie
	CMatrice<MType>* pMATMatriceSomme = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la somme : pour chaque �l�ment de la matrice
			pMATMatriceSomme->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) + MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceSomme;
}

/*********************************************************
Surcharge de l'operateur - pour la classe CMatrice<MType>
prenant un CMatrice<MType> en param�tre
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � soustraire
N�cessite: (Les matrices sont du m�me type)
Sortie: CMatrice<MType> : la diff�rence des deux matrices
Entra�ne : (la matrice en sortie est la diff�rence des deux matrices)
ou (Exception dim_matrice_diff lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType>& MATMatrice)
{
	// V�rification faisabilit� diff�rence
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne() || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

	// Allocation du r�sulat de la diff�rence : initialis� par recopie
	CMatrice<MType>* pMATMatriceDiff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la diff�rence : pour chaque �l�ment de la matrice
			pMATMatriceDiff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) - MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceDiff;
}

/*********************************************************
Surcharge de l'operateur * pour la classe CMatrice<MType>
prenant un CMatrice<MType> en param�tre : produit matricielle
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � multiplier
N�cessite: (Les matrices sont du m�me type)
Sortie: CMatrice<MType> : le produit des deux matrices
Entra�ne : (La matrice en sortie est le produit matricielle des deux matrices)
ou (Exception dimension_incorrecte est lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType>& MATMatrice)
{
	// V�rification faisabilit� produit matricielle
	if (MATMatrice.MATLireNombreLigne() != MATLireNombreColonne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Allocation du r�sulat du produit : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduit = new CMatrice<MType>(*this);
	pMATMatriceProduit->MATModifierNombreColonne(MATMatrice.MATLireNombreColonne());
	pMATMatriceProduit->MATModifierNombreLigne(MATLireNombreLigne());

	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= MATMatrice.uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit matricielle : pour chaque �l�ment de la matrice
			MType MTypeSomme = 0;
			for (unsigned int uiBoucleProduit = 1; uiBoucleProduit <= uiMATNbColonne; uiBoucleProduit++)
			{
				// On somme la uiBoucleProduit-i�me ligne de la premi�re matrice avec la uiBoucleProduit-i�me colonne de la matrice en param�tre
				MTypeSomme = MTypeSomme + MATLireElement(uiBoucleLigne, uiBoucleProduit) * MATMatrice.MATLireElement(uiBoucleProduit, uiBoucleColonne);
			}
			pMATMatriceProduit->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeSomme);
		}
	}
	return *pMATMatriceProduit;
}


/*********************************************************
Surcharge de l'operateur * pour la classe CMatrice<MType>
prenant un MType en param�tre
*********************************************************
Entr�e: MType MTypeParam : la constante multiplicative
N�cessite: (La matrice doit �tre du m�me type que MTypeParam)
Sortie: CMatrice<MType> : le produit de la matrice par MTypeParam
Entra�ne :(tous les �l�ments de la matrice en sortie sont multipli�s par MTypeParam)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const MType MTypeParam)
{
	// Allocation du r�sulat du produit : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit : pour chaque �l�ment de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeParam * MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceProduitCoeff;
}


/*********************************************************
Surcharge de l'operateur / pour la classe CMatrice<MType>
prenant un MType en param�tre
*********************************************************
Entr�e: MType MTypeParam : la constante dividende
N�cessite: (La matrice doit �tre du m�me type que MTypeParam)
Sortie: CMatrice<MType> : le quotient de la matrice par MTypeParam
Entra�ne : (tous les �l�ments de la matrice en sortie sont divis�s par MTypeParam)
ou (Exception diviseur_nul est lev�)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(const MType MTypeParam)
{
	// V�rification diviseur non nul
	if (MTypeParam == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(diviseur_nul);
		throw(EXCLevee);
	}

	// Allocation du r�sulat de la division : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la division : pour chaque �l�ment de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) / MTypeParam);
		}
	}
	return *pMATMatriceProduitCoeff;
}

/*********************************************************
Surcharge de l'operateur * prenant un MType en param�tre 
et une CMatrice<MType>
*********************************************************
Entr�e: MType MTypeParam : la constante multiplicative
CMatrice<MType> : la matrice � multiplier
N�cessite: (La matrice doit �tre du m�me type que MTypeParam)
Sortie: CMatrice<MType> : le produit de la matrice par MTypeParam
Entra�ne : (tous les �l�ments de la matrice en sortie sont multipli�s par MTypeParam)
*********************************************************/
template <class MType>
CMatrice<MType>& operator*(const MType MTypeParam, CMatrice<MType>& MATMatrice)
{
	// Allocation du r�sulat du produit : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(MATMatrice);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= MATMatrice.MATLireNombreColonne(); uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= MATMatrice.MATLireNombreLigne(); uiBoucleLigne++)
		{
			// Calcul du produit : pour chaque �l�ment de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeParam * MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceProduitCoeff;
}

#endif //MAT