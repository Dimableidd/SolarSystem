#include "solarsystem.hpp"
#include <cstdlib>
#include <FreeImage.h>
#define REST 700
#define REST_Y (-REST)
#define REST_Z (REST)

GLuint spaceTexture;


#define PI 3.1415926535
void loadSpaceTexture() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "space.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &spaceTexture);
    glBindTexture(GL_TEXTURE_2D, spaceTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void SolarSystem::drawSpace() {
    glDisable(GL_LIGHTING);
    glBindTexture(GL_TEXTURE_2D, spaceTexture);

    static float angleX = 0.0f;
    static float angleY = 0.0f;
    static float angleZ = 0.0f;

    static float angX = 0.0f;
    static float angY = 0.0f;
    static float angZ = 0.0f;

    angleX += 0.01f;
    angleY += 0.02f;
    angleZ += 0.03f;

    angX = atan2(viewX, viewZ) * 180 / PI;
    angY = atan2(viewY, viewZ) * 180 / PI;
    angZ = atan2(viewZ, viewZ) * 180 / PI;
    glPushMatrix();
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    glRotatef(angX, 1.0f, 0.0f, 0.0f);
    glRotatef(angY, 0.0f, 1.0f, 0.0f);
    glRotatef(angZ, 0.0f, 0.0f, 1.0f);
    GLUquadric* sphere = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glColor3f(1.0f, 1.0f, 1.0f);
    gluQuadricTexture(sphere, GL_TRUE);
    gluSphere(sphere, 10000000.0f, 64, 64);
    glDisable(GL_TEXTURE_2D);
    gluDeleteQuadric(sphere);
    glPopMatrix();
    glEnable(GL_LIGHTING);
}
void SolarSystem::onDisplay() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0f, 1.0f, 1.0f, 40000000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawSpace();

    gluLookAt(viewX, viewY, viewZ, centerX, centerY, centerZ, upX, upY, upZ);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    for (int i = 0; i < STARS_NUM; i++)
        stars[i]->draw();



    glutSwapBuffers();
}


#define TIMEPAST 1
void SolarSystem::onUpdate() {

    for (int i = 0; i < STARS_NUM; i++)
        stars[i]->update(TIMEPAST);

    this->onDisplay();
}


#define OFFSET 20
void SolarSystem::onKeyboard(unsigned char key, int x, int y) {

    switch (key) {
    case 'w': viewY += OFFSET; break;
    case 's': viewZ += OFFSET; break;
    case 'S': viewZ -= OFFSET; break;
    case 'a': viewX -= OFFSET; break;
    case 'd': viewX += OFFSET; break;
    case 'x': viewY -= OFFSET; break;
    case 'r':
        viewX = 0; viewY = REST_Y; viewZ = REST_Z;
        centerX = centerY = centerZ = 0;
        upX = upY = 0; upZ = 1;
        break;
    case 27: exit(0); break;
    default: break;
    }

}
void SolarSystem::onMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        lastX = x;
        lastY = y;
    }
}
void SolarSystem::onMouseMove(int x, int y) {

    viewX += (x - lastX) * 5.0f;
    viewY -= (y - lastY) * 5.0f;
    lastX = x;
    lastY = y;

}

#define SUN_RADIUS 48.74
#define MER_RADIUS  7.32
#define VEN_RADIUS 18.15
#define EAR_RADIUS 19.13
#define MOO_RADIUS  6.15
#define MAR_RADIUS 10.19
#define JUP_RADIUS 42.90
#define SAT_RADIUS 36.16
#define URA_RADIUS 25.56
#define NEP_RADIUS 24.78

#define MER_DIS    62.06
#define VEN_DIS   115.56
#define EAR_DIS   168.00
#define MOO_DIS    26.01
#define MAR_DIS   228.00
#define JUP_DIS   333.40
#define SAT_DIS   428.10
#define URA_DIS   848.00
#define NEP_DIS   949.10

#define MER_SPEED   87.0
#define VEN_SPEED  225.0
#define EAR_SPEED  365.0
#define MOO_SPEED   30.0
#define MAR_SPEED  687.0
#define JUP_SPEED 1298.4
#define SAT_SPEED 3225.6
#define URA_SPEED 3066.4
#define NEP_SPEED 6014.8

#define SELFROTATE 3

enum STARS {
    Sun, Mercury, Venus, Earth, Moon,
    Mars, Jupiter, Saturn, Uranus, Neptune
};



SolarSystem::SolarSystem() {


    viewX = 0;
    viewY = REST_Y;
    viewZ = REST_Z;
    centerX = centerY = centerZ = 0;
    upX = upY = 0;
    upZ = 1;
    stars[Sun] = new LightPlanet(SUN_RADIUS, 0, 0, SELFROTATE, 0, "sun.jpg");

    stars[Mercury] = new Planet(MER_RADIUS, MER_DIS, MER_SPEED, SELFROTATE, stars[Sun], "mercury.jpeg");

    stars[Venus] = new Planet(VEN_RADIUS, VEN_DIS, VEN_SPEED, SELFROTATE, stars[Sun], "venus.jpg");

    stars[Earth] = new Planet(EAR_RADIUS, EAR_DIS, EAR_SPEED, SELFROTATE, stars[Sun], "earth.jpg");

    stars[Moon] = new Planet(MOO_RADIUS, MOO_DIS, MOO_SPEED, SELFROTATE, stars[Earth], "moon.jpg");

    stars[Mars] = new Planet(MAR_RADIUS, MAR_DIS, MAR_SPEED, SELFROTATE, stars[Sun], "mars.jpg");

    stars[Jupiter] = new Planet(JUP_RADIUS, JUP_DIS, JUP_SPEED, SELFROTATE, stars[Sun], "jupiter.jpg");

    stars[Saturn] = new Planet(SAT_RADIUS, SAT_DIS, SAT_SPEED, SELFROTATE, stars[Sun], "saturn.jpg");

    stars[Uranus] = new Planet(URA_RADIUS, URA_DIS, URA_SPEED, SELFROTATE, stars[Sun], "uranus.jpg");

    stars[Neptune] = new Planet(NEP_RADIUS, NEP_DIS, NEP_SPEED, SELFROTATE, stars[Sun], "neptune.jpg");


}
SolarSystem::~SolarSystem() {
    for (int i = 0; i < STARS_NUM; i++)
        delete stars[i];
}