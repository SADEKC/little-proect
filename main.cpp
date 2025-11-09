#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
#include <cmath>
#include <stdlib.h>
#define MAX_DROPS 100000
float _angle1S1 = 0.0f;
float move1S1 = 0.0f;
float move2S1 = 0.0f;
float move3S1 = 0.0f;
float move4S1 = 0.0f;
float move5S1 = 0.0f;
float move6S1 = 0.0f;
float move7S1 = 0.0f;
float move8S1 = 0.0f;
float leafOffset = 0.0f;
float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
int totalDrops = 0;


float waterLevel = -9.0f;
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();
}



void addDrop() {
    if (totalDrops < MAX_DROPS) {
        dropX[totalDrops] = -10.0f + static_cast<float>(rand()) / (RAND_MAX / 20.0f);
        dropY[totalDrops] = 10.0f;
        totalDrops++;
    }
}





void drawRaindrops() {
    glColor3f(0.2f, 0.4f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.05f);
    }
    glEnd();
}


void drawWater() {
    // Water
     glColor3ub(68,221,255);
    glBegin(GL_QUADS);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(10.0f, -10.0f);
        glVertex2f(10.0f, waterLevel);
        glVertex2f(-10.0f, waterLevel);
    glEnd();


    // Ground
    glColor3ub(68,221,255);
    glBegin(GL_QUADS);
        glVertex2f(-10.0f, waterLevel);
        glVertex2f(10.0f, waterLevel);
        glVertex2f(10.0f, -9.0f);
        glVertex2f(-10.0f, -9.0f);
    glEnd();
}





