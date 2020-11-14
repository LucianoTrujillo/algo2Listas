#include <stdio.h>
#include "pa2mm.h"
#include "lista.h"

#define ERROR -1
#define EXITO 0

void probar_creacion_lista(){
    lista_t* lista = lista_crear();
    pa2m_afirmar(
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL && 
        lista->cantidad == 0,
        "Se crea una lista con sus nodos nulos y cantidad de nodos 0");
    lista_destruir(lista);
}

void probar_insertar_lista(){
    lista_t* lista = lista_crear();
    char* elemento_1 = "elemento";
    char* elemento_2 = "otro elemento";
    char* elemento_3 = "un elemento mas";
    
    int resultado =  lista_insertar(NULL, elemento_1);
    pa2m_afirmar(resultado == ERROR, "No se puede insertar un elemento a una lista inexistente");
    
    resultado = lista_insertar(lista, elemento_1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1,
        "Se inserta un elemento a una lista vacía");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, elemento_1);
    resultado = lista_insertar(lista, elemento_2);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 2,
        "Se inserta un elemento a una lista con un elemento");
        
    resultado = lista_insertar(lista, elemento_3);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente->siguiente == lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_3 &&
        lista->cantidad == 3,
        "Se inserta un elemento a una lista con múltiples elementos");

    lista_destruir(lista);
}

void probar_insertar_en_posicion_lista(){
    lista_t* lista = lista_crear();
    char* elemento_1 = "elemento";
    char* elemento_2 = "otro elemento";
    char* elemento_3 = "un elemento mas";
    char* elemento_4 = "otro elemento mas";
    
    int resultado =  lista_insertar_en_posicion(NULL, elemento_1, 0);
    pa2m_afirmar(resultado == ERROR, "No se puede insertar un elemento a una lista inexistente");
    
    resultado = lista_insertar_en_posicion(lista, elemento_1, 0);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente == NULL &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1,
        "Se inserta un elemento a una lista vacía en posicion 0");
    
    lista_destruir(lista);
    lista = lista_crear();
    resultado = lista_insertar_en_posicion(lista, elemento_1, (size_t)(-312));
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente == NULL &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1, 
        "Dada una lista vacía, Se trata de insertar un elemento en una posición menor a 0, entonces se inserta al comienzo.");
        
    lista_destruir(lista);
    lista = lista_crear();
    resultado = lista_insertar_en_posicion(lista, elemento_1, 312);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente == NULL &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1,
        "Dada una lista vacía, se trata de insertar un elemento en una posicón mayor a 0, entonces se inserta al comienzo.");
        
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, elemento_1);
    lista_insertar(lista, elemento_2);
    resultado = lista_insertar_en_posicion(lista, elemento_3, 2);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente->siguiente == lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_3 &&
        lista->cantidad == 3,
        "Dada una lista con múltiples elementos, se inserta un elemento en la última posición, entonces se inserta al final.");
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, elemento_1);
    lista_insertar(lista, elemento_2);
    resultado = lista_insertar_en_posicion(lista, elemento_3, 321);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente->siguiente == lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_3 &&
        lista->cantidad == 3,
        "Dada una lista con múltiples elementos, se trata de insertar un elemento en una posición mayor a la última, entonces se inserta al final.");
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, elemento_1);
    resultado = lista_insertar_en_posicion(lista, elemento_2, 1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente == lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 2,
        "Se inserta un elemento en la última posicion a una lista con un elemento");
        
    resultado = lista_insertar_en_posicion(lista, elemento_3, 1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_inicio->siguiente->elemento == elemento_3 &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 3,
        "Se inserta un elemento en el medio de la lista");
        
    resultado = lista_insertar_en_posicion(lista, elemento_4, 0);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == elemento_4 &&
        lista_elemento_en_posicion(lista, 1) == elemento_1 &&
        lista_elemento_en_posicion(lista, 2) == elemento_3 &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 4, "Se inserta un elemento al inicio de una lista no vacía");
    
    lista_destruir(lista);
}

