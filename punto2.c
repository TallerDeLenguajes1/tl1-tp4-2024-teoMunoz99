#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Declaracion de estructuras
typedef struct {
    int TareaID;        // Numérico autoincremental comenzando en 1000
    char *Descripcion;  //
    int Duracion;       // entre 10 – 100
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

// Declaracion de funciones
Nodo *CrearListaVacia();
Nodo *CrearListaVacia() {
    return NULL;
}



int main(int argc, char * argv[]){

    Nodo * tareasPendientes = CrearListaVacia();
    printf("\n %p \n", tareasPendientes);

    return 0;
}