#include <glut.h>
#include <glaux.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#pragma comment(lib,"glaux.lib")
#pragma comment(lib,"legacy_stdio_definitions.lib")

double k0, k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
double S;
float XAngle = 0.0;
float YAngle = 0.0;
GLUquadricObj *sphere[13];
unsigned int ids[13];

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D); 
	GLfloat ambientLight0[] = { 0.2,0.2,0.2,1.0 };
	GLfloat diffuseLight0[] = { 0.8,0.8,0.8,1.0 };
	GLfloat specularLight0[] = { 0.9,0.9,0.9,1.0 };
	GLfloat light0pos[] = { 100,100,-100, 1.0 };//�ϴ� �߾ӿ� ������ �����Ѵ�

	
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_POSITION, light0pos);


	GLfloat ambientref[] = { 0.2,0.2,0.2,1.0 };
	GLfloat diffuseref[] = { 0.6,0.6,0.8,1.0 };
	GLfloat specref[] = { 1.0,1.0,1.0,1.0 };

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseref);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientref);
	glMaterialf(GL_FRONT, GL_SHININESS, 128);
	//�༺���� ǥ�� ������ �����Ͽ� �������Ͽ� ���� �ߺ��̵��� ����

	glRotated(XAngle, 1.0, 0.0, 0.0);//���� ���������� x�� ȸ��
	glRotated(YAngle, 0.0, 1.0, 0.0);//���� ���������� y�� ȸ��
	

	glPushMatrix();
	glRotated(S, 0, 0, 1.0);
	S += 0.15;//�¾� ����
	glBindTexture(GL_TEXTURE_2D, ids[0]); 
	GLfloat plane_coef_s[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat plane_coef_t[] = { 0.0, 1.0, 0.0, 1.0 };
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[0]);
	gluQuadricTexture(sphere[0], 1);
	gluSphere(sphere[0], 0.1, 30, 30);//�¾翡 �ؽ��� ����
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();



	glPushMatrix();//����
	glRotated(k0, 0, 0, 1.0);
	glTranslatef(0.0, 0.25, 0.0);//y�� �̵�
	glRotated(k0, 0, 0, 1.0);
	k0 = k0 + 0.3;//������ ����
	glBindTexture(GL_TEXTURE_2D, ids[1]); 
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[1]);
	gluQuadricTexture(sphere[1], 1);
	gluSphere(sphere[1], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);//������ �ؽ��� ����
	glPopMatrix();

	glPushMatrix();//�ݼ�
	glRotated(k1, 0, 0, 1.0);
	glTranslatef(0.0, 0.3, 0.0);//y�� �̵�
	glRotated(k1, 0, 0, 1.0);
	k1 = k1 + 0.2;
	glBindTexture(GL_TEXTURE_2D, ids[2]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[2]);
	gluQuadricTexture(sphere[2], 1);
	gluSphere(sphere[2], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glPushMatrix();//����
	glRotated(k2, 0, 0, 1.0);
	glTranslatef(0.0, 0.4, 0.0);//y�� �̵�
	glRotated(k2, 0, 0, 1.0);
	k2 = k2 + 0.15;
	glBindTexture(GL_TEXTURE_2D, ids[3]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[3]);
	gluQuadricTexture(sphere[3], 1);
	gluSphere(sphere[3], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glutSolidSphere(0.02, 50000, 1000);

	glPushMatrix();//�ޱ׸���
	glRotated(k3, 0, 0, 1.0);
	k3 = k3 + 0.01;
	glTranslatef(0.0, 0.08, 0.0);//y�� �̵�
	glRotated(k3, 0, 0, 1.0);
	glBindTexture(GL_TEXTURE_2D, ids[4]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[4]);
	gluQuadricTexture(sphere[4], 1);
	gluSphere(sphere[4], 0.01, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//ȭ��
	glRotated(k4, 0, 0, 1.0);
	glTranslatef(0.0, 0.51, 0.0);//y�� �̵�
	k4 = k4 + 0.1;
	glRotated(k4, 0, 0, 1.0);
	glBindTexture(GL_TEXTURE_2D, ids[5]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[5]);
	gluQuadricTexture(sphere[5], 1);
	gluSphere(sphere[5], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glPushMatrix();//��
	glRotated(k5, 0, 0, 1.0);
	glTranslatef(0.0, 0.65, 0.0);//y�� �̵�
	k5 = k5 + 0.09;
	glRotated(k5, 0, 0, 1.0);
	glBindTexture(GL_TEXTURE_2D, ids[6]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[6]);
	gluQuadricTexture(sphere[6], 1);
	gluSphere(sphere[6], 0.04, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);

	glPushMatrix();//����1 �׸���
	glRotated(k6, 0, 0, 1.0);
	k6 = k6 + 0.061;
	glTranslatef(0.0, 0.08, 0.0);//y�� �̵�
	glRotated(k6, 0, 0, 1.0);
	glBindTexture(GL_TEXTURE_2D, ids[7]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[7]);
	gluQuadricTexture(sphere[7], 1);
	gluSphere(sphere[7], 0.01, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glPushMatrix();//����2�׸���
	glRotated(k7, 0, 0, 1.0);
	glTranslatef(0.0, 0.11, 0.0);//y�� �̵�
	glRotated(k7, 0, 0, 1.0);
	k7 = k7 + 0.04;
	glBindTexture(GL_TEXTURE_2D, ids[8]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[8]);
	gluQuadricTexture(sphere[8], 1);
	gluSphere(sphere[8], 0.01, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//�伺�׸���
	glRotated(k8, 0, 0, 1.0);
	glTranslatef(0.0, 0.82, 0.0);//y�� �̵�
	glRotated(k8, 0, 0, 1.0);
	glRotated(45, 1.0, 0.0, 0.0);//�������� x������ 45�� ��ŭ �����
	k8 = k8 + 0.07;
	glBindTexture(GL_TEXTURE_2D, ids[9]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[9]);
	gluQuadricTexture(sphere[9], 1);
	gluSphere(sphere[1], 0.03, 30, 30);

	glPushMatrix();//�伺�� �� �׸���
	glBindTexture(GL_TEXTURE_2D, ids[12]);
	gluQuadricTexture(sphere[12], 1);
	gluDisk(sphere[12], 0.1, 0.12, 10, 8);//gluDisk�� �ؽ��ĸ����Ͽ� �����¸� ����
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//õ�ռ�
	glRotated(k9, 0, 0, 1.0);
	glTranslatef(0.0, 0.9, 0.0);//y�� �̵�
	glRotated(k9, 0, 0, 1.0);
	k9 = k9 + 0.05;
	glBindTexture(GL_TEXTURE_2D, ids[10]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[10]);
	gluQuadricTexture(sphere[10], 1);
	gluSphere(sphere[10], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();

	glPushMatrix();//�ؿռ�
	glRotated(k10, 0, 0, 1.0);
	glTranslatef(0.0, 0.95, 0.0);//y�� �̵�
	glRotated(k10, 0, 0, 1.0);
	k10 = k10 + 0.03;
	glBindTexture(GL_TEXTURE_2D, ids[11]);
	glEnable(GL_TEXTURE_GEN_S);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, plane_coef_s);
	glEnable(GL_TEXTURE_GEN_T);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, plane_coef_t);
	glBindTexture(GL_TEXTURE_2D, ids[11]);
	gluQuadricTexture(sphere[11], 1);
	gluSphere(sphere[11], 0.02, 30, 30);
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutSwapBuffers();
	glFlush();
}

void SetupTexture()
{

	AUX_RGBImageRec *tex[13]; /* structure to contain a texture image */
	tex[0] = auxDIBImageLoad("Sun.bmp");
	tex[1] = auxDIBImageLoad("Mercury.bmp");
	tex[2] = auxDIBImageLoad("Venus.bmp");
	tex[3] = auxDIBImageLoad("Earth.bmp");
	tex[4] = auxDIBImageLoad("Moon.bmp");
	tex[5] = auxDIBImageLoad("Mars.bmp");
	tex[6] = auxDIBImageLoad("Jupiter.bmp");
	tex[7] = auxDIBImageLoad("Io.bmp");
	tex[8] = auxDIBImageLoad("Europa.bmp");
	tex[9] = auxDIBImageLoad("Saturn.bmp");
	tex[10] = auxDIBImageLoad("Uranus.bmp");
	tex[11] = auxDIBImageLoad("Neptune.bmp");
	tex[12] = auxDIBImageLoad("Saturn_Ring.bmp");//tex�迭�� bmp���� ����
	glGenTextures(13, ids); 
	for (int k = 0; k < 13; k++) {
		sphere[k] = gluNewQuadric();
		gluQuadricTexture(sphere[k], GL_TRUE);
	glBindTexture(GL_TEXTURE_2D, ids[k]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, tex[k]->sizeX, tex[k]->sizeY, 0, GL_RGB,
		GL_UNSIGNED_BYTE, tex[k]->data); 
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	}//���� bmp�� �ؽ��Ŀ� �����ϸ鼭 ����� ����
	}


void DoSpecial(int key, int x, int y)
{
	switch (key) {//����Ű ���ۿ� ���� x,y�� ����
	case GLUT_KEY_RIGHT:
		XAngle += 10.0;
		break;
	case GLUT_KEY_LEFT:
		XAngle -= 10.0;
		break;
	case GLUT_KEY_UP:
		YAngle += +10.0;

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
	glutCreateWindow("�¾��׸���");//ȭ��ũ��� �̸� ����
	glClearColor(0, 0, 0, 0);
	SetupTexture();//�ؽ��� ����
	glutDisplayFunc(display);//�׸��� ����
	glutIdleFunc(display);
	glutSpecialFunc(DoSpecial);
	glutMainLoop();
}