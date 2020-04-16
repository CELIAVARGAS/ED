/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <string> 
#include <iostream>
#include <cstring>  
#include <stdio.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <fstream>

#define sizeTablas 10
#define sizeColumnas 10
#define sizeDatos 10
#define sizeTablaHash 5
#define sizeChar 100


using namespace std;


//Definimos nuestras estructuras 

struct informacionDato {
    char tipoChar[sizeChar];
    string tipoString;
    int tipoEntero;
    double tipoDouble;
    int esAlta;
};
typedef struct informacionDato datosColumnasTabla;

struct tipotablaH {
    informacionDato *tablaD[sizeTablaHash];
    int elementos;
    double factorcarga;
};
typedef struct tipotablaH tablaHash;

struct nombreColumnas {
    string nombreC;
    string tipoDatoC;
    informacionDato *valorFila[sizeDatos];
    tipotablaH *tablaH[sizeTablaHash];
};
typedef struct nombreColumnas Columnas;

struct nombreTablas {
    Columnas *nombreColumna[sizeColumnas];
    string nombreTabla;
    int posicion;
};
typedef struct nombreTablas Tablas;

void llenarTablas(string nombreTabla, string columnas);
void llenarColumnas(Tablas *, int t);
void menuLLenarColumnas(Tablas *, int i, int j);
void imprimirTablas();
void MENU();
void analisisCrearTabla();
void analisisInsertarDatos();
void valoresColumnas(string nombreTabla, string nombresColumnas);
bool verificarExistenciaColumna(string nombreTabla, string nombeColumna);
bool verificarExistenciaTabla(string nombreTabla);
void insertarDatosColumnas(string datosCol, string tabla, string columnasNombres, int pos);
void valoresColumnas(string nombreTabla, string nombresColumnas, int pos);
void llenarXTipos(string tipo, string dato, Columnas* c, int pos, datosColumnasTabla* datoC, tipotablaH* t, int k, int factor);
void analisisSelect();
void imprimir2();
void formasImpimir(string nombresTablas, string nombesColumnas, string nombresRestricciones);
void imprimirTodasColumnas(string cadenaTablasI);
int numeroTabla(string nombreTabla);
vector<string> split(const string &s, char delim);
int buscarPuntero(Columnas* c, string restriccion);
void impresion(Columnas* c);
void impresionTodoWhere(string cadenaRestricciones, string nombresTablas, string nombresColumnas);
void imprimirAlgunasColumnas(string cadenaTablasI, string cadenaColumnasI);
void archivo();
void cantidadDeFilasDeMismoTipoTabla();
void cantidadTablas(int t);
void cantidadColumnas(int c, string tabla);
void cantidadTipos(int s, int i, int c, int d, string tabla);
void impresionRep(Columnas* c);
void archivo();
void fio(string nombreFichero, string unString);

void CrearTabla(Tablas* t1, tablaHash* t, int i, int k);
void insertar(tablaHash*, datosColumnasTabla, int p);
datosColumnasTabla *buscar(tablaHash*, datosColumnasTabla*d);
int eliminar(tablaHash *, datosColumnasTabla *d);
long transforma(char *);
int direccionC(tablaHash *, datosColumnasTabla *d);
int direccionS(tablaHash *, datosColumnasTabla *d, int n);

int cantidadString = 0;
int cantidadChar = 0;
int cantidadInt = 0;
int cantidadDouble = 0;

//variables globales;
Tablas *tablaLlenar = new Tablas[sizeTablas];
int l = 0, pos = 0;

