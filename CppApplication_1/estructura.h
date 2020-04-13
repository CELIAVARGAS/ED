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
    informacionDato *tabla[sizeTablaHash];
    int elementos;
    double factorcarga;
};
typedef struct tipotablaH tablaHash;

struct nombreColumnas {
    string nombreC;
    string tipoDatoC;
    informacionDato *valorFila[sizeDatos];
};
typedef struct nombreColumnas Columnas;

struct nombreTablas {
    Columnas *nombreColumna[sizeColumnas];
    string nombreTabla;
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
void llenarXTipos(string tipo, string dato, Columnas* c, int pos);
void analisisSelect();
void imprimir2();
void formasImpimir(string nombresTablas, string nombesColumnas, string nombresRestricciones);
void imprimirTodasColumnas(string cadenaTablasI);
vector<string> split(const string &s, char delim);

void CrearTabla(tablaHash *);
void insertar(tablaHash*, datosColumnasTabla, int p);
datosColumnasTabla *buscar(tablaHash*, char *);
int eliminar(tablaHash *, char *);
long transforma(char *);
int direccion(tablaHash *, char *);

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

        //    cout << "\n Datos columna " << cadenaDatos[j];
        string cadena = cadenaDatos[j];
        //  cout << "\n j++: " << j;
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
                        // cout << "\n\t Nombre Columna " << palabra;
                        //llenamos struct columna
                        columnaAuxiliar->nombreC = palabra;
                        //llenamos struct tablas->columna
                        tabla[i].nombreColumna[j] = columnaAuxiliar;
                    }
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
            Columnas *c;
            for (j = 0; j < sizeColumnas; j++) {
                if (tablaLlenar[i].nombreColumna[j] == 0) {
                } else {
                    c = tablaLlenar[i].nombreColumna[j];
                    cout << "\n  Nombre Columna " << c->nombreC;
                    cout << "\n  Nombre Tipo Columna " << c->tipoDatoC;
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
        if (columnaEncontrada == true) {//se encontro, sigue evaluando
            valoresColumnas(nombreTabla, columnasNombres, pos); //pedimos datos de las columnas
            pos++;
            getline(cin, simbolo);
            while (simbolo == ",") {
                valoresColumnas(nombreTabla, columnasNombres, pos);
                pos++;
                getline(cin, simbolo);
            }
        } else {
        }

    } else {
        //no existe la tabla
        cout << "\n Error no existe la tabla " << nombreTabla;
    }
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
    string datosColumna;
    cout << " VALUES ";
    cout << " ( ";
    //    getchar();
    getline(cin, datosColumna);
    cout << " ) ";

    //insertamos datos de las columnas
    insertarDatosColumnas(datosColumna, nombreTabla, nombresColumnas, pos);
}

