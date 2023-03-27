#include <GL/glut.h>

float angle = 0.0f; // �ngulo de rotaci�n
float scale = 1.0f; // Factor de escala
float tx = 0.0f, ty = 0.0f; // Desplazamiento

// Definir los v�rtices del pol�gono en coordenadas 2D
GLfloat vertices[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Definir la matriz de proyecci�n
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

    // Definir la matriz de modelo-vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Dibujar el pol�gono
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_POLYGON, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'r':
        // Rotar el pol�gono
        angle += 5.0f;
        break;
    case 'e':
        // Rotar el pol�gono
        angle -= 5.0f;
        break;
    case 's':
        // Escalar el pol�gono
        scale += 0.1f;
        break;
    case 'd':
        // Escalar el pol�gono
        scale -= 0.1f;
        break;
    case 't':
        // Trasladar el pol�gono
        tx += 0.1f;
        ty += 0.1f;
        break;
    case 'y':
        // Trasladar el pol�gono
        tx -= 0.1f;
        ty -= 0.1f;
        break;
    case 'q':
        // Salir del programa
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Pol�gono con transformaciones");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
