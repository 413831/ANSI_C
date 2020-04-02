
#include "LinkedList.h"

#ifndef _COMPRA_H
#define _COMPRA_H
typedef struct
{
	char nombreCliente[50];
	int id;
	float precio;
	int unidades;
	float iva;
	float precioTotal;
}Compra;
#endif// _COMPRA_H


#define BUFFER 4000
#define LEN_LL 6

Compra* compra_new();
Compra* compra_constructor(char* nombreCliente,int id,float precio,int unidades,float iva);
int compra_destructor(Compra* this);
int compra_setNombreCliente(Compra* this,char* nombreCliente);
int compra_setId(Compra* this,int id);
int compra_setPrecio(Compra* this,float precio);
int compra_setUnidades(Compra* this,int unidades);
int compra_setIva(Compra* this,float iva);
int compra_setTotal(Compra* this,float precio);
char* compra_getNombreCliente(Compra* this);
int compra_getId(Compra* this);
float compra_getPrecio(Compra* this);
int compra_getUnidades(Compra* this);
float compra_getIva(Compra* this);
Compra* compra_getByNombreCliente(LinkedList* pArray,char* nombreCliente);
Compra* compra_getById(LinkedList* pArray,int id);
Compra* compra_getByPrecio(LinkedList* pArray,float precio);
Compra* compra_getByUnidades(LinkedList* pArray,int unidades);
Compra* compra_getByIva(LinkedList* pArray,float iva);
int compra_compareByNombreCliente(void* thisA ,void* thisB);
int compra_compareById(void* thisA ,void* thisB);
int compra_compareByPrecio(void* thisA ,void* thisB);
int compra_compareByUnidades(void* thisA ,void* thisB);
int compra_compareByIva(void* thisA ,void* thisB);
int compra_show(Compra* this);
int compra_calculoPrecio(void* this);
int compra_findById(void* this,int id);
