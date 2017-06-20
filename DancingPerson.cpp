#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include<stdlib.h>
#include<time.h>
#include <Windows.h>
#include <thread>
static int Dance = 0, a = 20, b = 0, c = 0, d = 0;
GLUquadricObj *obj;
static int delay = 100;
int dance_Control = 1;
void Draw_Body();
void Draw_Neck();
void Draw_Head();
void Draw_L_Ball();
void Draw_L_UpperArm();
void Draw_L_LowerArm();
void Draw_L_Hand();
void Draw_R_Ball();
void Draw_R_UpperArm();
void Draw_R_LowerArm();
void Draw_R_Hand();
void Draw_L_U_Ball();
void Draw_L_UpperLeg();
void Draw_L_LowerLeg();
void Draw_L_Foot();
void Draw_R_U_Ball();
void Draw_R_UpperLeg();
void Draw_R_LowerLeg();
void Draw_R_Foot();
void draw_man(double x, double y);
void MyDisplay() {//��ü ����� ����
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	for (double i = 3.0; i >= -3.0; i -= 2.0) {
			draw_man(0.0, i);
		if (i - 0.8 >= -3.0) {
			draw_man(1.0, i - 0.8);
			draw_man(-1.0, i - 0.8);
		}
		
	}
		draw_man(2.0, 1.0);
		draw_man(-2.0, 1.0);
		draw_man(2.0, -1);
		draw_man(-2.0, -1.0);
		draw_man(3.0, 0);
		draw_man(-3.0, 0);
	glutSwapBuffers();
}
void draw_man(double x,double y)
{
	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glRotatef((GLfloat)Dance, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.31, 0.0);
	Draw_Body();//���׸���

	glPushMatrix();
	glTranslatef(0.0, 0.02, 0.0);
	glTranslatef(0.0, 0.3, 0.0);
	Draw_Neck();//��׸���

	glPushMatrix();
	glTranslatef(0.0, -0.19, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	Draw_Head();//�Ӹ��׸���

	glPopMatrix(); //�� ��ǥ��
	glPopMatrix(); //���� ��ǥ��

	glPushMatrix();
	glTranslatef(-0.1, 0.0, 0.0);
	glTranslatef(-0.40, 0.21, 0.0);
	Draw_L_Ball();  //���� �� �κ� ����(���)

	glPushMatrix();
	glRotatef(a, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.22, 0.0);//����� ����
	glTranslatef(0.0, 0.03, 0.0);
	Draw_L_UpperArm(); //���� ����� ����

	glPushMatrix();
	glTranslatef(0.0, 0.15, 0.0);
	Draw_L_Ball();  //���� �� �κ� ���� �Ʒ��κ�

	glPushMatrix();
	glRotatef(b, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.25, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	Draw_L_LowerArm();   //���� �ȸ� �Ʒ���

	glPushMatrix();
	glTranslatef(0.0, -0.05, 0.0);
	glTranslatef(0.0, -0.2, 0.0);
	Draw_L_Hand();   //���� ��
	glPopMatrix(); //���� �ȸ�
	glPopMatrix();  //���� �ȸ����
	glPopMatrix();  //���� ���
	glPopMatrix();  //���� �������
	glPopMatrix(); //����
				   //���� �Ȱ� �� ����

				   //�ٵ���� �ٽ� ����
	glPushMatrix();
	glTranslatef(0.1, 0.0, 0.0);
	glTranslatef(0.40, 0.21, 0.0);
	Draw_R_Ball();  //������ �� �κ� ���� ������ ���

	glPushMatrix();
	glRotatef(-a, 0.0, 0.0, 1.0);//astart
	glTranslatef(0.0, 0.22, 0.0);
	glTranslatef(0.0, 0.03, 0.0);
	Draw_R_UpperArm(); //������ �����

	glPushMatrix();
	glTranslatef(0.0, 0.15, 0.0);
	Draw_R_Ball();  //������ �� �κ� ����
	glPushMatrix();
	glRotatef(-b, 0.0, 0.0, 1.0);//bstart
								 //glRotatef(-a, 0.0, 0.0, 1.0);//astart
	glTranslatef(0.0, -0.25, 0.0);
	glTranslatef(0.0, -0.05, 0.0);
	Draw_R_LowerArm();   //������ �ȸ�
	glPushMatrix();
	glTranslatef(0.0, -0.05, 0.0);
	glTranslatef(0.0, -0.2, 0.0);
	Draw_R_Hand();   //������ ��
	glPopMatrix(); //������ �ȸ�
	glPopMatrix();  //������ �ȸ����
	glPopMatrix();  //������ ���
	glPopMatrix();  //������ �������
	glPopMatrix(); //����
	glPushMatrix();
	glTranslatef(-0.1, -0.0, 0.0);
	glTranslatef(-0.21, -0.2, 0.0);
	Draw_L_U_Ball();  //���� �ٸ� ���� ����
	glPushMatrix();
	glRotatef(c, 0.0, 0.0, 1.0);//c��ŸƮ
	glTranslatef(0.0, 0.33, 0.0);
	glTranslatef(0.0, 0.03, 0.0);

	Draw_L_UpperLeg();  //���� �����
	glPushMatrix();
	glTranslatef(0.15, -0.03, 0.0);
	glTranslatef(0.0, 0.18, 0.0);
	Draw_L_U_Ball();  //���� �ٸ� ���� ����
	glPushMatrix();
	glRotatef(d, 0.0, 0.0, 1.0);

	glTranslatef(0.0, -0.22, 0.0);
	glTranslatef(0.0, -0.02, 0.0);
	Draw_L_LowerLeg();  //���� �ٸ�
	glPushMatrix();
	glTranslatef(0.0, -0.02, 0.0);
	glTranslatef(0.0, -0.13, 0.0);
	Draw_L_Foot();  //���� ��
	glPopMatrix(); //���� �ٸ�
	glPopMatrix();  //�ٸ� ����
	glPopMatrix();  //���� �����
	glPopMatrix(); //���� �ٸ����۰���
	glPopMatrix(); //����
	glTranslatef(0.1, -0.0, 0.0);
	glTranslatef(0.21, -0.2, 0.0);
	Draw_R_U_Ball();  //������ �ٸ� ���� ����
	glPushMatrix();
	glRotatef(-d, 0.0, 0.0, 1.0);//c��ŸƮ
	glTranslatef(0.0, 0.33, 0.0);
	glTranslatef(0.0, 0.03, 0.0);
	Draw_R_UpperLeg();  //������ �����
	glPushMatrix();
	glTranslatef(-0.15, -0.03, 0.0);
	glTranslatef(0.0, 0.18, 0.0);
	Draw_R_U_Ball();  //������ �ٸ� ���� ����
	glPushMatrix();
	glTranslatef(0.0, -0.22, 0.0);
	glTranslatef(0.0, -0.02, 0.0);
	Draw_R_LowerLeg();  //������ �ٸ�
	glPushMatrix();
	glTranslatef(0.0, -0.02, 0.0);
	glTranslatef(0.0, -0.13, 0.0);
	Draw_R_Foot();  //������ ��
	glPopMatrix(); //������ �ٸ�
	glPopMatrix();  //������ �ٸ� ����
	glPopMatrix();  //������ �����
	glPopMatrix(); //������ �ٸ� ���� ����
	glPopMatrix(); //����
	glPushMatrix();
	glColor3f(0.450980, 0.13333, 0.66274);
	glTranslatef(0.0, 1.6, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.97, 0.75, 0.25, 10, 1);
	glPopMatrix();
}
void mouse_handler(int btn, int state, int x, int y)
{
	if (btn == GLUT_LEFT_BUTTON   && state == GLUT_DOWN)
	{
		Dance -= 180;
	}
	if (btn == GLUT_RIGHT_BUTTON   && state == GLUT_DOWN)
	{
		if (dance_Control == 1)
			dance_Control = 0;
		else
			dance_Control = 1;
	}
	glutPostRedisplay();
}
void timer()
{
	a = rand() % 150;
	b = rand() % 90;
	d = rand() % 50;
	if(dance_Control==1) //ȸ���� ���߰ų� �����ų� (������ ��ư�� ���� �����ȴ�)
		Dance += 10;
	Sleep(100);
	glutPostRedisplay();
}
void Draw_Body()//���κ��� �׷��ִ� �Լ���
{
	obj = gluNewQuadric();
	gluQuadricDrawStyle(obj, GLU_FILL);
	glScalef(0.2, 1.0, 0.1);
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.25, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.4, 0.55, 0.25, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.55, 1.3, 0.4, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glScalef(0.9, 0.20, 0.7);
	glTranslatef(0.0, -0.78, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.4235294);
	glColor3f(0.27843, 0.36078, 0.9764);

	gluCylinder(obj, 0.55, 0.4, 0.57, 10, 1);//���׸��� �κ�
	glPopMatrix();
}
void Draw_Neck()
{
	glScalef(2.0, -0.5, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 0.13, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	gluCylinder(obj, 0.05, 0.05, 0.2, 10, 1);
	glPopMatrix();
}
void Draw_L_Ball()
{
	glScalef(2.0, -0.5, 1.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	glutWireSphere(0.04, 20, 20);
}
void Draw_Head()
{
	glColor3f(1.0, 0.8392156, 0.4235294);
	glPushMatrix();
	glTranslatef(-0.2, 0.3, 0.0);
	glRotatef(-90, 0.0, 1.0, 1.0);

	glPopMatrix();
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.3, 0.2, 0.5, 10, 1);
	glPopMatrix();

	glColor3f(1.0, 0.8392156, 0.4235294);
	glutSolidSphere(0.2, 20, 20);

	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.4, 0.2, 0.19, 10, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.1, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	gluCylinder(obj, 0.3, 0.3, 0.05, 10, 1);
	glPopMatrix();
}
void Draw_L_UpperArm()
{
	glScalef(0.3, 1.5, 0.9);
	glPushMatrix();
	glTranslatef(0.0, 0.13, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	gluCylinder(obj, 0.15, 0.15, 0.3, 10, 1);
	glPopMatrix();
}
void Draw_L_LowerArm()
{
	glScalef(0.3, 2.5, 0.9);
	glPushMatrix();
	glTranslatef(0.0, 0.1, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	gluCylinder(obj, 0.28, 0.18, 0.3, 10, 1);
	glPopMatrix();
}
void Draw_L_Hand()
{
	glScalef(1.0, -0.5, 1.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	glutWireSphere(0.1, 20, 20);
}
void Draw_R_Ball()
{
	glScalef(2.0, -0.5, 1.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	glutWireSphere(0.04, 20, 20);
}
void Draw_R_UpperArm()
{
	glScalef(0.34, 1.5, 0.9);
	glPushMatrix();
	glTranslatef(0.0, 0.13, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	gluCylinder(obj, 0.15, 0.15, 0.3, 10, 1);
	glPopMatrix();
}
void Draw_R_LowerArm()
{
	glScalef(0.3, 2.5, 0.9);
	glPushMatrix();
	glTranslatef(0.0, 0.1, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	gluCylinder(obj, 0.28, 0.18, 0.3, 10, 1);
	glPopMatrix();
}
void Draw_R_Hand()
{
	glScalef(1.0, -0.5, 1.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	glutWireSphere(0.1, 20, 20);
}
void Draw_L_U_Ball()
{
	glPushMatrix();
	glScalef(2.0, -0.5, 1.0);
	glColor3f(1.0, 0.8392156, 0.4235294);
	glColor3f(0.27843, 0.36078, 0.9764);
	glutWireSphere(0.04, 20, 20);
	glPopMatrix();
	glScalef(2.0, -0.5, 1.0);
}
void Draw_L_UpperLeg()
{
	glColor3f(1.0, 0.8392156, 0.4235294);
	glPushMatrix();
	glScalef(0.4, 3, 1.5);
	glTranslatef(0.1, 0.12, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.27843, 0.36078, 0.9764);
	gluCylinder(obj, 0.1, 0.25, 0.25, 10, 1);
	glPopMatrix();
	glScalef(0.25, 2.5, 0.3);
}
void Draw_L_LowerLeg()
{
	glPushMatrix();
	glScalef(0.4, 2, 1.5);
	glTranslatef(0.04, 0.1, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.27843, 0.36078, 0.9764);
	gluCylinder(obj, 0.2, 0.3, 0.2, 10, 1);
	glPopMatrix();
	glScalef(0.5, 1.5, 0.3);

}
void Draw_L_Foot()
{
	glScalef(1.95, 0.1, 3.0);
	glColor3f(0.0, 0.0, 0.0);

	glutSolidCube(0.3);
}
void Draw_R_U_Ball()
{
	glScalef(2.0, -0.5, 1.0);
	glColor3f(0.27843, 0.36078, 0.9764);
	glutWireSphere(0.04, 20, 20);
}
void Draw_R_UpperLeg()
{

	glColor3f(1.0, 0.8392156, 0.4235294);
	glPushMatrix();
	glScalef(0.4, 3, 1.5);
	glTranslatef(-0.1, 0.12, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.27843, 0.36078, 0.9764);
	gluCylinder(obj, 0.1, 0.25, 0.25, 10, 1);
	glPopMatrix();
	glScalef(0.25, 2.5, 0.3);
}
void Draw_R_LowerLeg()
{
	glPushMatrix();
	glScalef(0.4, 2, 1.5);
	glTranslatef(0.04, 0.1, 0.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	glColor3f(0.27843, 0.36078, 0.9764);
	gluCylinder(obj, 0.2, 0.3, 0.2, 10, 1);
	glPopMatrix();
	glScalef(0.5, 1.5, 0.3);

}
void Draw_R_Foot()
{
	glScalef(1.95, 0.1, 3.0);
	glColor3f(0.0, 0.0, 0.0);
	glutSolidCube(0.3);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("�׷��Ƚ� ��������Ʈ : Let's tab dance party time~~!!!!");
	srand(time(NULL));
	glClearColor(1.0, 0.98, 0.70196, 0.2156);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
	glutDisplayFunc(MyDisplay);
	glutIdleFunc(timer);
	glutMouseFunc(mouse_handler);
	//glutTimerFunc(delay, timer, 0);
	//glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}