#include <iostream>
#include "../.include/Pelicula.hpp"

Pelicula::Pelicula(std::string title, char genre, int minutos, int estreno){
    titulo = title;
    genero = genre;
    duracion = minutos;
    fecha = estreno;
}