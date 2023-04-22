
class Tablero
{
	float x=-20.0;
	float y=-20.0;
	float z=0.0;
	float tam = 5.0;
	int rojo;
	int azul;
	int verde;
public: 
	void DibujaTablero(float tam);
	void DibujaCuadrado(float x, float y, float z,float tam);
	void SetColor(int, int);
};
