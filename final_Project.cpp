#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

// Variável para controlar o deslocamento horizontal dos retângulos
float offset = 1.0f;
int tempo = 0;
float offset_y = 0.0f;
// Velocidade de deslocamento
float speed = 0.005f;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float dist = 0.0f;
float dist2 = 0.0f;
float auxDist = 0.0f;
float auxAng = 1.0f;
float ang = 0.0f;
int aux = 0;
float esc = 0;
float r = 1;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float distStar = 0.0f;
float distYrocket = 0.0f;
float distXrocket = 0.0f;

float escDetail = 0.7f;
float distDetail = 0.0f;

float angAst = -45.0f;
int switchAngAst = 0;

float attPosiX = 0;
float attPosiY = 0;
float initPosiAst = 1;
float auxAttPosiX = 0;
float auxAttPosiY = 0;

int auxTimeStar = 0;
int timeDetail = 0;


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float radius = 0.1;  // Raio inicial do círculo
float step = 0.005;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void ceu(){
    // Desenhar o ceu
    glColor3f(0.0, 0.8, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, -0.5);
    glVertex2f(1, -0.5);
    glEnd();
}

void terra(){
    // Desenhar o chão
    glColor3f(0.4, 0.4, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -0.5);
    glVertex2f(1, -0.5);
    glEnd();
    
}


void foguete(){
    glPushMatrix();
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(-1.3f, -0.3f+offset_y, 0.0f);

    // Desenhar o corpo do foguete
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.2, -0.5);
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
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, -0.5);
        glVertex2f(-0.5, -0.7);
        glVertex2f(-0.2, -0.7);

        glVertex2f(0.2, -0.5);
        glVertex2f(0.5, -0.7);
        glVertex2f(0.2, -0.7);
     glEnd();
    glPopMatrix();
}