void llenarColumnas(Tablas *tabla, int i, string cadenaColumas) {

    //obtenemos los datos
    vector<string> cadenaDatos = split(cadenaColumas, ',');
    for (int j = 0; j < cadenaDatos.size(); j++) {

        //por cada cadena de datos crear columna auxiliar
        Columnas *columnaAuxiliar;
        columnaAuxiliar = new (struct nombreColumnas);

        //y tambien creamos una tabla hash
        string cadena = cadenaDatos[j];
        //obtenemos nombre y tipo
        vector<string> datos = split(cadena, ' ');
        for (int k = 0; k < datos.size(); k++) {

            //     cout << "\n palabra " << datos[k];
            string palabra = datos[k];
            if (palabra.empty()) {
            } else {
                if (palabra == " ") {
                    cout << " Espacio";
                } else {
                    if (palabra == "STRING") {
                        // cout << "\n\t Tipo Columna " << palabra;
                        columnaAuxiliar->tipoDatoC = palabra;
                    } else if (palabra == "INT") {
                        columnaAuxiliar->tipoDatoC = palabra;
                    } else if (palabra == "CHAR()") {
                        columnaAuxiliar->tipoDatoC = palabra;
                    } else if (palabra == "DOUBLE") {
                        columnaAuxiliar->tipoDatoC = palabra;
                    } else {
                        //llenamos struct columna
                        columnaAuxiliar->nombreC = palabra;
                        //llenamos struct tablas->columna
                        tabla[i].nombreColumna[j] = columnaAuxiliar;
                    }

                }
            }
        }

        //creamos tabla
        tablaHash *tablaH;
        tablaH = new(struct tipotablaH);
        CrearTabla(tabla, tablaH, i, j);

        for (int n = 0; n < sizeColumnas; n++) {

            if (tablaLlenar[i].nombreColumna[n] == 0) {
                tabla[i].nombreColumna[n] == NULL;
            } else {
                //            cout << "Se llenara casillas";
                for (int m = 0; m < sizeDatos; m++) {
                    datosColumnasTabla *datoC;
                    datoC = new (struct informacionDato);
                    datoC->tipoString = "NULL";
                    datoC->tipoEntero = 0;
                    datoC->tipoDouble = 0.0;
                    string dato = "NULL";
                    strcpy(datoC->tipoChar, dato.c_str());
                    tabla[i].nombreColumna[n]->valorFila[m] = datoC;
                    //tabla[i].nombreColumna[n]->valorFila[m] = datoC;
                }
            }
        }
    }

}

void llenarTablas(string nombreT, string cadenaDatos) {
    //primero verificar si existe la tabla sino entonces agregar
    bool encontrado = false;

    for (int i = 0; i < sizeTablas; i++) {
        string tablaBuscar = tablaLlenar[i].nombreTabla;
        //comparar cada i con el nombre 
        if (tablaBuscar == nombreT) {
            encontrado = true;
            break;
        } else {
        }
    }
    if (encontrado == true) {
        cout << "/n No se creara tabla ya existe una con el mismo nombre ";
    } else {
        //creamos tabla y mostramos columnas
        l++;
        //    cout << "\n valor i++= " << l;
        tablaLlenar[l].nombreTabla = nombreT;
        tablaLlenar[l].posicion = 0;

        llenarColumnas(tablaLlenar, l, cadenaDatos);
    }
}

void imprimirTablas() {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            cout << "\n\t IMPRESION DATOS";
            cout << "\nNombre Tabla: " << tablaLlenar[i].nombreTabla;
            for (j = 0; j < sizeColumnas; j++) {
                Columnas *c;
                if (tablaLlenar[i].nombreColumna[j] == 0) {
                } else {
                    c = tablaLlenar[i].nombreColumna[j];
                    cout << "\n  Nombre Columna " << c->nombreC;
                    cout << "\n  Nombre Tipo Columna " << c->tipoDatoC;
                    cout << "\nSTRING      INTEGER     CHAR()      DOUBLE";
                    for (k = 0; k < sizeDatos; k++) {
                        if (c->valorFila[k] == NULL) {
                        } else {
                            cout << "\n-----" << c->valorFila[k]->tipoString << "-----" << c->valorFila[k]->tipoEntero
                                    << "-----" << c->valorFila[k]->tipoChar << "-----" << c->valorFila[k]->tipoDouble;
                        }
                    }
                }
            }
        }
    }
}

void imprimir2() {
    int i = 0, j = 0, k = 0;
    for (i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            cout << "\n\t IMPRESION DATOS";
            cout << "\nNombre Tabla: " << tablaLlenar[i].nombreTabla;
            Columnas *c;
            for (j = 0; j < sizeColumnas; j++) {
                if (tablaLlenar[i].nombreColumna[j] == 0) {
                } else {
                    c = tablaLlenar[i].nombreColumna[j];
                    //  cout << "\n  Nombre Columna " << c->nombreC;
                    //  cout << "\n  Nombre Tipo Columna " << c->tipoDatoC;
                    for (k = 0; k < sizeDatos; k++) {
                        //cout << "\n " << c->valorFila[k];
                        if (c->valorFila[k] == 0) {
                        } else {
                            cout << "\n Tipo string " << c->valorFila[k]->tipoString;
                            cout << "\n Tipo int " << c->valorFila[k]->tipoEntero;
                            cout << "\n Tipo char " << c->valorFila[k]->tipoChar;
                            cout << "\n Tipo double " << c->valorFila[k]->tipoDouble;
                        }
                    }
                }
            }
        }
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim)) {
        result.push_back(item);
    }

    return result;
}

