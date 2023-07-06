#ifndef COMMON_HPP
#define COMMON_HPP
#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <cmath>
//#pragma warning(disable:4996)
#define MY_PI 3.14159265358979323846
using namespace std;

typedef float point3[3];
//GLfloat theta = 0.0;   // rotation angle of the object
GLdouble pix2angle;     // pixels to degrees
GLdouble R = 10.0;
GLdouble azymut = -1.5;
GLdouble elewacja = 0.0;
GLdouble temp = 1.0;

GLdouble viewer[] = { R * cos(azymut) * cos(elewacja), R * sin(elewacja), R * sin(azymut) * cos(elewacja) };
GLdouble viewAt[] = { 0.0, 0.0, 0.0 };
GLfloat theta[] = { 0.0, 0.0, 0.0 };

GLfloat basic_light_position[] = { 0.0, 0.0, 10.0, 1.0 };
GLfloat basic_light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat basic_light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat basic_light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

GLfloat red_light_ambient[] = { 0.1, 0.0, 0.0, 1.0 };
GLfloat red_light_diffuse[] = { 1.0, 0.0, 0.0, 0.0 };
GLfloat red_light_specular[] = { 1.0, 0.0, 0.0, 0.0 };
GLdouble azymut_red = -1;
GLdouble elewacja_red = 2.0;
GLfloat R_red = 15.0;
GLfloat red_light_position[] = { R_red * cos(azymut_red) * cos(elewacja_red), R_red * sin(elewacja_red), R_red * sin(azymut_red) * cos(elewacja_red), 1.0 };

GLfloat blue_light_ambient[] = { 0.0, 0.0, 0.1, 1.0 };
GLfloat blue_light_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat blue_light_specular[] = { 0.0, 0.0, 1.0, 1.0 };
GLdouble azymut_blue = -2;
GLdouble elewacja_blue = 1.0;
GLfloat R_blue = 15.0;
GLfloat blue_light_position[] = { R_blue * cos(azymut_blue) * cos(elewacja_blue), R_blue * sin(elewacja_blue), R_blue * sin(azymut_blue) * cos(elewacja_blue), 1.0 };

GLint status = 0;       // mouse key state: 0 - no key is pressed / 1 - the left key is pressed
int x_pos_old = 0;       // previous position of the mouse cursor
int y_pos_old = 0;
int delta_x = 0;        // difference between the current position
int delta_y = 0;  	   // and the previous position of the mouse cursor

const int N = 30;

int model = 1;  // 1 - points, 2 - grid, 3 - filled triangles, 4 - kettle, 5 - pyramid, 6 - triangle
int movement = 1; //1 - rotating the object, 2 - rotating the camera, 3 - rotating the light sources
int light = 1; //1 - one stationary source, 2 - two moving sources
float N_len;
float divider = 1.0 / N; //Because when calculating points 0<=u<=1 and 0<=v<=1

struct Point {
	float x;
	float y;
	float z;
	float red;
	float green;
	float blue;
	float Nx;
	float Ny;
	float Nz;
	float t1;
	float t2;
};
Point points_in_3D[N][N];
inline float N_length(float xv, float yv, float zv) {
	return sqrt(xv * xv + yv * yv + zv * zv);
}
#endif