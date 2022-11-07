#include <vector>
// import master para asset

namespace Contexto
{
    class Dibujador
    {
    private:
        void (*d)();

    public:
        Dibujador(void (*f)())
        {
            d = f;
        };
        void callF()
        {
            d();
        }
        ~Dibujador();
    };
    std::vector<Dibujador *> ListDibujado;
    void DibujarListado()
    {
        int r = ListDibujado.size();
        for (int i = 0; i < r; i++)
        {
            Dibujador *d = ListDibujado[i];
            d->callF();
        }
    };
    // funciones para dibujar elementos
    class Coordenadas
    {
    private:
        double _x = 0;
        double _y = 0;
        double velocidad_m = 0.06f;
        // se debe agregar limites a los movimientos
    public:
        Coordenadas(double x_, double y_)
        {
            _x = x_;
            _y = y_;
        };
        Coordenadas(){};
        ~Coordenadas();
        void up()
        {
            _y += velocidad_m;
        }
        void down()
        {
            _y -= velocidad_m;
        }
        void left()
        {
            _x -= velocidad_m;
        }
        void right()
        {
            _x += velocidad_m;
        }
        double getx() { return _x; };
        double gety() { return _y; };
    };

}
#pragma once
#include "../headers.hpp"
#include "nave/nave.hpp"
#include "nave/disparo.hpp"
#include "bloques/bloques.hpp"