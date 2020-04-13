/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <cstdlib>
#include <iostream>
#include "estructura.h"

using namespace std;

/*
 * 
 */
//Definimos nuestros metodos

void MENU() {
    int opcion = 0;

    cout << "\n\t********** MENU ********** ";
    cout << "\n1. Crear Tabla ";
    cout << "\n2. Insertar Dato en Tabla ";
    cout << "\n3. Select Dato ";
    cout << "\n4. Reportes ";
    cout << "\n5. Graficas ";
    cout << "\n6. Salir \n";
    cin >> opcion;

    switch (opcion) {
        case 1:
            analisisCrearTabla();
            imprimirTablas();
            MENU();
            break;
        case 2:
            analisisInsertarDatos();
           // imprimir2();
            MENU();
            break;
        case 3:
            analisisSelect();
            MENU();
            break;
        case 4:
            MENU();
            break;
        case 5:
            MENU();
            break;
        case 6:
            //   borrar();
            exit(0);
            break;
        default:
            MENU();
            break;
    }
}

int main(int argc, char** argv) {

    //MENU 
    MENU();
    return 0;
}