void probar_borrar_lista(){
    lista_t* lista = lista_crear();
    
    int resultado =  lista_borrar(NULL);
    pa2m_afirmar(resultado == ERROR, "No se puede borrar de una lista inexistente");
    
    resultado = lista_borrar(lista);
    pa2m_afirmar(resultado == ERROR, "No se puede borrar de una lista vacía");
    
    lista_insertar(lista, "elemento_1");
    resultado = lista_borrar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista->cantidad == 0, "Se borra un elemento de una lista y queda vacía");

    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    resultado = lista_borrar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_1" &&
        lista->nodo_fin->elemento == (void*)"elemento_1" &&
        lista->cantidad == 1, "Se borra un elemento de una lista con 2 elementos");

    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    resultado = lista_borrar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_1" &&
        lista_elemento_en_posicion(lista, 1) == (void*)"elemento_2" &&
        lista->nodo_fin->elemento == (void*)"elemento_3" &&
        lista->cantidad == 3, "Se borra un elemento de una lista con múltiples elementos");

    
    lista_destruir(lista);
}

void probar_borrar_en_posicion_lista(){
    lista_t* lista = lista_crear();
    
    int resultado =  lista_borrar_de_posicion(NULL, 0);
    pa2m_afirmar(resultado == ERROR, "No se puede borrar de una lista inexistente");
    
    resultado = lista_borrar_de_posicion(lista, 0);
    pa2m_afirmar(
        resultado == ERROR &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista-> cantidad == 0, "No se puede borrar de una lista vacía");
        
    lista_insertar(lista, "elemento_1");
    resultado = lista_borrar_de_posicion(lista, 0);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista->cantidad == 0, "Se borra el elemento en la posicion 0 de una lista con solo un elemento");
        
    lista_insertar(lista, "elemento_1");
    resultado = lista_borrar_de_posicion(lista, 123);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista->cantidad == 0, "Se borra el único elemento de una lista si la posicion pasada no existe");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    resultado = lista_borrar_de_posicion(lista, 123);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_1" &&
        lista->nodo_fin->elemento == (void*)"elemento_1" &&
        lista->cantidad == 1, "Se borra el último elemento de una lista si la posicion pasada no existe");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    resultado = lista_borrar_de_posicion(lista, 1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_1" &&
        lista->nodo_fin->elemento == (void*)"elemento_3" &&
        lista->cantidad == 2, "Se borra el elemento del medio de una lista con múltipes elementos");
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    resultado = lista_borrar_de_posicion(lista, 0);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_2" &&
        lista->nodo_fin->elemento == (void*)"elemento_3" &&
        lista->cantidad == 2, "Se borra el primer elemento de una lista con múltiples elementos");

    lista_destruir(lista);
}

