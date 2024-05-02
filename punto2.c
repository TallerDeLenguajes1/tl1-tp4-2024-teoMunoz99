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

Nodo *CrearNodo(Tarea tarea);
Nodo *CrearNodo(Tarea tarea) {
    // creo un nodo aux y le doy tamaño, para guardar los datos y retornarlo
    Nodo *nodoNuevo = (Nodo *)malloc(sizeof(Nodo));
    nodoNuevo->T = tarea;
    // nodoNuevo->T.TareaID = tarea.TareaID;
    // doy el tamaño a la variable donde voy a guardar la descripcion
    // nodoNuevo->T.Descripcion = (char*)malloc(sizeof(char)* strlen(tarea.Descripcion) + 1);
    // strcpy(nodoNuevo->T.Descripcion, tarea.Descripcion);
    // nodoNuevo->T.Duracion = tarea.Duracion;
    nodoNuevo->Siguiente = NULL;
    return nodoNuevo;
}

void instertarNodo(Nodo **inicio, Nodo *nodoNuevo);
void instertarNodo(Nodo **inicio, Nodo *nodoNuevo) {
    nodoNuevo->Siguiente = *inicio;
    *inicio = nodoNuevo;
}

void insertarUltimo(Nodo *inicio, Nodo *nuevoNodo);
void insertarUltimo(Nodo *inicio, Nodo *nuevoNodo) {
    // declaro una variable aux que apunte al inicio de la lista para poder recorrerla sin perder la direccion de la variable inicio
    Nodo *aux = inicio;
    // el bucle se ejecuta siempre que aux->siguiente sea distinto de null
    while (aux->Siguiente != NULL) {
        // como es != de null, guardo en aux la siguiente direccion
        aux = aux->Siguiente;
    }
    // ahora que salio del bucle y aux->siguiente apunta a null(porque llego al ultimo nodo), hago que apunte al nuevo nodo
    aux->Siguiente = nuevoNodo;
}

int generarID(Nodo *inicio);
int generarID(Nodo *inicio) {
    Nodo *aux = inicio;
    //verifico si el inicio apunta a null, si es asi es el primer nodo entonces su id empieza en mil
    if (aux->Siguiente == NULL) {
        return 1000;
    } else {// si entra en el else es porque ya existian nodos entonces leemos el id del ultimo y lo retornamos incrementado
        while (aux->Siguiente != NULL) {
            aux = aux->Siguiente;
        }
        // una vez que aux esta posicionado en el nodo final retorno su id incrementado en 1
        return aux->T.TareaID++;
    }
}


Tarea crearTarea(Nodo *inicio);
Tarea crearTarea(Nodo *inicio) {
    char buff[50];//var aux para guardar temporalmente la descripcion
    Tarea tNueva;
    tNueva.TareaID = generarID(inicio);
    printf("\nIngrese la descripcion: ");
    fflush(stdin);
    gets(buff);
    tNueva.Descripcion = (char*)malloc(sizeof(char)* strlen(buff)+1);
    strcpy(tNueva.Descripcion,buff);
    printf("\nIngrese la duracion: ");
    scanf("%d", &tNueva.Duracion);
    return tNueva;
}

void cargarTarea(Nodo *inicio);
void cargarTarea(Nodo *inicio){
    int opcion=0;//variable bandera para salir del bucle
    do
    {
        /* code */
    } while (opcion != 0);
}

int main() {
    Nodo *tareasPendientes = CrearListaVacia();
    Nodo *tareasRealizadas = CrearListaVacia();
    return 0;
}