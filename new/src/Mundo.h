#include <MenuInicial.h>
#include <Tablero.h>
#include <Color.h>

class Mundo
{
	MenuInicial menu;
	Tablero tablero;

	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 
	
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void dibuja();
	void inicializa();
	void Raton(int button, int state, int x, int y);
};
