#include "headers.hpp"
#include "asset/Context.hpp"
bool update = false;
Nave *player1 = new Nave(0.02f, -0.94f);
Bloques *bloque = new Bloques(0.02f, 0.03f);
void customkey(unsigned char key, int x, int y)
{
    std::cout << key << std::endl;
    player1->keyboard(key, x, y);
}
using Contexto::Dibujador;
using Contexto::ListDibujado;
using Contexto::DibujarListado;
void renderScene()
{
    std::string mensaje = "aplicando render";
    Console->gotoxy(10, 20);
    if (update)
    {
        Console->warning(mensaje);
    }
    else
    {
        Console->error(mensaje);
    }
    update = !update;
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    DibujarListado();
    // bloque->draw();
    glFlush();
}
void changeSize(int w, int h)
{
    // set view
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char **argv)
{
    ListDibujado.push_back(new Dibujador([]()
                                         { player1->draw(); }));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 400);
    glutCreateWindow("By jake");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(customkey);
    glutMainLoop();
}