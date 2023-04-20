
class Tablero {
private:	
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;

	float x;
	float y;
	float z;
public:
	void DibujarCuadrado(float x, float y, float z, float tam);
	void DibujarTablero();
};
