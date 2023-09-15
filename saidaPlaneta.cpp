#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float dist = 0.0f;
float dist2 = 0.0f;
float auxDist = 0.0f;
float auxAng = 1.0f;
float ang = 0.0f;
int aux = 0;
int auxTime = 0;
float esc = 0;

// Função de desenho do círculo
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN); // Use GL_TRIANGLE_FAN para preencher o círculo
    glVertex2f(cx, cy); // Centro do círculo
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Ângulo atual em radianos
        float x = r * cosf(theta); // Coordenada x do ponto no círculo
        float y = r * sinf(theta); // Coordenada y do ponto no círculo
        glVertex2f(cx + x, cy + y); // Desenha o ponto
    }
    glEnd();
}


void drawRocket(){
    glPushMatrix();
    glRotatef(-45.0f + ang, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(-0.3f, dist-1.0, 0.0f);

    // Desenhar o corpo do foguete
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2, - 0.5);
        glVertex2f(0.2, -0.5);
        glVertex2f(0.2, 0.5);
        glVertex2f(-0.2, 0.5);
    glEnd();

    // Desenhar a ponta do foguete
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, 0.5);
        glVertex2f(0.2, 0.5);
        glVertex2f(0.0, 0.7);
    glEnd();

    // Desenhar as aletas do foguete
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, -0.5);
        glVertex2f(-0.5, -0.7);
        glVertex2f(-0.2, -0.7);

        glVertex2f(0.2, -0.5);
        glVertex2f(0.5, -0.7);
        glVertex2f(0.2, -0.7);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
    // glFlush();

}

void drawBackRocket(){
    glPushMatrix();

    glTranslatef(-1.4f + dist2, 0.7f, 0.0f);
    glScalef(0.64f-esc, 0.64f - esc, 1.0f);
    // Desenhar o corpo do foguete
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2, - 0.2);
        glVertex2f(0.2, -0.2);
        glVertex2f(0.2, 0.2);
        glVertex2f(-0.2, 0.2);
    glEnd();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, - 0.1);
        glVertex2f(0.1, -0.1);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.1, 0.1);
    glEnd();

    // Desenhar a ponta do foguete
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, 0.2);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.3, 0.3);
    glEnd();

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.2, -0.2);
        glVertex2f(0.3, 0.3);
    glEnd();
    
    
    glPopMatrix();
    glutSwapBuffers();

}

float r = 1;
void update(int value) {
    auxTime += 1;
    if (auxTime <= 220){
        if(auxDist <= r){
            dist += 0.02f;
            auxDist += 0.07;
        }
        else{
            r += 0.04;
            auxDist = 0;
            ang = -360 * auxAng/16;
            auxAng += 0.5;
        }
    }
    else if(auxTime <= 325){
        dist2 += 0.02f;
        esc += 0.005;
        }

    glutTimerFunc(30, update, 0);
    glutPostRedisplay();
    

}




// Função de desenho
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 1.0, 0.5); // Define a cor vermelha
    // Preenche o interior do círculo com a cor vermelha
    drawCircle(-1.0f, -1.0f, 1, 100);

    glColor3f(1.0, 1.0, 1.0); // Define a cor vermelha
    // Preenche o interior do círculo com a cor vermelha
    drawCircle(0.75f, 0.75f, 0.1, 16);
    
    glColor3f(1.0, 1.0, 1.0); // Define a cor vermelha
    // Preenche o interior do círculo com a cor vermelha
    drawCircle(0.75f, 0.75f, 0.1, 16);
    drawRocket();
    drawBackRocket();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Círculo Preenchido em OpenGL");
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}