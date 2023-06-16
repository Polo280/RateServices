#include <iostream>
#include <vector>
#include "../.include/Serie.hpp"

Serie::Serie(std::string title, char genre, int num_ep, int temps, std::vector<Episodio> epis){
    titulo = title;
    genero = genre;
    temporadas = temps;
    num_episodios = num_ep;
    episodios = epis;
}

void Serie::calificarEps(int index){
    episodios[index].calificar();
}

std::string detectCategoria(char cat){ //Funcion usada en mostrarInfo para imprimir nombre completo de genero
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

void Serie::mostrarInfo(){
    int epMejor = 0; //para guardar el indice del episodio mejor evaluado
    for(int i=0; i < episodios.size() - 1; i++){
        if(episodios[i] < episodios[i+1]){
            epMejor = i + 1;
        }else if (episodios[i+1] < episodios[i]){
            epMejor = i;
        }
    }
    std::cout << "INFORMACION DE LA SERIE" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << "TITULO: " << titulo << std::endl;
    std::cout << "GENERO: " << detectCategoria(genero) << std::endl;
    std::cout << "TEMPORADAS: " << temporadas << std::endl;
    std::cout << "EPISODIOS: " << num_episodios << std::endl;
    if(episodios[epMejor].getRating() != 0){
        std::cout << "EPISODIO MEJOR EVALUADO: " << episodios[epMejor].getTitulo() << "_ RATING = " << episodios[epMejor].getRating() << std::endl;
    }else{
        std::cout << "EPISODIO MEJOR EVALUADO: NO HAY " << std::endl;
    }
    std::cout << std::endl;
    for(int i=0; i < episodios.size(); i++){
        std::cout << episodios[i].getTitulo() << " - Rating = " << episodios[i].getRating() << std::endl;
    }
    std::cout << "---------------------------------------------------------------" << std::endl;
}

void Serie::rate(){ //Funcion para que usuario introduzca calificacion de un video
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
    updateRate(calificacion);  //Guardar nueva calificacion y actualizar promedio de ratings
    std::cout << "Rating " << calificacion << " guardado exitosamente." << std::endl;
    std::cout << "Numero de calificaciones: " << ratings.size() << std::endl;
    std::cout << "Rating actual del video: " << calificacionAvg << std::endl;
}

//Llamar cada vez que se agrega una calificacion
void Serie::updateRate(int calificacion){ //Funcion para calcular el promedio de ratings actualizado
    ratings.push_back(calificacion); //Actualizar el vector de calificaciones
    int total = 0;
    int counter = 0;
    for(int num:ratings){
        total += num; //Sumar calificaciones
        counter++;
    }
    calificacionAvg = float(total) / counter;  //Obtencion del rating promedio
}

bool operator < (Serie ser1, Serie ser2){
    if(ser1.calificacionAvg < ser2.calificacionAvg){
        return true;
    }else{
        return false;
    }
}

std::string Serie::getTitulo(){
    return titulo;
}

float Serie::getRating(){
    return calificacionAvg;
}

char Serie::getCategoria(){
    return genero;
}

std::vector<Episodio>& Serie::getEpisodios(){
    return episodios;
}