void probar_elemento_en_posicion_lista(){
    lista_t* lista = lista_crear();
    
    char* elemento = (char*)lista_elemento_en_posicion(NULL, 0);
    pa2m_afirmar(elemento == NULL, "Debe devolver elemento nulo si la lista es inexistente");
    
    elemento = (char*)lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(elemento == NULL, "Debe devolver elemento nulo si se quiere acceder a la posicion 0 de una lista vacía");
    
    lista_insertar(lista, "elemento_1");
    elemento = (char*)lista_elemento_en_posicion(lista, 123);
    pa2m_afirmar(elemento == NULL, "Debe devolver elemento nulo si se quiere acceder a una posicion mayor a la máxima de una lista");
       
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    elemento = (char*)lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Debe devolver el único elemento si se accede a la posicion 0 de una lista con un único elemento");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    elemento = (char*)lista_elemento_en_posicion(lista, 0);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Debe devolver el primer elemento si se accede a la posicion 0 de una lista con múltiples elementos");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    elemento = (char*)lista_elemento_en_posicion(lista, 2);
    pa2m_afirmar(elemento == (void*)"elemento_3", "Debe devolver el último elemento si se accede a la última posicion de una lista con un múltiples elementos");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    elemento = (char*)lista_elemento_en_posicion(lista, 1);
    pa2m_afirmar(elemento == (void*)"elemento_2", "Debe devolver el segundo elemento si se accede al segundo posicion de una lista con un múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_ultimo_lista(){
    lista_t* lista = lista_crear();
    
    char* elemento = lista_ultimo(NULL);
    pa2m_afirmar(elemento == NULL, "Devuelve el elemento nulo si la lista es inexistente");
    
    elemento = lista_ultimo(lista);
    pa2m_afirmar(elemento == NULL, "Devuelve el elemento nulo si la lista está vacía");
    
    lista_insertar(lista, "elemento_1");
    elemento = lista_ultimo(lista);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Dada una lista con un elemento, devuelve el único elemento.");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    elemento = lista_ultimo(lista);
    pa2m_afirmar(elemento == (void*)"elemento_3", "Devuelve el último elemento de una lista de múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_vacia_lista(){
    lista_t* lista = lista_crear();
    
    bool lista_esta_vacia = lista_vacia(NULL);
    pa2m_afirmar(lista_esta_vacia == true, "Una lista inexistente es una lista vacía");
    
    lista_esta_vacia = lista_vacia(lista);
    pa2m_afirmar(lista_esta_vacia == true, "Una lista recién inicializada sin elementos está vacía");
    
    lista_insertar(lista, "elemento_1");
    lista_esta_vacia = lista_vacia(lista);
    pa2m_afirmar(lista_esta_vacia == false, "Una lista con un elemento no está vacía");
    
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_esta_vacia = lista_vacia(lista);
    pa2m_afirmar(lista_esta_vacia == false, "Una lista con múltiples elemento no está vacía");
    
    lista_destruir(lista);
}

void probar_lista_elementos_lista(){
    lista_t* lista = lista_crear();
    
    size_t cantidad = lista_elementos(NULL);
    pa2m_afirmar(cantidad == 0, "Una lista inexistente tiene cero elementos");
    
    cantidad = lista_elementos(lista);
    pa2m_afirmar(cantidad == 0, "Una lista inicializada vacía tiene cero elementos");
    
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    cantidad = lista_elementos(lista);
    pa2m_afirmar(cantidad == 4, "Una lista con múltiples elementos devuelve la cantidad exacta de elementos");
    
    lista_destruir(lista);
}

void probar_lista_apilar(){
    lista_t* lista = lista_crear();
    char* elemento_1 = "elemento";
    char* elemento_2 = "otro elemento";
    char* elemento_3 = "un elemento mas";
    
    int resultado =  lista_apilar(NULL, elemento_1);
    pa2m_afirmar(resultado == ERROR, "No se puede apilar un elemento a una lista inexistente");
    
    resultado = lista_apilar(lista, elemento_1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1, "Se apila un elemento a una lista vacía");
        
    resultado = lista_apilar(lista, elemento_2);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 2, "Se apila un elemento a una lista con un elemento");
        
    resultado = lista_apilar(lista, elemento_3);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista_elemento_en_posicion(lista, 1) == elemento_2 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_3 &&
        lista->cantidad == 3, "Se apila un elemento a una lista con múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_desapilar(){
    lista_t* lista = lista_crear();
    
    int resultado =  lista_desapilar(NULL);
    pa2m_afirmar(resultado == ERROR, "No se puede desapilar de una lista inexistente");
    
    resultado = lista_desapilar(lista);
    pa2m_afirmar(resultado == ERROR, "No se puede desapilar de una lista vacía");
    
    lista_insertar(lista, "elemento_1");
    resultado = lista_desapilar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista->cantidad == 0, "Se desapila un elemento de una lista y queda vacía");

    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    resultado = lista_desapilar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_1" &&
        lista_elemento_en_posicion(lista, 1) == (void*)"elemento_2" &&
        lista->nodo_fin->elemento == (void*)"elemento_3" &&
        lista->cantidad == 3, "Se desapila un elemento de una lista con múltiples elementos");

    
    lista_destruir(lista);
}

