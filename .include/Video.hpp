#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>
#include <vector>

class Video{
    public:
      Video(); //Constructor default
      Video(std::string, char, int, int);
      void mostrarInfo();   //Mostrar la informacion de un video
      void calificar();     //Funcion para que el usuario introduzca su reseña
      void updateRating(int calificacion);  //Funcion para actualizar el promedio de calificaciones
      bool friend operator < (Video vid1, Video vid2); //Sobrecarga de operadores para ver cual tiene mejor rating
      //Getters
      std::string getTitulo();
      char getCategoria();
      float getRating();
    protected:
      std::string titulo;   //Titulo del video
      char genero;          //Clasificacion de la pelicula
      int duracion;         //Duracion en minutos
      int fecha;            //Fecha de lanzamiento
      float calificacionAvg; //Promedio de calificiaciones
      std::vector<int> calificaciones; //Vector de calificaciones
};

#endif //VIDEO_H