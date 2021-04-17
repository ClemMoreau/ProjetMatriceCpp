#ifndef FIC
#define FIC 0

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdio.h>
#include "CMatrice.h"
#include "CException.h"

#define nom_null 301
#define mauvais_type 302
#define ouverture_fichier_impossible 303


using namespace std;

class CFichier
{
private:
					/*************
					* ATTRIBUTS *
					*************/

	/*Nom du fichier*/
	char* psFICNomFichier;

public:

					/*****************
					 * CONSTRUCTEURS *
					*****************/

	/*********************************************************
	Constructeur par défaut de la classe CFichier
	*********************************************************/
	CFichier();
	
	/*********************************************************
	Constructeur de recopie de la classe CFichier
	prenant en paramètre un CFichier
	*********************************************************/
	CFichier(CFichier &FICFichier);


					/***************
					* DESTRUCTEUR *
					***************/

	/*********************************************************
	Destructeur de la classe CFichier
	*********************************************************/
	~CFichier();

					/***********
					 * GETTERS *
					 ***********/

	/*********************************************************
	Renvoie le nom du fichier
	*********************************************************/
	char* FICLireNomFichier();

					/***********
					* SETTERS *
					***********/

	/*********************************************************
	Modifie le nom du fichier
	*********************************************************/
	void FICModifierNomFichier(const char* sNomFichier);

					/************
					* METHODES *
					************/

	/*********************************************************
	Lecture du fichier et extraction des informations dans le fichier
	*********************************************************/
	CMatrice<double>& FICLireFichier();
};

#endif //FIC