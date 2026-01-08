#include <iostream>
#include "Menu.h"
#include "Juego.h"
#include "Funciones.h"
#include "Juego2.h"

using namespace std;

void menu()
{

    int opcion;



    do
    {
        system("cls");
        cout << "------------------" << endl;
        cout << "1- 1 JUGADOR      " << endl;
        cout << "2- 2 JUGADORES    " << endl;
        cout << "3- CREDITOS       " << endl;
        cout << "------------------" << endl;
        cout << "0- SALIR          " << endl;
        cout << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 0:
            return;
            break;
        case 1:
            juego();
            break;
        case 2:
            juego2();
            break;
        case 3:
            system("cls");
            cout << "Programa desarrollado por Octavio Perone";
            system("pause");
            break;
        }

    }
    while(true);
}

