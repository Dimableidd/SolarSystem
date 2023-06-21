#include "stars.hpp"
#include <cmath>
#include <FreeImage.h>
#include <iostream>
#define PI 3.1415926535
GLuint Texture;


GLuint SunTexture;
GLuint MercuryTexture;
GLuint VenusTexture;
GLuint EarthTexture;
GLuint MoonTexture;
GLuint MarsTexture;
GLuint JupiterTexture;
GLuint SaturnTexture;
GLuint SaturnRingTexture;
GLuint UranusTexture;
GLuint NeptuneTexture;


void loadTextureSun() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "sun.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &SunTexture);
    glBindTexture(GL_TEXTURE_2D, SunTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureMercury() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "mercury.jpeg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &MercuryTexture);
    glBindTexture(GL_TEXTURE_2D, MercuryTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureVenus() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "venus.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &VenusTexture);
    glBindTexture(GL_TEXTURE_2D, VenusTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureEarth() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "earth.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &EarthTexture);
    glBindTexture(GL_TEXTURE_2D, EarthTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureMoon() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "moon.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &MoonTexture);
    glBindTexture(GL_TEXTURE_2D, MoonTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureMars() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "mars.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &MarsTexture);
    glBindTexture(GL_TEXTURE_2D, MarsTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureJupiter() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "jupiter.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &JupiterTexture);
    glBindTexture(GL_TEXTURE_2D, JupiterTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureSaturn() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "saturn.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &SaturnTexture);
    glBindTexture(GL_TEXTURE_2D, SaturnTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureSaturnRing() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "saturnring.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &SaturnRingTexture);
    glBindTexture(GL_TEXTURE_2D, SaturnRingTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureUranus() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "uranus.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &UranusTexture);
    glBindTexture(GL_TEXTURE_2D, UranusTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

void loadTextureNeptune() {
    FIBITMAP* bitmap = FreeImage_Load(FIF_JPEG, "neptune.jpg", 0);
    int width = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    BYTE* pixels = FreeImage_GetBits(bitmap);

    glGenTextures(1, &NeptuneTexture);
    glBindTexture(GL_TEXTURE_2D, NeptuneTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);

    FreeImage_Unload(bitmap);
}

Star::Star(GLfloat radius, GLfloat distance,
    GLfloat speed, GLfloat selfSpeed,
    Star* parent, const char* textfile) {
    this->radius = radius;
    this->selfSpeed = selfSpeed;
    this->alphaSelf = this->alpha = 0;
    this->distance = distance;
    this->textfile = textfile;
    for (int i = 0; i < 4; i++)
        this->rgbaColor[i] = 0.5f;

    this->parentStar = parent;
    if (speed > 0)
        this->speed = 360.0f / speed;
    else
        this->speed = 0.0f;

}

void Star::drawStar() {

    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    int n = 1440;
    glPushMatrix();
    {
        if (parentStar != 0 && parentStar->distance > 0) {
            glRotatef(parentStar->alpha, 0, 0, 1);
            glTranslatef(parentStar->distance, 0.0, 0.0);
        }
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        for (int i = 0; i < n; ++i)
            glVertex2f(distance * cos(2 * PI * i / n),
                distance * sin(2 * PI * i / n));
        glEnd();
        glEnable(GL_LIGHTING);
        glRotatef(alpha, 0, 0, 1);

        glTranslatef(distance, 0.0, 0.0);
        GLUquadric* spheres = gluNewQuadric();

        if (strcmp(textfile, "sun.jpg") == 0) {
            glDisable(GL_LIGHTING);
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, SunTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glEnable(GL_LIGHTING);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "mercury.jpeg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, MercuryTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "venus.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, VenusTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "earth.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, EarthTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "moon.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, MoonTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "mars.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, MarsTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "jupiter.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, JupiterTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "saturn.jpg") == 0) {
            glRotatef(alphaSelf * 0.001, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, SaturnTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "saturn.jpg") == 0) {

            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, SaturnRingTexture);
            gluQuadricTexture(spheres, GL_TRUE);

            float tilt_angle = 25.0;
            glRotatef(tilt_angle, -20.0f, -20.0f, 10.0f);

            float matDiffuse[4] = { 1.8f, 1.8f, 1.8f, 1.0f };

            glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);

            glColor3f(1, 1, 1);
            gluDisk(spheres, radius + 0.1 * radius, radius + 0.5 * radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "uranus.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, UranusTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

        if (strcmp(textfile, "neptune.jpg") == 0) {
            glRotatef(alphaSelf, 0, 0, 1);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, NeptuneTexture);
            glColor3f(1, 1, 1);
            gluQuadricTexture(spheres, GL_TRUE);
            gluSphere(spheres, radius, 64, 64);
            glDisable(GL_TEXTURE_2D);
            gluDeleteQuadric(spheres);

            glDisable(GL_TEXTURE_2D);
            glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
        }

    }
    glPopMatrix();

}

void Star::update(long timeSpan) {
    alpha += timeSpan * speed;
    alphaSelf += selfSpeed;
}


Planet::Planet(GLfloat radius, GLfloat distance,
    GLfloat speed, GLfloat selfSpeed,
    Star* parent, const char* textfile) :
    Star(radius, distance, speed, selfSpeed, parent, textfile) {
}

void Planet::drawPlanet() {

    float matAmbient[4] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float matDiffuse[4] = { 0.8f, 0.8f, 0.8f, 1.0f };
    float matSpecular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float matShininess = 100.0f;

    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialf(GL_FRONT, GL_SHININESS, matShininess);
}

LightPlanet::LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed,
    GLfloat selfSpeed, Star* parent, const char* textfile) :
    Planet(radius, distance, speed, selfSpeed, parent, textfile) {
    ;
}

void LightPlanet::drawLight() {

    float lightPos[4] = { 0.0f,0.0f, 0.0f, 1.0f };
    float lightColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);

}