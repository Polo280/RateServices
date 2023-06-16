#ifndef EPISODIO_H
#define EPISODIO_H
#include <iostream>
#include "./Video.hpp"

class Episodio : public Video{
    public:
      Episodio(std::string, char, int, int, int); //Constructor del episodio
      std::string getTitulo();  //getter para el titulo
    private:
      int temporada; //Temporada a la que pertenece
};

#endif //EPISODIO_H