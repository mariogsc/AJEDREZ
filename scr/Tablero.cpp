#include "freeglut.h"
#include <Tablero.h>
#include <Piezas.h>

Tablero tablero;
Piezas piezas;

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

Tablero::Tablero() {}

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
	piezas.ImprimePiezas();
	tablero.GrisOscuro->draw();
	tablero.tab->draw();
	
	
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	switch (key)
	{
	case ' ':

	case 'd':
		tablero.x += 5.0;
		break;
	case 'a':
		tablero.x -= 5.0;
		break;
	case 'w':
		tablero.y += 5.0;
		break;
	case 's':
		tablero.y -= 5.0;
		break;
	}
	tablero.CheckPosition(tablero.x, tablero.y);
	tablero.GrisOscuro->setPos(tablero.x, tablero.y);
	
	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void Tablero::CheckPosition(float x,float y) {
	if (x < -20.0)tablero.x = -17.5;
	else if (x > 20.0)tablero.x = 17.5;
	else if (y < -20.0)tablero.y = -17.5;
	else if (y > 20.0)tablero.y = 17.5;
}
