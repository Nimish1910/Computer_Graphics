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


void Display_solid(float x,float y)
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(15);
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

void dotted_line(float x1,float y1,float x2,float y2){
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
		if(i%30==0){
			Display_solid(x1,y1);
			x1 = x1 + xinc;
			y1 = y1 + yinc;
		}
		else{
			x1 = x1 + xinc;
			y1 = y1 + yinc;
		}
		
	}
	
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
    
    /* Stair case
    simple_line(50, 100, 50,300);
    simple_line(50, 300, 250,300);
    simple_line(250, 300, 250,500);
    simple_line(250, 500, 450,500);
    simple_line(450, 500, 450,700);
    simple_line(450, 700, 650,700);
    simple_line(650, 100, 650,700);
    simple_line(50,100,650, 100);*/
    
    // dotted_line(100,100,700,700);
    
    // chess board
    dotted_line(600,300,600,455);
    dotted_line(615,315,600,435);
    dotted_line(630,300,630,455);
    dotted_line(645,315,645,435);
    dotted_line(660,300,660,455);
    dotted_line(675,315,675,435);
    dotted_line(690,300,690,455);
    dotted_line(705,315,705,435);
    dotted_line(720,300,720,455);
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1500,900);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}
