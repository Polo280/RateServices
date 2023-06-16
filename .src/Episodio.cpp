#include <iostream>
#include "../.include/Episodio.hpp"

Episodio::Episodio(std::string title, char genre, int minutos, int estreno, int temp){
    titulo = title;
    genero = genre;
    duracion = minutos;
    fecha = estreno;
    temporada = temp;
}

std::string Episodio::getTitulo(){
    return titulo;
}