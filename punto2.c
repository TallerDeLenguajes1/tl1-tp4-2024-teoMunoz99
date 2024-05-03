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

//--Funcion que devuelve una tarea
Tarea crearTarea();
Tarea crearTarea(){
    char buff[50];
    Tarea aux;
    printf("\nIngrese la descripcion: ");
    fflush(stdin);
    gets(buff);
    aux.Descripcion = (char *)malloc(sizeof(char) * strlen(buff) + 1);
    strcpy(aux.Descripcion,buff);
    aux.TareaID = 1;//funcion para generar un id
    printf("\nIngrese la duracion: ");
    scanf("%d", &aux.Duracion);//validar que sea entre 10 y 100
    return aux;
}

//--Funcion que devuelve un nodo
Nodo * crearNodo();
Nodo * crearNodo(){
    Nodo * aux = (Nodo *)malloc(sizeof(Nodo));
    aux->T = crearTarea();
    aux->Siguiente = NULL;
    return aux;
}

int main(int argc, char * argv[]){

    Nodo * tareasPendientes = CrearListaVacia();
    Nodo * nodo1 = crearNodo();
    printf("\n %s \n", nodo1->T.Descripcion);
    printf("\n %d \n", nodo1->T.Duracion);
    printf("\n %d \n", nodo1->T.TareaID);

    return 0;
}