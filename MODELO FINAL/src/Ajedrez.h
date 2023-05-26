#include <MenuInicial.h>
#include <Tablero.h>
#include <ColorRGB.h>
#include <ETSIDI.h>
using ETSIDI::Sprite;

class Ajedrez
{
	MenuInicial menu;
	Tablero tablero;


	Vector origen;
	Vector destino;

	Sprite* Blancas = new Sprite("imagenes/GANAN_BLANCAS.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* Negras = new Sprite("imagenes/GANAN_NEGRAS.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* Tablas = new Sprite("imagenes/tablas.png", 4.0, 4.0, 4.0, 4.0);
	Sprite* Inicio = new Sprite("imagenes/inicio.png", 4.0, 4.0, 4.0, 4.0);


public:
	Ajedrez();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);

	//DIBUJA
	void dibujaMenu();
	void dibujaB();
	void dibujaN();

	void dibujaPartida();
	void dibujaPausa();
	void dibujaTablas();
	void dibujaInicio();


	void Raton(int button, int state, int x, int y);
	bool JaqueMate();
	Pieza* devuelvePieza(Vector origen);

};
