#ifndef MAT
#define MAT 0
#include <stdio.h>
#include "CException.h"

#define matrice_param_null 100
#define dimension_incorrecte 101
#define type_different 102

template <class MType> class CMatrice
{
private:
	/*Nombre de lignes de la matrice : 1 <= uiMATNbLigne*/
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
	CMatrice<MType>(unsigned int uiNbLigne, unsigned int uiNbColonne);

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
	MType MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

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
	void MATModifierNombreLigne(unsigned int uiNbLigne);

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
	void MATModifierNombreColonne(unsigned int uiNbColonne);

	/*********************************************************
	Modifie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entr�e: MType MTypeParam : le nouvelle �l�ment � mettre dans la matrice
	N�cessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
	Sortie: (rien)
	Entra�ne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
	*********************************************************/
	void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTypeParam);

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
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en param�tre
	*********************************************************
	Entr�e: CMatrice<MType>& MATMatrice : la matrice � diviser
	N�cessite: Le nombre de colonne de la matrice appelante dois �tre �gale au nombre de colonne de la matrice en param�tre
	Sortie: CMatrice<MType> MATMatrice : le quotient des deux matrices
	Entra�ne :
	*********************************************************/
	CMatrice<MType>& operator/(CMatrice<MType>& MATMatrice);

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
	Entra�ne :
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
N�cessite:	CMatrice<MType>& MATMatrice dois �tre initialis�
Sortie: (rien)
Entra�ne :	L'objet est initialis� � partir des attributs
	de MATMatrice en param�tre
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MATMatrice)
{
	/*if (MATMatrice == NULL)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(matrice_param_null);
		throw(EXCObjet);
	}*/
	// recopie des dimensions de la matrice
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne()); 
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	// Cr�ation du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 1; uiIndiceBoucleColonne <= uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		// Cr�ation des lignes de la matrice
		*(ppMATMatrice + uiIndiceBoucleColonne - 1) = new MType[uiMATNbLigne];
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
N�cessite:	CMatrice<MType>& MATMatrice dois �tre initialis�
Sortie: (rien)
Entra�ne :	L'objet initialis� est une matrice
de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialis� par le compilateur
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(unsigned int uiNbLigne, unsigned int uiNbColonne)
{
	// Cr�ation du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[uiNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		// Cr�ation des lignes de la matrice
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

	///CE BLOC DEVIENT INUTILE A CAUSE DES SETTERS
	/*for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < MATLireNombreColonne(); uiIndiceBoucleColonne++)
	{
		if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
		{
			// Destruction des lignes de la matrice
			delete *(ppMATMatrice + uiIndiceBoucleColonne);
		}
	}*/
	// Mise � jour du nombre de ligne et de colonne de la matrice
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	
	// Destruction des colonnes de la matrice
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
l'�l�ment ligne uiIndiceColonne 
Entra�ne :	(retourne l'�l�ment) ou (exception lev� pour dimension incorrecte)
*********************************************************/
template <class MType>
 MType CMatrice<MType>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{ 
	 if (uiIndiceLigne > MATLireNombreLigne() || uiIndiceColonne > MATLireNombreColonne())
	 {
		 CException EXCObjet;
		 EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		 throw(EXCObjet);
	 }
	 return *(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1));
}

template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(unsigned int uiNbLigne)
{
	//cr�ation tempo
	MType** ppMTypeTempo = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMTypeTempo + uiIndiceBoucleColonne) = new MType[uiNbLigne];
	}

	if (uiNbLigne > uiMATNbLigne)	//si on rajoute des lignes
	{
		//copie tempo
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		//initialisation nouvelles lignes
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = uiMATNbLigne; uiIndiceBoucleLigne < uiNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}

		//destruction ancien tableau
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
			{
				delete *(ppMATMatrice + uiIndiceBoucleColonne);
			}
		}
		delete ppMATMatrice;
	}
	else //si on enl�ve des lignes
	{
		//copie tempo
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		//destruction ancien tableau
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
			{
				delete *(ppMATMatrice + uiIndiceBoucleColonne);
			}
		}
		delete ppMATMatrice;
	}
	ppMATMatrice = ppMTypeTempo;
	ppMTypeTempo = NULL;
	uiMATNbLigne = uiNbLigne;
}

template <class MType>	/*revoir l'algo*/
void CMatrice<MType>::MATModifierNombreColonne(unsigned int uiNbColonne)
{
	//cr�ation tempo
	MType** ppMTypeTempo = new MType*[uiNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMTypeTempo + uiIndiceBoucleColonne) = new MType[MATLireNombreLigne()];
	}


	if (uiNbColonne > uiMATNbColonne)	//si on rajoute des colonnes
	{
		//copie tempo
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		//initialisation nouvelles colonnes
		for (unsigned int uiIndiceBoucleColonne = uiMATNbColonne; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}

		//destruction ancien tableau
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
			{
				delete *(ppMATMatrice + uiIndiceBoucleColonne);
			}
		}
		delete ppMATMatrice;
	}
	else //si on enl�ve des colonnes
	{
		//copie tempo
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
		}
		//destruction ancien tableau
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
			{
				delete *(ppMATMatrice + uiIndiceBoucleColonne);
			}
		}
		delete ppMATMatrice;
	}
	ppMATMatrice = ppMTypeTempo;
	ppMTypeTempo = NULL;
	uiMATNbColonne = uiNbColonne;
}

/*********************************************************
Modifie l'�l�ment ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entr�e: MType MTypeParam : le nouvelle �l�ment � mettre dans la matrice
N�cessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
Sortie: (rien)
Entra�ne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTypeParam)
{
	if (uiIndiceLigne > MATLireNombreLigne() || uiIndiceColonne > MATLireNombreColonne())
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	/*if (typeof(this->**ppMATMatrice) != typeof(MTypeParam))
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(type_different);
		throw(EXCObjet);
	}*/
	*(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1)) = MTypeParam;
}

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

template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	std::cout << "Nombre de colonne de la matrice : " << MATLireNombreColonne() << std::endl;
	std::cout << "Nombre de ligne de la matrice : " << MATLireNombreLigne() << std::endl;

	for (unsigned int uiBoucleNbLigne = 0; uiBoucleNbLigne < MATLireNombreLigne(); uiBoucleNbLigne++)
	{
		std::cout << "| ";
		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < MATLireNombreColonne(); uiBoucleNbColonne++)
		{
			std::cout << MATLireElement(uiBoucleNbLigne + 1, uiBoucleNbColonne + 1) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{
	CMatrice<MType>* pMATMatriceSomme = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			pMATMatriceSomme->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) + MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceSomme;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType>& MATMatrice)
{
	CMatrice<MType>* pMATMatriceDiff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			pMATMatriceDiff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) - MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceDiff;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType>& MATMatrice)
{
	CMatrice<MType>* pMATMatriceProduit = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
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

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(MType MTypeParam)
{
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne + 1, uiBoucleColonne + 1, MTypeParam * MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1));
		}
	}
	return *pMATMatriceProduitCoeff;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(MType MTypeParam)
{
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne + 1, uiBoucleColonne + 1, MATLireElement(uiBoucleLigne + 1, uiBoucleColonne + 1) / MTypeParam);
		}
	}
	return *pMATMatriceProduitCoeff;
}


#endif //MAT