void probar_lista_tope(){
    lista_t* lista = lista_crear();
    
    char* elemento = lista_tope(NULL);
    pa2m_afirmar(elemento == NULL, "Devuelve el elemento nulo si la pila es inexistente");
    
    elemento = lista_tope(lista);
    pa2m_afirmar(elemento == NULL, "Devuelve el elemento nulo si la pila está vacía");
    
    lista_insertar(lista, "elemento_1");
    elemento = lista_tope(lista);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Devuelve el elemento único elemento de la pila");
    
    lista_destruir(lista);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    elemento = lista_tope(lista);
    pa2m_afirmar(elemento == (void*)"elemento_3", "Devuelve el último elemento de una pila de múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_encolar(){
    lista_t* lista = lista_crear();
    char* elemento_1 = "elemento";
    char* elemento_2 = "otro elemento";
    char* elemento_3 = "un elemento mas";
    
    int resultado =  lista_encolar(NULL, elemento_1);
    pa2m_afirmar(resultado == ERROR, "No se puede encolar un elemento a una lista inexistente");
    
    resultado = lista_encolar(lista, elemento_1);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_1 &&
        lista->cantidad == 1, "Se encola un elemento a una lista vacía");
        
    resultado = lista_encolar(lista, elemento_2);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_2 &&
        lista->cantidad == 2, "Se encola un elemento a una lista con un elemento");
        
    resultado = lista_encolar(lista, elemento_3);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio &&
        lista->nodo_inicio->elemento == elemento_1 &&
        lista_elemento_en_posicion(lista, 1) == elemento_2 &&
        lista->nodo_fin &&
        lista->nodo_fin->elemento == elemento_3 &&
        lista->cantidad == 3, "Se encola un elemento a una lista con múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_desencolar(){
    lista_t* lista = lista_crear();
    
    pa2m_afirmar(lista_desencolar(NULL) == ERROR, "No se puede desencolar una cola inexistente");
    
    pa2m_afirmar(lista_desencolar(lista) == ERROR, "No se puede desencolar una cola vacía");
    
    lista_encolar(lista, "elemento_1");
    int resultado =  lista_desencolar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL &&
        lista->cantidad == 0, "Se desencola una cola de un elemento y queda vacía");
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_encolar(lista, "elemento_1");
    lista_encolar(lista, "elemento_2");
    resultado = lista_desencolar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_2" &&
        lista->nodo_fin->elemento == (void*)"elemento_2" &&
        lista->cantidad == 1, "Se desencola una cola de dos elemento y queda el último elemento");
        
    lista_destruir(lista);
    lista = lista_crear();
    lista_encolar(lista, "elemento_1");
    lista_encolar(lista, "elemento_2");
    lista_encolar(lista, "elemento_3");
    lista_encolar(lista, "elemento_4");
    resultado = lista_desencolar(lista);
    pa2m_afirmar(
        resultado == EXITO &&
        lista->nodo_inicio->elemento == (void*)"elemento_2" &&
        lista_elemento_en_posicion(lista, 1) == (void*)"elemento_3" &&
        lista->nodo_fin->elemento == (void*)"elemento_4" &&
        lista->cantidad == 3, "Se desencola una cola de múltiples elementos");
    
    lista_destruir(lista);
}

void probar_lista_primero(){
    lista_t* lista = lista_crear();
    
    char* elemento = (char*)lista_primero(NULL);
    pa2m_afirmar(elemento == NULL, "devuelve elemento nulo si la cola es inexistente");
    
    elemento = (char*)lista_primero(lista);
    pa2m_afirmar(elemento == NULL, "Devuelve elemento nulo si se quiere acceder al primero de una cola vacía");
    
    lista_encolar(lista, "elemento_1");
    elemento = (char*)lista_primero(lista);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Devuelve el primer y único elemento de la cola");

    lista_destruir(lista);
    lista = lista_crear();
    lista_encolar(lista, "elemento_1");
    lista_encolar(lista, "elemento_2");
    lista_encolar(lista, "elemento_3");
    lista_encolar(lista, "elemento_4");
    elemento = (char*)lista_primero(lista);
    pa2m_afirmar(elemento == (void*)"elemento_1", "Devuelve el primer elemento de una cola con múltiples elementos");
    lista_destruir(lista);
}

void probar_lista() {
    pa2m_nuevo_grupo("PRUEBAS DE CREACION LISTA");
    probar_creacion_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE INSERTAR LISTA");
    probar_insertar_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE INSERTAR EN POSICION LISTA");
    probar_insertar_en_posicion_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE BORRAR EN LISTA");
    probar_borrar_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE BORRAR DE POSICION LISTA");
    probar_borrar_en_posicion_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE OBTENER ELEMENTO EN POSICION LISTA");
    probar_elemento_en_posicion_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE OBTENER ULTIMO EN LA LISTA");
    probar_lista_ultimo_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA VACÍA");
    probar_lista_vacia_lista();
    
    pa2m_nuevo_grupo("PRUEBAS DE LISTA CANTIDAD DE ELEMENTOS");
    probar_lista_elementos_lista();
}

void probar_pila(){
    pa2m_nuevo_grupo("PRUEBAS DE APILAR");
    probar_lista_apilar();
    
    pa2m_nuevo_grupo("PRUEBAS DE DESAPILAR");
    probar_lista_desapilar();
    
    pa2m_nuevo_grupo("PRUEBAS DE TOPE");
    probar_lista_tope();
    
}

