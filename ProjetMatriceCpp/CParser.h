#ifndef PAR
#define PAR 0

#include <stdio.h>
#include "CMatrice.h"
#include "CException.h"
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

class CParser
{
private:

					/*************
					* ATTRIBUTS *
					*************/

	/*Nom du fichier*/
	char* psPARNomFichier;

public:


					/*****************
					 * CONSTRUCTEURS *
					*****************/

	/*********************************************************
	Constructeur par défaut de la classe CParser
	*********************************************************/
	CParser();
	
	/*********************************************************
	Constructeur de recopie de la classe CParser
	prenant en paramètre un CParser
	*********************************************************/
	CParser(CParser &PARParser);


	/*********************************************************
	Destructeur de la classe CParser
	*********************************************************/
	~CParser();

						/***********
						 * GETTERS *
						 ***********/

	/*********************************************************
	Renvoie le nom du fichier
	*********************************************************/
	char* PARLireNomFichier();

						/***********
						* SETTERS *
						***********/

	/*********************************************************
	Modifie le nom du fichier
	*********************************************************/
	void PARModifierNomFichier(const char* sNomFichier);

						/************
						* METHODES *
						************/

	/*********************************************************
	Lecture du fichier et extraction des informations dans le fichier
	*********************************************************/
	CMatrice<double>& PARLireFichier();
};

#endif //PAR