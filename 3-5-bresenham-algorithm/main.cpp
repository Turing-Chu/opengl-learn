#include <GLUT/glut.h>
#include <cmath>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 250.0, 0.0, 350.0);
}

inline int Round(const float a) { return int(a + 0.5); }

// Bresenham line-drawing procedure for |m| < 1.0
void lineBres(int x0, int y0, int xEnd, int yEnd) {
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    // Determine which endpoint to use as start position
    if (x0 > xEnd) {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    } else {
        x = x0;
        y = y0;
    }
    glVertex2i(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyMinusDx;
        }
        glVertex2i(x, y);
    }
}

void lineSegment() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    lineBres(50, 50, 200, 300);
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
