#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

float distStar = 0.0f;
float dist2 = 0.0f;

float escDetail = 0.7f;
float distDetail = 0.0f;

float angAst = -45.0f;
float auxAngAst = 0.0f;
int switchAngAst = 0;

float attPosi = 0;
float initPosiAst = 1;

float auxAng = 1.0f;
float ang = 0.0f;
float esc = 0;

int auxTimeStar = 0;
int timeDetail = 0;
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


void drawPlanet(float cx, float cy, float r, int num_segments) {
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

void drawPlanetDetail(float cx, float cy, float r, int num_segments) {
    if((0.18f - distDetail) <= -0.18f){
        glColor3f(1.0, 0.5, 0.5);
    }
    else{
        glColor3f(0.5, 1.5, 0.5);
    }
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

void stars(){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    float cx =-1.0, aux = 0;
    float cy = -1.0;
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j<=20; j++){
            glVertex2f(cx-0.01f - distStar, cy); // Centro do círculo
            glVertex2f(cx+0.01f - distStar, cy);
            glVertex2f(cx - distStar, cy+0.01);
            cx += 0.2 + aux;
            aux += 0.001;
        }
        cx = -1.0;
        cy += 0.15;
    }
    glPopMatrix();
    glutSwapBuffers();
    
}

void drawRocket(){
    glPushMatrix();
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    glScalef(0.2f, 0.2f, 1.0f);
    glTranslatef(-1.0f, -2.5f, 0.0f);

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


void update(int value) {
    timeDetail += 1;
    if (auxTimeStar == 4){
        distStar += 0.01f;
        auxTimeStar = 0;
    }
    
    if(timeDetail== 7){
        if ((0.18f - distDetail) > 0.001){
            escDetail -= 0.04f;
        }
        else if((0.18f - distDetail)<0.001){
            if((0.18f - distDetail)<-0.18f){

                distDetail = 0.0f;
                escDetail = 0.7f;        
            }
            escDetail -= -0.04f;
        }
        else{
            escDetail = 0;
        }
   
        distDetail += 0.01f;
        auxTimeStar += 1;
        timeDetail = 0;

        }

    if (attPosi < 2.0f){
        attPosi += 0.01;
    }
    else{
        attPosi = 0;
        if(initPosiAst == 1){
            initPosiAst = -1;
        }
        else{
            initPosiAst = 1; 
        }

        if(switchAngAst == 0){
            angAst = 45.0f + auxAngAst;
            switchAngAst = 1;
        }
        else{
            angAst = -45.0f - auxAngAst;
            switchAngAst = 0;
        }
        auxAngAst += 60;
    }
    
    
    glutTimerFunc(15, update, 0);
    glutPostRedisplay();
    

}





// Função de desenho
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1.0, 1.0, 1.0);
    stars();

    glColor3f(0.5, 0.5, 0.5); // Define a cor vermelha
    // Preenche o interior do círculo com a cor vermelha
    drawCircle(0.0f, 1.5f, 0.1, 16);


    glColor3f(1.0, 0.5, 0.5); // Define a cor vermelha
    // Preenche o interior do círculo com a cor vermelha
    drawPlanet(0.0f, 0.0f, 0.2, 100);


    glPushMatrix();
    glTranslatef(0.18f - distDetail, 0.0f, 0.0f);
    glScalef(1.0f - escDetail, 1.0f, 1.0f);
    // Preenche o interior do círculo com a cor vermelha
    drawPlanetDetail(0.0f, 0.0f, 0.05, 100);
    glPopMatrix();
    glutSwapBuffers();


    glColor3f(0.5, 0.5, 0.5); // Define a cor vermelha
    //Asteroide 1
    glPushMatrix();
    glTranslatef(0.0f, initPosiAst, 0.0f);
    glRotatef(angAst, 0.0f, 0.0f, 1.0f);
    glTranslatef(attPosi, 0, 0.0f);
    drawCircle(0.0, 0.0f, 0.05, 100);
    glPopMatrix();
    

    glPushMatrix();
    glTranslatef(0.0f, initPosiAst, 0.0f);
    glRotatef(-angAst, 0.0f, 0.0f, 1.0f);
    glTranslatef(attPosi, 0, 0.0f);
    drawCircle(0.0, 0.0f, 0.05, 100);
    glPopMatrix();
    glutSwapBuffers();

    drawRocket();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Círculo Preenchido em OpenGL");
    glutDisplayFunc(display);
    glutTimerFunc(200, update, 0);
    glutMainLoop();
    return 0;
}