#include <iostream>
#include "Funciones.h"

using namespace std;

int tirarDado()
{
    return rand()% 6 + 1;
}

void generarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {

        v[i] = tirarDado();
        ///MODO SIMULADO
        /*
        int valor;
        cout << "ingrese valor: ";
        cin >> valor;
        v[i] = valor;
         */
    }
}

void mostrarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << " :" << v[i] << endl;
    }
}

bool compararVectoresEnMismaPosicion(int vec1[], int vec2[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec1[i] != vec2[i])
        {
            return false;
        }
    }
    return true;
}

bool existeNumeroVector(int vec[], int tam, int num)
{
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == num)
        {
            return true;
        }
    }
    return false;
}

void ordenarVector(int vec[], int tam)
{
    int aux;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(vec[j]<vec[i])
            {
                aux = vec[j];
                vec[j]=vec[i];
                vec[i]=aux;
            }
        }
    }
}

int contarNumerosRepetidos(int vec[], int tam, int num)
{
    int cant = 0;
    for(int i = 0; i < tam; i++)
    {
        if(vec[i] == num)
        {
            cant++;
        }
    }
    return cant;
}

bool verificarTodosRepetidos(int vec[], int tam)
{
    int cantidadRepetidos;
    cantidadRepetidos = contarNumerosRepetidos(vec, tam, vec[0]);
    if(cantidadRepetidos == tam)
    {
        return true;
    }
    return false;
}
bool escalera(int vec[], int tam)
{
    int cant = 0;
    for (int i = 0; i < tam; i++)
    {
        if (vec[i] == i+1)
        {
            cant++;
            if(cant == tam)
            {
                return true;
            }
        }

    }
    return false;
}
int combinaciones(int vec[], int tam, int puntaje)
{
    if (verificarTodosRepetidos(vec, tam) == true)
    {
        if(vec[0] != 6){
            puntaje+=vec[0]*10;
        }
        else puntaje = 0;
    }
    else if (contarNumerosRepetidos(vec, tam, vec[0]) > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            puntaje+=vec[i];
        }

    }
    return puntaje;
}
void mostrarCombinaciones(int vec[], int tam, int puntaje)
{
    if (verificarTodosRepetidos(vec, tam) == true)
    {
        if(vec[0] != 6){
            cout << "SEXTETO X! PUNTOS OBTENIDOS: " << combinaciones(vec, tam, puntaje) <<endl;
        }
        else cout << "SEXTETO 6! PUNTAJE RESETEADO A 0 " <<endl;
    }
    else if (escalera(vec, tam) == true)
    {
        cout<<"ESCALERA! GANASTE!" << endl;
    }
    else cout << "SUMA DE DADOS! PUNTOS OBTENIDOS: " << combinaciones(vec, tam, puntaje) <<endl;

}
