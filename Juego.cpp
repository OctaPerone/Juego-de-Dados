#include <iostream>
#include "Juego.h"
#include "Funciones.h"

using namespace std;

void juego()
{
    system("cls");


    int puntaje = 0;
    int puntajetotal = 0;
    int ronda = 0;
    int lanzamiento = 0;
    /// TIRADA
    const int TAM = 6;
    int tirada[TAM];
    int opcion;
    string nombre;
    cout <<  "ingrese nombre: ";
    cin.ignore();
    getline (cin, nombre);
    do
    {
        cout << "------------------" << endl;
        cout << "1- JUGAR          " << endl;
        cout << "0- TERMINAR JUEGO " << endl;
        cout << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 0:
                return;
                break;
            case 1:
                /// CARGAR TIRADA
                while (puntajetotal <= 100)
                {
                    ronda++;
                    int maxronda = 0;
                    int puntajeronda = 0;
                    for (int i = 0; i < 3; i++)
                    {
                        system("cls");

                        lanzamiento++;
                        cout << "TURNO DE: " << nombre << " | RONDA #" << ronda << " | PUNTAJE TOTAL: " << puntajetotal << endl;
                        cout << "-----------------------------------------------------------" << endl;
                        cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxronda << " PUNTOS" << endl;
                        cout << "LANZAMIENTO #" << lanzamiento << endl;
                        generarTirada(tirada, TAM);

                        /// MOSTRAR TIRADA
                        mostrarTirada(tirada, TAM);


                        ordenarVector(tirada, TAM);
                        puntajeronda = combinaciones(tirada, TAM, puntaje);
                        if (i == 0){
                            maxronda = puntajeronda;
                        }
                        else if (maxronda < puntajeronda)
                        {
                            maxronda = puntajeronda;
                        }
                        mostrarCombinaciones(tirada, TAM, puntaje);

                        if (escalera(tirada, TAM) == true)
                        {
                            return;
                        }

                        system("pause");

                    }
                    puntajetotal += maxronda;
                }
                system("cls");
                cout << "LLEGASTE A 100 PUNTOS! GANASTE LA PARTIDA!" << endl;
                cout << "RONDAS UTILIZADAS: " << ronda << endl;
                system("pause");
                return;
                break;
        }

    }




    while(true);

}

