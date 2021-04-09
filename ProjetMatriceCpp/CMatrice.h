#ifndef MAT
#define MAT 0
#include <stdio.h>
#include "CException.h"

#define dimension_incorrecte 101
#define dim_matrice_diff 103
#define diviseur_nul 104

template <class MType> class CMatrice
{
private:
	/*Nombre de lignes de la matrice */
	unsigned int uiMATNbLigne; 

	/*Nombre de colonnes de la matrice*/
	unsigned int uiMATNbColonne;

	/*
	* Contenu de la matrice : [1;uiMATNbLigne]x[1;uiMATNbColonne]
	* Il faut donc utiliser les indices math�matiques d'une matrice 
	* et non les indices d'un tableau en C 
	* (la colonne/ligne 0 n'existe pas dans nos matrice sauf durant l'initialisation)
	*/
	MType **ppMATMatrice;

public:
	/*CONSTRUCTEURS*/

	/*********************************************************
	Constructeur par d�faut de la classe CMatrice
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: (rien)
	Entra�ne :	L'objet est initialis� avec uiMATNbLigne = 0
	uiMATNbColonne = 0 et **ppMATMatrice = NULL
	*********************************************************/
	CMatrice<MType>();

	/*********************************************************
	Constructeur de recopie de la classe CMatrice 
	prenant en param�tre un CMatrice<MType> 
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � recopier
	N�cessite:	CMatrice<MType>& MATMatrice dois �tre initialis�
	Sortie: (rien)
	Entra�ne :	L'objet est initialis� � partir des attributs
	de MATMatrice en param�tre
	*********************************************************/
	CMatrice<MType>(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Constructeur de recopie de la classe CMatrice
	prenant en param�tre le nombre de ligne et de colonne
	de la matrice � cr�er
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � recopier
	N�cessite:	CMatrice<MType>& MATMatrice dois �tre initialis�
	Sortie: (rien)
	Entra�ne :	L'objet initialis� est une matrice 
	de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialis� par le compilateur
	*********************************************************/
	CMatrice<MType>(int uiNbLigne, int uiNbColonne);

	/*DESTRUCTEUR*/

	/*********************************************************
	Destructeur de la classe CMatrice
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: (rien)
	Entra�ne :	L'objet est pr�t � �tre d�truit, 
	les derniers traitements sont r�alis�
	*********************************************************/
	~CMatrice<MType>();

	/*GETTERS*/

	/*********************************************************
	Renvoie le nombre de ligne de la matrice
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
	Entra�ne :	(rien)
	*********************************************************/
	unsigned int MATLireNombreLigne();

	/*********************************************************
	Renvoie le nombre de colonne de la matrice
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(rien)
	Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
	Entra�ne :	(rien)
	*********************************************************/
	unsigned int MATLireNombreColonne();

	/*********************************************************
	Renvoie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
	Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) : � compl�ter
	Entra�ne :	uiMATNbColonne = nombre de colonne de la matrice
	*********************************************************/
	MType MATLireElement(int uiIndiceLigne, int uiIndiceColonne);

	/*SETTERS*/

	/*********************************************************
	Modifie le nombre de ligne de la matrice
	*********************************************************
	Entr�e: unsigned int uiNbLigne : le nouveau nombre de ligne de la matrice
	N�cessite:	(rien)
	Sortie: (rien)
	Entra�ne :	(uiMATNbLigne = uiNbLigne) et
	(les �l�ments des (uiMATNbLigne - uiNbLigne) derni�res lignes on �t� supprim�)
	ou
	(les �l�ments des (uiNbLigne - uiMATNbLigne) lignes on �t� rajout� en fin de la matrice)
	*********************************************************/
	void MATModifierNombreLigne(int uiNbLigne);

	/*********************************************************
	Modifie le nombre de colonne de la matrice
	*********************************************************
	Entr�e: unsigned int uiNbColonne : le nouveau nombre de colonne de la matrice
	N�cessite: (rien)
	Sortie: (rien)
	Entra�ne : (uiMATNbColonne = uiNbColonne) et
	(les �l�ments des (uiMATNbColonne - uiNbColonne) derni�res colonnes on �t� supprim�)
	ou
	(les �l�ments des (uiNbColonne - uiMATNbColonne) colones on �t� rajout� en fin de la matrice)
	*********************************************************/
	void MATModifierNombreColonne(int uiNbColonne);

	/*********************************************************
	Modifie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entr�e: MType MTypeParam : le nouvelle �l�ment � mettre dans la matrice
	N�cessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
	Sortie: (rien)
	Entra�ne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
	*********************************************************/
	void MATModifierElement(int uiIndiceLigne, int uiIndiceColonne, MType MTypeParam);

	/*METHODES*/

	/*********************************************************
	Calcul la transpos� de la matrice
	*********************************************************
	Entr�e: (rien)
	N�cessite: la matrice doit contenir des �l�ments
	Sortie: CMatrice<MType> : la tranpos� de la matrice
	Entra�ne : (rien)
	*********************************************************/
	CMatrice<MType>& MATTranspose();

	/*********************************************************
	Affiche la matrice dans la console
	*********************************************************
	Entr�e: (rien)
	N�cessite: la matrice doit contenir des �l�ments
	Sortie: (rien)
	Entra�ne : (la matrice est affich� dans la console)
	*********************************************************/
	void MATAfficherMatrice();

	/*SURCHARGES*/

	/*********************************************************
	Surcharge de l'operateur = pour la classe CMatrice<MType>
	prenant un MType en param�tre
	*********************************************************
	Entr�e: MType MTypeParam : la matrice � recopier
	N�cessite: Les matrices doivent �tre du m�me type
	Sortie: CMatrice<MType> : la matrice recopier � partir de MATMatrice en param�tre
	Entra�ne : this = MATMatrice
	*********************************************************/
	CMatrice<MType>& operator=(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur + pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � additionner 
	N�cessite: Les deux matrices ont les m�mes dimensions 
	Sortie: CMatrice<MType> MATMatrice : la somme des deux matrices
	Entra�ne : 
	*********************************************************/
	CMatrice<MType>& operator+(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur - pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � soustraire
	N�cessite: Les deux matrices ont les m�mes dimensions
	Sortie: CMatrice<MType> MATMatrice : la diff�rence des deux matrices
	Entra�ne :
	*********************************************************/
	CMatrice<MType>& operator-(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � multiplier
	N�cessite: Le nombre de colonne de la matrice appelante dois �tre �gale au nombre de colonne de la matrice en param�tre
	Sortie: CMatrice<MType> MATMatrice : le produit des deux matrices
	Entra�ne :
	*********************************************************/
	CMatrice<MType>& operator*(CMatrice<MType>& MATMatrice);


	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un MType en param�tre
	*********************************************************
	Entr�e: MType MTypeParam : la constante multiplicative
	N�cessite: La matrice doit �tre du m�me type que MTypeParam
	Sortie: CMatrice<MType> MATMatrice : le produit de la matrice pour MTypeParam
	Entra�ne :
	*********************************************************/
	CMatrice<MType>& operator*(MType MTypeParam);

	/*********************************************************
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un MType en param�tre
	*********************************************************
	Entr�e: MType MTypeParam : la constante dividende
	N�cessite: La matrice doit �tre du m�me type que MTypeParam
	Sortie: CMatrice<MType> MATMatrice : le quotient de la matrice pour MTypeParam
	Entra�ne : (tous les �l�ments de la matrice en sortie sont divis� par MTypeParam)
	ou (Levee l'exception diviseur_nul
	*********************************************************/
	CMatrice<MType>& operator/(MType MTypeParam);

};

/*********************************************************
Constructeur par d�faut de la classe CMatrice
*********************************************************
Entr�e: (rien)
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet est initialis� avec uiMATNbLigne = 0
uiMATNbColonne = 0 et **ppMATMatrice = NULL
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice()
{
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	ppMATMatrice = NULL;	//voir pour passer par une m�thode
}

/*********************************************************
Constructeur de recopie de la classe CMatrice
prenant en param�tre un CMatrice<MType>
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � recopier
N�cessite:	CMatrice<MType>& MATMatrice doit �tre initialis�
Sortie: (rien)
Entra�ne :	L'objet est initialis� � partir des attributs
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
Entr�e: CMatrice<MType>& MATMatrice : la matrice � recopier
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	L'objet initialis� est une matrice
de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialis� par le compilateur
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(int uiNbLigne, int uiNbColonne)
{
	// Test du nombre de colonne et de ligne pass� en param�tre
	if (uiNbLigne < 0 || uiNbColonne < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Allocation du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[uiNbColonne];
	for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		// Allocation des lignes de la matrice
		*(ppMATMatrice + uiIndiceBoucleColonne) = new MType[uiNbLigne];
	}

	// Mise � jour du nombre de ligne et de colonne de la matrice
	uiMATNbColonne = uiNbColonne;
	uiMATNbLigne = uiNbLigne;
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
	delete ppMATMatrice;

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
Entr�e: (rien)
N�cessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) :
l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne 
Entra�ne :	(retourne l'�l�ment) ou (exception lev� pour dimension incorrecte)
*********************************************************/
template <class MType>
 MType CMatrice<MType>::MATLireElement(int uiIndiceLigne, int uiIndiceColonne)
{ 
	 // Test sur les indices pass�s en param�tre
	 if (uiIndiceLigne < 0 || uiIndiceColonne < 0 || (unsigned) uiIndiceLigne > MATLireNombreLigne() || (unsigned int) uiIndiceColonne > MATLireNombreColonne())
	 {
		 CException EXCObjet;
		 EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		 throw(EXCObjet);
	 }

	 return *(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1));
}

/*********************************************************
Modifie le nombre de ligne de la matrice
*********************************************************
Entr�e: unsigned int uiNbLigne : le nouveau nombre de ligne de la matrice
N�cessite:	(rien)
Sortie: (rien)
Entra�ne :	(uiMATNbLigne = uiNbLigne) et
(les �l�ments des (uiMATNbLigne - uiNbLigne) derni�res lignes on �t� supprim�)
ou
(les �l�ments des (uiNbLigne - uiMATNbLigne) lignes on �t� rajout� en bas de la matrice)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(int iNbLigne)
{
	// Test sur le nombre de ligne pass� en param�tre
	if (iNbLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	/* Cr�ation de la matrice avec le nouveau nombre de ligne */
	
	// Allocation du tableau de colonne de la matrice
	MType** ppMTypeMatriceTempo = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		// Allocation des lignes de la matrice
		*(ppMTypeMatriceTempo + uiIndiceBoucleColonne) = new MType[iNbLigne];
	}

	if ((unsigned int)iNbLigne > uiMATNbLigne)	// Cas on rajoute des lignes
	{
		// Copie de la matrice initiale : on copie toute la matrice
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeMatriceTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		// Initialisation des nouvelles lignes : on ne g�re que les lignes rajouter (d�but de boucle en bas de la matrice)
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (int uiIndiceBoucleLigne = uiMATNbLigne; uiIndiceBoucleLigne < iNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeMatriceTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}
	}
	else // Cas on enl�ve des lignes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de ligne que l'on veux dans le r�sultat
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for ( int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < iNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeMatriceTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
	}

	// Destruction de l'ancien tableau
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
		{
			delete [] *(ppMATMatrice + uiIndiceBoucleColonne);
		}
	}
	delete[] ppMATMatrice;

	ppMATMatrice = ppMTypeMatriceTempo;
	ppMTypeMatriceTempo = NULL;
	uiMATNbLigne = iNbLigne;
}