void analisisCrearTabla() {
    //PEDIMOS DATOS DE LA TABLA
    string nombreTabla, nombreColumnas;
    cout << "\n CREATE TABLE ";
    cin >>nombreTabla;
    cout << " ( ";
    getchar();
    getline(cin, nombreColumnas);
    cout << " ) ";

    //mandamos datos correspondientes para llenar tabla y columnas
    llenarTablas(nombreTabla, nombreColumnas);

}

void analisisInsertarDatos() {
    //INSERT INTO usuarios (nombre, apellidos) VALUES ('Juan','Garcia Pérez');
    //INSERT INTO usuarios (nombre, apellidos) VALUES ('Juan','García Pérez'), ('Domingo', 'Sánchez Fernández');

    string nombreTabla, columnasNombres;
    string simbolo;
    cout << "\n INSERT INTO ";
    cin >>nombreTabla;


    bool tablaEncontrada = false;
    tablaEncontrada = verificarExistenciaTabla(nombreTabla);
    bool columnaEncontrada = false;
    if (tablaEncontrada == true) {
        //existe la tabla, pedimos valores
        cout << " ( ";
        getchar();
        getline(cin, columnasNombres);
        cout << " ) ";

        //verificamos que existan las columnas
        vector<string> cadenaCol = split(columnasNombres, ',');
        for (int j = 0; j < cadenaCol.size(); j++) {
            string palabra = cadenaCol[j];
            if (palabra.empty()) {
            } else {
                columnaEncontrada = verificarExistenciaColumna(nombreTabla, palabra); //buscamos si existe la columna
                if (columnaEncontrada == true) {//se encontro, sigue evaluando
                } else {
                    //salir del ciclo
                    cout << "\n Error no existe la columna " << palabra;
                    break;
                }
            }
        }

        int n = numeroTabla(nombreTabla);
        if (columnaEncontrada == true) {//se encontro, sigue evaluando
            pos = tablaLlenar[n].posicion;
            //      cout << "\n Posicion obtenida " << pos;
            valoresColumnas(nombreTabla, columnasNombres, pos); //pedimos datos de las columnas
            pos++;
            tablaLlenar[n].posicion = pos;
            //        cout << "\n Posicion ingresada " << pos;

            getline(cin, simbolo);
            while (simbolo == ",") {
                pos = tablaLlenar[n].posicion;
                //            cout << "\n Posicion obtenida " << pos;
                valoresColumnas(nombreTabla, columnasNombres, pos); //pedimos datos de las columnas
                pos++;
                tablaLlenar[n].posicion = pos;
                //            cout << "\n Posicion ingresada " << pos;
                getline(cin, simbolo);
            }
        } else {
        }

    } else {
        //no existe la tabla
        cout << "\n Error no existe la tabla " << nombreTabla;
    }
}

int numeroTabla(string nombreTabla) {
    //Verificar que exista tabla, sino mostrar error;
    int numero;
    for (int i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            string tablaLeida = tablaLlenar[i].nombreTabla;
            if (tablaLeida == nombreTabla) {
                numero = i; //se encontro una tabla con el nomnbre
            } else {
            }
        }
    }
    return numero;
}

bool verificarExistenciaTabla(string nombreTabla) {
    //Verificar que exista tabla, sino mostrar error;
    bool encontrado = false;
    for (int i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            string tablaLeida = tablaLlenar[i].nombreTabla;
            if (tablaLeida == nombreTabla) {
                encontrado = true; //se encontro una tabla con el nomnbre
            } else {
            }
        }
    }
    return encontrado;
}

