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

	void draw_line(int xi,int yi,int xf,int yf){
		int dx = xf - xi;
		int dy = yf - yi;

		if(dx<0)  dx = -dx;

		if(dy<0) dy = -dy;

		int x = xi;
		int y = yi;

		int x_change = 1;
		int y_change = 1;

		if (xf<xi) x_change = - 1;
		if (yf<yi) y_change = - 1;
		
		if(dx==0){
			glBegin(GL_POINTS);
			for(int i = 0; i<dy;i++){
					y += y_change;
					glVertex2i(x,y);			
			}
		glEnd();
		}
		if(dy==0){
			glBegin(GL_POINTS);
			for(int i = 0; i<dx;i++){
					x += x_change;
					glVertex2i(x,y);			
			}
			glEnd();
		}
		glBegin(GL_POINTS);
		if(dx>dy){
			int p = 2*dy - dx;
			for(int i = 0;i< dx;i++){
				if(p>0){
					y += y_change;
					p += 2*(dy-dx);				
				}
				else{
					p += 2*dy;			
				}
				x += x_change;
				glVertex2i(x,y);
			}
		}
		else{
			int p = 2*dx - dy;
			for(int i = 0;i< dy;i++){
				if(p>0){
					x += x_change;
					p += 2*(dx-dy);				
				}
				else{
					p += 2*dx;			
				}
				y += y_change;
				glVertex2i(x,y);
			}
		}
	glEnd();	
}

	void EightWaySymmetricPlot(int xc,int yc,int x,int y){  
		Display(x+xc,y+yc);  
		Display(x+xc,-y+yc);  
		Display(-x+xc,-y+yc);  
		Display(-x+xc,y+yc);  
		Display(y+xc,x+yc);  
		Display(y+xc,-x+yc);  
		Display(-y+xc,-x+yc);  
		Display(-y+xc,x+yc);  
}  
  
    void BresenhamCircle(int xc,int yc,int r) {  
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


void renderFunction(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(-750.0,750.0,-450.0,450.0);
    BresenhamCircle(0,0,300);
	BresenhamCircle(0,0,200);
	BresenhamCircle(0,250,50);
	BresenhamCircle(0,-250,50);
	BresenhamCircle(250,0,50);
	BresenhamCircle(-250,0,50);
	BresenhamCircle(176.77,176.77,50);
	BresenhamCircle(-176.77,176.77,50);
	BresenhamCircle(176.77,-176.77,50);
	BresenhamCircle(-176.77,-176.77,50);
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


