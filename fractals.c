#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
int n ;

void recurse(x1 ,y1 ,x2 ,y2 ,x3 ,y3 ,a1 ,b1 ,a2 ,b2 ,a3 , b3)
{
	static int i = 1, j= 1, k = 1;
    //top
	if(i<n)
	{
		int p1 = (a1+x3)/2, q1 = (b1+y3)/2,
		p2 = (a2+x3)/2, q2 = (b2+y3)/2,
		p3 = (a1+a2)/2, q3 = (b1+b2)/2;
		
	glBegin(GL_LINE_LOOP);
	glVertex2i(p1, q1);
	glVertex2i(p2, q2);
	glVertex2i(p3, q3);
	glEnd();
		glFlush();
	i++;
	recurse(a1 ,b1 ,a2 ,b2 ,x3 ,y3 ,p1 ,q1 ,p2 ,q2 ,p3 , q3);
printf("%d\n",i);

//left
		int m1 = (x1+a1)/2, n1 = (y1+b1)/2,
		m2 = (a1+a3)/2, n2 = (b1+b3)/2,
		m3 = (x1+a3)/2, n3 = (y1+b3)/2	  ;
		
	glBegin(GL_LINE_LOOP);
	glVertex2i(m1, n1);
	glVertex2i(m2, n2);
	glVertex2i(m3, n3);
	glEnd();
		glFlush();
	recurse(x1 ,y1 ,a3 ,b3 ,a1 ,b1 ,m1 ,n1 ,m2 ,n2 ,m3 , n3);
	
//right	
		int v1 = (a2+a3)/2, u1 = (b2+b3)/2,
		v2 = (x2+a2)/2, u2 = (y2+b2)/2,
		v3 = (x2+a3)/2, u3 = (y2+b3)/2 ;		
	glBegin(GL_LINE_LOOP);
	glVertex2i(v1, u1);
	glVertex2i(v2, u2);
	glVertex2i(v3, u3);
	glEnd();
	glFlush();	
k++;
	recurse(a3 ,b3 ,x2 ,y2 ,a2 ,b2 ,v1 ,u1 ,v2 ,u2 ,v3 , u3);
	glEnd();
		
		i--;
}
}
void drawFractals(void)
{
	int x1 = 0  , y1 = 0,
	    x2 = 800, y2 = 0,
	    x3 = 400, y3 = 800,
	    a1 = (x1+ x3)/2, b1 = (y1+y3)/2,
	    a2 = (x2+ x3)/2, b2 = (y2+y3)/2,
	    a3 = (x1+ x2)/2, b3 = (y1+y2)/2;
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(a1, b1);
	glVertex2i(a2, b2);
	glVertex2i(a3, b3);
	glEnd();
	
	recurse(x1 ,y1 ,x2 ,y2 ,x3 ,y3 ,a1 ,b1 ,a2 ,b2 ,a3 , b3);
	glFlush();
	
}
void Init()
{
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50 ,800 ,-50 ,800);
}
int main(int argc, char **argv)
{
	printf("Enter the size of fractal\n");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Draw Fractals");
	Init();
	glutDisplayFunc(drawFractals);
	glutMainLoop();
	return 0;
}
