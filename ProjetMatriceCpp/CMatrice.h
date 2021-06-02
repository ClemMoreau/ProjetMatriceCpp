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
	///Il faut utiliser les indices mathématiques d'une matrice et non les indices d'un tableau en C 
	MType **ppMATMatrice;

public:
					/*****************
					 * CONSTRUCTEURS *
					 *****************/
	 
	/*********************************************************
	Constructeur par défaut de la classe CMatrice
	*********************************************************/
	CMatrice<MType>();

	/*********************************************************
	Constructeur de recopie de la classe CMatrice 
	prenant en paramètre un CMatrice<MType> 
	*********************************************************/
	CMatrice<MType>(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Constructeur de recopie de la classe CMatrice
	prenant en paramètre le nombre de ligne et de colonne
	de la matrice à créer
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
	Renvoie l'élément ligne iIndiceLigne et colonne iIndiceColonne
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
	Modifie l'élément ligne iIndiceLigne et colonne iIndiceColonne
	*********************************************************/
	void MATModifierElement(int iIndiceLigne, int iIndiceColonne, MType MTypeParam);

					   /************
						* METHODES *
						************/

	/*********************************************************
	Calcul la transposé de la matrice
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
	prenant un MType en paramètre
	*********************************************************/
	CMatrice<MType>& operator=(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur + pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre : addtition matricielle
	*********************************************************/
	CMatrice<MType>& operator+(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur - pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre : soustraction matricielle
	*********************************************************/
	CMatrice<MType>& operator-(CMatrice<MType>& MATMatrice);

	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un CMatrice<MType> en paramètre : produit matricielle
	*********************************************************/
	CMatrice<MType>& operator*(CMatrice<MType>& MATMatrice);


	/*********************************************************
	Surcharge de l'operateur * pour la classe CMatrice<MType>
	prenant un MType en paramètre : multiplication par constante
	*********************************************************/
	CMatrice<MType>& operator*(const MType MTypeParam);

	/*********************************************************
	Surcharge de l'operateur / pour la classe CMatrice<MType>
	prenant un MType en paramètre : division par constante
	*********************************************************/
	CMatrice<MType>& operator/(const MType MTypeParam);

};

/*********************************************************
Constructeur par défaut de la classe CMatrice
*********************************************************
Entrée: (rien)
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet est initialisé avec uiMATNbLigne = 0
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
prenant en paramètre un CMatrice<MType>
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à recopier
Nécessite:	CMatrice<MType>& MATMatrice doit être initialisé
Sortie: (rien)
Entraîne : L'objet est initialisé à partir des attributs
de MATMatrice en paramètre
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(CMatrice<MType>& MATMatrice)
{
	// Recopie des dimensions de MATMatrice en paramètre
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne()); 
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	for (unsigned int uiIndiceBoucleColonne = 1; uiIndiceBoucleColonne <= uiMATNbColonne; uiIndiceBoucleColonne++)
	{
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
Entrée: int iNbLigne, int iNbColonne : les dimensions de la nouvelle matrice
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	L'objet initialisé est une matrice
de taille (uiMATNbLigne x uiNbColonne) dont le contenu est initialisé par le compilateur
*********************************************************/
template <class MType>
CMatrice<MType>::CMatrice(int iNbLigne, int iNbColonne)
{
	// Test du nombre de colonne et de ligne passé en paramètre
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

	// Mise à jour du nombre de ligne et de colonne de la matrice
	uiMATNbColonne = iNbColonne;
	uiMATNbLigne = iNbLigne;
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
		/// La suppression du contenu de la matrice est géré par les setters sur les lignes/colonnes ci-dessous
	MATModifierNombreColonne(0);
	MATModifierNombreLigne(0);
	
	// Destruction du tableau de colonnes de la matrice
	delete[] ppMATMatrice ;

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
Entrée: int iIndiceLigne, int iIndiceColonne : les indices de l'élément à retourner
Nécessite:	(rien)
Sortie: <MType> *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) :
l'élément ligne uiIndiceLigne et colonne uiIndiceColonne 
Entraîne :	(retourne l'élément) ou (exception levé pour dimension incorrecte)
*********************************************************/
template <class MType>
 MType CMatrice<MType>::MATLireElement(int iIndiceLigne, int iIndiceColonne)
{ 
	 // Vérification indices en paramètre
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
Entrée: int iNbLigne : le nouveau nombre de ligne de la matrice
Nécessite:	(rien)
Sortie: (rien)
Entraîne :	(uiMATNbLigne = iNbLigne) et
(les éléments des (uiMATNbLigne - iNbLigne) dernières lignes on été supprimé)
ou
(les éléments des (iNbLigne - uiMATNbLigne) lignes on été rajouté en bas de la matrice)
ou
(Exception dimension_incorrecte levé)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(int iNbLigne)
{
	// Vérification nouveau nombre de colonnes positif
	if (iNbLigne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}
	
	/* Création de la matrice avec le nouveau nombre de ligne */
		/// utilisation du constructeur prenant un nombre ligne et de colonne en paramètre
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
		// Initialisation des nouvelles lignes : on ne gère que les lignes rajouter (début de boucle en bas de la matrice)
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			for (int iBoucleIndiceLigne = uiMATNbLigne + 1; iBoucleIndiceLigne <= iNbLigne; iBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(iBoucleIndiceLigne, uiBoucleIndiceColonne, NULL);
			}
		}
	}
	else // Cas on enlève des lignes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de ligne que l'on veux dans le résultat
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

	// Récupération nouveau tableau
	ppMATMatrice = MATMatriceTempo->ppMATMatrice;
	MATMatriceTempo = NULL;

	// Mise à jour du nombre de ligne
	uiMATNbLigne = iNbLigne;
}


/*********************************************************
Modifie le nombre de colonne de la matrice
*********************************************************
Entrée: int iNbColonne : le nouveau nombre de colonne de la matrice
Nécessite: (rien)
Sortie: (rien)
Entraîne : (uiMATNbColonne = iNbColonne) et
(les éléments des (uiMATNbColonne - iNbColonne) dernières colonnes on été supprimé)
ou
(les éléments des (uiNbColonne - iMATNbColonne) colones on été rajouté à droite de la matrice)
ou
(Exception dimension_incorrecte levé)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierNombreColonne(int iNbColonne)
{
	// Vérification nouveau nombre de colonnes positif
	if (iNbColonne < 0)
	{
		CException EXCObjet;
		EXCObjet.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCObjet);
	}

	/* Création de la matrice avec le nouveau nombre de colonne */
		/// utilisation du constructeur prenant un nombre ligne et de colonne en paramètre
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
		// Initialisation des nouvelles colonnes : on ne gère que les colonnes rajouter (début de boucle à droite de la matrice)
		for (int iBoucleIndiceColonne = uiMATNbColonne + 1; iBoucleIndiceColonne <= iNbColonne; iBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, iBoucleIndiceColonne, NULL);

			}
		}
	}
	else // Cas on enlève des colonnes
	{
		// Copie de la matrice initiale : on ne copie que le nombre de colonne que l'on veux dans le résultat
		for (int iBoucleIndiceColonne = 1; iBoucleIndiceColonne <= iNbColonne; iBoucleIndiceColonne++)
		{
			for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
			{
				MATMatriceTempo->MATModifierElement(uiBoucleIndiceLigne, iBoucleIndiceColonne, MATLireElement(uiBoucleIndiceLigne, iBoucleIndiceColonne));

			}
		}
	}

	// Destruction de l'ancien tableau
		///Ce bloc est utilisé par le destructeur pour la désalocation du tableau d'une matrice
	for (unsigned int uiBoucleIndiceColonne = 0; uiBoucleIndiceColonne < uiMATNbColonne; uiBoucleIndiceColonne++)
	{
		if (*(ppMATMatrice + uiBoucleIndiceColonne) != NULL)
		{
			delete[] *(ppMATMatrice + uiBoucleIndiceColonne);
		}
	}
	delete [] ppMATMatrice;

	// Récupération nouveu tableau
	ppMATMatrice = MATMatriceTempo->ppMATMatrice;
	MATMatriceTempo = NULL;

	// Mise à jour du nombre nombre de colonne
	uiMATNbColonne = iNbColonne;
}

