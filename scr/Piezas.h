#include <ETSIDI.h>
#include <freeglut.h>

using ETSIDI::getTexture;

using ETSIDI::Sprite;

class Piezas
{
	// float Pos = -17.5; ¿porque no va? Poniendolo publico tmpc
	Sprite* tab = new Sprite("imagenes/Tablero.png", 0.0, 0.0, 40.0, 40.0);
	
	// PREGUNTAR SI SE HACE ASÍ
	/*
	bool color;
	bool seleccionado;
	int valor;
	int tipo;
	Sprite* Imagen;*/
public:
	void ImprimePiezas();
	float limite;
	
};
