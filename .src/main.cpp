#include <iostream>
#include <vector>
#include "../.include/Video.hpp"
#include "../.include/Pelicula.hpp"
#include "../.include/Serie.hpp"
#include "../.include/Episodio.hpp"

//Biblioteca de peliculas
Pelicula shrek2("Shrek 2", 'i', 120, 2008);
Pelicula ironman("Ironman: El hombre de hierro", 'a', 130, 2008);
Pelicula terminator("Terminator", 'a', 125, 1984);
Pelicula matrix("Matrix", 'a', 130, 1999);
Pelicula fastf("Rapidos y furiosos 7", 'a', 140, 2015);
Pelicula rush("Una pareja explosiva", 'c', 98, 1998);

//Series (declaracion de objetos)
Episodio ep1("Big Bang Ep1", 'c', 60, 2008, 1);
Episodio ep2("Big Bang Ep2", 'c', 55, 2009, 1);
Episodio ep3("Big Bang Ep3", 'c', 40, 2010, 2);
Episodio ep4("Big Bang Ep4", 'c', 68, 2011, 2);
std::vector<Episodio> bigBangEps = {ep1, ep2, ep3, ep4};
Serie bigbang("The big bang theory", 'c', 4, 2, bigBangEps);

Episodio epd1("Good doctor Ep1", 'c', 80, 2019, 1);
Episodio epd2("Good doctor Ep2", 'c', 85, 2020, 1);
Episodio epd3("Good doctor Ep3", 'c', 75, 2021, 2);
Episodio epd4("Good doctor Ep4", 'c', 70, 2022, 2);
std::vector<Episodio> goodDocEps = {epd1, epd2, epd3, epd4};
Serie goodDoctor("The good doctor", 'd', 4, 2, goodDocEps);

//Agrupacion de series y peliculas
Pelicula peliculas[] = {shrek2, ironman, terminator, matrix, fastf, rush};
Serie series[] = {bigbang, goodDoctor};

void mostrarCatalogo(){  //Codigo para mostrar catalogo
    std::cout << "\nCATALOGO DE PELICULAS & SERIES" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "SERIES --> " << sizeof(series) / sizeof(series[0]) << std::endl;  //Calcular cantidad de series
    for(Serie ser : series){                        //Iterar en cada serie del array de series disponibles
        std::cout << ser.getTitulo() << std::endl;  //Imprimir titulos
    }
    std::cout << "\nPELICULAS --> " << sizeof(peliculas) / sizeof(peliculas[0]) << std::endl;  //Calcular cantidad de pelis
    for(Pelicula peli : peliculas){                 //Iterar en cada pelicula del array global de peliculas
        std::cout << peli.getTitulo() << std::endl; //Imprimir titulos
    }
}

void calificarVideo(){ //funcion para calificar pelicula o serie
    int sizePeli = sizeof(peliculas)/sizeof(peliculas[0]);
    int sizeSerie = sizeof(series)/sizeof(series[0]);
    std::cout << "CALIFICACION DE VIDEOS" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "INDICE" << std::endl; 
    std::cout << "PELICULAS" << std::endl;
    //Imprimir primero todas las peliculas y despues todas las series
    for(int i = 0; i < sizePeli; i++){
       std::cout << peliculas[i].getTitulo() << " - " << i + 1 << std::endl;
    }
    std::cout << "\nSERIES" << std::endl;
    for(int i=sizePeli; i < sizeSerie + sizePeli; i++){
       std::cout << series[i - sizePeli].getTitulo() << " - "  << i + 1 << std::endl;  //Normalizar el indice
    }
    //Eleccion de video
    int index = -1;
    std::cout << "Introduce indice para elegir video : ";
    std::cin >> index;  
    while(index < 1 || index > sizePeli + sizeSerie){  //CHECAR ESTA LINEA
       std::cout << "Introduce un indice valido: ";
       std::cin >> index;  
    }
    //Enfoque en video elegido
    if(index <= sizePeli){
       std::cout << "PELICULA ELEGIDA: " << peliculas[index-1].getTitulo() << std::endl;  
       peliculas[index - 1].calificar();
    }else{
       std::cout << "SERIE ELEGIDA: " << series[(index-sizePeli)-1].getTitulo() << std::endl;  
       series[(index-sizePeli)-1].rate();
    }
}

