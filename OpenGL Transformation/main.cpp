#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();//��Ʈ������ push�Ѵ�
	glColor3f(0, 0, 0);
	glRotatef(-45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 10.0, 0.0);//y�� �̵�
	glRotatef(45.0, 0.0, 0.0, 1.0);//��� ������쿡�� �̸� 45���� ������ �������� �밢������ �̵��Ѱ�ó�� ���δ�.
	glutWireSphere(0.20, 50000, 1000); // ũ��, ������ ����,  ���� ����, �ٰ����� �������� ���Ѵ�� ���� ��ó�� ���� ����.
	glPopMatrix();//����� pop�ؼ� ��Ÿ���ش�.


	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireSphere(0.20, 50000, 1000);//���� �׸��� �÷��� ���ϰ� ����
	glPopMatrix();
	glutSwapBuffers();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("���׸���");//ȭ��ũ��� �̸� ����
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(display);//���׸��� ����
	glutMainLoop();
}
//[CG]201302423_HW01_������
