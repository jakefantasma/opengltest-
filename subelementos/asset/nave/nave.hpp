#pragma once
#include "../Context.hpp"
#include "disparo.hpp"

using Contexto::Dibujador;
using Contexto::ListDibujado;
class Nave : public Contexto::Coordenadas
{
private:
    int live = 99;

public:
    Nave(double x_, double y_) : Coordenadas(x_, y_){

                                 };
    Nave() : Coordenadas(){

             };
    void draw()
    {
        std::string nave_reg = "";
        nave_reg += std::to_string(this->getx()) + " - ";
        nave_reg += std::to_string(this->gety());
        Console->gotoxy(10, 10);
        Console->log("             ");
        Console->gotoxy(10, 10);
        Console->log(nave_reg);
        // glColor3f(1.0f, 1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glPushMatrix();
        glTranslatef(this->getx(), this->gety(), 0);
        glPointSize(4);
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.00f, 0.0f);
        glVertex2f(0.02f, 0.04f);
        glVertex2f(0.04f, 0.0f);
        glEnd();
        glPopMatrix();
    }
    void Fire()
    {
        Console->gotoxy(2, 2);
        Console->error("fire");
        Disparo *dis = new Disparo(this->getx(), this->gety());
        Dibujador *d = new Dibujador([]()());
        ListDibujado.push_back(d);
    }

    void keyboard(unsigned char key, int x, int y)
    {
        switch (key)
        {
        case 119:
            this->up();
            break;
        case 97:
            this->left();
            break;
        case 115:
            this->down();
            break;
        case 100:
            this->right();
            break;
        case 113:
            Fire();
            break;

        default:
            break;
        }
    }
    ~Nave();
};