void imprimirGenero(){ //Funcion para checar las series y peliculas de un determinado genero e imprimirlas
   char opciones[] = {'a','c', 'd', 't', 'i'};
   std::string opcionString[] = {"Accion", "Comedia", "Drama", "Suspenso/terror", "Infantil"};
   int index = 0;
   std::cout << "EXPLORAR POR GENERO" << std::endl; 
   std::cout << "--------------------------------------------------------" << std::endl;
   std::cout << "INDICE :" << std::endl;
   std::cout << "OPCION 1 - ACCION" << std::endl;
   std::cout << "OPCION 2 - COMEDIA" << std::endl;
   std::cout << "OPCION 3 - DRAMA" << std::endl;
   std::cout << "OPCION 4 - SUSPENSO/TERROR" << std::endl;
   std::cout << "OPCION 5 - INFANTIL" << std::endl;
   std::cout << "Elegir indice de opcion: ";
   std::cin >> index;

   while(index <= 0 || sizeof(opciones)/sizeof(opciones[0]) < index){
      std::cout << "Elegir indice de opcion valido: ";
      std::cin >> index;
   }
   char catElegida = opciones[index - 1];
   //ITERAR PARA ENCONTRAR CATEORIAS E IR GUARDANDO INDICES
   std::vector <int> clasificadosIndex;
   int counter = 0;  //CONTADOR PARA MAPEAR A ENTEROS
   for(Pelicula peli : peliculas){  
      char cat = peli.getCategoria();
      if(cat == catElegida){    //Si la categoria del video actual es la misma que la elegida, agregar
         clasificadosIndex.push_back(counter);
      }
      counter++;
   } 
   for(Serie ser : series){
      char cat = ser.getCategoria(); //Obtener categoria de cada serie en formato char
      if(cat == catElegida){         //Si la categoria del video actual es la misma que la elegida, agregar
         clasificadosIndex.push_back(counter);
      }
      counter ++;
   }
   std::cout << "\nCategoria elegida: " << opcionString[index-1] << std::endl;
   std::cout << "Mostrando videos de " << opcionString[index-1] << std::endl;
   for(int i : clasificadosIndex){ //Iterar en indices de videos clasificados para mapear a peliculas/series
      if(i < sizeof(peliculas)/sizeof(peliculas[0])){ //El indice es de una pelicula
         std::cout << peliculas[i].getTitulo() << " - Tipo: Pelicula" << std::endl; 
      }else{
         std::cout << series[i - sizeof(peliculas)/sizeof(peliculas[0])].getTitulo() << " - Tipo: Serie" << std::endl; //Si el indice es mayor al size de peliculas, entonces es serie
      }
   }
}

void mejorCalificado(){
   std::cout << "\nVIDEOS CON MEJOR CALIFICACION" << std::endl;
   std::cout << "--------------------------------------------------------" << std::endl;
   std::cout << "Opcion 1: Pelicula mejor calificada" << std::endl;
   std::cout << "Opcion 2: Serie mejor calificada" << std::endl;
   std::cout << "Elegir opcion: ";
   int opcion; 
   std::cin >> opcion; //Entrada de opcion para usuario
   while(opcion < 1 || opcion > 2){
      std::cout << "Elegir opcion valida: ";
      std::cin >> opcion; //Entrada de opcion para usuario
   }
   int indexMejor = -1; //variable para guardar el mejor calificado
   if(opcion == 1){ //si usuario elige categoria pelicula
      for(int i = 0; i < (sizeof(peliculas)/sizeof(peliculas[0])-1); i++){ //iterar en todas las peliculas
         if(peliculas[i] < peliculas[i + 1]){  //SOBRECARGA DE OPERADORES
            indexMejor = i + 1;  //siguiente indice si el actual es menor al siguiente
         }
      }
      std::cout << "Pelicula mejor calificada: " << peliculas[indexMejor].getTitulo() 
                << " con calificacion: " << peliculas[indexMejor].getRating(); //Imprimir peli mejor calificada
   }else{ //ver series mejor calificadas
      for(int i = 0; i < (sizeof(series)/sizeof(series[0])-1); i++){
         if(series[i] < series[i + 1]){  //SOBRECARGA DE OPERADORES
            indexMejor = i + 1;
         }
      }
      std::cout << "Serie mejor calificada: " << series[indexMejor].getTitulo() 
                << " con calificacion: " << series[indexMejor].getRating(); //Imprimir serie mejor calificada
   }
}

