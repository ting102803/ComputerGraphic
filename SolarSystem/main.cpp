#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>
double k0, k1, k2, k3,k4,k5,k6,k7,k8,k9,k10,k11,k12 ;
double S;
float XAngle = 0.0;
float YAngle = 0.0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glRotated(XAngle, 1.0, 0.0, 0.0);//x축 이동
	glRotated(YAngle,0.0,1.0,0.0);//y축 이동

	glPushMatrix();//태양그리기
	glRotated(S, 0, 0, 1.0);
	S += 1.5;//자전
	GLfloat ambient0[] = { 0.4, 0.3, 0.3, 1.0 };
	GLfloat diffuse0[] = { 0.4, 0.3, 0.3, 1.0 };
	GLfloat specular0[] = { 0.4, 0.3, 0.3, 1.0 };
	GLfloat emission0[] = { 0.8, 0.23, 0.23, 1.0 };
	GLfloat shine0 = 120.0;
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular0);
	glMaterialf(GL_FRONT, GL_SHININESS, shine0);//반사될 물체 설정
	glMaterialfv(GL_FRONT, GL_EMISSION, emission0);//광원 설정
	glutSolidSphere(0.10, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//수성
	glRotated(k0, 0, 0, 1.0);
	glTranslatef(0.0, 0.25, 0.0);//y축 이동
	glRotated(k0, 0, 0, 1.0);
	k0 = k0 + 1.5;//자전과 공전
	GLfloat diffuse1[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat ambient1[] = { 0.0, 0.0,1.0, 1.0 };
	GLfloat specular1[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat light_pos1[] = { 0.0, 0.0, 0.5, 1.0 };
	GLfloat shine1 = 20.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos1);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular1);
	glMaterialf(GL_FRONT, GL_SHININESS, shine1);
	glutSolidSphere(0.02, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//금성
	glRotated(k1, 0, 0, 1.0);
	glTranslatef(0.0, 0.3, 0.0);//y축 이동
	glRotated(k1, 0, 0, 1.0);
	k1 = k1 + 1;
	GLfloat diffuse2[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat ambient2[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat specular2[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light2_pos[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat shine2 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light2_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse2);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular2);
	glMaterialf(GL_FRONT, GL_SHININESS, shine2);
	glutSolidSphere(0.02, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//지구
	glRotated(k2, 0, 0, 1.0);
	glTranslatef(0.0, 0.4, 0.0);//y축 이동
	glRotated(k2, 0, 0, 1.0);
	k2 = k2 + 0.5;
	GLfloat diffuse3[] = { 0.1, 0.6, 0.8, 1.0 };
	GLfloat ambient3[] = { 0.2, 0.5, 0.8, 1.0 };
	GLfloat specular3[] = { 0.4, 0.5, 0.1, 1.0 };
	GLfloat light_3[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat shine3 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_3);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient3);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse3);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular3);
	glMaterialf(GL_FRONT, GL_SHININESS, shine3);
	glutSolidSphere(0.02, 50000, 1000);

	glPushMatrix();//달그리기
	glRotated(k3, 0, 0, 1.0);
	k3 = k3 + 1;
	glTranslatef(0.0, 0.08, 0.0);//y축 이동
	glRotated(k3, 0, 0, 1.0);
	GLfloat diffuse4[] = { 0.1, 0.2, 0.7, 1.0 };
	GLfloat ambient4[] = { 0.8, 0.3, 0.4, 1.0 };
	GLfloat specular4[] = { 0.15, 0.2, 0.1, 1.0 };
	GLfloat light_4[] = { 0.45, 0.5, 0.5, 1.0 };
	GLfloat shine4 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_4);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient4);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse4);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular4);
	glMaterialf(GL_FRONT, GL_SHININESS, shine4);
	glutSolidSphere(0.01, 50000, 1000);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//화성
	glRotated(k4, 0, 0, 1.0);
	glTranslatef(0.0, 0.51, 0.0);//y축 이동
	k4 = k4 + 0.75;
	glRotated(k4, 0, 0, 1.0);
	GLfloat diffuse5[] = { 0.95, 0.5, 0.5, 1.0 };
	GLfloat ambient5[] = { 0.95, 0.5, 0.5, 1.0 };
	GLfloat specular5[] = { 0.95, 0.5, 0.5, 1.0 };
	GLfloat light_5[] = { 0.95, 0.5, 0.5, 1.0 };
	GLfloat shine5 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_5);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient5);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse5);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular5);
	glMaterialf(GL_FRONT, GL_SHININESS, shine5);
	glutSolidSphere(0.02, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//목성
	glRotated(k5, 0, 0, 1.0);
	glTranslatef(0.0, 0.65,0.0);//y축 이동
	k5 = k5 + 0.7;
	glRotated(k5, 0, 0, 1.0);
	GLfloat diffuse6[] = { 0.15, 0.5, 0.35, 1.0 };
	GLfloat ambient6[] = { 0.15, 0.5, 0.35, 1.0 };
	GLfloat specular6[] = { 0.15, 0.35, 0.5, 1.0 };
	GLfloat light_6[] = { 0.15, 0.35, 0.5, 1.0 };
	GLfloat shine6 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_6);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient6);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse6);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular6);
	glMaterialf(GL_FRONT, GL_SHININESS, shine6);
	glutSolidSphere(0.04, 50000, 1000);

	glPushMatrix();//위성1 그리기
	glRotated(k6, 0, 0, 1.0);
	k6 = k6 + 1;
	glTranslatef(0.0, 0.08, 0.0);//y축 이동
	glRotated(k6, 0, 0, 1.0);
	glutSolidSphere(0.01, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//위성2그리기
	glRotated(k7, 0, 0, 1.0);
	glTranslatef(0.0, 0.11, 0.0);//y축 이동
	glRotated(k7, 0, 0, 1.0);
	k7 = k7 + 1.4;
	glutSolidSphere(0.01, 50000, 1000);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//토성그리기
	glRotated(k8, 0, 0, 1.0);
	glTranslatef(0.0, 0.82, 0.0);//y축 이동
	glRotated(k8, 0, 0, 1.0);
	glRotated(45, 1.0, 0.0, 0.0);//자전축을 x축으로 45도 만큼 기울임
	k8 = k8 + 1.4;
	GLfloat diffuse9[] = { 0.25, 0.45, 0.35, 1.0 };
	GLfloat ambient9[] = { 0.25, 0.5, 0.35, 1.0 };
	GLfloat specular9[] = { 0.25, 0.45, 0.5, 1.0 };
	GLfloat light_9[] = { 0.25, 0.45, 0.35, 1.0 };
	GLfloat shine9 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_9);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient9);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse9);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular9);
	glMaterialf(GL_FRONT, GL_SHININESS, shine9);
	glutSolidSphere(0.02, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//천왕성
	glRotated(k10, 0, 0, 1.0);
	glTranslatef(0.0, 0.9, 0.0);//y축 이동
	glRotated(k10, 0, 0, 1.0);
	k10 = k10 + 1.3;
	GLfloat diffuse11[] = { 0.75, 0.5, 0.5, 1.0 };
	GLfloat ambient11[] = { 0.5, 0.75, 0.5, 1.0 };
	GLfloat specular11[] = { 0.5, 0.75, 0.5, 1.0 };
	GLfloat light_11[] = { 0.5, 0.85, 0.5, 1.0 };
	GLfloat shine11 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_11);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient11);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse11);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular11);
	glMaterialf(GL_FRONT, GL_SHININESS, shine11);
	glutSolidSphere(0.025, 50000, 1000);
	glPopMatrix();

	glPushMatrix();//해왕성
	glRotated(k11, 0, 0, 1.0);
	glTranslatef(0.0, 0.95, 0.0);//y축 이동
	glRotated(k11, 0, 0, 1.0);
	k11 = k11 + 0.9;
	GLfloat diffuse12[] = { 0.5, 0.25, 0.95, 1.0 };
	GLfloat ambient12[] = { 0.45, 0.55, 0.56, 1.0 };
	GLfloat specular12[] = { 0.15, 0.5, 0.5, 1.0 };
	GLfloat light_12[] = { 0.5, 0.85, 0.95, 1.0 };
	GLfloat shine12 = 80.0;
	glLightfv(GL_LIGHT0, GL_POSITION, light_12);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient12);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse12);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular12);
	glMaterialf(GL_FRONT, GL_SHININESS, shine12);
	glutSolidSphere(0.03, 50000, 1000);
	glPopMatrix();


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	

	
	glutSwapBuffers();
	glFlush();
}
void DoSpecial(int key, int x, int y)
{
	switch (key) {//방향키 조작에 따라 x,y축 변경
	case GLUT_KEY_RIGHT:
		XAngle += 10.0;
		break;
	case GLUT_KEY_LEFT:
		XAngle -= 10.0;
		break;
	case GLUT_KEY_UP:
		YAngle += + 10.0;

		break;
	case GLUT_KEY_DOWN:
		YAngle -= 10.0;;
		break;
	}
	glutPostRedisplay();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	glutCreateWindow("원그리기");//화면크기와 이름 지정
	glClearColor(0, 0, 0, 0);
	glutDisplayFunc(display);//원그리기 시작
	glutIdleFunc(display);
	glutSpecialFunc(DoSpecial);
	glutMainLoop();
}
//[CG]HW06_201302423_신종욱