void Hill()
{

    glBegin(GL_POLYGON);//1st hill
    glColor3ub(217, 201, 171);
    glVertex2f(-10.0f, 2.6f);
    glVertex2f(-8.0f, 4.5f);
    glVertex2f(-5.2f, 2.6f);
    glEnd();
    glBegin(GL_POLYGON);//2nd hill
    glColor3ub(217, 201, 171);
    glVertex2f(-7.8f, 2.6f);
    glVertex2f(-5.67f, 3.8f);
    glVertex2f(-3.6f, 2.6f);
    glEnd();
    glBegin(GL_POLYGON);//3rd hill
    glColor3ub(217, 201, 171);
    glVertex2f(-6.6f, 2.6f);
    glVertex2f(-3.13f, 4.59f);
    glVertex2f(-0.2f, 2.6f);
    glEnd();
    glBegin(GL_POLYGON);//4th hill
    glColor3ub(217, 201, 171);
    glVertex2f(-1.2f, 2.6f);
    glVertex2f(0.22f, 4.46f);
    glVertex2f(2.6f, 2.6f);
    glEnd();

    glBegin(GL_POLYGON);//5th hill
    glColor3ub(217, 201, 171);
    glVertex2f(0.8f, 2.6f);
    glVertex2f(2.74f, 4.39f);
    glVertex2f(4.8f, 2.6f);
    glEnd();
    glBegin(GL_POLYGON);//6th hill
    glColor3ub(217, 201, 171);
    glVertex2f(3.8f, 2.6f);
    glVertex2f(5.71f, 4.05f);
    glVertex2f(7.8f, 2.6f);
    glEnd();
    glBegin(GL_POLYGON);//7th hill
    glColor3ub(217, 201, 171);
    glVertex2f(6.8f, 2.6f);
    glVertex2f(8.63f, 4.06f);
    glVertex2f(10.0f,2.6f);
    glEnd();
}


 void FieldGrass()
 {
    glBegin(GL_POLYGON);
    glColor3ub(107, 142, 35);
    glVertex2f(-10.0f, 2.6f);
    glVertex2f(10.0f, 2.6f);
    glVertex2f(10.0f,0.0f);
    glVertex2f(-10.0f,0.0f);
    glEnd();
 }

 void  RiverSideGrass()
 {

    glBegin(GL_POLYGON);//river side grass
    glColor3ub(107, 142, 35);
    glVertex2f(-10.0f, -4.0f);
    glVertex2f(10.0f, -4.0f);
    glVertex2f(10.0f,-6.0f);
    glVertex2f(-10.0f,-6.0f);
    glEnd();
 }

 void RiverWater()
 {
    glBegin(GL_POLYGON);//river water
    glColor3ub(68,221,255);
    glVertex2f(-10.0f, -6.4f);
    glVertex2f(10.0f, -6.4f);
    glVertex2f(10.0f,-10.0f);
    glVertex2f(-10.0f,-10.0f);
    glEnd();
 }

 void RoadUpl()
 {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glVertex2f(10.0f, -0.2f);
    glVertex2f(-10.0f, -0.2f);
    glEnd();
 }
 void Road()
 {
    glBegin(GL_POLYGON);
    glColor3ub(155, 161, 161);
    glVertex2f(-10.0f, -0.2f);
    glVertex2f(10.0f, -0.2f);
    glVertex2f(10.0f,-3.8f);
    glVertex2f(-10.0f,-3.8f);
    glEnd();
 }

 void RoadDL()
 {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(-10.0f, -3.8f);
    glVertex2f(10.0f, -3.8f);
    glVertex2f(10.0f, -4.0f);
    glVertex2f(-10.0f, -4.0f);
    glEnd();
 }

 void RoadML()
 {
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(-10.0f, -1.95f);
    glVertex2f(-8.85f, -1.95f);
    glVertex2f(-8.85f, -2.05f);
    glVertex2f(-10.0f, -2.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(-6.75f, -1.95f);
    glVertex2f(-3.15f, -1.95f);
    glVertex2f(-3.15f, -2.05f);
    glVertex2f(-6.75f, -2.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(-0.65f, -1.95f);
    glVertex2f(2.55f, -1.95f);
    glVertex2f(2.55f, -2.05f);
    glVertex2f(-0.65f, -2.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(4.35f, -1.95f);
    glVertex2f(7.45f, -1.95f);
    glVertex2f(7.45f, -2.05f);
    glVertex2f(4.35f, -2.05f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);//White
    glVertex2f(9.2f, -1.95f);
    glVertex2f(10.0f, -1.95f);
    glVertex2f(10.0f, -2.05f);
    glVertex2f(9.2f, -2.05f);
    glEnd();
 }

// RiverSide Tree


void Tree1()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-8.6f + leafOffset, -4.2f);
    glVertex2f(-8.0f + leafOffset, -4.8f);
    glVertex2f(-9.2f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(-8.6f, -4.8f);
    glVertex2f(-8.6f, -5.6f);
    glEnd();
}

void Tree2()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-6.0f + leafOffset, -4.2f);
    glVertex2f(-6.6f + leafOffset, -4.8f);
    glVertex2f(-5.4f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(-6.0f, -4.8f);
    glVertex2f(-6.0f, -5.6f);
    glEnd();
}

void Tree3()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-3.4f + leafOffset, -4.2f);
    glVertex2f(-4.0f + leafOffset, -4.8f);
    glVertex2f(-2.8f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(-3.4f, -4.8f);
    glVertex2f(-3.4f, -5.6f);
    glEnd();
}

void Tree4()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-1.0f + leafOffset, -4.2f);
    glVertex2f(-1.6f + leafOffset, -4.8f);
    glVertex2f(-0.4f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(-1.0f, -4.8f);
    glVertex2f(-1.0f, -5.6f);
    glEnd();
}

void Tree5()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(1.0f + leafOffset, -4.2f);
    glVertex2f(0.4f + leafOffset, -4.8f);
    glVertex2f(1.6f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(1.0f, -4.8f);
    glVertex2f(1.0f, -5.6f);
    glEnd();
}

void Tree6()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(3.4f + leafOffset, -4.2f);
    glVertex2f(2.8f + leafOffset, -4.8f);
    glVertex2f(4.0f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(3.4f, -4.8f);
    glVertex2f(3.4f, -5.6f);
    glEnd();
}

void Tree7()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(6.0f + leafOffset, -4.2f);
    glVertex2f(5.4f + leafOffset, -4.8f);
    glVertex2f(6.6f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(6.0f, -4.8f);
    glVertex2f(6.0f, -5.6f);
    glEnd();
}

