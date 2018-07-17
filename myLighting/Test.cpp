#include <stdio.h>
#include <cstdlib>

struct lightmaterial
{
	double ambient[4];
	double diffuse[4];
	double specular[4];
	double diffuselight;
	double specularlight;
	double ambientlight;

};//물체의 속성을 가진 구조체
lightmaterial identity;
//기본 속성을 전역으로 선언


struct RGBL
{
	double RGBLvalue[4];
};//RGBL의 구조체
enum PROP {AMB,DIFF,SPEC};//확산광 주변광 경면광을 나타내기위한 enum이다.
enum light{ GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, GL_LIGHT5, GL_LIGHT6, GL_LIGHT7, GL_LIGHTING};
//light의 세기에대해서 나타내기위한 enum이다.

void reset();
void myAmbient(light ID, struct RGBL coef);
void myDiffuse(light ID, struct RGBL coef);
void mySpecular(light ID, struct RGBL coef);
void printlight();

void mySetLight(light ID, PROP attri,struct RGBL coef) {
	if (attri == 0) {
		myAmbient(ID, coef);
	}
	else if(attri == 1) {
		myDiffuse(ID, coef);
	}
	else if (attri == 2) {
		mySpecular(ID, coef);
	}
	//들어온 PROP의 값에 따라 실행되는 함수가 선택된다.
}

void myAmbient(light ID, struct RGBL coef) {
	if (identity.ambientlight == 12880) {//ENABLE일 경우에만 실행
		identity.ambient[0] = coef.RGBLvalue[0];
		identity.ambient[1] = coef.RGBLvalue[1];
		identity.ambient[2] = coef.RGBLvalue[2];
		identity.ambient[3] = coef.RGBLvalue[3];
		identity.ambientlight = 16385 + ID;
	}
	else  printf("LightENABLE이 안되었습니다."); 

}
void myDiffuse(light ID, struct RGBL coef) {
	if (identity.diffuselight == 12880){
		identity.diffuse[0] = coef.RGBLvalue[0];
		identity.diffuse[1] = coef.RGBLvalue[1];
		identity.diffuse[2] = coef.RGBLvalue[2];
		identity.diffuse[3] = coef.RGBLvalue[3];
		identity.diffuselight = 16385 + ID;
	}
	else  printf("LightENABLE이 안되었습니다.");
}
void mySpecular(light ID, struct RGBL coef) {
	if (identity.specularlight == 12880){
		identity.specular[0] = coef.RGBLvalue[0];
		identity.specular[1] = coef.RGBLvalue[1];
		identity.specular[2] = coef.RGBLvalue[2];
		identity.specular[3] = coef.RGBLvalue[3];
		identity.specularlight = 16385 + ID;
	}
	else  printf("LightENABLE이 안되었습니다.");
}
void myAttenuation(double A, double B, double C, double Dist ) {
	double Attenuation = 1.0 / (A + B*Dist + C*Dist*Dist);
	identity.diffuselight *= Attenuation;
	identity.specularlight *= Attenuation;
	//거리에 따른 light 조절
}
void myLighting(light ID) {
	if (ID == 8) {
		identity.diffuselight = 12880;
		identity.specularlight = 12880;
		identity.ambientlight = 12880;
	}
}//GLEnable

void main(int argc, char **argv)
{
	reset();
	myLighting(GL_LIGHTING);
	struct RGBL red;
	red.RGBLvalue[0] = 1;
	red.RGBLvalue[1] = 0;
	red.RGBLvalue[2] = 0;
	red.RGBLvalue[3] = 1;

	struct RGBL redbule;
	redbule.RGBLvalue[0] = 0.5;
	redbule.RGBLvalue[1] = 0;
	redbule.RGBLvalue[2] = 0.5;
	redbule.RGBLvalue[3] = 1;

	struct RGBL redgreen;
	redgreen.RGBLvalue[0] = 0.5;
	redgreen.RGBLvalue[1] = 0.5;
	redgreen.RGBLvalue[2] = 0;
	redgreen.RGBLvalue[3] = 1;

	//////////////////////////////////////////////////////

	mySetLight(GL_LIGHT0, AMB, red);
	mySetLight(GL_LIGHT1, DIFF, redbule);
	mySetLight(GL_LIGHT2, SPEC, redgreen);
	printlight();

	myAttenuation(3, 5, 1, 10);
	printlight();

	///////////////////////////////////////
	reset();
	myLighting(GL_LIGHTING);

	mySetLight(GL_LIGHT1, AMB, redbule);
	mySetLight(GL_LIGHT2, DIFF, redgreen);
	mySetLight(GL_LIGHT3, SPEC, red);
	printlight();

	system("pause");
}
//[CG]HW05_201302423_신종욱
void reset() {
	

	identity.diffuselight=0;
	identity.specularlight=0;
	identity.ambientlight=0;

	identity.diffuse[0] = { 1.0 };
	identity.diffuse[1] = { 1.0 };
	identity.diffuse[2] = { 1.0 };
	identity.diffuse[3] = { 1.0 };

	identity.ambient[0] = { 1.0 };
	identity.ambient[1] = { 1.0 };
	identity.ambient[2] = { 1.0 };
	identity.ambient[3] = { 1.0 };

	identity.specular[0] = { 1.0 };
	identity.specular[1] = { 1.0 };
	identity.specular[2] = { 1.0 };
	identity.specular[3] = { 1.0 };

}
void printlight() {
	int i = 0;
	printf("Ambient RGBL : ");
	for (i = 0; i < 4; i++) {
		printf("%.1f ",identity.ambient[i]);
	}
	printf("%.1f \n", identity.ambientlight);

	printf("Diffuse RGBL : ");
	for (i = 0; i < 4; i++) {
		printf("%.1f ", identity.diffuse[i]);
	}
	printf("%.1f \n", identity.diffuselight);
	
	printf("Specular RGBL : ");
	for (i = 0; i < 4; i++) {
		printf("%.1f ", identity.specular[i]);
	}
	printf("%.1f \n\n", identity.specularlight);
}