#include <iostream>
#include "Juego2.h"
#include "Funciones.h"
using namespace std;

void juego2()
{
    system("cls");


    int puntaje1 = 0;
    int puntaje2 = 0;
    int puntajetotal1 = 0;
    int puntajetotal2 = 0;
    int ronda = 0;
    int lanzamiento = 0;
    bool turno = false;
    /// TIRADA
    const int TAM = 6;
    int tirada[TAM];
    int opcion;
    string jugador1;
    string jugador2;
    cout <<  "INGRESE NOMBRE JUGADOR 1: ";
    cin.ignore();
    getline (cin, jugador1);

    cout <<  "INGRESE NOMBRE JUGADOR 2: ";
    getline (cin, jugador2);
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
                system("cls");
                /// CARGAR TIRADA
                while (puntajetotal1 <= 100 && puntajetotal2 <= 100)
                {
                    ronda++;
                    int maxronda1 = 0;
                    int maxronda2 = 0;
                    int puntajeronda1 = 0;
                    int puntajeronda2 = 0;
                    for (int i = 0; i < 6; i++)
                    {
                        system("cls");
                        lanzamiento++;

                        cout << "------------------" << endl;
                        cout << "RONDA #" << ronda <<endl;
                        if (turno == false)
                        {
                            cout << "PROXIMO TURNO: " << jugador1 <<endl;
                        }
                        else
                        {
                            cout << "PROXIMO TURNO: " << jugador2 <<endl;

                        }

                        cout << "PUNTAJE " << jugador1 << ": " << puntajetotal1 << " PUNTOS" <<endl;
                        cout << "PUNTAJE " << jugador2 << ": " << puntajetotal2 << " PUNTOS" <<endl;
                        cout << "------------------" << endl;

                        system("pause");


                        if(turno == false)
                        {
                            system("cls");


                            cout << "TURNO DE: " << jugador1 << " | RONDA #" << ronda << " | PUNTAJE TOTAL: " << puntajetotal1 << endl;
                            cout << "-----------------------------------------------------------" << endl;
                            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxronda1 << " PUNTOS" << endl;
                            cout << "LANZAMIENTO #" << lanzamiento << endl;

                            generarTirada(tirada, TAM);

                        /// MOSTRAR TIRADA
                            mostrarTirada(tirada, TAM);


                            ordenarVector(tirada, TAM);
                            puntajeronda1 = combinaciones(tirada, TAM, puntaje1);
                            if (i == 0){
                                maxronda1 = puntajeronda1;
                            }
                            else if (maxronda1 < puntajeronda1)
                            {
                                maxronda1 = puntajeronda1;
                            }
                            mostrarCombinaciones(tirada, TAM, puntaje1);

                            if (escalera(tirada, TAM) == true)
                            {
                                return;
                            }
                            turno = true;
                            system("pause");
                            }
                        else
                        {
                            system("cls");


                            cout << "TURNO DE: " << jugador2 << " | RONDA #" << ronda << " | PUNTAJE TOTAL: " << puntajetotal2 << endl;
                            cout << "-----------------------------------------------------------" << endl;
                            cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxronda2 << " PUNTOS" << endl;
                            cout << "LANZAMIENTO #" << lanzamiento << endl;

                            generarTirada(tirada, TAM);

                        /// MOSTRAR TIRADA
                            mostrarTirada(tirada, TAM);


                            ordenarVector(tirada, TAM);
                            puntajeronda2 = combinaciones(tirada, TAM, puntaje2);
                            if (i == 0){
                                maxronda2 = puntajeronda2;
                            }
                            else if (maxronda2 < puntajeronda2)
                            {
                                maxronda2 = puntajeronda2;
                            }

                            mostrarCombinaciones(tirada, TAM, puntaje2);

                            if (escalera(tirada, TAM) == true)
                            {
                                return;
                            }

                            turno = false;
                            system("pause");
                        }


                    }
                    puntajetotal1 += maxronda1;
                    puntajetotal2 += maxronda2;
                }
                system("cls");
                if (puntajetotal1 >= 100 && puntajetotal2 >=100){
                    cout << "FIN DEL JUEGO! EMPATE!" <<endl;
                }
                else if(puntajetotal1 >= 100)
                {
                    cout << "FIN DEL JUEGO! EL GANADOR ES: " << jugador1 << "!" << endl;
                }
                else
                {
                    cout << "FIN DEL JUEGO! EL GANADOR ES: " << jugador2 << "!" << endl;
                }
                cout << "RONDAS UTILIZADAS: " << ronda << endl;

                if (puntajetotal1 > puntajetotal2)
                {
                    cout << "EL PUNTAJE MAS ALTO REALIZADADO POR " << jugador1 << " ES DE: " <<puntajetotal1 << endl;
                }
                else
                {
                    cout << "EL PUNTAJE MAS ALTO REALIZADADO POR " << jugador2 << " ES DE: " <<puntajetotal2 << endl;

                }

                system("pause");

                return;
                break;
        }

    }




    while(true);

}



