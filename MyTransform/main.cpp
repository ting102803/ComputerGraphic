#include <glut.h>
#include <gl\GLU.h>
#include <gl\GL.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#define PI 3.141592
double getRadian(int num) 
{
	return num*(PI / 180);
}
struct Matrix
{
	double trix[4][4];
};
struct Vertex
{
	double trix[4];
};
Matrix Stack[100];
int Spoint=0;
struct Matrix Matrix_4x4mul(struct Matrix a, struct Matrix b) {
	struct Matrix result;
	int i, j;
	for (i = 0; i < 4; i++) {
	result.trix[i][0] = a.trix[i][0] * b.trix[0][0] + a.trix[i][1] * b.trix[1][0] + a.trix[i][2] * b.trix[2][0] + a.trix[i][3] * b.trix[3][0];
	result.trix[i][1] = a.trix[i][0] * b.trix[0][1] + a.trix[i][1] * b.trix[1][1] + a.trix[i][2] * b.trix[2][1] + a.trix[i][3] * b.trix[3][1];
	result.trix[i][2] = a.trix[i][0] * b.trix[0][2] + a.trix[i][1] * b.trix[1][2] + a.trix[i][2] * b.trix[2][2] + a.trix[i][3] * b.trix[3][2];
	result.trix[i][3] = a.trix[i][0] * b.trix[0][3] + a.trix[i][1] * b.trix[1][3] + a.trix[i][2] * b.trix[2][3] + a.trix[i][3] * b.trix[3][3];
}
	return result;
}
int mode = 0;
void mySetMatrixMode(int m) {
	if (m == 0) {
		mode = 0;
	}
	else {
		mode = 1;
	}
}
void myLoadIdentity() {
	Matrix newMatrix;
	int i = 0,j = 0;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++){
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}else
	newMatrix.trix[i][j] = 0;}
	Stack[Spoint] = newMatrix;
	
}

struct Matrix myPopMatrix() {
	if (Spoint == 0) {
		printf("Stack is empty");
	}
	return Stack[Spoint--];
}
void myPushMatrix() {
	Stack[Spoint + 1] = Stack[Spoint];
	Spoint++;
}
void myMatrixMul(int m) {
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
				Stack[Spoint].trix[i][j] *= m;
			}
}

struct Vertex myRunMatrix(Vertex v) {
	struct Vertex result;
	int i, j;
	for (i = 0; i < 4; i++) {
		result.trix[i] = v.trix[0] * Stack[Spoint].trix[i][0] + v.trix[1] * Stack[Spoint].trix[i][1] + v.trix[2] * Stack[Spoint].trix[i][2] + v.trix[3] * Stack[Spoint].trix[i][3];
	}
	return result;
}

void myTranslateX(int d) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[0][3] = d;
	Stack[Spoint]=Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}

void myTranslateY(int d) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[1][3] = d;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myTranslateZ(int d) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[2][3] = d;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myRotateX(int r) {

	double num = getRadian(r);
	double coss = cos(num);
	double sinn = sin(num);
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[1][1] = coss;
	newMatrix.trix[1][2] = -sinn;
	newMatrix.trix[2][1] = sinn;
	newMatrix.trix[2][2] = coss;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myRotateY(int r) {
	double num = getRadian(r);
	double coss = cos(num);
	double sinn = sin(num);
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else 
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[0][0] = coss;
	newMatrix.trix[0][2] = sinn;
	newMatrix.trix[2][0] = -sinn;
	newMatrix.trix[2][2] = coss;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myRotateZ(int r) {
	double num = getRadian(r);
	double coss = cos(num);
	double sinn = sin(num);
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
				newMatrix.trix[0][0] = coss;
				newMatrix.trix[0][1] = -sinn;
				newMatrix.trix[1][0] = sinn;
				newMatrix.trix[1][1] = coss;
			}
			else
			{
				newMatrix.trix[i][j] = 0;
			}
		}
	newMatrix.trix[0][0] = coss;
	newMatrix.trix[0][1] = -sinn;
	newMatrix.trix[1][0] = sinn;
	newMatrix.trix[1][1] = coss;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myScaleX(int s) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[0][0] = s;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}
void myScaleY(int s) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[1][1] = s;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}

void myScaleZ(int s) {
	Matrix newMatrix;
	int i = 0, j = 0;
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++) {
			if (i == j) {
				newMatrix.trix[i][j] = 1;
			}
			else
				newMatrix.trix[i][j] = 0;
		}
	newMatrix.trix[2][2] = s;
	Stack[Spoint] = Matrix_4x4mul(Stack[Spoint], newMatrix);
	if (mode == 1) { ; }
}

void main(int argc)
{
	mySetMatrixMode(0);
	Vertex test;
	test.trix[0] = 10;
	test.trix[1] = 60;
	test.trix[2] = 10;
	test.trix[3] = 1;
	Vertex test2;
	test2.trix[0] = 30;
	test2.trix[1] = 60;
	test2.trix[2] = 20;
	test2.trix[3] = 1;
	printf("%f %f %f %f\n", test.trix[0], test.trix[1], test.trix[2], test.trix[3]);
	printf("%f %f %f %f\n", test2.trix[0], test2.trix[1], test2.trix[2], test2.trix[3]);
	printf("%f \n\n", pow(test2.trix[0]- test.trix[0],2)+pow(test2.trix[1]- test.trix[1],2)+pow(test2.trix[2]- test.trix[2],2));
	mySetMatrixMode(0);
	myLoadIdentity();
	myPushMatrix();
	myTranslateX(3);
	myRotateZ(45);
	myScaleZ(2);
	myScaleX(2);
	myScaleY(2);
	test = myRunMatrix(test);
	myPopMatrix();

	myPushMatrix();
	myTranslateX(3);
	myRotateZ(45);
	test2 = myRunMatrix(test2);
	myPopMatrix();

	printf("%f %f %f %f\n",test.trix[0], test.trix[1],test.trix[2], test.trix[3]);
	printf("%f %f %f %f\n", test2.trix[0], test2.trix[1], test2.trix[2], test2.trix[3]);
	printf("%f \n\n", pow(test2.trix[0] - test.trix[0], 2) + pow(test2.trix[1] - test.trix[1], 2) + pow(test2.trix[2] - test.trix[2], 2));
	system("pause");

}
//[CG]HW02_201302423_½ÅÁ¾¿í
