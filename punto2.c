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
    //aux.TareaID = 1;//funcion para generar un id
    //----
    printf("\nIngrese el id: ");
    scanf("%d", &aux.TareaID);
    //----
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

//--Funcion para insertar nodo, al comienzo de la lista
void insertarNodo(Nodo **inicio, Nodo * nuevoNodo);
void insertarNodo(Nodo **inicio, Nodo * nuevoNodo){
    nuevoNodo->Siguiente = *inicio;
    *inicio = nuevoNodo;
}

//--Funcion para buscar un nodo y retornarlo
Nodo * buscarNodo(Nodo *inicio, int idBuscado);
Nodo * buscarNodo(Nodo *inicio, int idBuscado){
    Nodo * aux = inicio;
    while (aux != NULL && aux->T.TareaID != idBuscado)
    {
        aux = aux->Siguiente;
    }
    return aux;
}

//--Funcion para quitar un nodo
void quitarNodo(Nodo **inicio, int idEliminar);
void quitarNodo(Nodo **inicio, int idEliminar){
    //creo un puntero aux que apunte al inicio para recorrer la lista
    Nodo * actual = *inicio;//apunta al comienzo
    Nodo * anterior = NULL;//este apuntara al nodo anterior al actual cuando se vaya recorriendo el bucle 

    while (actual != NULL && actual->T.TareaID != idEliminar)
    {
        anterior = actual;
        actual = actual->Siguiente;
    }
    //ahora actual contiene el dato a borrar, y anterior el nodo que esta antes del nodo a borrar
    //verifico que actual no sea null
    if(actual != NULL){
        //verifico si anterior es null, si es null es porque el nodo actual es el primer elemento de la lista
        if(anterior == NULL){
            *inicio = actual->Siguiente;
        }else{
            //si anterior no es null, hago que anterior apunte al puntero donde apuntaba actual
            anterior->Siguiente = actual->Siguiente;
        }
        //ahora libero la memoria, de adentro hacia afuera
        free(actual->T.Descripcion);
        free(actual);
    }
}

//--Funcion para mostrar una lista
void mostrarLista(Nodo *inicio);
void mostrarLista(Nodo *inicio) {
    Nodo *actual = inicio;
    while (actual != NULL) {
        printf("Tarea ID: %d\n", actual->T.TareaID);
        printf("Descripcion: %s\n", actual->T.Descripcion);
        printf("Duracion: %d\n", actual->T.Duracion);
        printf("-------------------------\n");
        actual = actual->Siguiente;
    }
}

//--Funcion para cargar una tarea en una lista
void cargarTarea(Nodo **inicio);
void cargarTarea(Nodo **inicio){
    int opcion;
    do
    {
        Nodo * nAux = crearNodo();
        insertarNodo(inicio,nAux);
        printf("\n-Desea cargar otra tarea? 1-SI | 2-NO (ingrese 1 o 2): ");
        scanf("%d", &opcion);
    } while (opcion != 2);
    
}

//--Funcion para mo

int main(int argc, char * argv[]){

    Nodo * tareasPendientes = CrearListaVacia();
    //cargarTarea(&tareasPendientes);
    Nodo * nodo1 = crearNodo();
    Nodo * nodo2 = crearNodo();
    Nodo * nodo3 = crearNodo();
    insertarNodo(&tareasPendientes, nodo1);
    insertarNodo(&tareasPendientes, nodo2);
    insertarNodo(&tareasPendientes, nodo3);
    mostrarLista(tareasPendientes);
    quitarNodo(&tareasPendientes, 1);
    mostrarLista(tareasPendientes);

    return 0;
}