#ifndef MAT
#define MAT 0

template <class MType> class CMatrice
{
private:
	unsigned int uiMATNbLigne;
	unsigned int uiMATNbColonne;
	<MType>** ppMATMatrice;		//maybe créer une sous classe cellule
public:
	CMatrice<MType>();
	CMatrice<MType>(CMatrice<MType>& MATMatrice);
	~CMatrice<MType>();

	unsigned int MATLireNombreLigne();
	unsigned int MATLireNombreColonne();
	<MType> MATLireElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne);

	MATModifierNombreLigne(unsigned int uiNbLigne);
	MATModifierNombreColonne(unsigned int uiNbColonne);
	MATModifierElement(unsigned int uiIndiceLigne, unsigned int uiIndiceColonne, <MType> Truc);

	void MATTranspose();
	void MATAfficherMatrice();

	&CMatrice<MType> operator+(CMatrice<MType>& MATMatrice);
	&CMatrice<MType> operator-(CMatrice<MType>& MATMatrice);
	&CMatrice<MType> operator*(CMatrice<MType>& MATMatrice);
	&CMatrice<MType> operator/(CMatrice<MType>& MATMatrice);

	&CMatrice<MType> operator*(<MType> truc);
	&CMatrice<MType> operator/(<MType> truc);
};

template <class MType>
CMatrice<MType>::CMatrice<MType>()
{

}

template <class MType>
CMatrice<MType>::CMatrice<MType>(CMatrice<MType>& MATMatrice)
{

}

template <class MType>
CMatrice<MType>::~CMatrice()
{

}
#endif //MAT