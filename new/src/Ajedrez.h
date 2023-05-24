#include <MenuInicial.h>
#include <Tablero.h>
#include <ColorRGB.h>

class Ajedrez
{
	MenuInicial menu;
	Tablero tablero;

	float x_ojo;
	float y_ojo;
	float z_ojo;

	Vector origen;
	Vector destino;

public: 

	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void dibuja();
	void inicializa();
	void Raton(int button, int state, int x, int y);
	bool JaqueMate();

};