/*********************************************************
Modifie le nombre de colonne de la matrice
*********************************************************
Entr�e: unsigned int uiNbColonne : le nouveau nombre de colonne de la matrice
N�cessite: (rien)
Sortie: (rien)
Entra�ne : (uiMATNbColonne = uiNbColonne) et
(les �l�ments des (uiMATNbColonne - uiNbColonne) derni�res colonnes on �t� supprim�)
ou
(les �l�ments des (uiNbColonne - uiMATNbColonne) colones on �t� rajout� � droite de la matrice)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreColonne(int uiNbColonne)
{
	// Test sur le nombre de colonne pass� en param�tre
	if (uiNbColonne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	/* Cr�ation de la matrice avec le nouveau nombre de colonne */

	// Allocation du tableau de colonne de la matrice
	MType** ppMTypeTempo = new MType*[uiNbColonne];
	for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMTypeTempo + uiIndiceBoucleColonne) = new MType[MATLireNombreLigne()];
	}


	if ((unsigned int)uiNbColonne > uiMATNbColonne)	// Cas on rajoute des colonnes
	{
		// Copie de la matrice initiale : on copie toute la matrice
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		// Initialisation des nouvelles colonnes : on ne g�re que les colonnes rajouter (d�but de boucle � droite de la matrice)
		for (int uiIndiceBoucleColonne = uiMATNbColonne; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}
	}
	else // Cas on enl�ve des colonnes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de colonne que l'on veux dans le r�sultat
		for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
	}

	// Destruction de l'ancien tableau
		///Ce bloc est utilis� par le destructeur pour la d�salocation du tableau d'une matrice
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
		{
			delete [] *(ppMATMatrice + uiIndiceBoucleColonne);
		}
	}
	delete [] ppMATMatrice;
	ppMATMatrice = ppMTypeTempo;
	ppMTypeTempo = NULL;
	uiMATNbColonne = uiNbColonne;
}

