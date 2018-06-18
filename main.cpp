#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>
#include <math.h>
#include <ImageLoader.h>
#define M_PI 3.14159265358979323846


using namespace std;
float angulo=3.1;
float lx=0.041f,lz=1.0f;
float x=21.0f,z=-6.0f, y=7;
float aux1=0.0;
float aux2=0.0;
int xint=0,zint=0;
float grosorLoza=.5;
float i = 0;
float j = 0;
int k = 0;

GLuint _piso;
GLuint _piso2;
GLint _cielo;
GLint _bola;
GLint _blanco;
GLint _rojo;
GLint _pantalla;
GLint _techo;
GLint _pared;
GLint _negro;
GLUquadricObj *sphere;

bool rotasi = false;
int velocidad = 1;
bool efectoderecha = false;
bool efectoizquierda = false;
int cantidaddepinos = 10;
int bolax = 7;
int bolay = 0;
int oportunidad = 0;

char tablero[30][15] = {

{ 'c','0','0','0','0','0','0','b','0','0','0','0','0','0','c' }, //0
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //1
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //2
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //3
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //4
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //5
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //6
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //7
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //8
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //9
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //10
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //11
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //12
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //13
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //14
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //15
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //16
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //17
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //18
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //19
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //20
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //21
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //22
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //23
{ 'c','0','0','0','0','0','0','p','0','0','0','0','0','0','c' }, //24
{ 'c','0','0','0','0','0','p','0','p','0','0','0','0','0','c' }, //25
{ 'c','0','0','0','0','p','0','p','0','p','0','0','0','0','c' }, //26
{ 'c','0','0','0','p','0','p','0','p','0','p','0','0','0','c' }, //27
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //28
{ 'c','0','0','0','0','0','0','0','0','0','0','0','0','0','c' }, //29
};

int pino1x = 4,pino1y=27;
int pino2x = 5,pino2y=26;
int pino3x = 6,pino3y=25;
int pino4x = 6,pino4y=27;
int pino5x = 7,pino5y=26;
int pino6x = 7,pino6y=24;
int pino7x = 8,pino7y=27;
int pino8x = 8,pino8y=25;
int pino9x = 9,pino9y=26;
int pino10x = 10,pino10y=27;

bool pino1bol = false;
bool pino2bol = false;
bool pino3bol = false;
bool pino4bol = false;
bool pino5bol = false;
bool pino6bol = false;
bool pino7bol = false;
bool pino8bol = false;
bool pino9bol = false;
bool pino10bol = false;

void tirar( int vel) {
	velocidad = vel;
	    if(efectoderecha==false && efectoizquierda==false){
		int auxx = bolax;
		int auxy = bolay;
		bolay = bolay + velocidad;
		tablero[auxy][auxx] = '0';
		tablero[bolay][bolax] = 'b';
		return;
		}else
	    if(efectoderecha==true){
	    int auxx = bolax;
		int auxy = bolay;
		if(bolax<15){
	    bolax= bolax + 1;
		}
		bolay = bolay + velocidad;
		tablero[auxy][auxx] = '0';
		tablero[bolay][bolax] = 'b';
		return;
	     }else
	    if(efectoizquierda==true){
	    int auxx = bolax;
		int auxy = bolay;
		if(bolax>0){
	    bolax= bolax - 1;
		}
		bolay = bolay + velocidad;
		tablero[auxy][auxx] = '0';
		tablero[bolay][bolax] = 'b';
		return;
        }
	}

void draw_circle(){
    sphere = gluNewQuadric();
    gluQuadricTexture(sphere, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _bola);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluSphere(sphere,2,100,100);
}

void circulo(){
    sphere = gluNewQuadric();
    gluQuadricTexture(sphere, GL_TRUE);
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _cielo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    gluSphere(sphere,110,100,100);
}


GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}

void initRendering() {
	Image* cielo = loadBMP("C://Users//Lilo//Desktop//Boliche//ciel.bmp");
	Image* bola = loadBMP("C://Users//Lilo//Desktop//Boliche//bola1.bmp");
	Image* piso = loadBMP("C://Users//Lilo//Desktop//Boliche//piso.bmp");
	Image* piso2 = loadBMP("C://Users//Lilo//Desktop//Boliche//piso2.bmp");
	Image* blanco= loadBMP("C://Users//Lilo//Desktop//Boliche//blanco.bmp");
	Image* rojo= loadBMP("C://Users//Lilo//Desktop//Boliche//rojo.bmp");
	Image* pantalla= loadBMP("C://Users//Lilo//Desktop//Boliche//pantalla.bmp");
	Image* techo= loadBMP("C://Users//Lilo//Desktop//Boliche//techo.bmp");
	Image* pared= loadBMP("C://Users//Lilo//Desktop//Boliche//pared.bmp");
	Image* negro= loadBMP("C://Users//Lilo//Desktop//Boliche//negro.bmp");
	_cielo = loadTexture(cielo);
	_bola = loadTexture(bola);
	_piso = loadTexture(piso);
	_piso2 = loadTexture(piso2);
	_blanco = loadTexture(blanco);
	_rojo = loadTexture(rojo);
	_pantalla = loadTexture(pantalla);
	_techo = loadTexture(techo);
	_pared = loadTexture(pared);
	_negro = loadTexture(negro);
	delete cielo,bola,piso,piso2,blanco,rojo,pantalla,techo,pared,negro;
}