bool verificarExistenciaColumna(string nombreTabla, string nombeColumna) {
    bool encontrado = false;
    int i = 0, j = 0;

    for (i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            string tablaLeida = tablaLlenar[i].nombreTabla;
            if (tablaLeida == nombreTabla) {//se encontro el nombre de la tabla

                for (j = 0; j < sizeColumnas; j++) {
                    Columnas *c;
                    if (tablaLlenar[i].nombreColumna[j] == 0) {
                    } else {
                        c = tablaLlenar[i].nombreColumna[j];
                        string columnaLeida = c->nombreC;
                        if (columnaLeida == nombeColumna) {
                            encontrado = true; //existe la columna dentro de la tabla
                        } else {
                        }
                    }
                }
            } else {
            }
        }
    }

    return encontrado;
}

void valoresColumnas(string nombreTabla, string nombresColumnas, int pos) {
    string datosFilas;
    cout << " VALUES ";
    cout << " ( ";
    //    getchar();
    getline(cin, datosFilas);
    cout << " ) ";

    //insertamos datos de las columnas
    insertarDatosColumnas(datosFilas, nombreTabla, nombresColumnas, pos);
}
int factor = 0;

void insertarDatosColumnas(string datosFilas, string tabla, string columnasNombres, int pos) {
    //debemos de colocar cada dato por columna leida... 
    //luego verificcar cuales quedaron vacias para escribir null
    int i, j, k;
    for (i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            string tablaLeida = tablaLlenar[i].nombreTabla;
            if (tablaLeida == tabla) {//se encontro el nombre de la tabla
                //como ya se verifico nombre entonces solo obtenemos nombres y procedemos a llenar
                vector<string> cadenaCol = split(columnasNombres, ','); //obtenemos cada nombre de columna
                factor = 0;
                for (int j = 0; j < cadenaCol.size(); j++) {
                    string col = cadenaCol[j];
                    /*  cout << "\n C " << col;
                      cout << "\n j " << j;
                     */
                    if (col.empty()) {
                    } else {
                        vector<string> cadenaD = split(datosFilas, ','); //separamos cada dato de la columna

                        string dato = cadenaD[j]; //tendra la misma posicion de la columna

                        Columnas *c;
                        //buscamos puntero de la columna dentro de la tabla
                        for (k = 0; k < sizeColumnas; k++) {
                            if (tablaLlenar[i].nombreColumna[k] == 0) {
                            } else {
                                c = tablaLlenar[i].nombreColumna[k];
                                string columnaLeida = c->nombreC;
                                if (columnaLeida == col) {//cuando encuentro la columna, obtengo el tipo
                                    string tipo = c->tipoDatoC;
                                    //llenamos conforme el tipo
                                    datosColumnasTabla *datoC;
                                    datoC = new (struct informacionDato);

                                    tablaHash *t;
                                    t = new(struct tipotablaH);
                                    factor++;
                                    llenarXTipos(tipo, dato, c, pos, datoC, t, k, factor);
                                } else {
                                }
                            }
                        }
                    }
                }

            } else {
            }
        }
    }
}

void llenarXTipos(string tipo, string dato, Columnas *c, int pos, datosColumnasTabla *datoC, tipotablaH *t, int k, int factor) {

    if (tipo == "STRING") {
        int posicion;

        datoC->tipoString = dato;
        c->valorFila[pos] = datoC;

        datoC->esAlta = 1;
        posicion = direccionS(t, datoC, 1);

        t->tablaD[posicion] = datoC;
        t->elementos = pos;
        t->factorcarga = (t->elementos) / sizeTablaHash;
        c->tablaH[k] = t;

        /*cout << " elementos " << t->elementos;
        cout << " factor carga " << t->factorcarga;
         */
        if (t->factorcarga > 0.5) {
            puts("\nFactor de Carga supera el 50% de la tabla");
        }

    } else if (tipo == "CHAR()") {
        int posicion;

        strcpy(datoC->tipoChar, dato.c_str());
        c->valorFila[pos] = datoC;

        datoC->esAlta = 1;
        posicion = direccionS(t, datoC, 2);

        t->tablaD[posicion] = datoC;
        t->elementos = pos;
        t->factorcarga = (t->elementos) / sizeTablaHash;
        c->tablaH[k] = t;

        if (t->factorcarga > 0.5) {
            puts("\nFactor de Carga supera el 50% de la tabla");
        }


    } else if (tipo == "INT") {
        int num;
        std::istringstream(dato) >> num;
        datoC->tipoEntero = num;
        c->valorFila[pos] = datoC;

        int posicion;
        datoC->esAlta = 1;
        posicion = direccionS(t, datoC, 3);

        t->tablaD[posicion] = datoC;
        t->elementos = pos;
        t->factorcarga = (t->elementos) / sizeTablaHash;
        c->tablaH[k] = t;

        if (t->factorcarga > 0.5) {
            puts("\nFactor de Carga supera el 50% de la tabla");
        }

    } else if (tipo == "DOUBLE") {
        double dC = atof(dato.c_str());
        datoC->tipoDouble = dC;
        c->valorFila[pos] = datoC;

        int posicion;
        datoC->esAlta = 1;
        posicion = direccionS(t, datoC, 3);

        t->tablaD[posicion] = datoC;
        t->elementos = pos;
        t->factorcarga = (t->elementos) / sizeTablaHash;
        c->tablaH[k] = t;

        if (t->factorcarga > 0.5) {
            puts("\nFactor de Carga supera el 50% de la tabla");
        }
    } else {
    }
}

