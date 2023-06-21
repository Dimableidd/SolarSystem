#ifndef solarsystem_hpp
#define solarsystem_hpp


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "stars.hpp"

#define STARS_NUM 10

void loadSpaceTexture();

class SolarSystem {

public:

    SolarSystem();
    ~SolarSystem();
    void drawSpace();
    void onDisplay();
    void onUpdate();
    void onKeyboard(unsigned char key, int x, int y);
    void onMouseClick(int button, int state, int x, int y);
    void onMouseMove(int x, int y);
private:
    Star* stars[STARS_NUM];
    int lastX = 0;
    int lastY = 0;
    GLdouble viewX, viewY, viewZ;
    GLdouble centerX, centerY, centerZ;
    GLdouble upX, upY, upZ;
};

#endif /* solarsystem_hpp */
