#ifndef SERIE_H
#define SERIE_H
#include <iostream>
#include <vector>
#include "./Episodio.hpp"

class Serie{
    public: 
      Serie(std::string title, char genre, int temps, int num_ep, std::vector<Episodio> episodios);
      void mostrarInfo(); //Mostrar la info de la serie
      void rate();        //Calificar la serie (general) con input del usuario
      void updateRate(int calificacion);  //Funcion que se llama dentro de rate() para actualizar vector ratings
      void calificarEps(int); //Para calificar los episodios en el vector
      bool friend operator < (Serie, Serie); //Comparar calificaciones de series 
      //Getters
      std::string getTitulo();
      char getCategoria();
      float getRating();
      std::vector<Episodio>& getEpisodios(); //Pasar referencia a direccion de memoria y modificar directamente
    protected:
      std::string titulo; //Titulo de la serie
      char genero;        //genero de la serie
      int temporadas;     //Numero de temporadas
      int num_episodios;  //Numero de episodios 
      std::vector<Episodio> episodios; //Episodios de la serie
      //Rating promedio
      int num_ratings; //numero de calificaciones totales (para calcular promedio)
      float calificacionAvg; //calificacion promedio de la serie
      std::vector <int> ratings; //vector que almacena calificaciones
};

#endif //SERIE_H