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
		Contructeur par défaut
		Initilaise Le nom du fichier à NULL
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
		Paramètre en entréé : aucun
		Paramètre en sortie : Nom du fichier
		C'est un getter 
	*/
	char* PARLireNomFichier();

	/*
		modification du nom du fichier
		Paramètre en entrée : sNomFichier --> Le nom du fichier
		Paramètre en sortie : Le nom du fichier modifié
	*/
	void PARModifierNomFichier(char* sNomFichier);

	/*
		Lecture du fichier
		Vérification du typage
		Vérification Taille
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
		perror("pas de fichier trouvé");
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
	
	//on veut récupérer les lignes du fichier et les stocker dans une matrice CMatrice
	
	fscanf(fichier, %s, )
}

*/
#endif //PAR