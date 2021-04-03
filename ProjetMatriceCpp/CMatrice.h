#ifndef MAT
#define MAT 0
#include <stdio.h>

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbLigne;
	unsigned int uiMATNbColonne;
	MType **ppMATMatrice;		//maybe cr�er une sous classe cellule
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
	Entra�ne :	L'objet est initialis� avec uiMATNbLigne = MATMatrice.uiMATNbLigne 
	MATMatrice.uiMATNbColonne = 0 et MATMatrice.**ppMATMatrice = NULL
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
	Entra�ne :	L'objet est initialis� avec uiMATNbLigne = MATMatrice.uiMATNbLigne
	MATMatrice.uiMATNbColonne = 0 et MATMatrice.**ppMATMatrice = NULL
	*********************************************************/
	CMatrice<MType>(unsigned int uiNbColonne, unsigned int uiNbLigne);

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
	N�cessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
	Sortie: unsigned int uiMATNbLigne : le nombre de ligne de la matrice
	Entra�ne :	uiMATNbLigne = nombre de ligne de la matrice
	*********************************************************/
	unsigned int MATLireNombreLigne();

	/*********************************************************
	Renvoie le nombre de colonne de la matrice
	*********************************************************
	Entr�e: (rien)
	N�cessite:	(uiIndiceColonne <= uiMATNbColonne) et (uiIndiceLigne <= uiMATNbLigne)				//voir si pr� ou post condition (perso je pref post)
	Sortie: unsigned int uiMATNbColonne : le nombre de colonne de la matrice
	Entra�ne :	uiMATNbColonne = nombre de colonne de la matrice
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
	CMatrice<MType> MATTranspose();

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

	for (unsigned int uiIndiceBoucleColonne = 0; uiIndiceBoucleColonne < uiMATNbColonne; uiIndiceBoucleColonne++)
	{
		*(ppMATMatrice + uiIndiceBoucleColonne) = new MType[uiMATNbLigne];
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
	 return *(*(ppMATMatrice + uiIndiceColonne) + uiIndiceLigne);
}

template <class MType>
void CMatrice<MType>::MATModifierNombreLigne(unsigned int uiNbLigne)
{
	if (uiMATNbLigne < uiNbLigne)
	{

	}
	uiMATNbLigne = uiNbLigne;
}

template <class MType>
void CMatrice<MType>::MATModifierNombreColonne(unsigned int uiNbColonne)
{
	/*if (uiMATNbColonne < uiNbColonne)
	{
		MType **tempo = NULL;
		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < uiNbColonne; uiBoucleNbColonne++)
		{
			*(tempo + uiBoucleNbColonne) = new MType[uiNbColonne];
		}

		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < uiMATNbColonne; uiBoucleNbColonne++)
		{
			for (unsigned int uiBoucleNbLigne = 0; uiBoucleNbLigne < uiMATNbLigne; uiBoucleNbLigne++)
			{
				*(*(tempo + uiBoucleNbColonne) + uiBoucleNbLigne) = *(*(ppMATMatrice + uiBoucleNbColonne) + uiBoucleNbLigne);
			}
		}
		for (unsigned int uiBoucleNbColonne = uiMATNbColonne; uiBoucleNbColonne < uiNbColonne; uiBoucleNbColonne++)
		{
			for (unsigned int uiBoucleNbLigne = 0; uiBoucleNbLigne < uiMATNbLigne; uiBoucleNbLigne++)
			{
				*(*(tempo + uiBoucleNbColonne) + uiBoucleNbLigne) = (MType)0 ;
			}
		}
		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < uiMATNbColonne; uiBoucleNbColonne++)
		{
			delete *(ppMATMatrice + uiBoucleNbColonne);
		}
		
		ppMATMatrice = tempo;
	}*/
	uiMATNbColonne = uiNbColonne;
}

template <class MType>
void CMatrice<MType>::MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, MType MTypeParam)
{
	*(*(ppMATMatrice + (uiIndiceColonne - 1)) + (uiIndiceLigne - 1)) = MTypeParam;
}

template <class MType>
CMatrice<MType> CMatrice<MType>::MATTranspose()
{

}

template <class MType>
void CMatrice<MType>::MATAfficherMatrice()
{
	std::cout << "Nombre de colonne de la matrice : " << MATLireNombreColonne() << std::endl;
	std::cout << "Nombre de ligne de la matrice : " << MATLireNombreLigne() << std::endl;
//	std::cout << "Type de la matrice : " << MType;

	for (unsigned int uiBoucleNbLigne = 0; uiBoucleNbLigne < MATLireNombreLigne(); uiBoucleNbLigne++)
	{
		for (unsigned int uiBoucleNbColonne = 0; uiBoucleNbColonne < MATLireNombreColonne(); uiBoucleNbColonne++)
		{
			std::cout << MATLireElement(uiBoucleNbLigne, uiBoucleNbColonne) << " ";
		}
		std::cout << std::endl;
	}

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator+(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator-(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator*(MType MTypeParam)
{

}

template <class MType>
CMatrice<MType>& CMatrice<MType>::operator/(MType MTypeParam)
{

}
#endif //MAT