#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0, 0.75, 0.0);//y축 이동
	GLfloat diffuse0[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat ambient0[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat specular0[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat light0_pos[] = { 0.5, 0.0, 0.0, 1.0 };
	GLfloat shine = 120.0;
	GLfloat emission[] = { 0.5, 0.1, 0.1, 1.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glutSolidSphere(0.20, 50000, 1000);
	glPopMatrix();

	glPushMatrix();
	
	GLfloat ambient[] = { 0.1, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 0.1, 0.0, 0.0, 1.0 };
	GLfloat specular[] = { 0.1, 0.0, 0.0, 1.0 };
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shine);
	glutSolidSphere(0.20, 50000, 1000);
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("원그리기");//화면크기와 이름 지정
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(display);//원그리기 시작
	glutMainLoop();
}
//[CG]HW04_201302423_신종욱
