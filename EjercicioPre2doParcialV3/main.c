#include <stdio.h>
#include <stdlib.h>
#include "Compra.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"

/**
    Realizar un programa que lee de un archivo los datos de compras de productos realizadas por clientes.
    Luego se le pedira al usuario que ingrese un id de un producto y el programa deberá imprimir por pantalla:
    - 1. Lista de compras filtrada segun el producto ingresado
    - 2. Monto total de cada compra considerando el valor del iva indicado.

    - 3. Por ultimo la lista filtrada obtenida con los datos ya calculados, debera ser escrita en un archivo separado por
    comas llamado "informe.csv", con el mismo formato que el original pero con una columna mas al final, en donde se
    indicara el monto total calculado.

    Para realizar el punto 1, se debera utilizar la funcion "filter".
    Para realizar el punto 2, se debera utilizar la funcion "map".
    Para imprimir por pantalla la lista, utilizar iterator.
*/

int generarArchivoInforme(char* fileName,LinkedList* listaCompras);

int main()
{
    LinkedList* listaCompras = ll_newLinkedList();
    LinkedList* listaProducto = ll_newLinkedList();
    FILE* archivoCompras = fopen("data.csv","r");
    FILE* archivoInformes = fopen("informes.csv","w");
    int idIngresado;

    parser_CompraFromText(archivoCompras,listaCompras);
    input_getEnteros(&idIngresado,"\nIngrese ID de producto: ","Numero invalido",2);

    listaProducto = ll_filter(listaCompras,compra_findById,idIngresado);
    ll_map(listaProducto,compra_calculoPrecio);
    parser_SaveToText(archivoInformes,listaProducto);

    return 0;
}

