#ifndef PAR
#define PAR 0
#include <stdio.h>
#include "CMatrice.h"


class CParser
{
private:
	char* psPARNomFichier;

public:

	/*
		Contructeur par d�faut
		Initilaise Le nom du fichier � NULL
		Ne renvoie rien
	*/
	CParser();
	
	/*
		Constructeur de Recopie 
	*/
	CParser(CParser &PARParser);


	/*
		Destructeur
	*/
	~CParser();

	/*
		Lecture du nom du fichier, permet de tester si il est correcte
		Param�tre en entr�� : aucun
		Param�tre en sortie : Nom du fichier
		C'est un getter 
	*/
	char* PARLireNomFichier();

	/*
		modification du nom du fichier
		Param�tre en entr�e : sNomFichier --> Le nom du fichier
		Param�tre en sortie : Le nom du fichier modifi�
	*/
	void PARModifierNomFichier(char* sNomFichier);

	/*
		Lecture du fichier
		V�rification du typage
		V�rification Taille
		Stockage des infos essentiel dans un objet CMatrice
	*/
	template <class MType> CMatrice<MType> PARLireFichier();
};

/*
CParser::CParser()
{
	psPARNomFichier = NULL;
}


CParser::~CParser()
{
	delete psPARNomFichier;
}


char* CParser::PARLireNomFichier()
{
	if (psPARNomFichier == NULL)
	{
		CException EXCObjet;

	}
	else 
	{
		return psPARNomFichier;
	}
}


void CParser::PARModifierNomFichier(char* sNomFichier)
{

}


template <class MType>
CMatrice<MType> CParser::PARLireFichier()
{
	if (psPARNomFichier == NULL)
	{
		perror("pas de fichier trouv�");
		exit(EXIT_FAILURE);
	}
	FILE* fichier = NULL;
	// On ouvre notre fichier en mode lecture 
	fichier = fopen(psPARNomFichier, "r");
	if (fichier == NULL)
	{
		perror("fail");
		exit(EXIT_FAILURE);
	}
	
	//on veut r�cup�rer les lignes du fichier et les stocker dans une matrice CMatrice
	
	fscanf(fichier, %s, )
}

*/
#endif //PAR