/*********************************************************
Modifie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entr�e: MType MTypeParam : le nouvelle �l�ment � mettre dans la matrice
N�cessite: (rien)
Sortie: (rien)
Entra�ne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(int uiIndiceLigne, int uiIndiceColonne, MType MTypeParam)
{
	// Test sur les indices pass�s en param�tre : l'�l�ment doit pouvoir �tre dans le tableau
	if ((unsigned int)uiIndiceLigne > MATLireNombreLigne() || (unsigned int)uiIndiceColonne > MATLireNombreColonne()
		|| uiIndiceLigne < 0 || uiIndiceLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	*(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1)) = MTypeParam;
}

/*********************************************************
Calcul la transpos� de la matrice
*********************************************************
Entr�e: (rien)
N�cessite: la matrice doit contenir des �l�ments
Sortie: CMatrice<MType> : la tranpos� de la matrice
Entra�ne : (rien)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTranspose()
{
	// Cas matrice carr� : uiMATNbLigne == uiMATNbColonne
	if (MATLireNombreColonne() == MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreLigne(), MATLireNombreColonne());
		for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
		{
			for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleLigne,  uiBoucleColonne, MATLireElement(uiBoucleColonne, uiBoucleLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne < uiMATNbColonne
	else if (MATLireNombreColonne() > MATLireNombreLigne())
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreColonne(), MATLireNombreLigne());
		for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbLigne; uiBoucleColonne++)
		{
			for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbColonne; uiBoucleLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleColonne, uiBoucleLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
	// Cas matrice non carr� : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Cr�ation de la transpos� de la matrice
		CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(MATLireNombreColonne(), MATLireNombreLigne());
		for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbLigne ; uiBoucleColonne++)
		{
			for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbColonne; uiBoucleLigne++)
			{
				// Inversion des colonnes et des lignes
				pMATMatriceTranspose->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleColonne, uiBoucleLigne));
			}
		}
		return *pMATMatriceTranspose;
	}
}

/*********************************************************
Affiche la matrice dans la console
*********************************************************
Entr�e: (rien)
N�cessite: la matrice doit contenir des �l�ments
Sortie: (rien)
Entra�ne : (la matrice est affich� dans la console)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	// Affichage des dimensions de la matrice
	std::cout << "Nombre de colonne de la matrice : " << MATLireNombreColonne() << std::endl;
	std::cout << "Nombre de ligne de la matrice : " << MATLireNombreLigne() << std::endl;

	for (unsigned int uiBoucleNbLigne = 0; uiBoucleNbLigne < MATLireNombreLigne(); uiBoucleNbLigne++)
	{
		std::cout << "| ";
		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < MATLireNombreColonne(); uiBoucleNbColonne++)
		{
			// Affichage des �l�ments de la matrice
			std::cout << MATLireElement(uiBoucleNbLigne + 1, uiBoucleNbColonne + 1) << " ";		
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;

}

/*********************************************************
Surcharge de l'operateur = pour la classe CMatrice<MType>
prenant un MType en param�tre
*********************************************************
Entr�e: MType MTypeParam : la matrice � recopier
N�cessite: Les matrices doivent �tre du m�me type
Sortie: CMatrice<MType> : la matrice recopier � partir de MATMatrice en param�tre
Entra�ne : this = MATMatrice
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
N�cessite: Les deux matrices ont les m�mes dimensions
Sortie: CMatrice<MType> MATMatrice : la somme des deux matrices
Entra�ne :
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{
	// Test des dimensions des matrices
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
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
N�cessite: Les deux matrices ont les m�mes dimensions
Sortie: CMatrice<MType> MATMatrice : la diff�rence des deux matrices
Entra�ne :
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType>& MATMatrice)
{
	// Test des dimensions des matrices
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
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
prenant un CMatrice<MType> en param�tre
*********************************************************
Entr�e: CMatrice<MType>& MATMatrice : la matrice � multiplier
N�cessite: Le nombre de colonne de la matrice appelante dois �tre �gale au nombre de colonne de la matrice en param�tre
Sortie: CMatrice<MType> MATMatrice : le produit des deux matrices
Entra�ne :
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType>& MATMatrice)
{
	// Test des dimensions des matrices
	if (MATMatrice.MATLireNombreLigne() != MATLireNombreColonne)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Allocation du r�sulat du produit : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduit = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit matricielle : pour chaque �l�ment de la matrice
			MType MTypeSomme = 0;
			for (unsigned int uiBoucleProduit = 1; uiBoucleProduit <= uiMATNbColonne; uiBoucleProduit++)
			{
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
N�cessite: La matrice doit �tre du m�me type que MTypeParam
Sortie: CMatrice<MType> MATMatrice : le produit de la matrice pour MTypeParam
Entra�ne :
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(MType MTypeParam)
{
	// Allocation du r�sulat du produit : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit : pour chaque �l�ment de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne + 1, uiBoucleColonne + 1, MTypeParam * MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1));
		}
	}
	return *pMATMatriceProduitCoeff;
}

/*********************************************************
Surcharge de l'operateur / pour la classe CMatrice<MType>
prenant un MType en param�tre
*********************************************************
Entr�e: MType MTypeParam : la constante dividende
N�cessite: La matrice doit �tre du m�me type que MTypeParam
Sortie: CMatrice<MType> MATMatrice : le quotient de la matrice pour MTypeParam
Entra�ne : (tous les �l�ments de la matrice en sortie sont divis� par MTypeParam)
ou (Levee l'exception diviseur_nul
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(MType MTypeParam)
{
	// Divison par 0 interdis
	if (MTypeParam == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(diviseur_nul);
		throw(EXCLevee);
	}

	// Allocation du r�sulat de la division : initialis� par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la division : pour chaque �l�ment de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne + 1, uiBoucleColonne + 1, MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1) / MTypeParam);
		}
	}
	return *pMATMatriceProduitCoeff;
}


#endif //MAT