void analisisSelect() {
    string nombreColumnasIngresadas, nombreTablasIngresadas, nombreRestriccion;
    cout << "\n SELECT ";
    getchar();
    getline(cin, nombreColumnasIngresadas);
    cout << "\n FROM ";
    getline(cin, nombreTablasIngresadas);
    cout << "\n ; ";

    //analisamos tablas
    bool tablaEncontrada = false, columnaEncontrada = false, error = false;
    vector<string> cadenaTablas = split(nombreTablasIngresadas, ','); //separamos cada dato de la columna
    for (int m = 0; m < cadenaTablas.size(); m++) {
        string nombreTab = cadenaTablas[m];
        tablaEncontrada = verificarExistenciaTabla(nombreTab);
        if (tablaEncontrada == true) {
            //buscamos las columnas
            if (nombreColumnasIngresadas == "*") {
            } else {
                vector<string> cadenaColumnas = split(nombreColumnasIngresadas, ','); //separamos cada dato de la columna
                for (int i = 0; i < cadenaColumnas.size(); i++) {
                    string nombreCols = cadenaColumnas[i];
                    columnaEncontrada = verificarExistenciaColumna(nombreTab, nombreCols);
                    if (columnaEncontrada == true) {
                        error = false;
                    } else {
                        cout << "\n Error no existe columna " << nombreCols << " en tabla " << nombreTab;
                        error = true;
                        break;
                    }
                }
            }
        } else {
            error = true;
            cout << "\n Error no existe tabla" << nombreTab;
            break;
        }
    }
    //mostramos datos
    formasImpimir(nombreTablasIngresadas, nombreColumnasIngresadas, nombreRestriccion);
}

void formasImpimir(string nombresTablas, string nombesColumnas, string nombresRestricciones) {

    if (nombesColumnas == "*") {
        if (nombresRestricciones.empty()) {
            imprimirTodasColumnas(nombresTablas);
        } else {
        }
    } else {// existe nombre de columnas
        imprimirAlgunasColumnas(nombresTablas, nombesColumnas);
    }
}