void Tree8()
{
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(8.6f + leafOffset, -4.2f);
    glVertex2f(8.0f + leafOffset, -4.8f);
    glVertex2f(9.2f + leafOffset,-4.8f);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(61,47,32);
    glVertex2f(8.6f, -4.8f);
    glVertex2f(8.6f, -5.6f);
    glEnd();
}

   //end river side tree

 void RiverSideSoil()
 {
    glBegin(GL_POLYGON);
    glColor3ub(62,49,23);
    glVertex2f(-10.0f, -6.0f);
    glVertex2f(10.0f, -6.0f);
    glVertex2f(10.0f,-6.4f);
    glVertex2f(-10.0f,-6.4f);
    glEnd();
 }

 void TreeJ9()
 {
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(4.47f, 1.84f);
    glVertex2f(4.21f, 1.42f);
    glVertex2f(4.72f,1.42f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(4.31f, 1.42f);
    glVertex2f(4.62f, 1.42f);
    glVertex2f(4.79f,1.14f);
    glVertex2f(4.14f,1.14f);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(4.22f, 1.14f);
    glVertex2f(4.69f, 1.14f);
    glVertex2f(4.9f,0.8f);
    glVertex2f(4.02f,0.8f);
    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(61,47,32);
    glVertex2f(4.36f, 0.8f);
    glVertex2f(4.56f, 0.8f);
    glVertex2f(4.56f,0.68f);
    glVertex2f(4.36f,0.68f);
    glEnd();//end J9
 }

 void TreeD7()
 {
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-5.71f, 1.94f);
    glVertex2f(-5.9f, 1.64f);
    glVertex2f(-5.52f,1.64f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-5.841f, 1.64f);
    glVertex2f(-5.58f, 1.64f);
    glVertex2f(-5.48f,1.42f);
    glVertex2f(-5.94f,1.42f);

    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(-5.88f, 1.42f);
    glVertex2f(-5.52f, 1.42f);
    glVertex2f(-5.4f,1.18f);
    glVertex2f(-6.02f,1.18f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(61,47,32);
    glVertex2f(-5.78f, 1.18f);
    glVertex2f(-5.64f, 1.18f);
    glVertex2f(-5.64f,1.08f);
    glVertex2f(-5.78f,1.08f);
    glEnd();
 }

 void TreeW10()
 {
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(7.62f, 1.27f);
    glVertex2f(7.43f, 0.96f);
    glVertex2f(7.8f,0.96f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(7.5f, 0.96f);
    glVertex2f(7.73f, 0.96f);
    glVertex2f(7.85f,0.75f);
    glVertex2f(7.37f,0.75f);

    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(7.44f, 0.75f);
    glVertex2f(7.79f, 0.75f);
    glVertex2f(7.94f,0.5f);
    glVertex2f(7.3f,0.5f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(61,47,32);
    glVertex2f(7.54f, 0.5f);
    glVertex2f(7.7f, 0.5f);
    glVertex2f(7.7f,0.42f);
    glVertex2f(7.54f,0.42f);
    glEnd();
 }

 void TreeL7()
 {
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(0.0f, 2.05f);
    glVertex2f(-0.24f, 1.66f);
    glVertex2f(0.28f,1.66f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(0.0f, 1.78f);
    glVertex2f(-0.3f, 1.35f);
    glVertex2f(0.35f,1.35f);


    glEnd();
     glBegin(GL_POLYGON);
    glColor3ub(66,105,47);
    glVertex2f(0.0f, 1.55f);
    glVertex2f(-0.43f, 1.03f);
    glVertex2f(0.48f,1.03f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(61,47,32);
    glVertex2f(-0.1f, 1.03f);
    glVertex2f(0.1f, 1.03f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(-0.1f,0.9f);
    glEnd();
 }






 void HouseS1()
 {
 glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(-5.36f,2.1f);
    glVertex2f(-3.6f,2.1f);
    glVertex2f(-3.6f, 1.0f);
    glVertex2f(-5.36f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(-3.6f,1.0f);
    glVertex2f(-3.6f,2.1f);
    glVertex2f(-3.5f, 2.1f);
    glVertex2f(-2.8f, 3.2f);
    glVertex2f(-2.1f, 2.14f);
    glVertex2f(-2.1f, 1.0f);
    glEnd();

    glBegin(GL_POLYGON);//door
    glColor3f(0.482f, 0.247f, 0.176f);
    glVertex2f(-3.22f,1.0f);
    glVertex2f(-3.22f,2.14f);
    glVertex2f(-2.4f, 2.14f);
    glVertex2f(-2.4f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(-4.84f,3.38f);
    glVertex2f(-2.8f,3.38f);
    glVertex2f(-3.58f,2.2f);
    glVertex2f(-5.5f,2.2f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(-5.5f,2.2f);
    glVertex2f(-5.55f,2.1f);
    glVertex2f(-3.5f,2.1f);
    glVertex2f(-3.58f,2.2f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(-3.58f,2.2f);
    glVertex2f(-2.8f,3.38f);
    glVertex2f(-2.8f,3.2f);
    glVertex2f(-3.5f,2.1f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(-2.8f,3.2f);
    glVertex2f(-2.1f,2.14f);
    glVertex2f(-1.94f,2.1f);
    glVertex2f(-2.8f,3.37f);
    glEnd();

 }
 void House1S1()
 {
    glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(1.5f,1.25f);
    glVertex2f(2.8f,1.25f);
    glVertex2f(2.8f, 0.4f);
    glVertex2f(1.5f, 0.4f);
    glEnd();
    glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(2.8f,1.25f);
    glVertex2f(2.85f,1.25f);
    glVertex2f(3.38f, 2.03f);
    glVertex2f(3.9f, 1.24f);
    glVertex2f(3.9f, 0.4f);
    glVertex2f(2.8f, 0.4f);
    glEnd();
    glBegin(GL_POLYGON);//door
    glColor3f(0.482f, 0.247f, 0.176f);
    glVertex2f(3.07f,1.25f);
    glVertex2f(3.65f,1.25f);
    glVertex2f(3.65f, 0.4f);
    glVertex2f(3.07f, 0.4f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(1.37f,1.25f);
    glVertex2f(1.4f,1.3f);
    glVertex2f(2.8f,1.3f);
    glVertex2f(2.85f,1.25f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(2.8f,1.3f);
    glVertex2f(3.38f,2.15f);
    glVertex2f(3.38f,2.03f);
    glVertex2f(2.85f,1.25f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(3.38f,2.15f);
    glVertex2f(3.98f,1.25f);
    glVertex2f(3.9f,1.24f);
    glVertex2f(3.38f,2.03f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(1.9f,2.15f);
    glVertex2f(3.38f,2.15f);
    glVertex2f(2.8f,1.3f);
    glVertex2f(1.4f,1.3f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(39, 34, 28);
    glVertex2f(1.37f,1.25f);
    glVertex2f(2.85f,1.25f);
    glVertex2f(1.4f,1.3f);
    glVertex2f(2.8f,1.3f);
    glVertex2f(2.8f,1.3f);
    glVertex2f(3.38f,2.15f);
    glVertex2f(3.38f,2.03f);
    glVertex2f(2.85f,1.25f);
    glVertex2f(3.38f,2.15f);
    glVertex2f(3.98f,1.25f);
    glVertex2f(3.9f,1.24f);
    glVertex2f(3.38f,2.03f);
    glVertex2f(1.9f,2.15f);
    glVertex2f(3.38f,2.15f);
    glVertex2f(2.8f,1.3f);
    glVertex2f(1.4f,1.3f);
    glVertex2f(1.37f,1.25f);
    glVertex2f(1.9f,2.15f);
    glEnd();




 }
 void House2S1()
 {
    glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(7.08f,2.05f);
    glVertex2f(7.86f,2.05f);
    glVertex2f(7.86f, 1.54f);
    glVertex2f(7.08f, 1.54f);
    glEnd();
    glBegin(GL_POLYGON);//wall
    glColor3f(0.866f, 0.651f, 0.427f);
    glVertex2f(7.86f,1.54f);
    glVertex2f(7.86f,2.05f);
    glVertex2f(7.9f, 2.05f);
    glVertex2f(8.24f, 2.55f);
    glVertex2f(8.57f, 2.07f);
    glVertex2f(8.57f, 1.54f);
    glEnd();

    glBegin(GL_POLYGON);//door
    glColor3f(0.482f, 0.247f, 0.176f);
    glVertex2f(8.06f,2.06f);
    glVertex2f(8.42f,2.06f);
    glVertex2f(8.42f, 1.54f);
    glVertex2f(8.05f, 1.54f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(7.31f,2.63f);
    glVertex2f(8.23f,2.63f);
    glVertex2f(7.89f,2.1f);
    glVertex2f(7.03f,2.1f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(7.03f,2.1f);
    glVertex2f(7.0f,2.05f);
    glVertex2f(7.9f,2.05f);
    glVertex2f(7.89f,2.1f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(7.89f,2.1f);
    glVertex2f(8.23f,2.63f);
    glVertex2f(8.24f,2.55f);
    glVertex2f(7.9f,2.05f);
    glEnd();
    glBegin(GL_POLYGON);//roof
    glColor3ub(109, 54, 49);
    glVertex2f(8.23f,2.63f);
    glVertex2f(8.61f,2.07f);
    glVertex2f(8.57f,2.07f);
    glVertex2f(8.24f,2.55f);
    glEnd();





 }
 //car1 start
 void bodyS1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(-9.78f,-2.89f);
    glVertex2f(-7.92f,-2.89f);
    glVertex2f(-7.92f,-3.44f);
    glVertex2f(-9.76f,-3.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(-9.16f,-2.26f);
    glVertex2f(-8.53f,-2.26f);
    glVertex2f(-8.53f,-2.89f);
    glVertex2f(-9.16f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(-8.53f,-2.26f);
    glVertex2f(-8.09f,-2.89f);
    glVertex2f(-8.53f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(-9.16f,-2.26f);
    glVertex2f(-9.16f,-2.89f);
    glVertex2f(-9.58f,-2.89f);
    glEnd();



}
void leftWheelS1() {
    glPushMatrix();
    glTranslatef(-9.38f,-3.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheelS1() {
    glPushMatrix();
    glTranslatef(-8.36f,-3.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car1S1() {
    glPushMatrix();
    glTranslatef(move1S1, 0.0f, 0.0f);
    bodyS1();
    leftWheelS1();
    rightWheelS1();
    glPopMatrix();
}
//end car1
void body1S1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(0.22f,-2.89f);
    glVertex2f(2.08f,-2.89f);
    glVertex2f(2.08f,-3.44f);
    glVertex2f(0.24f,-3.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(0.84f,-2.26f);
    glVertex2f(1.47f,-2.26f);
    glVertex2f(1.47f,-2.89f);
    glVertex2f(0.84f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(1.47f,-2.26f);
    glVertex2f(1.91f,-2.89f);
    glVertex2f(1.47f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(0.84f,-2.26f);
    glVertex2f(0.84f,-2.89f);
    glVertex2f(0.42f,-2.89f);
    glEnd();



}
void leftWheel1S1() {
    glPushMatrix();
    glTranslatef(0.62f,-3.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheel1S1() {
    glPushMatrix();
    glTranslatef(1.64f,-3.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car2S1() {
    glPushMatrix();
    glTranslatef(move1S1, 0.0f, 0.0f);
    body1S1();
    leftWheel1S1();
    rightWheel1S1();
    glPopMatrix();
}
void body2S1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(6.22f,-2.89f);
    glVertex2f(8.08f,-2.89f);
    glVertex2f(8.08f,-3.44f);
    glVertex2f(6.24f,-3.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(6.84f,-2.26f);
    glVertex2f(7.47f,-2.26f);
    glVertex2f(7.47f,-2.89f);
    glVertex2f(6.84f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(7.47f,-2.26f);
    glVertex2f(7.91f,-2.89f);
    glVertex2f(7.47f,-2.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(6.84f,-2.26f);
    glVertex2f(6.84f,-2.89f);
    glVertex2f(6.42f,-2.89f);
    glEnd();



}
void leftWheel2S1() {
    glPushMatrix();
    glTranslatef(6.62f,-3.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheel2S1() {
    glPushMatrix();
    glTranslatef(7.64f,-3.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car3S1() {
    glPushMatrix();
    glTranslatef(move1S1, 0.0f, 0.0f);
    body2S1();
    leftWheel2S1();
    rightWheel2S1();
    glPopMatrix();
}
 void body3S1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(-9.78f,-0.89f);
    glVertex2f(-7.92f,-0.89f);
    glVertex2f(-7.92f,-1.44f);
    glVertex2f(-9.76f,-1.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(-9.16f,-0.26f);
    glVertex2f(-8.53f,-0.26f);
    glVertex2f(-8.53f,-0.89f);
    glVertex2f(-9.16f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(-8.53f,-0.26f);
    glVertex2f(-8.09f,-0.89f);
    glVertex2f(-8.53f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(-9.16f,-0.26f);
    glVertex2f(-9.16f,-0.89f);
    glVertex2f(-9.58f,-0.89f);
    glEnd();



}
void leftWheel3S1() {
    glPushMatrix();
    glTranslatef(-9.38f,-1.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheel3S1() {
    glPushMatrix();
    glTranslatef(-8.36f,-1.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car4S1() {
    glPushMatrix();
    glTranslatef(move8S1, 0.0f, 0.0f);
    body3S1();
    leftWheel3S1();
    rightWheel3S1();
    glPopMatrix();
}
void body4S1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(0.22f,-0.89f);
    glVertex2f(2.08f,-0.89f);
    glVertex2f(2.08f,-1.44f);
    glVertex2f(0.24f,-1.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(0.84f,-0.26f);
    glVertex2f(1.47f,-0.26f);
    glVertex2f(1.47f,-0.89f);
    glVertex2f(0.84f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(1.47f,-0.26f);
    glVertex2f(1.91f,-0.89f);
    glVertex2f(1.47f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(0.84f,-0.26f);
    glVertex2f(0.84f,-0.89f);
    glVertex2f(0.42f,-0.89f);
    glEnd();



}
void leftWheel4S1() {
    glPushMatrix();
    glTranslatef(0.62f,-1.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheel4S1() {
    glPushMatrix();
    glTranslatef(1.64f,-1.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car5S1() {
    glPushMatrix();
    glTranslatef(move8S1, 0.0f, 0.0f);
    body4S1();
    leftWheel4S1();
    rightWheel4S1();
    glPopMatrix();
}
void body5S1() {
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(6.22f,-0.89f);
    glVertex2f(8.08f,-0.89f);
    glVertex2f(8.08f,-1.44f);
    glVertex2f(6.24f,-1.44f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(163, 64, 19);
    glVertex2f(6.84f,-0.26f);
    glVertex2f(7.47f,-0.26f);
    glVertex2f(7.47f,-0.89f);
    glVertex2f(6.84f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(7.47f,-0.26f);
    glVertex2f(7.91f,-0.89f);
    glVertex2f(7.47f,-0.89f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(135, 206, 235);
    glVertex2f(6.84f,-0.26f);
    glVertex2f(6.84f,-0.89f);
    glVertex2f(6.42f,-0.89f);
    glEnd();



}
void leftWheel5S1() {
    glPushMatrix();
    glTranslatef(6.62f,-1.41f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void rightWheel5S1() {
    glPushMatrix();
    glTranslatef(7.64f,-1.42f,0.0f);
    glRotatef(_angle1S1,0.0f,0.0f,1.0f);
    circle(0.3f, 0.0f, 0.0f, 0.03f, 0.03f, 0.03f);
    glPopMatrix();
}
void car6S1() {
    glPushMatrix();
    glTranslatef(move8S1, 0.0f, 0.0f);
    body5S1();
    leftWheel5S1();
    rightWheel5S1();
    glPopMatrix();
}


//start boat code
void boatbody()
{
    glBegin(GL_POLYGON);
    glColor3ub(46, 39, 245);
    glVertex2f(-9.8f,-7.5f);
    glVertex2f(-9.1f,-8.6f);
    glVertex2f(-8.41f,-8.02f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(46, 39, 245);
    glVertex2f(-8.41f,-8.02f);
    glVertex2f(-9.1f,-8.6f);
    glVertex2f(-7.6f,-8.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(46, 39, 245);
    glVertex2f(-8.41f,-8.02f);
    glVertex2f(-7.6f,-8.6f);
    glVertex2f(-7.0f,-7.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(238, 245, 39);
    glVertex2f(-8.42f,-7.05f);
    glVertex2f(-8.73f,-7.89f);
    glVertex2f(-8.41f,-8.02f);
    glVertex2f(-8.07f,-7.92f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(245, 39, 84);
    glVertex2f(-8.42f,-7.05f);
    glVertex2f(-8.46f,-8.0f);
    glVertex2f(-8.36f,-8.01f);
    glEnd();
}

void boat() {
    glPushMatrix();
    glTranslatef(move2S1, 0.0f, 0.0f);
    boatbody();
    glPopMatrix();
}
//end boat code
void CloudShapeS1()
{
    circle(0.51, -8.57, 8.27, 1.0f, 1.0f, 1.0f);
    circle(0.51, -8.21, 7.75, 1.0f, 1.0f, 1.0f);
    circle(0.51, -7.97, 8.13, 1.0f, 1.0f, 1.0f);
}
void CloudShape1S1()
{
    circle(0.83, -5.48, 5.96, 1.0f, 1.0f, 1.0f);//r
    circle(0.83, -4.82, 6.0, 1.0f, 1.0f, 1.0f);//s
    circle(0.83, -4.99, 5.47, 1.0f, 1.0f, 1.0f);//u
    circle(0.83, -4.58, 6.13, 1.0f, 1.0f, 1.0f);//t
    circle(0.83, -4.37, 5.61, 1.0f, 1.0f, 1.0f);//w

}
void CloudShape2S1()
{
    circle(0.83, 5.48, 5.96, 1.0f, 1.0f, 1.0f);//r
    circle(0.83, 4.82, 6.0, 1.0f, 1.0f, 1.0f);//s
    circle(0.83, 4.99, 5.47, 1.0f, 1.0f, 1.0f);//u
    circle(0.83, 4.58, 6.13, 1.0f, 1.0f, 1.0f);//t
    circle(0.83, 4.37, 5.61, 1.0f, 1.0f, 1.0f);//w

}
void CloudShape3S1()
{
    circle(0.51, -1.57, 8.27, 1.0f, 1.0f, 1.0f);
    circle(0.51, -1.21, 7.75, 1.0f, 1.0f, 1.0f);
    circle(0.51, -0.97, 8.13, 1.0f, 1.0f, 1.0f);
}
void CloudShape4S1()
{
    circle(0.51, 8.57, 8.27, 1.0f, 1.0f, 1.0f);
    circle(0.51, 8.21, 7.75, 1.0f, 1.0f, 1.0f);
    circle(0.51, 7.97, 8.13, 1.0f, 1.0f, 1.0f);
}




void CloudS1()
{
    glPushMatrix();
    glTranslatef(move3S1, 0.0f, 0.0f);
    CloudShapeS1();
    glPopMatrix();
}
void Cloud1S1()
{
    glPushMatrix();
    glTranslatef(move4S1, 0.0f, 0.0f);
    CloudShape1S1();
    glPopMatrix();
}
void Cloud2S1()
{
    glPushMatrix();
    glTranslatef(move5S1, 0.0f, 0.0f);
    CloudShape2S1();
    glPopMatrix();
}
void Cloud3S1()
{
    glPushMatrix();
    glTranslatef(move6S1, 0.0f, 0.0f);
    CloudShape3S1();
    glPopMatrix();
}
void Cloud4S1()
{
    glPushMatrix();
    glTranslatef(move7S1, 0.0f, 0.0f);
    CloudShape4S1();
    glPopMatrix();
}
void display() {

    glClearColor(0.529f, 0.808f, 0.922f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    circle(1.0, 0, 7.0, 0.960f, 0.949f, 0.153f);//sun



    Hill();// call all hill


    FieldGrass();
    RiverSideGrass();
    RiverSideSoil();
    RiverWater();
    RoadUpl();
    Road();
    RoadDL();
    RoadML();

    TreeJ9();


    //River Side Tree
    Tree1();
    Tree2();
    Tree3();
    Tree4();
    Tree5();
    Tree6();
    Tree7();
    Tree8();
    //end

     TreeD7();
     TreeW10();
     TreeL7();


    HouseS1();
    House1S1();
    House2S1();
    car1S1();
    car2S1();
    car3S1();
    car4S1();
    car5S1();
    car6S1();
    boat();

    CloudS1();
    Cloud1S1();
    Cloud2S1();
    Cloud3S1();
    Cloud4S1();


    glutSwapBuffers();


    glFlush();

}
void nightscenceS1() {

    glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //circle(0.39, 6.78, 6.46, 0.95f, 0.95f, 0.85f); // moon
    circle(0.39, 6.78, 6.46, 0.88f, 0.88f, 0.76f);

    Hill();// call all hill

    FieldGrass();
    RiverSideGrass();
    RiverSideSoil();
    RiverWater();
    RoadUpl();
    Road();
    RoadDL();
    RoadML();

    TreeJ9();


    //River Side Tree
    Tree1();
    Tree2();
    Tree3();
    Tree4();
    Tree5();
    Tree6();
    Tree7();
    Tree8();
    //end

     TreeD7();


    HouseS1();
    House1S1();
    House2S1();
    TreeW10();
    TreeL7();


    HouseS1();

    car1S1();
    car2S1();
    car3S1();
    car4S1();
    car5S1();
    car6S1();
    boat();



    glutSwapBuffers();


    glFlush();

}
void RainfloodS1() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    circle(1.0, 0, 7.0, 0.960f, 0.949f, 0.153f);//sun



    Hill();// call all hill


    FieldGrass();
    RiverSideGrass();
    RiverSideSoil();
    RiverWater();
    RoadUpl();
    Road();
    RoadDL();
    RoadML();

    TreeJ9();


    //River Side Tree
    Tree1();
    Tree2();
    Tree3();
    Tree4();
    Tree5();
    Tree6();
    Tree7();
    Tree8();
    //end

     TreeD7();
     TreeW10();
     TreeL7();


    HouseS1();
    House1S1();
    House2S1();
    car1S1();
    car2S1();
    car3S1();
    car4S1();
    car5S1();
    car6S1();
    boat();

    CloudS1();
    Cloud1S1();
    Cloud2S1();
    Cloud3S1();
    Cloud4S1();
    //rain flood
    drawWater();
    drawRaindrops();
    glutSwapBuffers();
    glFlush();
}


void timer(int value) {
    leafOffset = 0.05f * sin(value * 0.1f);
    glutPostRedisplay();
    glutTimerFunc(30, timer, value + 1);
}
void update(int value) {
    _angle1S1 -= 5.0f;
    if (_angle1S1 <= -360.0f) _angle1S1 += 360.0f;

    move1S1 +=0.04f;
    if (move1S1 > 20.0f)
    {
       move1S1 = -20.0f;
    }

        move2S1 +=0.01f;
    if (move2S1 > 20.0f)
    {
       move2S1 = -20.0f;
    }
            move3S1 +=0.004f;
    if (move3S1 > 20)
    {
       move3S1 = -20.0;
    }
    move4S1 +=0.004f;
        if (move4S1 > 20.0f)
    {
       move4S1 = -20.0f;
    }
        move5S1 +=0.004f;
        if (move5S1 > 20.0f)
    {
       move5S1 = -20.0f;
    }
            move6S1 +=0.004f;
        if (move6S1 > 20.0f)
    {
       move6S1 = -20.0f;
    }
            move7S1 +=0.004f;
        if (move7S1 > 20.0f)
    {
       move7S1 = -20.0f;
    }
        move8S1 -=0.04f;
    if (move8S1 < -20.0f)
    {
       move8S1 = +20.0f;
    }
     for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= 0.03f;


        // If raindrop hits the water
        if (dropY[i] <= waterLevel + 0.05f) {
            if (waterLevel < 0.5f) {
                waterLevel += 0.0005f;
            }


            // Remove the drop by shifting others down
            for (int j = i; j < totalDrops - 1; j++) {
                dropX[j] = dropX[j + 1];
                dropY[j] = dropY[j + 1];
            }
            totalDrops--;
            i--; // Stay on the same index
        }
    }


    // Add a few new drops
    for (int i = 0; i < 5; i++) {
        addDrop();
    }





    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'd':
        glutDisplayFunc(display);
        glutPostRedisplay();
        break;
    case 'n':
        glutDisplayFunc(nightscenceS1);
        glutPostRedisplay();
        break;
    case 'r':
        glutDisplayFunc(RainfloodS1);
        glutPostRedisplay();
        break;


    }
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Project:");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,  timer,  0);
    glutTimerFunc(20, update, 0);

    glutMainLoop();
    return 0;
}