/*********************************************************
Modifie l'élément ligne uiIndiceLigne et colonne uiIndiceColonne
*********************************************************
Entrée: MType MTypeParam : le nouvelle élément à mettre dans la matrice
int iIndiceLigne, iIndiceColonne : les indices de l'élément à modifier
Nécessite: (la matrice doit être du même type que MTypeParam)
Sortie: (rien)
Entraîne : *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne) = MTypeParam
*********************************************************/
template <class MType>
void CMatrice<MType>::MATModifierElement(int iIndiceLigne, int iIndiceColonne, MType MTypeParam)
{
	// Test sur les indices passés en paramètre : l'élément doit pouvoir être dans le tableau
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
Calcul la transposé de la matrice
*********************************************************
Entrée: (rien)
Nécessite: (la matrice doit contenir des éléments)
Sortie: CMatrice<MType> : la tranposé de la matrice
Entraîne : (la matrice en sortie est la tranposé de la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::MATTranspose()
{
	// Cas matrice carré : uiMATNbLigne == uiMATNbColonne
	if (MATLireNombreColonne() == MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
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
	// Cas matrice non carré : uiMATNbLigne < uiMATNbColonne
	else if (MATLireNombreColonne() > MATLireNombreLigne())
	{
		// Création de la transposé de la matrice
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
	// Cas matrice non carré : uiMATNbLigne > uiMATNbColonne
	else
	{
		// Création de la transposé de la matrice
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
Entrée: (rien)
Nécessite: (la matrice doit contenir des éléments)
Sortie: (rien)
Entraîne : (la matrice est affiché dans la console)
*********************************************************/
template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
	{
		std::cout << "| ";
		for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
		{
			// Affichage des éléments de la matrice
			std::cout << MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl << std::endl;

}

/*********************************************************
Surcharge de l'operateur = pour la classe CMatrice<MType>
prenant un MType en paramètre
*********************************************************
Entrée: MType MTypeParam : la matrice à affecter
Nécessite: (Les matrices sont du même type)
Sortie: CMatrice<MType> : la matrice affecter à partir de MATMatrice en paramètre
Entraîne : (MATMatrice est affecter à la matrice sur laquelle on travaille)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator=(CMatrice<MType>& MATMatrice)
{
	// Recopie des dimensions de MATMatrice en paramètre
	MATModifierNombreColonne(MATMatrice.MATLireNombreColonne());
	MATModifierNombreLigne(MATMatrice.MATLireNombreLigne());

	for (unsigned int uiBoucleIndiceColonne = 1; uiBoucleIndiceColonne <= uiMATNbColonne; uiBoucleIndiceColonne++)
	{
		for (unsigned int uiBoucleIndiceLigne = 1; uiBoucleIndiceLigne <= uiMATNbLigne; uiBoucleIndiceLigne++)
		{
			// Copie du contenu de MAtMatrice en paramètre
			MATModifierElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne, MATMatrice.MATLireElement(uiBoucleIndiceLigne, uiBoucleIndiceColonne));
		}
	}

	return *this;
}

/*********************************************************
Surcharge de l'operateur + pour la classe CMatrice<MType>
prenant un CMatrice<MType> en paramètre
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à additionner
Nécessite: (Les matrices sont du même type)
Sortie: CMatrice<MType> : la somme des deux matrices
Entraîne :(la matrice en sortie est la somme des deux matrices)
ou (Exception dim_matrice_diff levé)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{
	// Vérification faisabilité somme
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne() || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

	// Allocation du résulat de l'addition : initialisé par recopie
	CMatrice<MType>* pMATMatriceSomme = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la somme : pour chaque élément de la matrice
			pMATMatriceSomme->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) + MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceSomme;
}

/*********************************************************
Surcharge de l'operateur - pour la classe CMatrice<MType>
prenant un CMatrice<MType> en paramètre
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à soustraire
Nécessite: (Les matrices sont du même type)
Sortie: CMatrice<MType> : la différence des deux matrices
Entraîne : (la matrice en sortie est la différence des deux matrices)
ou (Exception dim_matrice_diff levé)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType>& MATMatrice)
{
	// Vérification faisabilité différence
	if (MATMatrice.MATLireNombreColonne() != MATLireNombreColonne() || MATMatrice.MATLireNombreLigne() != MATLireNombreLigne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dim_matrice_diff);
		throw(EXCLevee);
	}

	// Allocation du résulat de la différence : initialisé par recopie
	CMatrice<MType>* pMATMatriceDiff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la différence : pour chaque élément de la matrice
			pMATMatriceDiff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) - MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceDiff;
}

/*********************************************************
Surcharge de l'operateur * pour la classe CMatrice<MType>
prenant un CMatrice<MType> en paramètre : produit matricielle
*********************************************************
Entrée: CMatrice<MType>& MATMatrice : la matrice à multiplier
Nécessite: (Les matrices sont du même type)
Sortie: CMatrice<MType> : le produit des deux matrices
Entraîne : (La matrice en sortie est le produit matricielle des deux matrices)
ou (Exception dimension_incorrecte est levé)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType>& MATMatrice)
{
	// Vérification faisabilité produit matricielle
	if (MATMatrice.MATLireNombreLigne() != MATLireNombreColonne())
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(dimension_incorrecte);
		throw(EXCLevee);
	}

	// Allocation du résulat du produit : initialisé par recopie
	CMatrice<MType>* pMATMatriceProduit = new CMatrice<MType>(*this);
	pMATMatriceProduit->MATModifierNombreColonne(MATMatrice.MATLireNombreColonne());
	pMATMatriceProduit->MATModifierNombreLigne(MATLireNombreLigne());

	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= MATMatrice.uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit matricielle : pour chaque élément de la matrice
			MType MTypeSomme = 0;
			for (unsigned int uiBoucleProduit = 1; uiBoucleProduit <= uiMATNbColonne; uiBoucleProduit++)
			{
				// On somme la uiBoucleProduit-ième ligne de la première matrice avec la uiBoucleProduit-iéme colonne de la matrice en paramètre
				MTypeSomme = MTypeSomme + MATLireElement(uiBoucleLigne, uiBoucleProduit) * MATMatrice.MATLireElement(uiBoucleProduit, uiBoucleColonne);
			}
			pMATMatriceProduit->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeSomme);
		}
	}
	return *pMATMatriceProduit;
}


/*********************************************************
Surcharge de l'operateur * pour la classe CMatrice<MType>
prenant un MType en paramètre
*********************************************************
Entrée: MType MTypeParam : la constante multiplicative
Nécessite: (La matrice doit être du même type que MTypeParam)
Sortie: CMatrice<MType> : le produit de la matrice par MTypeParam
Entraîne :(tous les éléments de la matrice en sortie sont multipliés par MTypeParam)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(const MType MTypeParam)
{
	// Allocation du résulat du produit : initialisé par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul du produit : pour chaque élément de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeParam * MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceProduitCoeff;
}


/*********************************************************
Surcharge de l'operateur / pour la classe CMatrice<MType>
prenant un MType en paramètre
*********************************************************
Entrée: MType MTypeParam : la constante dividende
Nécessite: (La matrice doit être du même type que MTypeParam)
Sortie: CMatrice<MType> : le quotient de la matrice par MTypeParam
Entraîne : (tous les éléments de la matrice en sortie sont divisés par MTypeParam)
ou (Exception diviseur_nul est levé)
*********************************************************/
template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(const MType MTypeParam)
{
	// Vérification diviseur non nul
	if (MTypeParam == 0)
	{
		CException EXCLevee;
		EXCLevee.EXCmodifier_valeur(diviseur_nul);
		throw(EXCLevee);
	}

	// Allocation du résulat de la division : initialisé par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(*this);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= uiMATNbColonne; uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= uiMATNbLigne; uiBoucleLigne++)
		{
			// Calcul de la division : pour chaque élément de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MATLireElement(uiBoucleLigne, uiBoucleColonne) / MTypeParam);
		}
	}
	return *pMATMatriceProduitCoeff;
}

/*********************************************************
Surcharge de l'operateur * prenant un MType en paramètre 
et une CMatrice<MType>
*********************************************************
Entrée: MType MTypeParam : la constante multiplicative
CMatrice<MType> : la matrice à multiplier
Nécessite: (La matrice doit être du même type que MTypeParam)
Sortie: CMatrice<MType> : le produit de la matrice par MTypeParam
Entraîne : (tous les éléments de la matrice en sortie sont multipliés par MTypeParam)
*********************************************************/
template <class MType>
CMatrice<MType>& operator*(const MType MTypeParam, CMatrice<MType>& MATMatrice)
{
	// Allocation du résulat du produit : initialisé par recopie
	CMatrice<MType>* pMATMatriceProduitCoeff = new CMatrice<MType>(MATMatrice);
	for (unsigned int uiBoucleColonne = 1; uiBoucleColonne <= MATMatrice.MATLireNombreColonne(); uiBoucleColonne++)
	{
		for (unsigned int uiBoucleLigne = 1; uiBoucleLigne <= MATMatrice.MATLireNombreLigne(); uiBoucleLigne++)
		{
			// Calcul du produit : pour chaque élément de la matrice
			pMATMatriceProduitCoeff->MATModifierElement(uiBoucleLigne, uiBoucleColonne, MTypeParam * MATMatrice.MATLireElement(uiBoucleLigne, uiBoucleColonne));
		}
	}
	return *pMATMatriceProduitCoeff;
}

#endif //MAT