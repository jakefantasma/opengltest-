#include "headers.hpp"
bool update = false;
struct Coord
{
    double x = 0;
    double y = 0;
};
Coord player_1;
Coord player_2;
void customkey(unsigned char key, int x, int y)
{
    std::cout << key << std::endl;
    
    if (key == 119)
    {
        player_1.x = player_1.x + 0.02f;
    }
    if (key == 115)
    {
        player_1.x = player_1.x - 0.02f;
    }

    if (key == 100)
    {
        player_2.y = player_2.y + 0.02f;
    }
    if (key == 97)
    {
        player_2.y = player_2.y - 0.02f;
    }
}
void drawCube(double x, double y, float cfa, float cfb, float cfc)
{
    glColor3f(cfa, cfb, cfc);
    glPushMatrix();
    glTranslatef(x, y, 0);
    glPointSize(10);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.05f);
    glEnd();
    glPopMatrix();
}
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
    drawCube(player_1.x, player_1.y, 1.0f, 1.0f, 1.0f);
    drawCube(player_2.x, player_2.y, 1.0f, 1.0f, 0.0f);
    glFlush();
    // Sleep(1); // add to fix bug
}
void changeSize(int w, int h)
{
    // set view
    // gluOrtho2D(0, v_x, v_y, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 900);
    glutCreateWindow("By jake");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(customkey);
    glutMainLoop();
}