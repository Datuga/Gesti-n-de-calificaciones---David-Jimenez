#include <iostream>
#include <iomanip>

//Dejare notas mas que nada como guia. atte: David Jimènez

//Declaracion de Variables

const int Califi_Total = 3;

const int Estudiantes_Total = 20;

void cargarNomina(std::string cedulas[], std::string nombres[]); // Requerimento 1

void cargarNotas(int notas[][Califi_Total]); // Requerimento 2

void calcularPromedio(int notas[][Califi_Total], double promedios[]); // Requerimento 3

void mostrarBoletin(std::string cedulas[], std::string nombres[], int notas[][Califi_Total], double promedios[]); // Requerimento 4

//Inicio del Main

int main() {
	
    std::string cedulas[Estudiantes_Total];
    
    std::string nombres[Estudiantes_Total];
    
    int calificaciones[Estudiantes_Total][Califi_Total];
    
    double promedios[Estudiantes_Total];
    
//Agrego Menu para tener el programa ordenado.

    int opcion;
    do {
        std::cout << "========MENU DE OPCIONES=======\n";
        std::cout << "1. Cargar Nomina de Estudiantes\n";
        std::cout << "2. Cargar Notas de los Estudiantes\n";
        std::cout << "3. Calcular Promedio de Notas\n";
        std::cout << "4. Mostrar Boletin de Calificaciones\n";
        std::cout << "0. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                cargarNomina(cedulas, nombres);
                break;
            case 2:
                cargarNotas(calificaciones);
                break;
            case 3:
                calcularPromedio(calificaciones, promedios);
                break;
            case 4:
                mostrarBoletin(cedulas, nombres, calificaciones, promedios);
                break;
            case 0:
                std::cout << "Saliendo del programa.\n";
                break;
            default:                                                           //
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0; // pd: Dure como 1 hora para que agarre y era por que el return lo puse abajo por costumbre.
}

//Funcion 1

void cargarNomina(std::string cedulas[], std::string nombres[]) {
	
    std::cout << "Ingrese la información de los estudiantes:\n";
        
    for (int i = 0; i < Estudiantes_Total; ++i) {
        std::cout << "Estudiante " << i + 1 << ":\n";
        std::cout << "Cedula: ";
        std::cin >> cedulas[i];
        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombres[i]);
    }//Fin del Ford
    
}//Fin Funcion 

//Funcion 2

void cargarNotas(int notas[][Califi_Total]) {
    std::cout << "Ingrese las notas de los estudiantes:\n";
    for (int i = 0; i < Estudiantes_Total; ++i) {
        std::cout << "Estudiante " << i + 1 << ":\n";
        
        for (int j = 0; j < Califi_Total; ++j) {
            std::cout << "Nota " << j + 1 << ": ";
            std::cin >> notas[i][j];
        }
    }//Fin del Doble Ford
    
}//Fin Funcion 2

//Funcion 3

void calcularPromedio(int notas[][Califi_Total], double promedios[]) {
    for (int i = 0; i <Estudiantes_Total; ++i) {
        int suma = 0;
        for (int j = 0; j < Califi_Total; ++j) {
            suma += notas[i][j];
        }
        promedios[i] = static_cast<double>(suma) / Califi_Total;
    }
    std::cout << "Promedios calculados.\n";
    
}//Fin Funcion 3

//Funcion 4

void mostrarBoletin(std::string cedulas[], std::string nombres[], int notas[][Califi_Total], double promedios[]) {
    std::cout << std::setw(10) << "Cedula" << std::setw(20) << "Nombre" << std::setw(15) << "Nota1" << std::setw(15) << "Nota2" << std::setw(15) << "Nota3" << std::setw(15) << "Promedio\n";
    
	for (int i = 0; i < Estudiantes_Total; ++i) {
        std::cout << std::setw(10) << cedulas[i] << std::setw(20) << nombres[i];
        for (int j = 0; j < Califi_Total; ++j) {
            std::cout << std::setw(15) << notas[i][j];
        }
        std::cout << std::setw(15) << std::fixed << std::setprecision(2) << promedios[i] << "\n";
        
    } //Fin Funcion 4  
    
}//Fin del Programa.