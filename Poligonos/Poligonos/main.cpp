#include <GL/glut.h>

float angle = 0.0f; // Ángulo de rotación
float scale = 1.0f; // Factor de escala
float tx = 0.0f, ty = 0.0f; // Desplazamiento

// Definir los vértices del polígono en coordenadas 2D
GLfloat vertices[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Definir la matriz de proyección
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

    // Definir la matriz de modelo-vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Dibujar el polígono
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
        // Rotar el polígono
        angle += 5.0f;
        break;
    case 'e':
        // Rotar el polígono
        angle -= 5.0f;
        break;
    case 's':
        // Escalar el polígono
        scale += 0.1f;
        break;
    case 'd':
        // Escalar el polígono
        scale -= 0.1f;
        break;
    case 't':
        // Trasladar el polígono
        tx += 0.1f;
        ty += 0.1f;
        break;
    case 'y':
        // Trasladar el polígono
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
    glutCreateWindow("Polígono con transformaciones");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
