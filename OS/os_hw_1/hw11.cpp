#include <GL/glut.h>
#define WIDTH 935
#define HEIGHT 311
void getv(int a, int b) {	
	glVertex2f((float)a / (float)WIDTH, -((float)b - (float)HEIGHT) / (float)HEIGHT);
}
void rightmove_n(int plus) {
	plus = plus - 175;
	glBegin(GL_TRIANGLE_STRIP);
	getv(175+plus, 248);
	getv(179 + plus, 248);
	getv(175 + plus, 276);
	getv(179 + plus, 276);
	glEnd();
	glFlush();
	glBegin(GL_TRIANGLE_STRIP);
	getv(179 + plus, 256);
	getv(179 + plus, 251);
	getv(185 + plus, 253);
	getv(184 + plus, 248);
	getv(188 + plus, 253);
	getv(189 + plus, 247);
	getv(191 + plus, 253);
	getv(195 + plus, 249);
	getv(193 + plus, 256);
	getv(198 + plus, 256);
	getv(193 + plus, 276);
	getv(198 + plus, 276);
	glEnd();
	glFlush();
}
void rightmove_g(int p) {
	p = p - 435;
	glBegin(GL_TRIANGLE_STRIP);
	getv(435 + p, 257);
	getv(435 + p, 252);
	getv(432 + p, 254);
	getv(431 + p, 249);
	getv(429 + p, 252);
	getv(425 + p, 247);
	getv(424 + p, 252);
	getv(420 + p, 249);
	getv(421 + p, 254);
	getv(416 + p, 254);
	getv(420 + p, 258);
	getv(415 + p, 262);
	getv(419 + p, 266);
	getv(415 + p, 269);
	getv(421 + p, 270);
	getv(420 + p, 274);
	getv(425 + p, 272);
	getv(425 + p, 276);
	getv(428 + p, 272);
	getv(431 + p, 275);
	getv(431 + p, 270);
	getv(434 + p, 272);
	getv(434 + p, 267);
	glEnd();
	glFlush();
	glBegin(GL_TRIANGLE_STRIP);
	getv(434 + p, 248);
	getv(439 + p, 248);
	getv(434 + p, 279);
	getv(439 + p, 279);
	getv(432 + p, 281);
	getv(435 + p, 285);
	getv(429 + p, 284);
	getv(430 + p, 288);
	getv(426 + p, 285);
	getv(423 + p, 288);
	getv(423 + p, 283);
	getv(416 + p, 284);
	getv(420 + p, 279);
	getv(415 + p, 279);
	glEnd();
	glFlush();
}
void rightmove_s(int p) {
	p = p - 526;
	glBegin(GL_TRIANGLE_STRIP);
	getv(526 + p, 255);
	getv(521 + p, 255);
	getv(525 + p, 251);
	getv(520 + p, 253);
	getv(521 + p, 248);
	getv(518 + p, 251);
	getv(516 + p, 247);
	getv(513 + p, 251);
	getv(510 + p, 248);
	getv(510 + p, 253);
	getv(506 + p, 253);
	getv(509 + p, 256);
	getv(505 + p, 258);
	getv(511 + p, 258);
	getv(509 + p, 262);
	getv(514 + p, 260);
	getv(514 + p, 263);
	getv(519 + p, 260);
	getv(519 + p, 264);
	getv(523 + p, 262);
	getv(522 + p, 266);
	getv(528 + p, 266);
	getv(523 + p, 268);
	getv(527 + p, 271);
	getv(522 + p, 271);
	getv(523 + p, 275);
	getv(519 + p, 273);
	getv(517 + p, 276);
	getv(513 + p, 272);
	getv(509 + p, 275);
	getv(510 + p, 271);
	getv(505 + p, 272);
	getv(508 + p, 267);
	getv(505 + p, 267);
	glEnd();
	glFlush();
}
void rightmove_i(int p) {
	p = p - 126;
	glBegin(GL_TRIANGLE_STRIP);
	getv(126 + p, 242);
	getv(126 + p, 238);
	getv(130 + p, 242);
	getv(130 + p, 238);
	glEnd();
	glFlush();
	glBegin(GL_TRIANGLE_STRIP);
	getv(126 + p, 276);
	getv(126 + p, 248);
	getv(130 + p, 276);
	getv(130 + p, 248);
	glEnd();
	glFlush();
}
void rightmove_t(int p) {
	p = p - 105;
	glBegin(GL_TRIANGLE_STRIP);
	getv(105 + p, 248);
	getv(105 + p, 253);
	getv(117 + p, 248);
	getv(117 + p, 253);
	glEnd();
	glFlush();
	glBegin(GL_TRIANGLE_STRIP);
	getv(108 + p, 241);
	getv(112 + p, 238);
	getv(108 + p, 273);
	getv(112 + p, 271);
	getv(111 + p, 276);
	getv(117 + p, 272);
	getv(117 + p, 276);
	glEnd();
	glFlush();
}
void rightmove_v(int p) {
	p = p - 721;
	glBegin(GL_TRIANGLE_STRIP);
	getv(721 + p, 248);
	getv(726 + p, 248);
	getv(733 + p, 276);
	getv(735 + p, 270);
	getv(738 + p, 276);
	getv(743 + p, 248);
	getv(748 + p, 248);
	glEnd();
	glFlush();
}
void Display(void)
{
	glPushMatrix();
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	float g = 121.0 / 276.0;
	float b = 155.0 / 276.0;
	glColor3f(0, g, b);
	glViewport(0, 0, WIDTH, HEIGHT);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex2f(0.022, 0.8);
		glVertex2f(0.1137, 0.85);
		glVertex2f(0.114, 0.83);
		glVertex2f(0.02, 0.78);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.025, 0.8);
		glVertex2f(0.1137, 0.85);
		glVertex2f(0.096, 0.856);
		glVertex2f(0.036, 0.815);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLES);
		glVertex2f(0.02, 0.78);
		glVertex2f(0.07, 0.81);
		glVertex2f(0.02, 0.765);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.02, 0.8);
		glVertex2f(0.035, 0.78);
		glVertex2f(0.03, 0.56);
		glVertex2f(0.02, 0.552);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.035, 0.78);
		glVertex2f(0.045, 0.75);
		glVertex2f(0.045, 0.725);
		glVertex2f(0.032, 0.7);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.045, 0.75);
		glVertex2f(0.083, 0.79);
		glVertex2f(0.083, 0.77);
		glVertex2f(0.045, 0.725);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.081, 0.82);
		glVertex2f(0.092, 0.825);
		glVertex2f(0.101, 0.77);
		glVertex2f(0.083, 0.77);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.067, 0.81);
		glVertex2f(0.078, 0.818);
		glVertex2f(0.079, 0.775);
		glVertex2f(0.095, 0.675);
		glVertex2f(0.104, 0.648);
		glVertex2f(0.10, 0.625);
		glVertex2f(0.102, 0.605);
		glVertex2f(0.069, 0.77);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.049, 0.737);
		glVertex2f(0.065, 0.742);
		glVertex2f(0.05, 0.702);
		glVertex2f(0.072, 0.75);
		glVertex2f(0.075, 0.725);
		glVertex2f(0.0668, 0.687);
		glVertex2f(0.083, 0.695);
		glVertex2f(0.081, 0.668);
		glVertex2f(0.035, 0.615);
		glVertex2f(0.034, 0.645);
		glVertex2f(0.041, 0.672);
		glVertex2f(0.033, 0.658);
		glVertex2f(0.032, 0.675);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.0915, 0.75);
		glVertex2f(0.1, 0.724);
		glVertex2f(0.0915, 0.65);
		glVertex2f(0.0837, 0.625);
		glVertex2f(0.0809, 0.6);
		glVertex2f(0.058, 0.6);
		glVertex2f(0.079, 0.648);
		glVertex2f(0.0837, 0.68);
		glVertex2f(0.087, 0.74);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.1, 0.6);
		glVertex2f(0.115, 0.585);
		glVertex2f(0.1, 0.57);
		glVertex2f(0.081, 0.575);
		glVertex2f(0.03, 0.567);
		glVertex2f(0.03, 0.59);
		glVertex2f(0.058, 0.6);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.107, 0.83);
		glVertex2f(0.114, 0.83);
		glVertex2f(0.117, 0.55);
		glVertex2f(0.112, 0.52);
		glVertex2f(0.107, 0.52);
		glVertex2f(0.1, 0.568);
		glVertex2f(0.11, 0.562);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.186, 0.83);
		glVertex2f(0.208, 0.8);
		glVertex2f(0.208, 0.775);
		glVertex2f(0.194, 0.77);
		glVertex2f(0.183, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.186, 0.83);
		glVertex2f(0.208, 0.8);
		glVertex2f(0.208, 0.775);
		glVertex2f(0.194, 0.77);
		glVertex2f(0.183, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.16, 0.74);
		glVertex2f(0.172, 0.75);
		glVertex2f(0.172, 0.745);
		glVertex2f(0.194, 0.77);
		glVertex2f(0.208, 0.775);
		glVertex2f(0.216, 0.78);
		glVertex2f(0.225, 0.774);
		glVertex2f(0.225, 0.75);
		glVertex2f(0.21, 0.745);//
		glVertex2f(0.195, 0.738);//
		glVertex2f(0.166, 0.7);
		glVertex2f(0.158, 0.71);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.195, 0.738);//1
		glVertex2f(0.21, 0.745);//2
		glVertex2f(0.195, 0.7);//3
		glVertex2f(0.177, 0.65);//12
		glVertex2f(0.173, 0.68);//13
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.195, 0.7);//3
		glVertex2f(0.219, 0.727);//4
		glVertex2f(0.225, 0.72);//5
		glVertex2f(0.2255, 0.7);//6
		glVertex2f(0.215, 0.705);//11
		glVertex2f(0.177, 0.65);//12
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.2255, 0.7);//6
		glVertex2f(0.215, 0.65);//7
		glVertex2f(0.205, 0.605);//8
		glVertex2f(0.195, 0.6);//9
		glVertex2f(0.207, 0.653);//10
		glVertex2f(0.215, 0.705);//11
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.195, 0.6);//
		glVertex2f(0.205, 0.605);//
		glVertex2f(0.233, 0.61);
		glVertex2f(0.241, 0.605);
		glVertex2f(0.2415, 0.585);
		glVertex2f(0.219, 0.588);
		glVertex2f(0.172, 0.565);
		glVertex2f(0.16, 0.575);
		glVertex2f(0.156, 0.595);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.267, 0.79);
		glVertex2f(0.273, 0.78);//
		glVertex2f(0.275, 0.77);//
		glVertex2f(0.277, 0.75);
		glVertex2f(0.284, 0.67);
		glVertex2f(0.275, 0.67);
		glVertex2f(0.26, 0.75);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.275, 0.77);//1
		glVertex2f(0.273, 0.78);//2
		glVertex2f(0.284, 0.79);//3
		glVertex2f(0.317, 0.808);//4
		glVertex2f(0.327, 0.81);//5
		glVertex2f(0.349, 0.815);//6
		glVertex2f(0.353, 0.8);//7
		glVertex2f(0.353, 0.785);//8
		//glVertex2f(0.327, 0.723);//9
		//glVertex2f(0.295, 0.675);//10
		//glVertex2f(0.3, 0.7);//11
		//glVertex2f(0.317, 0.73);//12
		//glVertex2f(0.327, 0.75);//13
		glVertex2f(0.339, 0.79);//14
		glVertex2f(0.329, 0.79);//15
		glVertex2f(0.32, 0.79);//16
		glVertex2f(0.287, 0.75);//17
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.353, 0.785);//8
		glVertex2f(0.327, 0.723);//9
		glVertex2f(0.295, 0.675);//10
		glVertex2f(0.3, 0.7);//11
		glVertex2f(0.317, 0.73);//12
		glVertex2f(0.327, 0.75);//13
		glVertex2f(0.339, 0.79);//14
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.317, 0.808);//4
		glVertex2f(0.317, 0.845);
		glVertex2f(0.322, 0.85);
		glVertex2f(0.327, 0.845);
		glVertex2f(0.327, 0.81);//5
		glVertex2f(0.327, 0.75);//13
		glVertex2f(0.327, 0.723);//9
		glVertex2f(0.327, 0.44);
		glVertex2f(0.317, 0.425);
		glVertex2f(0.317, 0.73);//12
		glVertex2f(0.32, 0.79);//16
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.327, 0.723);//9
		glVertex2f(0.339, 0.72);
		glVertex2f(0.336, 0.695);
		glVertex2f(0.295, 0.675);//10
		glVertex2f(0.3, 0.7);//11
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.394, 0.808);
		glVertex2f(0.4, 0.823);
		glVertex2f(0.406, 0.8);
		glVertex2f(0.406, 0.678);//
		glVertex2f(0.4, 0.675);//
		glVertex2f(0.4, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.406, 0.825);
		glVertex2f(0.417, 0.82);
		glVertex2f(0.417, 0.8);
		glVertex2f(0.417, 0.685);//
		glVertex2f(0.411, 0.675);//
		glVertex2f(0.411, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.422, 0.825);
		glVertex2f(0.444, 0.85);
		glVertex2f(0.45, 0.845);
		glVertex2f(0.45, 0.83);
		glVertex2f(0.438, 0.825);//口右上
		glVertex2f(0.428, 0.82);
		glVertex2f(0.428, 0.7);//
		glVertex2f(0.422, 0.69);//
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.45, 0.83);//r_u
		glVertex2f(0.449, 0.805);
		glVertex2f(0.448, 0.795);
		glVertex2f(0.446, 0.77);
		glVertex2f(0.445, 0.705);//
		glVertex2f(0.428, 0.7);//
		glVertex2f(0.428, 0.8);
		glVertex2f(0.438, 0.8);
		glVertex2f(0.438, 0.825);//口右上
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.45, 0.83);//r_u
		glVertex2f(0.471, 0.85);
		glVertex2f(0.469, 0.82);
		glVertex2f(0.463, 0.76);
		glVertex2f(0.467, 0.75);
		glVertex2f(0.462, 0.71);//
		glVertex2f(0.457, 0.708);//
		glVertex2f(0.46, 0.803);
		glVertex2f(0.449, 0.805);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.36, 0.65);
		glVertex2f(0.4, 0.675);//
		glVertex2f(0.406, 0.678);//
		glVertex2f(0.411, 0.675);//
		glVertex2f(0.417, 0.685);//
		glVertex2f(0.422, 0.69);//
		glVertex2f(0.428, 0.7);//
		glVertex2f(0.445, 0.705);//
		glVertex2f(0.457, 0.708);//
		glVertex2f(0.462, 0.71);//
		glVertex2f(0.48, 0.715);
		glVertex2f(0.487, 0.72);
		glVertex2f(0.494, 0.715);
		glVertex2f(0.492, 0.695);
		glVertex2f(0.443, 0.68);
		glVertex2f(0.402, 0.6503);
		glVertex2f(0.365, 0.6);
		glVertex2f(0.358, 0.62);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.383, 0.61);
		glVertex2f(0.391, 0.6);
		glVertex2f(0.443, 0.64);
		glVertex2f(0.393, 0.56);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.461, 0.65);
		glVertex2f(0.487, 0.6);
		glVertex2f(0.486, 0.57);
		glVertex2f(0.483, 0.5);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.461, 0.65);
		glVertex2f(0.487, 0.6);
		glVertex2f(0.486, 0.57);
		glVertex2f(0.483, 0.5);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.519, 0.71);
		glVertex2f(0.562, 0.755);
		glVertex2f(0.574, 0.765);
		glVertex2f(0.592, 0.765);
		glVertex2f(0.588, 0.74);
		glVertex2f(0.57, 0.73);
		glVertex2f(0.557, 0.725);
		glVertex2f(0.544, 0.7);
		glVertex2f(0.534, 0.68);
		glVertex2f(0.525, 0.677);
		glVertex2f(0.522, 0.69);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.562, 0.755);//
		glVertex2f(0.57, 0.83);
		glVertex2f(0.574, 0.845);
		glVertex2f(0.574, 0.765);//
		glVertex2f(0.57, 0.73);///
		glVertex2f(0.562, 0.67);
		glVertex2f(0.555, 0.625);
		glVertex2f(0.533, 0.605);
		glVertex2f(0.549, 0.655);
		glVertex2f(0.557, 0.725);///
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.574, 0.675);
		glVertex2f(0.602, 0.65);
		glVertex2f(0.608, 0.625);
		//glVertex2f(0.602, 0.595);
		//glVertex2f(0.592, 0.6);
		//glVertex2f(0.574, 0.6);
		glVertex2f(0.593, 0.63);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.608, 0.625);
		glVertex2f(0.602, 0.595);
		glVertex2f(0.592, 0.6);
		glVertex2f(0.574, 0.6);
		glVertex2f(0.593, 0.63);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.641, 0.84);
		glVertex2f(0.646, 0.825);
		glVertex2f(0.654, 0.855);
		glVertex2f(0.659, 0.842);
		glVertex2f(0.653, 0.82);
		glVertex2f(0.659, 0.818);
		glVertex2f(0.658, 0.79);
		glVertex2f(0.653, 0.76);
		glVertex2f(0.653, 0.7);
		glVertex2f(0.641, 0.7);
		glVertex2f(0.638, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.653, 0.76);
		glVertex2f(0.667, 0.794);
		//glVertex2f(0.661, 0.8);
		//glVertex2f(0.661, 0.819);
		glVertex2f(0.6675, 0.82);
		glVertex2f(0.675, 0.855);
		glVertex2f(0.683, 0.84);
		glVertex2f(0.679, 0.825);
		//glVertex2f(0.684, 0.825);
		//glVertex2f(0.683, 0.8);
		glVertex2f(0.675, 0.8);
		glVertex2f(0.652, 0.83);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.667, 0.794);
		glVertex2f(0.661, 0.8);
		glVertex2f(0.661, 0.819);
		glVertex2f(0.6675, 0.82);
		glVertex2f(0.679, 0.825);
		glVertex2f(0.684, 0.825);
		glVertex2f(0.683, 0.8);
		glVertex2f(0.675, 0.8);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.662, 0.755);
		glVertex2f(0.668, 0.76);
		//glVertex2f(0.675, 0.8);
		//glVertex2f(0.679, 0.78);
		glVertex2f(0.677, 0.75);
		glVertex2f(0.678, 0.73);
		glVertex2f(0.667, 0.725);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.668, 0.76);
		glVertex2f(0.675, 0.8);
		glVertex2f(0.679, 0.78);
		glVertex2f(0.677, 0.75);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.684, 0.83);
		glVertex2f(0.702, 0.85);
		glVertex2f(0.704, 0.83);
		glVertex2f(0.694, 0.81);
		glVertex2f(0.686, 0.82);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.704, 0.83);
		glVertex2f(0.699, 0.8);
		glVertex2f(0.698, 0.745);
		glVertex2f(0.688, 0.74);
		glVertex2f(0.683, 0.75);
		glVertex2f(0.684, 0.775);
		glVertex2f(0.683, 0.8);
		glVertex2f(0.696, 0.808);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.6335, 0.695);
		glVertex2f(0.641, 0.67);
		glVertex2f(0.627, 0.6);
		glVertex2f(0.618, 0.625);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.6335, 0.695);
		glVertex2f(0.641, 0.698);
		glVertex2f(0.653, 0.7);
		glVertex2f(0.667, 0.725);
		glVertex2f(0.678, 0.73);
		glVertex2f(0.688, 0.74);
		glVertex2f(0.698, 0.745);
		glVertex2f(0.714, 0.748);
		glVertex2f(0.725, 0.725);
		//glVertex2f(0.725, 0.713);
		//glVertex2f(0.722, 0.7);
		//glVertex2f(0.7, 0.7);
		glVertex2f(0.711, 0.725);
		glVertex2f(0.641, 0.67);//
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.725, 0.725);
		glVertex2f(0.725, 0.713);
		glVertex2f(0.722, 0.7);
		glVertex2f(0.698, 0.695);
		glVertex2f(0.711, 0.725);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.667, 0.675);
		glVertex2f(0.684, 0.7);
		glVertex2f(0.687, 0.68);
		glVertex2f(0.685, 0.66);
		glVertex2f(0.675, 0.66);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.685, 0.66);
		glVertex2f(0.6875, 0.65);//
		glVertex2f(0.6875, 0.625);//
		glVertex2f(0.6875, 0.525);
		//glVertex2f(0.679, 0.5);
		//glVertex2f(0.667, 0.45);
		//glVertex2f(0.65, 0.44);///
		//glVertex2f(0.652, 0.475);///
		glVertex2f(0.678, 0.54);
		glVertex2f(0.683, 0.58);
		glVertex2f(0.682, 0.625);//
		glVertex2f(0.68, 0.645);//
		glVertex2f(0.675, 0.66);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.6875, 0.525);
		glVertex2f(0.679, 0.5);
		glVertex2f(0.667, 0.45);
		glVertex2f(0.65, 0.44);///
		glVertex2f(0.652, 0.475);///
		glVertex2f(0.678, 0.54);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.6875, 0.65);//
		glVertex2f(0.7, 0.65);
		glVertex2f(0.708, 0.64);
		glVertex2f(0.706, 0.6245);
		glVertex2f(0.6875, 0.625);//
		glVertex2f(0.682, 0.625);//
		glVertex2f(0.645, 0.6);
		glVertex2f(0.64, 0.62);
		glVertex2f(0.65, 0.615);
		glVertex2f(0.68, 0.645);//
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		glVertex2f(0.65, 0.44);///
		glVertex2f(0.63, 0.445);
		glVertex2f(0.617, 0.465);
		glVertex2f(0.633, 0.458);
		glVertex2f(0.652, 0.475);///
		glEnd();
		glFlush();
	
	glBegin(GL_QUAD_STRIP);
		getv(756, 28);
		getv(758, 36);
		getv(771, 42);
		getv(771, 33);
		getv(785, 46);//
		getv(787, 36);//
		getv(799, 55);
		getv(802, 37);
		getv(810, 63);//R//
		getv(814, 38);//
		getv(826, 62);//R
		getv(845, 36);
		getv(835, 66);//R//
		getv(862, 34);//
		getv(842, 71);//R
		getv(885, 28);
		getv(846, 77);//R//
		getv(878, 46);//
		getv(850, 84);//R
		getv(874, 66);
		getv(851, 93);//R
		getv(873, 80);
		getv(846, 108);//R
		getv(872, 95);
		getv(851, 121);
		getv(875, 111);
		getv(856, 135);
		getv(879, 129);
		getv(860, 150);
		getv(884, 143);
		getv(878, 157);
		getv(888, 152);
		getv(886, 161);
		getv(894, 164);
		glEnd();
		glFlush();
	glBegin(GL_QUAD_STRIP);
		getv(760, 44);
		getv(764, 60);
		getv(777, 51);
		getv(769, 47);
		getv(765, 71);
		getv(788, 57);
		getv(766, 82);
		getv(803, 67);//R
		getv(765, 90);
		getv(792, 80);//R
		getv(764, 102);
		getv(790, 94);//R
		getv(762, 115);
		getv(793, 105);//R
		getv(757, 134);
		getv(797, 113);//R
		getv(746, 161);
		getv(804, 119);//R
		getv(784, 148);
		getv(814, 122);//R
		getv(811, 144);
		getv(826, 122);//R
		getv(826, 144);
		getv(833, 119);//R
		getv(843, 145);
		getv(841, 114);//R
		getv(840, 145);
		getv(848, 129);
		getv(848, 147);
		getv(853, 139);
		getv(856, 149);
		getv(854, 143);
		glEnd();
		glFlush();
		float r_r = 186.0 / 232.0;
		float r_g = 17.0 / 232.0;
		float r_b = 29.0 / 232.0;
	glColor3f(r_r, r_g, r_b);
	glBegin(GL_TRIANGLE_FAN);
		getv(832, 78);
		getv(810, 63);//R//
		getv(826, 62);//R
		getv(835, 66);//R//
		getv(842, 71);//R
		getv(846, 77);//R//
		getv(850, 84);//R
		getv(851, 93);//R
		getv(846, 108);//R
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_FAN);
		getv(832, 78);
		getv(846, 108);//R
		getv(838, 96);
		getv(829, 84);
		getv(821, 74);
		getv(810, 63);//R//
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		getv(803, 67);//R
		getv(792, 80);//R
		getv(790, 94);//R
		getv(793, 105);//R
		getv(797, 113);//R
		getv(804, 119);//R
		getv(814, 122);//R
		getv(826, 122);//R
		getv(833, 119);//R
		getv(841, 114);//R
		getv(832, 99);
		getv(825, 89);
		getv(815, 78);
		getv(809, 72);
		glEnd();
		glFlush();
	glColor3f(0, g, b);
	//N
	glBegin(GL_TRIANGLE_STRIP);
		getv(31, 276);
		getv(35, 276);
		getv(31, 238);
		getv(35, 238);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(35, 238);
		getv(35, 246);
		getv(57, 268);
		getv(57, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(57, 276);
		getv(61, 276);
		getv(57, 238);
		getv(61, 238);
		glEnd();
		glFlush();
	//a
	glBegin(GL_TRIANGLE_STRIP);
		getv(72, 255);
		getv(76, 257);
		getv(75, 250);
		getv(79, 253);
		getv(80, 248);
		getv(83, 252);
		getv(85, 247);
		getv(88, 253);
		getv(91, 249);
		getv(90, 254);
		getv(94, 252);
		getv(91, 258);//
		getv(95, 257);
		getv(92, 276);
		getv(97, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(91, 258);//
		getv(91, 262);
		getv(87, 259);
		getv(85, 264);
		getv(81, 260);
		getv(80, 264);
		getv(77, 262);
		getv(78, 266);
		getv(73, 264);
		getv(76, 268);
		getv(71, 269);
		getv(77, 271);
		getv(72, 273);
		getv(79, 273);
		getv(77, 276);
		getv(82, 273);
		getv(82, 277);
		getv(86, 272);
		getv(88, 275);
		getv(89, 271);
		getv(92, 271);
		getv(92, 267);
		glEnd();
		glFlush();
	//t105
	rightmove_t(105);
	//i
	rightmove_i(126);
	//o
	glBegin(GL_TRIANGLE_STRIP);
		getv(140, 261);
		getv(144, 259);
		getv(141, 254);
		getv(145, 256);
		getv(145, 250);
		getv(149, 253);
		getv(151, 247);
		getv(153, 252);
		getv(157, 248);
		getv(157, 253);
		getv(162, 250);
		getv(160, 256);
		getv(164, 255);
		getv(160, 260);
		getv(165, 260);
		getv(160, 265);
		getv(165, 267);
		getv(160, 268);
		getv(162, 273);
		getv(157, 272);
		getv(157, 276);
		getv(153, 273);
		getv(151, 277);
		getv(149, 272);
		getv(146, 275);
		getv(146, 270);
		getv(141, 270);
		getv(145, 266);
		getv(139, 266);
		getv(144, 263);
		getv(141, 254);
		glEnd();
		glFlush();
	//n
	glBegin(GL_TRIANGLE_STRIP);
		getv(175, 248);
		getv(179, 248);
		getv(175, 276);
		getv(179, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(179, 256);
		getv(179, 251);
		getv(185, 253);
		getv(184, 248);
		getv(188, 253);
		getv(189, 247);
		getv(191, 253);
		getv(195, 249);
		getv(193, 256);
		getv(198, 256);
		getv(193, 276);
		getv(198, 276);
		glEnd();
		glFlush();
	//a-208___208-72=136
	glBegin(GL_TRIANGLE_STRIP);
		getv(72+136, 255);
		getv(76 + 136, 257);
		getv(75 + 136, 250);
		getv(79 + 136, 253);
		getv(80 + 136, 248);
		getv(83 + 136, 252);
		getv(85 + 136, 247);
		getv(88 + 136, 253);
		getv(91 + 136, 249);
		getv(90 + 136, 254);
		getv(94 + 136, 252);
		getv(91 + 136, 258);//
		getv(95 + 136, 257);
		getv(92 + 136, 276);
		getv(97 + 136, 276);
		glEnd();
		glFlush();
		glBegin(GL_TRIANGLE_STRIP);
		getv(91 + 136, 258);//
		getv(91 + 136, 262);
		getv(87 + 136, 259);
		getv(85 + 136, 264);
		getv(81 + 136, 260);
		getv(80 + 136, 264);
		getv(77 + 136, 262);
		getv(78 + 136, 266);
		getv(73 + 136, 264);
		getv(76 + 136, 268);
		getv(71 + 136, 269);
		getv(77 + 136, 271);
		getv(72 + 136, 273);
		getv(79 + 136, 273);
		getv(77 + 136, 276);
		getv(82 + 136, 273);
		getv(82 + 136, 277);
		getv(86 + 136, 272);
		getv(88 + 136, 275);
		getv(89 + 136, 271);
		getv(92 + 136, 271);
		getv(92 + 136, 267);
		glEnd();
		glFlush();
	//l
	glBegin(GL_TRIANGLE_STRIP);
		getv(242, 238);
		getv(247, 238);
		getv(242, 276);
		getv(247, 276);
		glEnd();
		glFlush();
	//C
	glBegin(GL_TRIANGLE_STRIP);
		getv(298, 250);
		getv(304, 250);
		getv(298, 248);
		getv(302, 244);
		getv(297, 245);
		getv(298, 239);
		getv(294, 242);
		getv(294, 237);
		getv(292, 242);
		getv(291, 236);
		getv(288, 241);
		getv(285, 237);
		getv(285, 242);
		getv(281, 238);
		getv(282, 243);
		getv(275, 241);
		getv(278, 246);
		getv(271, 246);
		getv(276, 250);
		getv(269, 251);
		getv(275, 254);
		getv(269, 257);
		getv(275, 260);
		getv(270, 263);
		getv(276, 266);
		getv(272, 270);
		getv(279, 269);
		getv(278, 274);
		getv(283, 271);
		getv(283, 276);
		getv(288, 272);
		getv(290, 277);
		getv(292, 271);
		getv(296, 275);
		getv(296, 269);
		getv(302, 271);
		getv(298, 266);
		getv(304, 266);
		getv(299, 263);
		getv(304, 263);
		glEnd();
		glFlush();
	//h-313  n+一條__313
	rightmove_n(313);
	glBegin(GL_TRIANGLE_STRIP);
		getv(313, 238);
		getv(318, 238);
		getv(313, 276);
		getv(318, 276);
		glEnd();
		glFlush();
	//u
	glBegin(GL_TRIANGLE_STRIP);
		getv(353, 247);
		getv(348, 247);
		getv(353, 270);
		getv(348, 270);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(348, 270);
		getv(353, 270);
		getv(351, 275);
		getv(356, 272);
		getv(357, 276);
		getv(360, 272);
		getv(362, 275);
		getv(363, 271);
		getv(366, 272);
		getv(366, 269);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(366, 247);
		getv(371, 247);
		getv(366, 276);
		getv(371, 276);
		glEnd();
		glFlush();
	//n_382
	rightmove_n(382);
	//g
	rightmove_g(435);
	//H
	glBegin(GL_TRIANGLE_STRIP);
		getv(463, 238);
		getv(468, 238);
		getv(463, 276);
		getv(468, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(489, 238);
		getv(494, 238);
		getv(489, 276);
		getv(494, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(468, 253);
		getv(489, 253);
		getv(468, 258);
		getv(489, 258);
		glEnd();
		glFlush();
	//s右上起526
	rightmove_s(526);
	//i_537
	rightmove_i(537);
	//n_552
	rightmove_n(552);
	//g_605
	rightmove_g(605);
	//U
	glBegin(GL_TRIANGLE_STRIP);
		getv(633, 238);
		getv(638, 238);
		getv(633, 266);
		getv(638, 266);
		getv(637, 273);
		getv(641, 270);
		getv(643, 276);
		getv(647, 272);
		getv(651, 276);
		getv(654, 271);
		getv(659, 273);
		getv(659, 266);
		getv(664, 266);
		getv(659, 238);
		getv(664, 238);
		glEnd();
		glFlush();
	//n_676
	rightmove_n(676);
	//i_710
	rightmove_i(710);
	//v-721
	rightmove_v(721);
	//e
	glBegin(GL_TRIANGLE_STRIP);
		getv(760, 259);
		getv(760, 263);
		getv(777, 259);
		getv(781, 263);
		getv(776, 256);
		getv(779, 254);
		getv(774, 254);
		getv(774, 249);
		getv(769, 252);
		getv(768, 247);
		getv(765, 252);
		getv(762, 249);
		getv(761, 254);
		getv(757, 253);
		getv(760, 259);
		getv(754, 259);
		getv(760, 263);
		getv(754, 266);
		getv(761, 268);
		getv(759, 273);
		getv(763, 272);
		getv(764, 276);
		getv(768, 273);
		getv(772, 276);
		getv(774, 271);
		getv(780, 271);
		getv(776, 267);
		getv(781, 267);
		glEnd();
		glFlush();
	//r
	glBegin(GL_TRIANGLE_STRIP);
		getv(790, 248);
		getv(795, 248);
		getv(790, 276);
		getv(795, 276);
		glEnd();
		glFlush();
	glBegin(GL_TRIANGLE_STRIP);
		getv(795, 257);
		getv(795, 251);
		getv(799, 252);
		getv(800, 247);
		getv(805, 254);
		getv(805, 249);
		glEnd();
		glFlush();
	//s-832
	rightmove_s(832);
	//i-842
	rightmove_i(842);
	//t-858
	rightmove_t(858);
	//yv-873
	rightmove_v(873);
	glBegin(GL_TRIANGLE_STRIP);
		getv(889, 275);
		getv(884, 275);
		getv(888, 281);
		getv(882, 281);
		getv(883, 287);
		getv(876, 283);
		getv(876, 288);
		glEnd();
		glFlush();
	//補
	glBegin(GL_POLYGON);
		getv(769, 47);
		getv(786, 56);
		getv(765, 72);
		getv(764, 60);
		glEnd();
		glFlush();
	glBegin(GL_POLYGON);
		getv(760, 36);
		getv(784, 45);
		getv(787, 36);
		getv(771, 33);
		glEnd();
		glFlush();
	glPopMatrix();
	glutSwapBuffers();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(935, 311);
	glutCreateWindow("National Chung Hsing University ");
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
