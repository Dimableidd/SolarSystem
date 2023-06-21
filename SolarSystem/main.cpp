#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "solarsystem.hpp"
#include "stars.hpp"
#define WINDOW_X_POS 400
#define WINDOW_Y_POS 100
#define WIDTH 1000
#define HEIGHT 1000

SolarSystem solarsystem;

void onDisplay(void) {
    solarsystem.onDisplay();
}
void onUpdate(void) {
    solarsystem.onUpdate();
}
void onKeyboard(unsigned char key, int x, int y) {
    solarsystem.onKeyboard(key, x, y);
}
void onMouseClick(int button, int state, int x, int y) {
    solarsystem.onMouseClick(button, state, x, y);
}
void onMouseMove(int x, int y) {
    solarsystem.onMouseMove(x, y);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
    glutCreateWindow("SolarSystem");

    loadSpaceTexture();
    loadTextureSun();
    loadTextureMercury();
    loadTextureVenus();
    loadTextureEarth();
    loadTextureMoon();
    loadTextureMars();
    loadTextureJupiter();
    loadTextureSaturn();
    loadTextureSaturnRing();
    loadTextureUranus();
    loadTextureNeptune();

    glutDisplayFunc(onDisplay);
    glutIdleFunc(onUpdate);
    glutKeyboardFunc(onKeyboard);
    glutMouseFunc(onMouseClick);
    glutMotionFunc(onMouseMove);

    glutMainLoop();
    return 0;
}