void piso_cuadro(float posx, float posy, float posz, float grosorLoza, float ancho, float largo,GLuint _muro1, GLuint _muro2){

	//LADO TRASERO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glBegin(GL_POLYGON);

	glTexCoord2f(0.0f, 0.0f);  glVertex3f(posx, posy, posz);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx, posy + grosorLoza, posz);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(posx + ancho, posy, posz);
	glEnd();


	// LADO FRONTAL: lado amarillo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glBegin(GL_POLYGON);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx, posy, posz + largo);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx, posy + grosorLoza, posz + largo);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz + largo);
	glTexCoord2f(0.0f, 1.0f);glVertex3f(posx + ancho, posy, posz + largo);
	glEnd();

	// LADO Izquierdo: lado morado
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glBegin(GL_POLYGON);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx, posy, posz);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx, posy + grosorLoza, posz);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(posx, posy + grosorLoza, posz + largo);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(posx, posy, posz + largo);
	glEnd();

	// LADO derecho: lado verde
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glBegin(GL_POLYGON);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx + ancho, posy, posz);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz + largo);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(posx + ancho, posy, posz + largo);
	glEnd();

	// LADO SUPERIOR:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glNormal3f( 0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(posx, posy + grosorLoza, posz);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx + ancho, posy + grosorLoza, posz + largo);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx, posy + grosorLoza, posz + largo);
	glEnd();
	// LADO INFERIOR:
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _muro1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	//glColor3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(posx, posy, posz);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(posx + ancho, posy, posz);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(posx + ancho, posy, posz + largo);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(posx, posy, posz + largo);
	glEnd();
}

void pino(float x, float y, float z){
    piso_cuadro(x,    y,    z,    0.1,1.2,1.2,_blanco,_blanco);//1
    piso_cuadro(x-0.1,y+0.1,z-0.1,0.3,1.4,1.4,_blanco,_blanco);//2
    piso_cuadro(x-0.2,y+0.4,z-0.2,0.6,1.6,1.6,_blanco,_blanco);//3
    piso_cuadro(x-0.1,y+1.0,z-0.1,0.4,1.4,1.4,_blanco,_blanco);//4
    piso_cuadro(x,    y+1.4,z,    0.2,1.2,1.2,_blanco,_blanco);//5
    piso_cuadro(x+0.1,y+1.6,z+0.1,0.2,1.0,1.0,_blanco,_blanco);//6
    piso_cuadro(x+0.2,y+1.8,z+0.2,0.3,0.8,0.8,_blanco,_blanco);//7
    piso_cuadro(x+0.3,y+2.1,z+0.3,0.5,0.6,0.6,_rojo,_rojo);//8
    piso_cuadro(x+0.2,y+2.6,z+0.2,0.5,0.8,0.8,_blanco,_blanco);//9
    piso_cuadro(x+0.1,y+2.9,z+0.1,0.7,1.0,1.0,_blanco,_blanco);//10
    piso_cuadro(x+0.2,y+3.6,z+0.2,0.1,0.8,0.8,_blanco,_blanco);//11
    piso_cuadro(x+0.3,y+3.7,z+0.3,0.1,0.6,0.6,_blanco,_blanco);//12
    piso_cuadro(x+0.4,y+3.8,z+0.4,0.1,0.4,0.4,_blanco,_blanco);//13
}

