#include <GLUT/glut.h>
#include <cmath>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 250.0, 0.0, 350.0);
}

inline int Round(const float a) { return int(a + 0.5); }

void lineDDA(int x0, int y0, int xEnd, int yEnd) {
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;

    if (fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }
    xIncrement = float(dx)/ float(steps);
    yIncrement = float(dy)/ float(steps);

    glVertex2i(Round(x), Round(y));
    for(k=0;k<steps;k++){
        x += xIncrement;
        y+=yIncrement;
        glVertex2i(Round(x), Round(y));
    }

}

void lineSegment() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    lineDDA(50,50,200,300);
    glEnd();
    glFlush();
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Digital Differential Analyzer");

    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
    return 0;
}

