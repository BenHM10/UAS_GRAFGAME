#include <GL/glut.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=0.8;
void display(void);
void idle(void)
{
    xRotated =xRotated + 0.01;
    yRotated += 0.01;
    zRotated += 0.01;
    display();
}
void myinit()
{
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
void display(void)
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0.0,0.0,-5.0);

    glColor3f(0.9, 0.3, 0.2);

    glRotatef(xRotated,1.0,0.0,0.0);

    glRotatef(yRotated,0.0,1.0,0.0);

    glRotatef(zRotated,0.0,0.0,1.0);

    glScalef(1.0,1.0,1.0);

    glutSolidTeapot(size);

    glFlush();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

        glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640, 1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition(200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
    glutCreateWindow("TEKO");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    myInit();
    glutIdleFunc(idle);
    glutMainLoop();
}