void drawRocket(){
    glPushMatrix();
    glRotatef(-45.0f + ang, 0.0f, 0.0f, 1.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glTranslatef(-0.3f, dist-1.0, 0.0f);

    // Desenhar o corpo do foguete
    glColor3f(1.0, 0.0, 0.0);
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
    glColor3f(0.0, 0.0, 1.0);
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


void drawBackRocket2(){
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex2f(-1.0, 0.4);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f( -0.4, 0.4);
    glColor3f(1.0, 1.0, 0.0); 
    glVertex2f( -0.4, 1.0);
    glEnd();

    // Desenhar o triângulo de cima
    glColor3f(0.9, 0.9, 0.9); // Vermelho mais claro
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.4, 0.4);
    glVertex2f(-0.4, 1.0);
    glEnd();

    // Desenhar o triângulo de baixo da aeronave
    glColor3f(0.4, 0.4, 0.4); // Vermelho mais claro
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-1, 0.4);
    glVertex2f(-0.4, 0.4);
    glEnd();

    // Sombra do quadrado
    glColor3f(0.2, 0.2, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.4, 0.4);
    glVertex2f(-1.0, 0.4);
    glVertex2f(-1.0, 0.35);
    glVertex2f(-0.35, 0.35);
    glVertex2f(-0.35, 1);
    glVertex2f(-0.4, 1.0);
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

void stars2(){
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

void drawRocket2(){
    glPushMatrix();
    glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(distXrocket-0.0f, distYrocket -0.8f, 0.0f);
    glScalef(0.2f, 0.2f, 1.0f);

    // Desenhar o corpo do foguete
    glColor3f(1.0, 0.0, 0.0);
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
    glColor3f(0.0, 0.0, 1.0);
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

void movCena1(){
    glPushMatrix();
    // Loop para desenhar 10 retângulos
    for (int i = 0; i < 4; ++i) {
        // Loop para desenhar 10 retângulos
     // Calcula a posição x do retângulo com base no offset
        float x = i * 0.1f + offset;

        // Desenhar a parte superior do retângulo (verde)
        glColor3f(0.0f, 1.0f, 0.0f);  // Define a cor para verde
        glBegin(GL_QUADS);  // Começa a desenhar quadriláteros
        glVertex2f(x, -0.4f);
        glVertex2f(x, -0.3f);
        glVertex2f(x - 0.1f, -0.3f);
        glVertex2f(x - 0.1f, -0.4f);
        glEnd();  // Termina de desenhar

        // Desenhar a parte inferior do retângulo (marrom)
        glColor3f(0.6f, 0.3f, 0.0f);  // Define a cor para marrom
        glBegin(GL_QUADS);  // Começa a desenhar quadriláteros
        glVertex2f(x, -0.4f);
        glVertex2f(x, -0.5f);
        glVertex2f(x - 0.1f, -0.5f);
        glVertex2f(x - 0.1f, -0.4f);
        glEnd();  // Termina de desenhar
        if (tempo<220){
            float w = (i * 0.1f)/16 + offset - 0.45;
            // Desenhar a parte superior do retângulo - Pele Branca
            glColor3f(0.81f, 0.71f, 0.61f);  // Define a cor para verde
            glBegin(GL_QUADS);  // Começa a desenhar quadriláteros
            glVertex2f(w, -0.4f);
            glVertex2f(w, -0.3f);
            glVertex2f(w - 0.1f, -0.3f);
            glVertex2f(w - 0.1f, -0.4f);
            glEnd();  // Termina de desenhar

            // Desenhar a parte inferior do retângulo (marrom)
            glColor3f(0.6f, 0.3f, 0.0f);  // Define a cor para marrom
            glBegin(GL_QUADS);  // Começa a desenhar quadriláteros
            glVertex2f(w, -0.4f);
            glVertex2f(w, -0.5f);
            glVertex2f(w - 0.1f, -0.5f);
            glVertex2f(w - 0.1f, -0.4f);
            glEnd();  // Termina de desenhar
        }
        
    }
    glPopMatrix();
    
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

}

void keybord_test(GLubyte key, GLint x, GLint y)
{
  GLint m = glutGetModifiers();
  
//VERIFICAR TABELA ASCII QUANDO O CTRL ESTIVER PRECIONADO COM ALGUMA LETRA  
  if(m == GLUT_ACTIVE_CTRL && (GLint) key == 4)
    exit(EXIT_SUCCESS);
 
  
  //ESC = 27
  switch (key){
    case 100:
        distYrocket += 0.2;
        break;
    
    case 97:
        distYrocket -= 0.2;
        break;

    case 119:
        distXrocket -= 0.2;
        break;

    case 115:
        distXrocket += 0.2;
        break;

  }
    
}

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

void stars(){
    glPushMatrix();
    glBegin(GL_TRIANGLES);
    float cx =-1.0, aux = 0;
    float cy = -1.0;
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j<=20; j++){
            glVertex2f(cx-0.01f, cy); // Centro do círculo
            glVertex2f(cx+0.01f , cy);
            glVertex2f(cx , cy+0.01);
            cx += 0.2 + aux;
            aux += 0.001;
        }
        cx = -1.0;
        cy += 0.15;
    }
    glPopMatrix();
    glutSwapBuffers();
    
}

void update(int value) {
    //decorrer do tempo
    tempo += 1;
    if (tempo < 280){
        if (tempo < 200){
            offset -= speed;
        }else{
            offset = offset;
            if(tempo>226){
                offset_y+=0.05f;
            }
        }
    }
    else if (tempo < 610){
        if (tempo <= 500){
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
        else if(tempo <= 610){
            dist2 += 0.02f;
            esc += 0.005;
            }

    }
    else if(tempo < 900){
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
            //Logica Asteroides
        if(sqrt((attPosiX*attPosiX) + (attPosiY*attPosiY)) < 2){
             if (auxAttPosiX >= 0.03){
                auxAttPosiX = 0;
            }
            if (auxAttPosiY <= -0.03){
                auxAttPosiY = 0;
                }

            if(initPosiAst == 1){
                attPosiX += 0.01 - auxAttPosiX;
                attPosiY -= 0.01 - auxAttPosiY;
            }
            else{
               attPosiX += 0.01 - auxAttPosiX;
               attPosiY += 0.01 - auxAttPosiY; 
            }
        }
        else{
            attPosiY = 0;
            attPosiX = 0;
            auxAttPosiX += 0.006;
            auxAttPosiY -= 0.006;
            if(initPosiAst == 1){
                initPosiAst = -1;
            }
            else{
                initPosiAst = 1;
            }


        }
        //Logica colisão
        if((abs((-distXrocket) - (initPosiAst + attPosiY)) <= 0.02) && (abs((distYrocket-0.8f) - ( attPosiX)) <= 0.2)){
            distYrocket = 0;
            tempo = 611;

        }
    }
    else if(tempo<1100){
        radius += step;  // Aumentar o raio
    }
    

    glutTimerFunc(30, update, 0);
    glutPostRedisplay();
    

}

void planet3(){
    glColor3f(0.0, 1.0, 0.0);  // Verde
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159 / 180;
        glVertex2f(cos(angle) * radius, sin(angle) * radius);
    }
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    if (tempo < 280){
        glPushMatrix();
        ceu();
        terra();
        foguete();
        movCena1();
        glPushMatrix(); 
        glutSwapBuffers();
         
    }
    else if (tempo< 610){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        stars();
        drawCircle(-1.0f, -2.0f, 1, 100);

        //planeta
        glColor3f(0.0, 0.8, 0.0);
        drawCircle(-1.0f, -1.0f, 1, 100);

        //detalhe planeta
        glPushMatrix();
        glScalef(0.5,1,1);
        glColor3f(0.05, 0.0, 0.4);
        drawCircle(-0.9f, -0.9f, -0.4, 8);
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0); // Define a cor vermelha
        // Preenche o interior do círculo com a cor vermelha
        drawCircle(0.75f, 0.75f, 0.1, 16);

        glColor3f(1.0, 1.0, 1.0); // Define a cor vermelha
        // Preenche o interior do círculo com a cor vermelha
        drawCircle(0.75f, 0.75f, 0.1, 16);
        drawRocket();
        drawBackRocket();
        glutSwapBuffers();
        glFlush();  
    }
    else if(tempo<900){

        glColor3f(1.0, 1.0, 1.0);
        stars2();

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
        glTranslatef(attPosiX, attPosiY, 0.0f);
        drawCircle(0.0, 0.0f, 0.05, 100);
        glPopMatrix();


        drawRocket2();
        glutSwapBuffers();
        glFlush();

        }

    else if(tempo<1100){
        planet3();
        drawBackRocket2();
        glutSwapBuffers();
        glFlush();
    }
    
}

// Função principal
int main(int argc, char** argv) {
    // Inicializa o GLUT
    glutInit(&argc, argv);
    // Configura o modo de exibição
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Configura o tamanho da janela
    glutInitWindowSize(800, 600);
    // Cria a janela
    glutCreateWindow("Blocos em Movimento");
    // Registra a função de exibição
    glutKeyboardFunc(keybord_test);
    glutDisplayFunc(display);
    // Registra a função ociosa
    glutTimerFunc(30, update, 0);
    glutSwapBuffers();
    // Entra no loop principal do GLUT
    glutMainLoop();

    return 0;
}