void probar_cola(){
    pa2m_nuevo_grupo("PRUEBAS DE ENCOLAR");
    probar_lista_encolar();
    
    pa2m_nuevo_grupo("PRUEBAS DE DESENCOLAR");
    probar_lista_desencolar();
    
    pa2m_nuevo_grupo("PRUEBAS DE PRIMERO EN LA COLA");
    probar_lista_primero();
}

bool mostrar_elemento_test(void* elemento, void* contador){
    if(elemento && contador)
        (*(int*)contador)++;
    return true;
}

void probar_iterador_interno(){
    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR INTERNO");
    
    lista_t* lista = lista_crear();
    int contador = 0;
    
    size_t resultado =  lista_con_cada_elemento(NULL, mostrar_elemento_test, &contador);
    pa2m_afirmar(
        resultado == 0 &&
        contador == 0, "No se intera sobre una lista inexistente.");
    
    resultado = lista_con_cada_elemento(lista, NULL, &contador);
    pa2m_afirmar(
        resultado == 0 &&
        contador == 0, "No se itera con una función inexistente.");
    
    resultado = lista_con_cada_elemento(lista, mostrar_elemento_test, &contador);
    pa2m_afirmar(
        resultado == 0 &&
        contador == 0, "No se itera sobre una lista vacía");
    
    lista_insertar(lista, "elemento_1");
    resultado = lista_con_cada_elemento(lista, mostrar_elemento_test, &contador);
    pa2m_afirmar(
        resultado == 1 &&
        contador == 1, "La lista itera sobre el único elemento");
    
    lista_destruir(lista);
    lista = lista_crear();
    contador = 0;
    lista_insertar(lista, "elemento_1");
    resultado = lista_con_cada_elemento(lista, mostrar_elemento_test, NULL);
    pa2m_afirmar(
        resultado == 1 &&
        contador == 0, "La lista itera sobre el único elemento aunque no haya contexto");
        
    lista_destruir(lista);
    lista = lista_crear();
    contador = 0;
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    resultado = lista_con_cada_elemento(lista, mostrar_elemento_test, &contador);
    pa2m_afirmar(
        resultado == 4 &&
        contador == 4, "La lista itera sobre múltiples elementos");
        
    lista_destruir(lista);
    lista = lista_crear();
    contador = 0;
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    resultado = lista_con_cada_elemento(lista, mostrar_elemento_test, NULL);
    pa2m_afirmar(
        resultado == 4 &&
        contador == 0, "La lista itera sobre múltiples elementos aunque no haya contexto");
    
    lista_destruir(lista);
}

