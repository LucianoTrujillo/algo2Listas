# TDA Lista (+ pila y cola)

[![N|Solid](https://res.cloudinary.com/practicaldev/image/fetch/s--y3j6aJXJ--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://res.cloudinary.com/practicaldev/image/fetch/s--_PwtVEkJ--/c_limit%252Cf_auto%252Cfl_progressive%252Cq_auto%252Cw_880/https://www.educative.io/api/edpresso/shot/5077575695073280/image/5192456339456000)](https://nodesource.com/products/nsolid)

# El programa

### ¿Qúe es?

Es una implementación del tipo de dato abstracto "Lista simplemente enlazada", que además contiene diferentes primitivas de TDAs como pila y cola, junto con un iterador interno y externo. La lista está implementada con nodos en memoria dinámica y almacena cualquier tipo de dato.

### Compilación

Para compilarlo se puede hacer uso del siguiente comando dentro de la carpeta del proyecto.
```
$ make lista_se
```

### Ejecución

La ejecución es muy sencilla, solo basta con el siguiente comando para correr todas las pruebas unitarias del TDA.
```
$ ./lista_se
```

### Tests de memoria

El test de memoria con Valgrind se corre de la siguiente manera.
```
$ make mem_test
```

Para mas comandos visitar el Makefile.

### Funcionamiento general de la implementación

El TDA viene con las operaciones básicos que se esperan de una lista, las cuales se mencionan más abajo. Al utiliza nodos enlazados, maneja de manera eficiente la cantidad de memoria que ocupa en el Heap, ya que solo usa lo justo y necesario. Para hacer uso de la lista, basta con crearla, utilizarla y destruirla.

Cada operación del TDA se encuentra testeada con pruebas unitarias exhaustivas que se realizan al ejecutar el programa.

A continuacion se presenta un caso de uso para ilustrar las operaciones de la lista:
```

int numerito = 5;
int otro_numerito = 12342;

lista_t* lista = lista_crear();
lista_insertar(lista, &numerito);
lista_insertar(lista, &otro_numerito);

lista_borrar_en_posicion(lista, 0);
int* elemento = lista_elemento_en_posicion(lista, 0);
printf("%i", *elemento);
```

El resultado de este conjunto de operaciones sería "12342", dado se insertan dos elementos pero se borra el primero de ellos, y el segundo pasa a quedar en la primer posicion.

# Conceptos teóricos

## Lista

### Concepto
A nivel macro, una lista es un **conjunto de elementos ordenados**. 
Este concepto es utilizado todo el tiempo en nuestra vida contidiana, por ejemplo:
   - Cuando queremos comprar ciertos alimentos en el supermercado.
   - Cuando queremos tener la información de todos los invitados a un cumpleaños.
   - Cuando queremos organizarnos para hacer ciertas tareas en un día.
   - Coincidentemente, esto es una lista.

### Informática
En la informática hay ciertas operaciones que se pueden realizar sobre una lista, aunque dependiendo del problema a ser resuelto, puede sufrir variaciones.

Las **operaciones** mas comunes que se hacen sobre una lista son:

   - Crear.
   - Destruir.
   - Insertar en posición *n*.
   - Eliminar en posición *n*.
   - ¿Esta vacía?.
   - Ver elemento en posición *n*.

Una lista puede tener diferentes implementaciones ya sea estática, dinámica, usando nodos, etc. Cada una ofrece diferentes pros y cons, pero ahora nos interesa en particular la lista dinámicamente usada con **nodos**.

Un **nodo** es tipo de dato que dependiendo del tipo de lista varía, pero contiene un dato y referencias a almenos un nodo que no sea el mismo. 

### Simplemente Enlazada
En el caso de las listas simplemente enlazadas, se consta de nodos conformados por:
   - un dato.
   - una *referencia* al siguiente elemento en la lista.

La estructura de una lista con nodos enlazados permite la gran **ventaja** de que la memoria no debe ser contigua, es decir no se necesita reservar un bloque de memoria que guarde toda la lista, si no que se va reservando de a "pedazitos" (bloque que ocupa un nodo, muy poco comparado con la lista entera). Además, las operaciones como agregar y eliminación solo requieren unos pocos pasos, para cambiar las referencias de los nodos. No se necesita mover los otros nodos de lugar.

La lista de nodos enlazados maneja de manera muy **eficiente** la memoria ocupada, ya que se va agrandando y reduciendo para ocupar solo lo que necesita. A diferencia del vector dinámico, la lista no tiene que preocuparse por no encontrar un bloque de memoria nuevo donde guardar la lista en caso de fallo (lo cual genera un *O(n)* para la insersión o remoción en el peor caso del vector dinámico, pues tiene que copiar todos los elementos al nuevo vector).

Sin embargo, la lista de nodos enlazados tiene sus *desventajas*. Al no tener la memoria contigua fisicamente, para acceder/agregar/modificar un elemento en la posición *n*, se debe **recorrer** la lista hasta llegar a ese elemento, dado que no se puede calcular la posición de memoria de antemano. Esto trae una deficiencia a nivel complejidad en estas operaciones básicas sobre una lista.

### Doblemente Enlazada
En el caso de las listas doblemente enlazadas, se consta de nodos conformados por:
   - un dato.
   - una *referencia* al siguiente elemento en la lista (si es que existe). 
   - una *referencia* al anterior elemento en la lista (si es que existe).

Esta implementación de lista permite una manipulación mas fácil para ciertas operaciones particulares como invertir una lista y es muy útil para cuando se requiere recorrer de manera bidireccional la lista.

## Pilas

### Concepto
Al igual que la lista, la pila es un conjunto de elementos ordenados. Sin embargo, lo que las diferencia son las **operaciones** que se pueden realizar sobre cada una. Su estructura es conocida como **LIFO** (Last in, first out), en el cual como explica el nombre, el útlimo en entrar es el primero en salir. Esto restringe las operaciones que nos permiten las listas, pero modelan de una manera mas adecuada ciertas estructuras y comportamientos:

   - Platos de concina.
   - Cartas del juego UNO (si es que nadie hace trampa).
   - El historial del navegador.

El factor intrínseco de las pilas es que la prioridad de salida se la da al que "acaba de llegar".

### Características Fundamentales

Al igual que las listas, las pilas tienen ciertas operaciones fundamentales:

   - Crear.
   - Destruir.
   - Apilar.
   - Desapilar.
   - Tope.
   - ¿Está vacía?

## Colas

### Concepto
Al igual que la lista, la cola es un conjunto de elementos ordenados. Sin embargo, lo que las diferencia son las **operaciones** que se pueden realizar sobre cada una. Su estructura es conocida como **FIFO** (first in, first out), en el cual como explica el nombre, el primero en entrar es el primero en salir. Al igual que las pilas, restringe las operaciones que nos permiten las listas, pero a la vez facilita una manera de utilizarlas que es muy eficaz para resolver otros problemas de la vida contidiana:

   - Colas de colectivo.
   - Cola del supermercado.
   - Turno con la doctora.
   - Cola online de entradas a conciertos.

El factor intrínseco de las colas es que la prioridad de salida se la da al que estuvo más tiempo "esperando".

### Características Fundamentales

Al igual que las listas, las colas tienen ciertas operaciones fundamentales:

   - Crear.
   - Destruir.
   - Encolar.
   - Desencolar.
   - Obtener el primer elemento.
   - ¿Está vacía?

## Iteradores

Un iterador es un *herramienta* que permite **recorrer** de manera mas eficiente los elementos de una lista de nodos. Dependiendo del tipo, tiene más, o menos control sobre el recorrido de los elementos. En vez de tener que recorrer la lista desde el comienzo hasta el elemento actual siendo procesado (lo cual le da un orden de complejidad **O(n)** como peor caso), se accede directamente al elemento siguiente al anterior (cuyo orden de complejidad es **O(1)** para todos los casos).

### Iterador interno

Un iterador interno se encarga en absoluto de la lógica de iteración sobre la lista de elementos. Permite al usuario del iterador, pasar la acción que se quiere realizar sobre cada elemento de la lista.

Suele ser una sola función que se encarga de hacer la iteración, sin necesidad de crear estructuras extras.

Este tipo de iterador suele ser el más recomendado si su uso es posible, dado a que es menos propensa a errores de quien la utiliza. Además, requiere menos código de quien la utiliza y es más fácil de leer.

Como diría nuestro querido Edsger Dijkstra:

> “Simplicity is prerequisite for reliability.”

A continuación se muestra un ejemplo en pseudocódigo de como funciona un iterador interno:
```sh
funcion mostrar_personaje(personaje){
    ...
}

personajes = "Cutrulu", "Mamichula", "Ricardo Fort"

#iterador:
por_cada_personaje(lista_personajes, mostrar_personaje)

```

De esta manera, nos aseguramos que estamos recorriendo toda la lista de personajes y ejecutando la acción por cada uno de ellos.
También existen implementaciones como la de este trabajo, en el cual se introduce una variable que sirve de contexto para cada elemento iterado.

### Iterador externo

Un iterador externo le permite al usuario el control sobre la iteración de los elementos. El iterador externo se encarga de pasar al siguiente elemento cuando el usuario lo desee. 

Es útil cuando se necesita un flujo de control complejo a la hora de recorrer una lista.

En general suelen ser menos recomendados porque al darle mas control al usuario, genera mas espacio para errores. Además, su uso es más tedioso por toda la preparación y desmontamiento del mismo.

A continuación se muestra un ejemplo en pseudocódigo de como funciona un iterador externo:
```sh
funcion mostrar_personaje(personaje){
    ...
}

personajes = "Cutrulu", "Mamichula", "Ricardo Fort"

# creación
iterador = crear_iterador(personajes)

# iteración
mientras_que(iterador_tiene_siguiente(iterador)){
    personaje = lista_elemento_actual(iterador)
    mostrar(personaje)
    lista_avanzar_elemento(iterador)
}

# destrucción
destruir_iterador(iterador)

```
Como se observa, su uso requiere de más líneas de código y es mas propenso a error, pero puede ser útil para ciertos casos condicionales en iteraciones.


Licencia
----

Derechos reservados © Luchito

