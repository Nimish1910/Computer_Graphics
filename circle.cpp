#include <GL/freeglut.h>
#include <GL/gl.h>


void Display(float x,float y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();
}

void    EightWaySymmetricPlot(int xc,int yc,int x,int y){  
	Display(x+xc,y+yc);  
	Display(x+xc,-y+yc);  
	Display(-x+xc,-y+yc);  
	Display(-x+xc,y+yc);  
	Display(y+xc,x+yc);  
	Display(y+xc,-x+yc);  
	Display(-y+xc,-x+yc);  
	Display(-y+xc,x+yc);  
}  
  
    void BresenhamCircle(int xc,int yc,int r)  
   {  
	    int x=0,y=r,d=3-(2*r);  
	    EightWaySymmetricPlot(xc,yc,x,y);  
	  
	    while(x<=y) {  
		      if(d<=0){  
				d=d+(4*x)+6;  
		      }  
		     else{  
				d=d+(4*x)-(4*y)+10;  
				y=y-1;  
		      }  
		       x=x+1;  
		       EightWaySymmetricPlot(xc,yc,x,y);  
	      }  
 }  


void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0.0,1500.0,0.0,900.0);
    BresenhamCircle(750,450,300);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}


