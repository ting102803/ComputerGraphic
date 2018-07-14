#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();//매트릭스를 push한다
	glColor3f(0, 0, 0);
	glRotatef(-45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 10.0, 0.0);//y축 이동
	glRotatef(45.0, 0.0, 0.0, 1.0);//사과 같은경우에는 미리 45도를 돌리고 돌려야지 대각선으로 이동한거처럼 보인다.
	glutWireSphere(0.20, 50000, 1000); // 크기, 꼭지점 개수,  폭의 갯수, 다각형의 꼭지점이 무한대로 가면 원처럼 느껴 진다.
	glPopMatrix();//만들걸 pop해서 나타내준다.


	glPushMatrix();
	glColor3f(0, 0, 0);
	glutWireSphere(0.20, 50000, 1000);//원을 그리고 컬러만 정하고 끝남
	glPopMatrix();
	glutSwapBuffers();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("원그리기");//화면크기와 이름 지정
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(display);//원그리기 시작
	glutMainLoop();
}
//[CG]201302423_HW01_신종욱