void display(void) {
    i+=1;
    k+=1;
    if(rotasi){
            if(bolay < 29){
                    if(k%20==0){
                        tirar(1);
                    }
            }else{
            k=0;
            rotasi=false;
            efectoderecha=false;
            efectoizquierda=false;
            }
    }

    if(bolax == pino1x && bolay == pino1y) pino1bol = true;
    if(bolax == pino2x && bolay == pino2y) pino2bol = true;
    if(bolax == pino3x && bolay == pino3y) pino3bol = true;
    if(bolax == pino4x && bolay == pino4y) pino4bol = true;
    if(bolax == pino5x && bolay == pino5y) pino5bol = true;
    if(bolax == pino6x && bolay == pino6y) pino6bol = true;
    if(bolax == pino7x && bolay == pino7y) pino7bol = true;
    if(bolax == pino8x && bolay == pino8y) pino8bol = true;
    if(bolax == pino9x && bolay == pino9y) pino9bol = true;
    if(bolax == pino10x && bolay == pino10y) pino10bol = true;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	gluLookAt( x, y+aux1,z,x+lx,y+aux2,z+lz,0.0f, y, 0.0f);
	glPushMatrix();
	circulo();
	//X,Y,Z,ANCHO,LARGO,ABAJO,ARRIBA
	//_________________PISO________________________________
	piso_cuadro(0,0,0,0.5,45,90,_piso,_piso);
	piso_cuadro(-1.5,-2,0,0.5,1.5,90,_piso2,_piso2);
	piso_cuadro(0,-2,0,2,0.5,90,_piso,_piso);
	piso_cuadro(-2,-2,0,2,0.5,90,_piso,_piso);
	piso_cuadro(-4,0,0,0.5,2.5,90,_piso,_piso);

	piso_cuadro(45,-2,0,0.5,1.5,90,_piso2,_piso2);
	piso_cuadro(44.5,-2,0,2,0.5,90,_piso,_piso);
	piso_cuadro(46.5,-2,0,2,0.5,90,_piso,_piso);
	piso_cuadro(46.5,0,0,0.5,2.5,90,_piso,_piso);

	piso_cuadro(0,10,89.5,20,45,0.5,_pantalla,_pantalla);
	piso_cuadro(-4,30,0,0.5,53,90,_techo,_techo);
	piso_cuadro(-5,0,0,30.5,1,90,_pared,_pared);
	piso_cuadro(49,0,0,30.5,1,90,_pared,_pared);
	piso_cuadro(-5,0,90,30.5,55,0.5,_negro,_negro);
    piso_cuadro(-5,0,-7,30.5,55,0.5,_pared,_pared);
    piso_cuadro(-5,0,-7,0.5,55,8,_piso,_piso);
    piso_cuadro(-5,0,-7,30.5,1,8,_pared,_pared);
    piso_cuadro(49,0,-7,30.5,1,8,_pared,_pared);
    piso_cuadro(-5,30,-7,0.5,55,8,_techo,_techo);
    glPopMatrix();

    //_______________________________________________________
    glPushMatrix();
        if(!pino1bol) pino(pino1x *3,1,pino1y*3);
        if(!pino2bol) pino(pino2x *3,1,pino2y*3);
        if(!pino3bol) pino(pino3x *3,1,pino3y*3);
        if(!pino4bol) pino(pino4x *3,1,pino4y*3);
        if(!pino5bol) pino(pino5x *3,1,pino5y*3);
        if(!pino6bol) pino(pino6x *3,1,pino6y*3);
        if(!pino7bol) pino(pino7x *3,1,pino7y*3);
        if(!pino8bol) pino(pino8x *3,1,pino8y*3);
        if(!pino9bol) pino(pino9x *3,1,pino9y*3);
        if(!pino10bol) pino(pino10x *3,1,pino10y*3);
    glPopMatrix();

    glPushMatrix();
        if(rotasi){
            glTranslated(bolax*3,2.6,bolay*3);
            glRotated(i,1,0,1);
        }else{
            glTranslated(bolax*3,2.6,bolay*3);
        }
        draw_circle();
    glPopMatrix();

	glutSwapBuffers();

}

void changeSize(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(90.0f, ratio, 0.1f, 150.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Keyboard(unsigned char key, int x, int y) {
 switch(key) {
    case 27:
    	    exit(0);
        break;

	case 'a':
		aux1=1.0;
		aux2=0.0;
		break;
	case 's':
		aux1=0.0;
		aux2=0.0;
	 	break;
	case 'd':
		 aux2=1.0;
		 aux1=0.0;
		 break;
    case 'y':
		 bolay=0;
		 bolax=7;
		 rotasi = false;
		 if(oportunidad==2){
            pino1bol=false;
            pino2bol=false;
            pino3bol=false;
            pino4bol=false;
            pino5bol=false;
            pino6bol=false;
            pino7bol=false;
            pino8bol=false;
            pino9bol=false;
            pino10bol=false;
            oportunidad=0;
		 }else{
		 oportunidad+=1;}

		 break;
    case 't':
		 rotasi=true;
		 break;
    case 'u':
		 efectoderecha=true;
		 break;
    case 'i':
		 efectoderecha=false;
		 break;
    case 'o':
		 efectoizquierda=true;
		 break;
    case 'p':
		 efectoizquierda=false;
		 break;
    }
}

void processSpecialKeys(int key, int xx, int yy) {
	float fraction = 1.0f;
	switch (key) {
		case GLUT_KEY_LEFT :
			angulo -= 0.1f;
			lx = sin(angulo);
			lz = -cos(angulo);
		break;
		case GLUT_KEY_RIGHT :
			angulo += 0.1f;
			lx = sin(angulo);
			lz = -cos(angulo);
		break;


		case GLUT_KEY_UP :
            float tmpx;tmpx = x + lx * fraction;
            float tmpz;tmpz = z + lz * fraction;
                x= tmpx;
                z= tmpz;

		break;
		case GLUT_KEY_DOWN :
            float tmpx2;tmpx2 = x - lx * fraction;
            float tmpz2;tmpz2 = z - lz * fraction;
                x= tmpx2;
                z= tmpz2;
		break;
		case GLUT_KEY_END:
			y=y+0.2f;
		break;
		case GLUT_KEY_HOME:
			y=y-0.2f;
		break;
	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(00,00);
	glutInitWindowSize(800,600);
	glutCreateWindow("Casa");
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutIdleFunc(display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(processSpecialKeys);
	glEnable(GL_DEPTH_TEST);
	initRendering();
	glutMainLoop();
	return 0;
}

