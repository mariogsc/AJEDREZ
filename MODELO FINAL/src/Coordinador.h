
#pragma once
#include <Ajedrez.h>
#include "ETSIDI.h"
#include <MenuInicial.h>
using ETSIDI::Sprite;

class Coordinador
{
	int sobrecargaintro = 0;

	float x_ojo;
	float y_ojo;
	float z_ojo;


public:
	Coordinador();
	virtual ~Coordinador() {};

	//void mueve();
	//nose si haria falta mueve ya que lo metemos en raton el movimiento revisar
	void inicializa();
	void dibuja();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void Raton(int button, int state, int x, int y);

protected:

	enum Estado { INICIO, MENU, PARTIDA, PAUSA, GANA_B, GANA_N, TABLAS };

	Estado estado;
	Ajedrez ajedrez;
};

