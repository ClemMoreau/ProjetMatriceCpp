#ifndef MAT
#define MAT 0
#include <stdio.h>

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbLigne;
	unsigned int uiMATNbColonne;
	MType **ppMATMatrice;		//maybe créer une sous classe cellule
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
	Entraîne :	L'objet est initialisé avec uiMATNbLigne = MATMatrice.uiMATNbLigne 
	MATMatrice.uiMATNbColonne = 0 et MATMatrice.**ppMATMatrice = NULL
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
	Entraîne :	L'objet est initialisé avec uiMATNbLigne = MATMatrice.uiMATNbLigne
	MATMatrice.uiMATNbColonne = 0 et MATMatrice.**ppMATMatrice = NULL
	*********************************************************/
	CMatrice<MType>(unsigned int uiNbColonne, unsigned int uiNbLigne);

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
	Nécessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
	Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
	Entraîne :	uiMATNbLigne = nombre de ligne de la matrice
	*********************************************************/
	unsigned int MATLireNombreLigne();

	/*********************************************************
	Renvoie le nombre de colonne de la matrice
	*********************************************************
	Entrée: (rien)
	Nécessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
	Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
	Entraîne :	uiMATNbColonne = nombre de colonne de la matrice
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
	MType MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

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
	void MATModifierNombreLigne(unsigned int uiNbLigne);

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
	void MATModifierNombreColonne(unsigned int uiNbColonne);

	/*********************************************************
	Modifie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
	*********************************************************
	Entrée: MType MTypeParam : le nouvelle élément à mettre dans la matrice
	Nécessite: (uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pré ou post condition (perso je pref post)
	Sortie: (rien)
	Entraîne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
	*********************************************************/
	void MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTypeParam);

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
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre
	*********************************************************
	Entrée: CMatrice<MType>& MATMatrice : la matrice à diviser
	Nécessite: Le nombre de colonne de la matrice appelante dois être égale au nombre de colonne de la matrice en paramètre
	Sortie: CMatrice<MType> MATMatrice : le quotient des deux matrices
	Entraîne :
	*********************************************************/
	CMatrice<MType>& operator/(CMatrice<MType>& MATMatrice);

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

template <class MType>
CMatrice<MType>::CMatrice()
{
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;
	ppMATMatrice = NULL;
}

template <class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MATMatrice)
{
	uiMATNbColonne = MATMatrice.MATLireNombreColonne();
	uiMATNbLigne = MATMatrice.MATLireNombreLigne();
	ppMATMatrice = new MType*[uiMATNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMATMatrice + uiIndiceBoucleColonne) = new MType[uiMATNbLigne];
		for (unsigned int uiIndiceBoucleLigne = 0; uiIndiceBoucleLigne < uiMATNbLigne; uiIndiceBoucleLigne++)
		{
			MATModifierElement(uiIndiceBoucleLigne + 1, uiIndiceBoucleColonne + 1, MATMatrice.MATLireElement(uiIndiceBoucleLigne + 1, uiIndiceBoucleColonne + 1));
		}
	}
}
template <class MType>
CMatrice<MType>::CMatrice(unsigned int uiNbColonne, unsigned int uiNbLigne)
{
	ppMATMatrice = new MType*[uiNbColonne];
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMATMatrice + uiIndiceBoucleColonne) = new MType[uiNbLigne];
	}
	uiMATNbColonne = uiNbColonne;
	uiMATNbLigne = uiNbLigne;
}

template <class MType>
CMatrice<MType>::~CMatrice()
{
	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		if (*(ppMATMatrice + uiIndiceBoucleColonne) != NULL)
		{
			delete *(ppMATMatrice + uiIndiceBoucleColonne);
		}
	}
	delete ppMATMatrice;
	uiMATNbColonne = 0;
	uiMATNbLigne = 0;
}

template <class MType>
unsigned int CMatrice<MType>::MATLireNombreLigne()
{
	return uiMATNbLigne;
}

template <class MType>
unsigned int CMatrice<MType>::MATLireNombreColonne()
{
	return uiMATNbColonne;
}

template <class MType>
 MType CMatrice<MType>::MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne)
{ 
	 return *(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1));
}

template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(unsigned int uiNbLigne)
{
	//création tempo
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
	else //si on enlève des lignes
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
	//création tempo
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
	else //si on enlève des colonnes
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

template <class MType>
void CMatrice<MType>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTypeParam)
{
	*(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1)) = MTypeParam;
}

template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTranspose()
{
	CMatrice<MType>* pMATMatriceTranspose = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 0; uiBoucleColonne < uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 0; uiBoucleLigne < uiMATNbLigne; uiBoucleLigne++)
		{
			pMATMatriceTranspose->MATModifierElement(uiBoucleLigne + 1,  uiBoucleColonne + 1, MATLireElement(uiBoucleColonne + 1, uiBoucleLigne + 1));
		}
	}
	return *pMATMatriceTranspose;
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