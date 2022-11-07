#include "../Context.hpp"
class Bloques : public Contexto::Coordenadas
{
private:
    int live = 100;
    double z_b = 0.04f;
public:
    Bloques(double x_, double y_) : Coordenadas(x_, y_){};
    void draw()
    {
        //glColor3f(1.0f, 1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glPushMatrix();
        glTranslatef(this->getx(), this->gety(), 0);
        glPointSize(3);
        glBegin(GL_POINTS);
        glVertex2f(0.00f, 0.0f);
        glVertex2f(0.00f, z_b);
        glVertex2f(z_b, z_b);
        glVertex2f(z_b, 0.0f);
        glEnd();

        glPopMatrix();
    }
    ~Bloques();
};
