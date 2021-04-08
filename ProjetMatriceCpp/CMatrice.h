#ifndef MAT
#define MAT 0
#include <stdio.h>
#include "CException.h"

#define matrice_param_null 100
#define dimension_incorrecte 101
#define dim_matrice_diff 103

template <class MType> class CMatrice
{
private:
	/*Nombre de lignes de la matrice : 1 <= uiMATNbLigne*/
	unsigned int uiMATNbLigne; 

	/*Nombre de colonnes de la matrice*/
	unsigned int uiMATNbColonne;

	/*
	* Contenu de la matrice : [1;uiMATNbLigne]x[1;uiMATNbColonne]
	* Il faut donc utiliser les indices mathématiques d'une matrice 
	* et non les indices d'un tableau en C 
	* (la colonne/ligne 0 n'existe pas dans nos matrice sauf durant l'initialisation)
	*/
	MType **ppMATMatrice;

public:
	/*CONSTRUCTEURS*/

	/*********************************************************
	Constructeur par défaut de la classe CMatrice
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: (rien)
	Entraîne :	L'objet est initialisé avec uiMATNbLigne = 0
	uiMATNbColonne = 0 et **ppMATMatrice = NULL
	*********************************************************/
	CMatrice<MType>();

	/*********************************************************
	Constructeur de recopie de la classe CMatrice 
	prenant en paramètre un CMatrice<MType> 
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à recopier
	Nécessite:	CMatrice<MType>& MATMatrice dois être initialisé
	Sortie: (rien)
	Entraîne :	L'objet est initialisé à partir des attributs
	de MATMatrice en paramètre
	*********************************************************/
	CMatrice<MType>(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Constructeur de recopie de la classe CMatrice
	prenant en paramètre le nombre de ligne et de colonne
	de la matrice à créer
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à recopier
	Nécessite:	CMatrice<MType>& MATMatrice dois être initialisé
	Sortie: (rien)
	Entraîne :	L'objet initialisé est une matrice 
	de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialisé par le compilateur
	*********************************************************/
	CMatrice<MType>(int uiNbLigne, int uiNbColonne);

	/*DESTRUCTEUR*/

	/*********************************************************
	Destructeur de la classe CMatrice
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: (rien)
	Entraîne :	L'objet est prêt à être détruit, 
	les derniers traitements sont réalisé
	*********************************************************/
	~CMatrice<MType>();

	/*GETTERS*/

	/*********************************************************
	Renvoie le nombre de ligne de la matrice
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
	Entraîne :	(rien)
	*********************************************************/
	unsigned int MATLireNombreLigne();

	/*********************************************************
	Renvoie le nombre de colonne de la matrice
	*********************************************************
	Entrée: (rien)
	Nécessite:	(rien)
	Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
	Entraîne :	(rien)
	*********************************************************/
	unsigned int MATLireNombreColonne();

	/*********************************************************
	Renvoie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entrée: (rien)
	Nécessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
	Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) : à compléter
	Entraîne :	uiMATNbColonne = nombre de colonne de la matrice
	*********************************************************/
	MType MATLireElement(int uiIndiceLigne, int uiIndiceColonne);

	/*SETTERS*/

	/*********************************************************
	Modifie le nombre de ligne de la matrice
	*********************************************************
	Entrée: unsigned int uiNbLigne : le nouveau nombre de ligne de la matrice
	Nécessite:	(rien)
	Sortie: (rien)
	Entraîne :	(uiMATNbLigne = uiNbLigne) et
	(les éléments des (uiMATNbLigne - uiNbLigne) dernières lignes on été supprimé)
	ou
	(les éléments des (uiNbLigne - uiMATNbLigne) lignes on été rajouté en fin de la matrice)
	*********************************************************/
	void MATModifierNombreLigne(int uiNbLigne);

	/*********************************************************
	Modifie le nombre de colonne de la matrice
	*********************************************************
	Entrée: unsigned int uiNbColonne : le nouveau nombre de colonne de la matrice
	Nécessite: (rien)
	Sortie: (rien)
	Entraîne : (uiMATNbColonne = uiNbColonne) et
	(les éléments des (uiMATNbColonne - uiNbColonne) dernières colonnes on été supprimé)
	ou
	(les éléments des (uiNbColonne - uiMATNbColonne) colones on été rajouté en fin de la matrice)
	*********************************************************/
	void MATModifierNombreColonne(int uiNbColonne);

	/*********************************************************
	Modifie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entrée: MType MTypeParam : le nouvelle élément à mettre dans la matrice
	Nécessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
	Sortie: (rien)
	Entraîne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
	*********************************************************/
	void MATModifierElement(int uiIndiceLigne, int uiIndiceColonne, MType MTypeParam);

	/*METHODES*/

	/*********************************************************
	Calcul la transposé de la matrice
	*********************************************************
	Entrée: (rien)
	Nécessite: la matrice doit contenir des éléments
	Sortie: CMatrice<MType> : la tranposé de la matrice
	Entraîne : (rien)
	*********************************************************/
	CMatrice<MType>& MATTranspose();

	/*********************************************************
	Affiche la matrice dans la console
	*********************************************************
	Entrée: (rien)
	Nécessite: la matrice doit contenir des éléments
	Sortie: (rien)
	Entraîne : (la matrice est affiché dans la console)
	*********************************************************/
	void MATAfficherMatrice();

	/*SURCHARGES*/

	/*********************************************************
	Surcharge de l'operateur + pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à additionner 
	Nécessite: Les deux matrices ont les mêmes dimensions 
	Sortie: CMatrice<MType> MATMatrice : la somme des deux matrices
	Entraîne : 
	*********************************************************/
	CMatrice<MType>& operator+(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur - pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à soustraire
	Nécessite: Les deux matrices ont les mêmes dimensions
	Sortie: CMatrice<MType> MATMatrice : la différence des deux matrices
	Entraîne :
	*********************************************************/
	CMatrice<MType>& operator-(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à multiplier
	Nécessite: Le nombre de colonne de la matrice appelante dois être égale au nombre de colonne de la matrice en paramètre
	Sortie: CMatrice<MType> MATMatrice : le produit des deux matrices
	Entraîne :
	*********************************************************/
	CMatrice<MType>& operator*(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un MType en paramètre
	*********************************************************
	Entrée: MType MTypeParam : la constante multiplicative
	Nécessite: La matrice doit être du même type que MTypeParam
	Sortie: CMatrice<MType> MATMatrice : le produit de la matrice pour MTypeParam
	Entraîne :
	*********************************************************/
	CMatrice<MType>& operator*(MType MTypeParam);

	/*********************************************************
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un MType en paramètre
	*********************************************************
	Entrée: MType MTypeParam : la constante dividende
	Nécessite: La matrice doit être du même type que MTypeParam
	Sortie: CMatrice<MType> MATMatrice : le quotient de la matrice pour MTypeParam
	Entraîne :
	*********************************************************/
	CMatrice<MType>& operator/(MType MTypeParam);
};

/*********************************************************
Constructeur par défaut de la classe CMatrice
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec uiMATNbLigne = 0
uiMATNbColonne = 0 et **ppMATMatrice = NULL
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice()
{
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	ppMATMatrice = NULL;	//voir pour passer par une méthode
}

/*********************************************************
Constructeur de recopie de la classe CMatrice
prenant en paramètre un CMatrice<MType>
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à recopier
Nécessite:	CMatrice<MType>& MATMatrice dois être initialisé
Sortie: (rien)
Entraîne :	L'objet est initialisé à partir des attributs
	de MATMatrice en paramètre
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MATMatrice)
{
	// Recopie des dimensions de la matrice
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne()); 
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	// Création du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 1; uiIndiceBoucleColonne <= uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		// Création des lignes de la matrice
		*(ppMATMatrice + uiIndiceBoucleColonne - 1) = new MType[uiMATNbLigne];
		for (unsigned int uiIndiceBoucleLigne = 1; uiIndiceBoucleLigne <= uiMATNbLigne; uiIndiceBoucleLigne++)
		{
			// Copie du contenu de MAtMatrice en paramètre
			MATModifierElement(uiIndiceBoucleLigne, uiIndiceBoucleColonne, MATMatrice.MATLireElement(uiIndiceBoucleLigne, uiIndiceBoucleColonne));
		}
	}
}

/*********************************************************
Constructeur de recopie de la classe CMatrice
prenant en paramètre le nombre de ligne et de colonne
de la matrice à créer
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à recopier
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet initialisé est une matrice
de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialisé par le compilateur
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(int uiNbLigne, int uiNbColonne)
{
	// Le nombre de ligne/colonne doit être positif
	if (uiNbLigne < 0 || uiNbColonne < 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Création du tableau des colonnes de la matrice
	ppMATMatrice = new MType*[uiNbColonne];
	for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		// Création des lignes de la matrice
		*(ppMATMatrice + uiIndiceBoucleColonne) = new MType[uiNbLigne];
	}

	// Mise à jour du nombre de ligne et de colonne de la matrice
	uiMATNbColonne = uiNbColonne;
	uiMATNbLigne = uiNbLigne;
}

/*********************************************************
Destructeur de la classe CMatrice
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est prêt à être détruit,
les derniers traitements sont réalisé
*********************************************************/
template <class MType>
CMatrice<MType>::~CMatrice()
{
	// Mise à jour du nombre de ligne et de colonne de la matrice
		/// La suppression du contenu de la matrice est géré par les setters sur les lignes/colonnes
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	
	// Destruction des colonnes de la matrice
	delete ppMATMatrice;

}

/*********************************************************
Renvoie le nombre de ligne de la matrice
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
Entraîne :	(rien)
*********************************************************/
template <class MType>
unsigned int CMatrice<MType>::MATLireNombreLigne()
{
	return uiMATNbLigne;
}

/*********************************************************
Renvoie le nombre de colonne de la matrice
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
Entraîne :	(rien)
*********************************************************/
template <class MType>
unsigned int CMatrice<MType>::MATLireNombreColonne()
{
	return uiMATNbColonne;
}

/*********************************************************
Renvoie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entrée: (rien)
Nécessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) :
l'élément ligne uiIndiceColonne 
Entraîne :	(retourne l'élément) ou (exception levé pour dimension incorrecte)
*********************************************************/
template <class MType>
 MType CMatrice<MType>::MATLireElement(int uiIndiceLigne, int uiIndiceColonne)
{ 
	 if (uiIndiceLigne < 0 || uiIndiceColonne < 0
		 ||(unsigned) uiIndiceLigne > MATLireNombreLigne() || (unsigned int) uiIndiceColonne > MATLireNombreColonne())
	 {
		 CException EXCObjet;
		 EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		 throw(EXCObjet);
	 }


	 return *(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1));
}

template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(int uiNbLigne)
{
	// uiNbLigne doit être positif
	if (uiNbLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	//création tempo
	MType** ppMTypeTempo = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMTypeTempo + uiIndiceBoucleColonne) = new MType[uiNbLigne];
	}

	if ((unsigned int)uiNbLigne > uiMATNbLigne)	//si on rajoute des lignes
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
			for (int uiIndiceBoucleLigne = uiMATNbLigne; uiIndiceBoucleLigne < uiNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}
	}
	else //si on enlève des lignes
	{
		//copie tempo
		for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
		{
			for ( int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
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
	ppMATMatrice = ppMTypeTempo;
	ppMTypeTempo = NULL;
	uiMATNbLigne = uiNbLigne;
}

template <class MType>	/*revoir l'algo*/
void CMatrice<MType>::MATModifierNombreColonne(int uiNbColonne)
{
	// uiNbColonne doit être positif
	if (uiNbColonne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	//création tempo
	MType** ppMTypeTempo = new MType*[uiNbColonne];
	for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMTypeTempo + uiIndiceBoucleColonne) = new MType[MATLireNombreLigne()];
	}


	if ((unsigned int)uiNbColonne > uiMATNbColonne)	//si on rajoute des colonnes
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
		for (int uiIndiceBoucleColonne = uiMATNbColonne; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = NULL;
			}
		}
	}
	else //si on enlève des colonnes
	{
		//copie tempo
		for (int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
		{
			for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
			{
				*(*(ppMTypeTempo + uiIndiceBoucleColonne) + uiIndiceBoucleLigne) = *(*(ppMATMatrice + uiIndiceBoucleColonne) + uiIndiceBoucleLigne);
			}
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
	ppMATMatrice = ppMTypeTempo;
	ppMTypeTempo = NULL;
	uiMATNbColonne = uiNbColonne;
}

/*********************************************************
Modifie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entrée: MType MTypeParam : le nouvelle élément à mettre dans la matrice
Nécessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
Sortie: (rien)
Entraîne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(int uiIndiceLigne, int uiIndiceColonne, MType MTypeParam)
{
	if ((unsigned int)uiIndiceLigne > MATLireNombreLigne() || (unsigned int)uiIndiceColonne > MATLireNombreColonne()
		|| uiIndiceLigne < 0 || uiIndiceLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	*(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1)) = MTypeParam;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTranspose()	//faire un switch plus jolie
{
	// Cas matrice carré : uiMATNbLigne == uiMATNbColonne
	if (MATLireNombreColonne() == MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
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
	// Cas matrice non carré : uiMATNbLigne < uiMATNbColonne
	else if (MATLireNombreColonne() > MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
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
	// Cas matrice non carré : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Création de la transposé de la matrice
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
			try 
			{
				std::cout << MATLireElement(uiBoucleNbLigne + 1, uiBoucleNbColonne + 1) << " ";
			}
			catch (CException EXCLevee)
			{
				std::cout << "? ";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

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
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

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
	if (MATMatrice.MATLireNombreLigne() != MATLireNombreColonne)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}
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