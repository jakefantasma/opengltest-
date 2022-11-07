#pragma once
#include "../Context.hpp"
class Disparo : public Contexto::Coordenadas
{
private:
    int dano = 99;
public:
    Disparo(double x_, double y_) : Coordenadas(x_, y_){

                                 };
    Disparo() : Coordenadas(){

             };
    void draw()
    {
        //realizamos un calculo y nos movemos al pasar el limite 
        //destruimos 
        std::string nave_reg = "";
        nave_reg += std::to_string(this->getx()) + " - ";
        nave_reg += std::to_string(this->gety());
        Console->gotoxy(15, 10);
        Console->log("------------");
        Console->gotoxy(15, 10);
        Console->log(nave_reg);
        // glColor3f(1.0f, 1.0f, 1.0f);
        glColor3f(1.0f, 1.0f, 0.0f);
        glPushMatrix();
        glTranslatef(this->getx(), this->gety(), 0);
        glPointSize(4);
        glBegin(GL_LINES);
        glVertex2f(0.00f, 0.0f);
        glVertex2f(0.02f, 0.04f);
        glEnd();
        glPopMatrix();
    }
    
    ~Disparo();
};
