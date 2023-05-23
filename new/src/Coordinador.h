#pragma once
#include <Ajedrez.h>

//TENEMOS QUE METER TODO ESTO EN PRINCIPAL EN VEZ DE AJEDREZ


class Coordinador
{

public:
	Coordinador() { estado = INICIO; };
	virtual ~Coordinador() {};

	//void mueve();
	//nose si haria falta mueve ya que lo metemos en raton el movimiento revisar
	void dibuja();
	void tecla(unsigned char key);
	void Raton(int button, int state, int x, int y);
	
protected:
	
	enum Estado {INICIO,MENU, SELECCION, PARTIDA,PAUSA, GANA_B, GANA_N }; 

	Estado estado;
	Ajedrez ajedrez;
};