void mostrarParticular(){  //Mostrar info de un video en particular
   std::cout << "\nINFORMACION DE VIDEO PARTICULAR" << std::endl;
   std::cout << "--------------------------------------------------------" << std::endl;
   std::cout << "OPCION 1: Pelicula " << std::endl;
   std::cout << "OPCION 2: Serie " << std::endl;
   std::cout << "Elegir tipo de video: ";
   int option;
   std::cin >> option;
   while(option != 1 && option != 2){ //Validar input
      std::cout << "Elegir tipo de video valido: ";
      std::cin >> option;
   }
   //Casos de eleccion
   int index = 0;
   if(option == 1){ //Si eligio tipo pelicula
      for(int i = 0; i < sizeof(peliculas) / sizeof(peliculas[0]); i++){
         std::cout << i + 1 << " - " << peliculas[i].getTitulo() << std::endl; //imprimir titulos
      }
      std::cout << "Elegir indice de pelicula: ";
      std::cin >> index; //tomar indice como input
      while(index < 1 || index > sizeof(peliculas) / sizeof(peliculas[0])){ //Mientras entrada sea no valida
         std::cout << "Elegir indice de pelicula valido: ";
         std::cin >> index;
      }
      peliculas[index-1].mostrarInfo(); //Mostrar informacion de la pelicula con indice especificado
   }else{   //Si usuario elige serie
      for(int i=0; i < sizeof(series) / sizeof(series[0]); i++){
         std::cout << i + 1 << " - " << series[i].getTitulo() << std::endl;
      }
      std::cout << "Elegir indice de serie: ";
      std::cin >> index; //tomar indice como input
      while(index < 1 || index > sizeof(series) / sizeof(series[0])){ //Mientras entrada sea no valida
         std::cout << "Elegir indice de serie valido: ";
         std::cin >> index;
      }
      series[index-1].mostrarInfo(); //Mostrar informacion de la serie con indice especificado
   }
}

void calificarEpisodio(){ //funcion para calificar episodios individuales de una serie
   std::cout << "\nCALIFICAR EPISODIOS DE UNA SERIE" << std::endl;
   std::cout << "--------------------------------------------------------" << std::endl;
   for(int i=0; i < sizeof(series) / sizeof(series[0]); i++){
      std::cout << "OPCION " << i + 1 << " - " << series[i].getTitulo() << std::endl;
   }
   int opcion;
   std::cin >> opcion;
   while(opcion < 1 || opcion > sizeof(series) / sizeof(series[0])){ //Mientras entrada sea no valida
      std::cout << "Elegir indice de serie valido: ";
      std::cin >> opcion;
   }
   //Listar episodios
   std::cout << "EPISODIOS DE: " << series[opcion - 1].getTitulo() << std::endl;
   std::vector<Episodio> eps = series[opcion - 1].getEpisodios();
   for(int i=0; i < eps.size(); i++){ //Iterar en vector de episodios por indice
      std::cout << "OPCION " << i + 1 << " - " << eps[i].getTitulo() << std::endl; //Mostrar titulos de episodios
   }
   //Elegir opcion de episodio
   int opcionEp = 0;
   std::cout << "Elegir episodio: " << std::endl;
   std::cin >> opcionEp;
   while(opcionEp < 1 || opcionEp > eps.size()){  //verificar entrada valida
      std::cout << "Elegir indice de episodio valido: ";
      std::cin >> opcionEp;
   }
   std::cout << "Serie: " << series[opcion - 1].getTitulo() << std::endl;
   std::cout << "Episodio elegido: " << eps[opcionEp - 1].getTitulo() << std::endl;
   //Rating
   series[opcion - 1].getEpisodios()[opcionEp - 1].calificar();
}

void menu(){
   bool run = true;
   while(run){
      int option = 0;
      std::cout << "\nMENU DEL PROGRAMA" << std::endl;
      std::cout << "--------------------------------------------------------" << std::endl;
      std::cout << "OPCION 1 = Imprimir catalogo de videos" << std::endl;
      std::cout << "OPCION 2 = Calificar un video" << std::endl;
      std::cout << "OPCION 3 = Imprimir videos por genero" << std::endl;
      std::cout << "OPCION 4 = Ver mejores calificados" << std::endl;
      std::cout << "OPCION 5 = Mostrar informacion de video especifico" << std::endl;
      std::cout << "OPCION 6 = Evaluar episodios de una serie" << std::endl;
      std::cout << "OPCION 7 = Salir" << std::endl;
      std::cout << "Introduce numero de opcion: ";
      std::cin >> option;
      //Checar opcion valida
        while(option <= 0 || option > 7){
         std::cout << "Introduce numero de opcion valido: ";
         std::cin >> option;
      }
      switch(option){
         case 1:
            mostrarCatalogo(); //Mostar el catalogo de videos disponibles
            break;
         case 2:
            calificarVideo(); //Calificar un video
            break;
         case 3: 
            imprimirGenero(); //Mostrar videos de un genero
             break;
         case 4:
            mejorCalificado(); //Ver pelicula o serie mejor calificados
            break;
         case 5:
            mostrarParticular(); //Mostrar info de un video en particular
            break; 
         case 6:
            calificarEpisodio(); //calificar un episodio de una serie
            break;
         case 7:
            std::cout << "\nQue tenga un excelente dia" << std::endl; //Salir del programa
            run = false;
            break; 
      }
   }
}

int main(){
    menu();
    return EXIT_SUCCESS;
}