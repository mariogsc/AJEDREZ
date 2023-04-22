#include "freeglut.h"
#include <Tablero.h>

Tablero tablero;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	


int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("AJEDREZ");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(7.0, 0.0, 60.0,  // posicion del ojo
		7.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	glDisable(GL_LIGHTING);
	tablero.DibujaTablero(5.0);
	glEnable(GL_LIGHTING);
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado

	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void Tablero::DibujaCuadrado(float x, float y, float z,float tam) {

	glBegin(GL_POLYGON);
	glVertex3f(x, y, z);
	glVertex3f(x + tam, y, z);
	glVertex3f(x + tam, y + tam, z);
	glVertex3f(x, y + tam, z);
	glEnd();
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);

}
void Tablero::DibujaTablero(float tam) {
	float z = 0.0, movX = tam, movY = tam;

	for (int columna = 0; columna < 8; columna++) {
		movX = 0.0;
		movY = tam * columna;
		for (int fila = 0; fila < 8; fila++) {
			SetColor(columna, fila);
			tablero.DibujaCuadrado(x + movX, y + movY, 0.0, 5.0);
			movX += tam;
		}
		movY += tam;
	}
};

void Tablero::SetColor(int columna, int fila) {
	if (columna % 2 == 0) {
		if (fila % 2 == 0) { rojo = 224; verde = 180; azul = 143; }
		else rojo = verde = azul = 255;
	}
	else {
		if (fila % 2 == 0)rojo = verde = azul = 255;
		else { rojo = 224; verde = 180; azul = 143; }
	}
	glColor3ub(rojo, verde, azul);
};

