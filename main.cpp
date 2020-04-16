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

void subMenuReportes() {
    int opcion = 0;
    cout << "\n\t********** SUBMENU ********** ";
    cout << "\n\t1. Cantidad de columnas y tablas ";
    cout << "\n\t2. Cantidad de filas de un mismo tipo en una tabla ";
    cout << "\n\t3. Cantidad de datos totales ";
    cout << "\n\t4. Archivo ";
    cout << "\n\t5. Regresar a Menu \n";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cantidadDeFilasDeMismoTipoTabla(1);
            break;
        case 2:
            cantidadDeFilasDeMismoTipoTabla(2);
            break;
        case 3:
            cantidadDeFilasDeMismoTipoTabla(3);
            break;
        case 4:
            archivo();
            break;
        case 5:
            break;
        default:
            break;
    }

}

void MENU() {
    int opcion = 0;

    cout << "\n\n\t********** MENU ********** ";
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
            MENU();
            break;
        case 2:
            analisisInsertarDatos();
            MENU();
            break;
        case 3:
            analisisSelect();
            MENU();
            break;
        case 4:
            subMenuReportes();
            MENU();
            break;
        case 5:
            MENU();
            break;
        case 6:
            exit(0);
            break;
        default:
            MENU();
            break;
    }
}

int main(int argc, char** argv) {
    MENU();
    return 0;
}

