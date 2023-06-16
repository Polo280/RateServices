#ifndef PELICULA_H
#define PELICULA_H
#include <iostream>
#include "./Video.hpp"

class Pelicula : public Video{
    public:
        Pelicula(std::string, char, int, int); //Constructor de la pelicula
};
#endif //PELICULA_H