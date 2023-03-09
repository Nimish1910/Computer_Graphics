#include <GL/freeglut.h>
#include <GL/gl.h>

/*
void Display(float x,float y)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);
		glVertex2f(x,y);
	glEnd();
	glFlush();
}

void simple_line(float x1,float y1,float x2,float y2){
	float dx = x2-x1;
	float dy = y2-y1;
	
	int step;
	
	if(dx>dy){
		step = abs(dx);
	}
	else{
		step = abs(dy);
	}
	
	int xinc,yinc;
	
	xinc = dx/(float)step;
	yinc = dy/(float)step;
	
	for(int i = 0;i<=step;i++){
		Display(x1,y1);
		x1 = x1 + xinc;
		y1 = y1 + yinc;
	}
	
}

*/

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


void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    // glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluOrtho2D(0.0,1500.0,0.0,900.0);
    /*glBegin(GL_LINES);
        glVertex2f(100.0,100.0);
        glVertex2f(1400.0,800.0);
    glEnd();*/
    /*glBegin(GL_TRIANGLES);
        glVertex2f(-150,-150);
        glVertex2f(0,100);
        glVertex2f(150,-150);
    glEnd();*/
    /*glBegin(GL_POLYGON);
        glVertex2f(350,-250);
        glVertex2f(400,-250);
        glVertex2f(400,-300);
        glVertex2f(350,-300);
    glEnd();*/
    /*
    simple_line(50, 100, 50,300);
    simple_line(50, 300, 250,300);
    simple_line(250, 300, 250,500);
    simple_line(250, 500, 450,500);
    simple_line(450, 500, 450,700);
    simple_line(450, 700, 650,700);
    simple_line(650, 100, 650,700);
    simple_line(50,100,650, 100);
	*/
	draw_line(100,100,700,700);
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
