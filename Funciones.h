#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int tirarDado();
void generarTirada(int v[], int tam);
void mostrarTirada(int v[], int tam);
///
bool compararVectoresEnMismaPosicion(int vec1[], int vec2[], int tam);
bool existeNumeroVector(int vec[], int tam, int num);
void ordenarVector(int vec[], int tam);
int contarNumerosRepetidos(int vec[], int tam, int num);
void mostrarCombinaciones(int vec[], int tam, int puntaje);
bool verificarTodosRepetidos(int vec[], int tam);
bool escalera(int vec[], int tam);
int combinaciones(int vec[], int tam, int puntaje);
int puntos();
#endif // FUNCIONES_H_INCLUDED