void imprimirAlgunasColumnas(string cadenaTablasI, string cadenaColumnasI) {
    vector<string> cadenaTablas = split(cadenaTablasI, ','); //separamos cada tabla
    for (int m = 0; m < cadenaTablas.size(); m++) {
        string tablaBuscar = cadenaTablas[m];

        for (int i = 0; i < sizeTablas; i++) {
            if (tablaLlenar[i].nombreTabla.empty()) {
            } else {
                string tabla = tablaLlenar[i].nombreTabla;
                if (tabla == tablaBuscar) {//se encuentra tabla de la cadena de tablas
                    cout << "\n\t ***** " << tabla << " ***** ";
                    Columnas *c;
                    for (int j = 0; j < sizeColumnas; j++) {//obtenermos todas las columnas de la tabla
                        if (tablaLlenar[i].nombreColumna[j] == 0) {
                        } else {
                            string columna = tablaLlenar[i].nombreColumna[j]->nombreC;
                            c = tablaLlenar[i].nombreColumna[j];

                            vector<string> cadenaC = split(cadenaColumnasI, ','); //separamos cada columna
                            for (int k = 0; k < cadenaC.size(); k++) {
                                string columnaLeida = cadenaC[k];
                                if (columna == columnaLeida) {
                                    //se imprime
                                    cout << "\n-" << columna << "-> ";
                                    impresion(c);
                                } else {
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void imprimirTodasColumnas(string cadenaTablasI) {

    int i = 0, j = 0, k = 0, posicion = 0;
    vector<string> cadenaTablas = split(cadenaTablasI, ','); //separamos cada dato de la columna
    for (int m = 0; m < cadenaTablas.size(); m++) {

        string tablaBuscar = cadenaTablas[m];
        for (i = 0; i < sizeTablas; i++) {

            if (tablaLlenar[i].nombreTabla.empty()) {
            } else {
                string tabla = tablaLlenar[i].nombreTabla;
                if (tabla == tablaBuscar) {//se encuentra tabla de la cadena de tablas
                    cout << "\n\t ***** " << tabla << " ***** ";
                    Columnas *c;
                    for (j = 0; j < sizeColumnas; j++) {
                        if (tablaLlenar[i].nombreColumna[j] == 0) {
                        } else { //obtenermos todas las columnas de la tabla
                            c = tablaLlenar[i].nombreColumna[j];
                            cout << "\n  " << tablaLlenar[i].nombreColumna[j]->nombreC;
                            impresion(c);
                        }
                    }//despues de evaluar cada columna con restriccion , imprimimos solo restricciones
                } else {
                }
            }
        }
    }
}

void impresion(Columnas * c) {
    int k;
    string tipo = c->tipoDatoC;
    for (k = 0; k < sizeDatos; k++) {//Mostramos los datos de cada columna
        if (c->valorFila[k] == 0) {
        } else {
            if (tipo == "STRING") {
                string a = c->valorFila[k]->tipoString;
                if (a == "NULL") {
                    cout << "-NULL";
                } else {
                    cout << "-" << a;
                }
            } else if (tipo == "INT") {
                //
                int a = c->valorFila[k]->tipoEntero;
                stringstream ss;
                ss << a;
                string str = ss.str();
                if (a == 0) {
                    cout << "-NULL";
                } else {
                    cout << "-" << str;
                }
            } else if (tipo == "CHAR()") {
                string a = c->valorFila[k]->tipoChar;
                if (a == "NULL") {
                    cout << "-NULL";
                } else {
                    cout << "-" << a;
                }
            } else if (tipo == "DOUBLE") {
                double num = c->valorFila[k]->tipoDouble;
                std::ostringstream streamObj;
                streamObj << num;
                std::string strObj = streamObj.str();
                if (num == 0) {
                    cout << "-NULL";
                } else {
                    cout << "-" << strObj;
                }
            } else {
            }
        }
    }
}

void impresionRep(Columnas * c) {
    int k;
    string tipo = c->tipoDatoC;
    for (k = 0; k < sizeDatos; k++) {//Mostramos los datos de cada columna
        if (c->valorFila[k] == 0) {
        } else {
            if (tipo == "STRING") {
                string a = c->valorFila[k]->tipoString;
                if (a == "NULL") {
                } else {
                    cantidadString++;
                }
            } else if (tipo == "INT") {
                //
                int a = c->valorFila[k]->tipoEntero;
                stringstream ss;
                ss << a;
                string str = ss.str();
                if (a == 0) {
                } else {
                    cantidadInt++;
                }
            } else if (tipo == "CHAR()") {
                string a = c->valorFila[k]->tipoChar;
                if (a == "NULL") {
                } else {
                    cantidadChar++;
                }
            } else if (tipo == "DOUBLE") {
                double num = c->valorFila[k]->tipoDouble;
                std::ostringstream streamObj;
                streamObj << num;
                std::string strObj = streamObj.str();
                if (num == 0) {
                } else {
                    cantidadDouble++;
                }
            } else {
            }
        }
    }
}

void fio(string nombreFichero, string unString) {
    //Creo un fichero tanto para leer como para escribir. Si ya existe el fichero solo añade mas informacion al fichero existente.
    //fstream::in       habilita la lectura del fichero
    //fstream::out      habilita la escritura en el fichero
    //fstream::app      permite añadir contenido al final del fichero
    fstream fichero(nombreFichero.c_str(), fstream::in | fstream::out | fstream::app);

    if (unString.empty()) {
        while (getline(fichero, unString)) {
            cout << unString << endl;
        }
    } else if (!unString.empty()) {
        fichero << unString << endl;
    }
    fichero.close();
}

void archivo() {
    int contadorTablas = 0;
    //Imprimimos todas las tablas con sus columnas y contabilizamos los datos
    fio("reporte.txt", "\n ********** REPORTE DE TODAS LAS TABLAS **********");

    for (int i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            int contadorColumnas = 0;
            string tabla = tablaLlenar[i].nombreTabla;
            fio("reporte.txt", "\n\t ***** " + tabla + " *****");
            Columnas *c;
            cantidadString = 0;
            cantidadInt = 0;
            cantidadChar = 0;
            cantidadDouble = 0;

            for (int j = 0; j < sizeColumnas; j++) {
                if (tablaLlenar[i].nombreColumna[j] == 0) {
                } else { //obtenermos todas las columnas de la tabla
                    c = tablaLlenar[i].nombreColumna[j];
                    //  cout << "\n  " << tablaLlenar[i].nombreColumna[j]->nombreC;
                    string columna = tablaLlenar[i].nombreColumna[j]->nombreC;
                    fio("reporte.txt", columna);

                    string tipo = c->tipoDatoC;
                    for (int k = 0; k < sizeDatos; k++) {//Mostramos los datos de cada columna
                        if (c->valorFila[k] == 0) {
                        } else {
                            if (tipo == "STRING") {
                                string a = c->valorFila[k]->tipoString;
                                if (a == "NULL") {
                                    fio("reporte.txt", "-NULL");
                                } else {
                                    cantidadString++;
                                    fio("reporte.txt", "-" + a);
                                }
                            } else if (tipo == "INT") {
                                //
                                int a = c->valorFila[k]->tipoEntero;
                                stringstream ss;
                                ss << a;
                                string str = ss.str();
                                if (a == 0) {
                                    fio("reporte.txt", "-NULL");
                                } else {
                                    cantidadInt++;
                                    fio("reporte.txt", "-" + str);
                                }
                            } else if (tipo == "CHAR()") {
                                string a = c->valorFila[k]->tipoChar;
                                if (a == "NULL") {
                                    fio("reporte.txt", "-NULL");
                                } else {
                                    cantidadChar++;
                                    fio("reporte.txt", "-" + a);
                                }
                            } else if (tipo == "DOUBLE") {
                                double num = c->valorFila[k]->tipoDouble;
                                std::ostringstream streamObj;
                                streamObj << num;
                                std::string strObj = streamObj.str();
                                if (num == 0) {
                                    fio("reporte.txt", "-NULL");
                                } else {
                                    cantidadDouble++;
                                    fio("reporte.txt", "-" + strObj);
                                }
                            } else {
                            }
                        }
                    }
                    contadorColumnas++;
                }
            }
            stringstream ss;
            ss << contadorColumnas;
            string col = ss.str();
            fio("reporte.txt", "\n Cantidad de columnas " + col);
            stringstream ss1;
            ss1 << cantidadString;
            string st = ss1.str();
            fio("reporte.txt", "\n\t Cantidad de datos String " + st);
            stringstream ss2;
            ss2 << cantidadInt;
            string inte = ss2.str();
            fio("reporte.txt", "\n\t Cantidad de datos Int " + inte);
            stringstream ss3;
            ss3 << cantidadChar;
            string ch = ss3.str();
            fio("reporte.txt", "\n\t Cantidad de datos Char() " + ch);
            stringstream ss4;
            ss4 << cantidadDouble;
            string dob = ss4.str();
            fio("reporte.txt", "\n\t Cantidad de datos Double " + dob);
            contadorTablas++;
        }
    }
    stringstream ss5;
    ss5 << contadorTablas;
    string tab = ss5.str();
    fio("reporte.txt", "\n Cantidad de tablas " + tab);

}

void cantidadDeFilasDeMismoTipoTabla(int opcion) {
    int contadorTablas = 0;
    //Imprimimos todas las tablas con sus columnas y contabilizamos los datos
    cout << "\n\t ********** REPORTE **********";
    for (int i = 0; i < sizeTablas; i++) {
        if (tablaLlenar[i].nombreTabla.empty()) {
        } else {
            int contadorColumnas = 0;
            string tabla = tablaLlenar[i].nombreTabla;
            Columnas *c;
            cantidadString = 0;
            cantidadInt = 0;
            cantidadChar = 0;
            cantidadDouble = 0;
            for (int j = 0; j < sizeColumnas; j++) {
                if (tablaLlenar[i].nombreColumna[j] == 0) {
                } else { //obtenermos todas las columnas de la tabla
                    c = tablaLlenar[i].nombreColumna[j];
                    impresionRep(c);
                    contadorColumnas++;
                }
            }
            //cantidad tipos
            if (opcion == 2) {
                cantidadTipos(cantidadString, cantidadInt, cantidadChar, cantidadDouble, tabla);
            }
            if (opcion == 1) {
                cantidadColumnas(contadorColumnas, tabla);
            }
            if (opcion == 3) {
                cantidadTipos(cantidadString, cantidadInt, cantidadChar, cantidadDouble, tabla);
                cantidadColumnas(contadorColumnas, tabla);
            }
            //cantidad tablas
            contadorTablas++;
        }
    }
    if (opcion == 1 | opcion == 3) {
        cantidadTablas(contadorTablas);
    }
    //cantidad tablas
}

void cantidadTipos(int s, int i, int c, int d, string tabla) {
    cout << "\n CANTIDAD DE TIPOS ";
    cout << "\n\t Cantidad de datos tipo string " << s << " en tabla " << tabla;
    cout << "\n\t Cantidad de datos tipo int  " << i << " en tabla " << tabla;
    cout << "\n\t Cantidad de datos tipo char() " << c << " en tabla " << tabla;
    cout << "\n\t Cantidad de datos tipo double " << d << " en tabla " << tabla;
}

void cantidadColumnas(int c, string tabla) {
    cout << "\n CANTIDAD DE COLUMNAS ";
    cout << "\n\t Cantidad de columnas " << c << " en tabla " << tabla;
}

void cantidadTablas(int t) {
    cout << "\n CANTIDAD DE TABLAS ";
    cout << "\n\t Cantidad de tablas " << t;
}

void CrearTabla(Tablas *t1, tablaHash * t, int i, int k) {
    int j;
    //cout << "\n Se creo tabla en " << t1[i].nombreColumna[j]->nombreC;
    for (j = 0; j < sizeTablaHash; j++) {
        t1[i].nombreColumna[k]->valorFila[j] == NULL;
        //t->tablaD[j] == NULL;
        /// cout << "\n POsicion de tabla " << j;
    }
    t->elementos = 0;
    t->factorcarga = 0.0;
}

int direccionS(tablaHash *t, datosColumnasTabla *d2, int opcion) {
    string clave;

    if (opcion == 1) {
        clave = d2->tipoString;

    } else if (opcion == 2) {
        clave = d2->tipoChar;

    } else if (opcion == 3) {
        int entero = d2->tipoEntero;
        stringstream ss;
        ss << entero;
        clave = ss.str();

    } else if (opcion == 4) {
        double d = d2->tipoDouble;
        std::ostringstream streamObj;
        streamObj << d;
        clave = streamObj.str();
    }

    long p = 0, d = 0;
    for (int j = 0; j < clave.size(); j++) {
        d += (int) clave[j];
    }
//    cout << "\nClave " << d;
    p = d % sizeTablaHash;
//    cout << "\n Direccion hash " << p;
    return (int) p;
}

datosColumnasTabla * buscar(tablaHash *t, datosColumnasTabla *d1) {
    datosColumnasTabla *pr;
    int posicion;
    posicion = direccionS(t, d1, 1);
    pr = t->tablaD[posicion];
    if (pr != NULL) {
        if (!(pr->esAlta)) {
            pr = NULL;
        }
    }
    return pr;
}

/* Elimina el elemento de la tabla hash */
int eliminar(tablaHash *t, datosColumnasTabla *d) {
    int posicion;
    posicion = direccionS(t, d, 1);
    if (t->tablaD[posicion] != NULL) {
        t->tablaD[posicion] -> esAlta = 0;
    } else
        return 1;
}
#endif /* ESTRUCTURA_H */


