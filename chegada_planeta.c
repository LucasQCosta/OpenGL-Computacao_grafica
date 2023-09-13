#include <GL/glut.h>
#include <math.h>

float radius = 0.1;  // Raio inicial do círculo
float step = 0.005;  // Quanto o raio deve aumentar a cada vez

void update(int value) {
    radius += step;  // Aumentar o raio

    // Redesenhar a tela
    glutPostRedisplay();

    // Se o raio é menor que 1, continue aumentando
    if (radius < 1.5) {
        glutTimerFunc(50, update, 0);  // Agendar próxima atualização
    }
}

void timer(int value) {
    // Começar a aumentar o raio depois de 5 segundos
    glutTimerFunc(50, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar o círculo
    glColor3f(0.0, 1.0, 0.0);  // Verde
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();


// Desenhar o quadrado
    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.9);
    glVertex2f(-1.0, 1.0);
    glColor3f(0.0, 0.0, 0.8);
    glVertex2f(-1.0, 0.4);
    glVertex2f( -0.4, 0.4); 
    glVertex2f( -0.4, 1.0);
    glEnd();

    // Desenhar o triângulo de cima
    glColor3f(0.9, 0.0, 0.0); // Vermelho mais claro
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.2);
    glColor3f(0.2, 0.0, 0.0); // Vermelho mais escuro
    glVertex2f(-0.4, 0.4);
    glVertex2f(-0.4, 1.0);
    glEnd();

    // Desenhar o triângulo de baixo da aeronave
    glColor3f(0.9, 0.0, 0.0); // Vermelho mais claro
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.2);
    glColor3f(0.2, 0.0, 0.0); // Vermelho mais escuro
    glVertex2f(-1, 0.4);
    glVertex2f(-0.4, 0.4);
    glEnd();

    // // Desenhar o triângulo da sombra
    // glColor3f(0.9, 0.0, 0.0); // Vermelho mais escuro
    // glBegin(GL_POLYGON);
    // glVertex2f(-0.4, 0.4);
    // glColor3f(0.5, 0.0, 0.0); // Vermelho escuro
    // glVertex2f(-0.4, 1);
    // glVertex2f(-0.3, 0.3);
    // glVertex2f(-1.0, 0.4);
    // glEnd();

    // Sombra do quadrado
    glColor3f(0.0, 0.0, 0.4); // Vermelho
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.4);
    glVertex2f(-1.0, 0.4);
    glVertex2f(-1.0, 0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.5, 1.0);
    glVertex2f(-0.4, 1);
    glVertex2f(-0.4, 1);
    glEnd();

    glColor3f(0.2, 0.0, 0.0); // Branco
    glBegin(GL_LINES);
        glVertex2f(-0.4, 0.4);  // Ponto inicial
        glVertex2f(-0.2, 0.2);   // Ponto final
    glEnd();

    glColor3f(0.5, 0.5, 0.0); // Branco
    glBegin(GL_LINES);
        glVertex2f(-0.4, 0.4);  // Ponto inicial
        glVertex2f(-0.5, 0.5);   // Ponto final
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Planeta em Expansão");

    glutDisplayFunc(display);
    glutTimerFunc(5000, timer, 0);  // Timer de 5 segundos

    glutMainLoop();

    return 0;
}