void    probar_iterador_externo(){
    pa2m_nuevo_grupo("PRUEBAS DE CREACION ITERADOR EXTERNO");
    
    lista_t* lista = lista_crear();
    lista_iterador_t* it;
    
    it = lista_iterador_crear(NULL);
    pa2m_afirmar(it == NULL, "No se crea un un iterador si la lista es inexistente");
    
    it = lista_iterador_crear(lista);
    pa2m_afirmar(
        it->lista == lista &&
        it->corriente == lista->nodo_inicio, "Se crea un iterador sobre una lista vacía");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    it = lista_iterador_crear(lista);
    
    pa2m_afirmar(
        it->lista == lista &&
        it->corriente == lista->nodo_inicio, "El iterador queda inicializado apuntando al primer elemento de una lista no vacía");
        
    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR TIENE SIGUIENTE");
    
    pa2m_afirmar(lista_iterador_tiene_siguiente(NULL) == false, "Un iterador inexistente no tiene siguiente");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    it = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_tiene_siguiente(it) == false, "Una lista vacía no tiene siguiente");

    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    it = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_tiene_siguiente(it) == true, "Tiene siguiente si la lista es de un elemento");

    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    it = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_tiene_siguiente(it) == true, "Tiene siguiente si la lista es de múltiples elementos");
    
    pa2m_nuevo_grupo("PRUEBAS DE AVANZAR ITERADOR");
    
    pa2m_afirmar(lista_iterador_avanzar(NULL) == false, "Iterador inexistente no puede avanzar");


    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    it = lista_iterador_crear(lista);
    bool pudo_avanazar = lista_iterador_avanzar(it);
    
    pa2m_afirmar(pudo_avanazar == false && it->corriente == NULL, "No se avanza sobre una lista vacía");

    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    it = lista_iterador_crear(lista);
    pudo_avanazar = lista_iterador_avanzar(it);
    pa2m_afirmar(pudo_avanazar == false && it->corriente == NULL, "Se avanza sobre una lista de un elemento");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    it = lista_iterador_crear(lista);
    
    pudo_avanazar = lista_iterador_avanzar(it);
    pa2m_afirmar(
        pudo_avanazar == true &&
        it->corriente == lista->nodo_inicio->siguiente, "Se avanza 1 vez sobre una lista de muchos elementos");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    it = lista_iterador_crear(lista);
    
    pudo_avanazar = lista_iterador_avanzar(it);
    pudo_avanazar = lista_iterador_avanzar(it);
    pudo_avanazar = lista_iterador_avanzar(it);

    pa2m_afirmar(
        pudo_avanazar == true &&
        it->corriente == lista->nodo_fin, "Se avanza hasta llegar al útlimo elemento una lista de muchos elementos");
        
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    lista_insertar(lista, "elemento_3");
    lista_insertar(lista, "elemento_4");
    it = lista_iterador_crear(lista);
    
    pudo_avanazar = lista_iterador_avanzar(it);
    pudo_avanazar = lista_iterador_avanzar(it);
    pudo_avanazar = lista_iterador_avanzar(it);
    pudo_avanazar = lista_iterador_avanzar(it);

    pa2m_afirmar(
        pudo_avanazar == false &&
        it->corriente == NULL, "Se termina de iterar toda la lista y queda apuntando al elemento nulo");
        
    lista_iterador_avanzar(it);
    lista_iterador_avanzar(it);
    lista_iterador_avanzar(it);
    
    pa2m_afirmar(lista_iterador_avanzar(it) == false, "Luego de haber terminado de iterar no se puede avanazar más");
     

    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR ELEMENTO ACTUAL");
    
    pa2m_afirmar(lista_iterador_elemento_actual(NULL) == NULL, "Elemento actual de una lista inexistente es nulo");
    
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    it = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_elemento_actual(it) == NULL, "Elemento actual de una lista vacía es nulo");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    it = lista_iterador_crear(lista);
    pa2m_afirmar(lista_iterador_elemento_actual(it) == lista->nodo_inicio->elemento, "Elemento actual de una lista recién inicializada con un elemento es el elemento");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    lista_insertar(lista, "elemento_2");
    it = lista_iterador_crear(lista);
    lista_iterador_avanzar(it);
    pa2m_afirmar(lista_iterador_elemento_actual(it) == (void*)"elemento_2", "Se obtiene el elemento siguiente al primero en una lista de múltiples elementos");
    
    lista_destruir(lista);
    lista_iterador_destruir(it);
    lista = lista_crear();
    lista_insertar(lista, "elemento_1");
    it = lista_iterador_crear(lista);
    lista_iterador_avanzar(it);
    pa2m_afirmar(lista_iterador_elemento_actual(it) == NULL, "Elemento actual luego de haber iterado la lista es nulo");
    
    lista_iterador_avanzar(it);
    lista_iterador_avanzar(it);
    lista_iterador_avanzar(it);
    lista_iterador_avanzar(it);
    pa2m_afirmar(lista_iterador_elemento_actual(it) == NULL, "Elemento actual luego haber tratado de avanzar sobre una lista previamente iterada es nulo");


    lista_iterador_destruir(it);
    lista_destruir(lista);

}

void pruebas_masivas(){
    lista_t* lista = lista_crear();
    const size_t cantidad = 25000;

    int elementos[cantidad];

    for(int i = 0; i < cantidad; i++){
        elementos[i] = i; 
        lista_insertar(lista, &(elementos[i]));
    }

    bool elementos_en_su_lugar = true;
    for(size_t i = 0; i < cantidad && elementos_en_su_lugar; i++){
        elementos_en_su_lugar = *(int*)(lista_elemento_en_posicion(lista, i)) == i;
    }

    pa2m_afirmar(elementos_en_su_lugar, "Se agregan 50k elementos");

    for(int i = 0; i < cantidad; i++){
        lista_borrar(lista);
    }

    pa2m_afirmar(
        lista->cantidad == 0 &&
        lista->nodo_inicio == NULL &&
        lista->nodo_fin == NULL,
         "Se borran 50k elementos");


    lista_destruir(lista);
}

int main() {
    probar_lista();
    probar_pila();
    probar_cola();
    probar_iterador_interno();
    probar_iterador_externo();
    pruebas_masivas();
    pa2m_mostrar_reporte();
}