void insertarDatosColumnas(string datosCol, string tabla, string columnasNombres, int pos) {
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
                for (int j = 0; j < cadenaCol.size(); j++) {
                    string col = cadenaCol[j];
                    /*  cout << "\n C " << col;
                      cout << "\n j " << j;
                     */
                    if (col.empty()) {
                    } else {
                        vector<string> cadenaD = split(datosCol, ','); //separamos cada dato de la columna
                        for (int m = 0; m < cadenaD.size(); m++) {
                            // cout << "\n m " << m << " D " << cadenaD[m];
                        }
                        string dato = cadenaD[j]; //tendra la misma posicion de la columna

                        //buscamos puntero de la columna dentro de la tabla
                        for (k = 0; k < sizeColumnas; k++) {
                            Columnas *c;
                            if (tablaLlenar[i].nombreColumna[k] == 0) {
                            } else {
                                c = tablaLlenar[i].nombreColumna[k];
                                string columnaLeida = c->nombreC;
                                if (columnaLeida == col) {//cuando encuentro la columna, obtengo el tipo
                                    string tipo = c->tipoDatoC;
                                    //llenamos conforme el tipo
                                    llenarXTipos(tipo, dato, c, pos);
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

void llenarXTipos(string tipo, string dato, Columnas *c, int pos) {

    datosColumnasTabla *datoC;
    datoC = new (struct informacionDato);

    cout << "\nPosicion " << pos;
    cout << "\nDato " << dato;

    if (tipo == "STRING") {
        cout << "\n dato insertar " << dato;
        datoC->tipoString = dato;
        c->valorFila[pos] = datoC;
    } else if (tipo == "CHAR()") {
        char datoC1[sizeChar];
        strcpy(datoC->tipoChar, dato.c_str());
        cout << "\n dato insertar " << datoC->tipoChar;
        //        datoC->tipoChar = *datoC1;
        c->valorFila[pos] = datoC;
    } else if (tipo == "INT") {
        int num;
        std::istringstream(dato) >> num;
        cout << "\n dato insertar " << num;
        datoC->tipoEntero = num;
        c->valorFila[pos] = datoC;
    } else if (tipo == "DOUBLE") {
        double dC = atof(dato.c_str());
        cout << "\n dato insertar " << dC;
        datoC->tipoDouble = dC;
        c->valorFila[pos] = datoC;
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
    cout << "\n WHERE ";
    getline(cin, nombreRestriccion);

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
        cout << "Imprimir todas las columnas de la(s) tablas";
        imprimirTodasColumnas(nombresTablas);
    } else {
    }
}

void imprimirTodasColumnas(string cadenaTablasI) {

    int i = 0, j = 0, k = 0;
    vector<string> cadenaTablas = split(cadenaTablasI, ','); //separamos cada dato de la columna

    for (int m = 0; m < cadenaTablas.size(); m++) {
        string tablaBuscar = cadenaTablas[m];
        for (i = 0; i < sizeTablas; i++) {
            if (tablaLlenar[i].nombreTabla.empty()) {
            } else {
                string tabla = tablaLlenar[i].nombreTabla;
                if (tabla == tablaBuscar) {
                    cout << "\n   " << tabla << " -- ";
                    Columnas *c;
                    for (j = 0; j < sizeColumnas; j++) {
                        if (tablaLlenar[i].nombreColumna[j] == 0) {
                        } else {
                            c = tablaLlenar[i].nombreColumna[j];
                            cout << "  " << tablaLlenar[i].nombreColumna[j]->nombreC;
                            string tipo = c->tipoDatoC;
                            for (k = 0; k < sizeDatos; k++) {
                                //cout << "\n " << c->valorFila[k];
                                if (c->valorFila[k] == 0) {
                                } else {
                                    if (tipo == "STRING") {
                                        string a = c->valorFila[k]->tipoString;
                                        if (a.empty()) {
                                            cout << "   " << " NULL ";
                                        } else {
                                            cout << "   " << a;
                                        }
                                    } else if (tipo == "INT") {
                                        //
                                        int a = c->valorFila[k]->tipoEntero;
                                        stringstream ss;
                                        ss << a;
                                        string str = ss.str();
                                        if (str.empty()) {
                                            cout << "   " << " NULL ";
                                        } else {
                                            cout << "   " << str;
                                        }
                                    } else if (tipo == "CHAR()") {
                                        //                                      cout << "   " << c->valorFila[k]->tipoChar;
                                        string a = c->valorFila[k]->tipoChar;
                                        if (a.empty()) {
                                            cout << "   " << " NULL ";
                                        } else {
                                            cout << "   " << a;
                                        }
                                    } else if (tipo == "DOUBLE") {
                                        //                                    cout << "   " << c->valorFila[k]->tipoDouble;
                                        double num = c->valorFila[k]->tipoDouble;
                                        std::ostringstream streamObj;
                                        //Add double to stream
                                        streamObj << num;
                                        // Get string from output string stream
                                        std::string strObj = streamObj.str();
                                        if (strObj.empty()) {
                                            cout << "   " << " NULL ";
                                        } else {
                                            cout << "   " << strObj;
                                        }
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

}

void CrearTabla(tablaHash *t) {
    int j;
    for (j = 0; j < sizeTablaHash; j++) {
        t->tabla[j] == NULL;
        cout << "\n POsicion de tabla " << j;
    }
    t->elementos = 0;
    t->factorcarga = 0.0;
}

/* transforma los caracteres de la clave en valores enteros*/
long transforma(char *clave) {
    int j;
    long d = 0;
    for (j = 0; j < strlen(clave); j++) {
        d = d + clave[j];
    }
    cout << "\n Clave " << d;
    return ((d >= 0) ? d : -d);

    /* dirección recibe la tabladispersa y la clave para colocar esta ultima en la tabla*/
}

int direccion(tablaHash *t, char *clave) {
    int i = 0;
    long p = 0, d = 0;
    for (int j = 1; j < strlen(clave); j++) {
        d += (int) clave[j];
    }
    cout << "\nClave " << d;
    p = d % sizeTablaHash;
    cout << "\n Direccion hash " << p;
    return (int) p;
}

/* Inserta los datos que representa la clave en la tabla hash*/
void insertar(tablaHash *t, datosColumnasTabla r, int p) {
    datosColumnasTabla *pr;
    int posicion;
    pr = new (struct informacionDato);
    strcpy(pr->tipoChar, r.tipoChar);
    pr->esAlta = 1;
    posicion = p;
    t->tabla[posicion] = pr;
    t->elementos++;
    t->factorcarga = (t->elementos) / sizeTablaHash;
    if (t->factorcarga > 0.7) {
        puts("\nFactor de Carga supera el 70% de la tabla");
    }
}

/* Busca el elemento en la tabla e imprime si lo encuentra o no ...
 ****** como la clave es igual a otra entonces buscar que este en ese
 listado con la misma cadena */
datosColumnasTabla *buscar(tablaHash *t, char *clave) {
    datosColumnasTabla *pr;
    int posicion;
    posicion = direccion(t, clave);
    pr = t->tabla[posicion];
    if (pr != NULL) {
        if (!(pr->esAlta)) {
            pr = NULL;
        }
    }
    return pr;
}

/* Elimina el elemento de la tabla hash */
int eliminar(tablaHash *t, char * clave) {
    int posicion;
    posicion = direccion(t, clave);
    if (t->tabla[posicion] != NULL) {
        t->tabla[posicion] -> esAlta = 0;
    } else
        return 1;
}
#endif /* ESTRUCTURA_H */


