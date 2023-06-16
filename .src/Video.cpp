//Archivo para implementacion de clase Video
#include <iostream>
#include "../.include/Video.hpp"

Video::Video(){}

Video::Video(std::string title, char genre, int duracion_min, int estreno){
    titulo = title;  //Asignacion de atributos en inicializacion
    genero = genre;
    duracion = duracion_min;
    fecha = estreno;
    std::cout << "Video " << titulo << " creado efectivamente" << std::endl;
}

std::string detectarCategoria(char cat){ //Funcion usada en mostrarInfo para imprimir nombre completo de genero
    int index;
    std::string generos[]  = {"Accion", "Comedia", "Drama", "Terror/suspenso", "Infantil"};
    char charsCategorias[] = {'a', 'c', 'd', 't', 'i'};
    int arraySize = sizeof(generos) / sizeof(generos[0]); //Calcular el numero de elementos en el array
    for(int i=0;i<arraySize;i++){
        if(cat == charsCategorias[i]){
            index = i;   //Encontrar el indice de la categoria (en char) para traducir a string
            break;
        }
    }
    return generos[index];  //Mapeo a string
}

void Video::mostrarInfo(){  //Funcion para imprimir la informacion relacionada a un video
    std::cout << "\nINFORMACION DEL VIDEO" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "TITULO: " << titulo << std::endl;
    std::cout << "GENERO: " << detectarCategoria(genero) << std::endl;
    std::cout << "DURACION: " << duracion << std::endl;
    std::cout << "FECHA ESTRENO: " << fecha << std::endl;
    std::cout << "CALIFICACION PROMEDIO: " << calificacionAvg << std::endl;
    std::cout << "---------------------------------------------------------------\n" << std::endl;
}

void Video::calificar(){ //Funcion para que usuario introduzca calificacion de un video
    int calificacion = 0;
    std::cout << "\nCALIFICAR VIDEO" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << titulo << std::endl;
    std::cout << "Introduzca calificacion para el video -> ";
    std::cin >> calificacion;
    while(calificacion < 1 || calificacion > 5){ //Mientras entrada no sea valida
        std::cout << "Numero no valido, introducir del 1-5" << std::endl;
        std::cin >> calificacion;
    }
    updateRating(calificacion);  //Guardar nueva calificacion y actualizar promedio de ratings
    std::cout << "Rating " << calificacion << " guardado exitosamente." << std::endl;
    std::cout << "Numero de calificaciones: " << calificaciones.size() << std::endl;
    std::cout << "Rating actual del video: " << calificacionAvg << std::endl;
}

//Llamar cada vez que se agrega una calificacion
void Video::updateRating(int calificacion){ //Funcion para calcular el promedio de ratings actualizado
    calificaciones.push_back(calificacion); //Actualizar el vector de calificaciones
    int total = 0;
    int counter = 0;
    for(int num:calificaciones){
        total += num; //Sumar calificaciones
        counter++;
    }
    calificacionAvg = float(total) / counter;  //Obtencion del rating promedio
}

std::string Video::getTitulo(){
    return titulo;
}

float Video::getRating(){
    return calificacionAvg;
}

char Video::getCategoria(){
    return genero; //Utilizamos el atributo de la clase para pasar como argumento a la funcion local
}

bool operator < (Video vid1, Video vid2){
    if(vid1.getRating() < vid2.getRating()){
        return true;
    }else{
        return false;
    }
}