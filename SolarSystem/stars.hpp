#ifndef star_hpp
#define star_hpp

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
void loadSpaceTexture();
void loadTextureSun();
void loadTextureMercury();
void loadTextureVenus();
void loadTextureEarth();
void loadTextureMoon();
void loadTextureMars();
void loadTextureJupiter();
void loadTextureSaturn();
void loadTextureSaturnRing();
void loadTextureUranus();
void loadTextureNeptune();


class Star {
public:
    GLfloat radius;
    GLfloat speed, selfSpeed;
    GLfloat distance;
    GLfloat rgbaColor[4];
    const char* textfile;
    Star* parentStar;

    Star(GLfloat radius, GLfloat distance,
        GLfloat speed, GLfloat selfSpeed,
        Star* parent, const char* textfile);
    void drawStar();
    virtual void draw() { drawStar(); }
    virtual void update(long timeSpan);
protected:
    GLfloat alphaSelf, alpha;
};

class Planet : public Star {
public:
    Planet(GLfloat radius, GLfloat distance,
        GLfloat speed, GLfloat selfSpeed,
        Star* parent, const char* textfile);
    void drawPlanet();
    virtual void draw() { drawPlanet(); drawStar(); }
};

class LightPlanet : public Planet {
public:
    LightPlanet(GLfloat Radius, GLfloat Distance,
        GLfloat Speed, GLfloat SelfSpeed,
        Star* Parent, const char* textfile);
    void drawLight();
    virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};

#endif /* star_hpp */