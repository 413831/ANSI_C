
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "Compra.h"

static int isValidNombreCliente(char* nombreCliente);
static int isValidId(int id);
static int isValidPrecio(float precio);
static int isValidUnidades(int unidades);
static int isValidIva(float iva);

/**
*\brief Valida un dato del campo nombreCliente
*\param nombreCliente Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidNombreCliente(char* nombreCliente)
{
	int retorno = 0;
	if(nombreCliente != NULL && strlen(nombreCliente) > 1)
	{
		retorno = 1;
	}
	return retorno;
}

/**
*\brief Valida un dato del campo id
*\param id Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidId(int id)
{
	int retorno = 0;
	if(id >= 0)
	{
		retorno = 1;
	}
	return retorno;
}

/**
*\brief Valida un dato del campo precio
*\param precio Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidPrecio(float precio)
{
	int retorno = 0;
	if(precio >= 0)
	{
		retorno = 1;
	}
	return retorno;
}

/**
*\brief Valida un dato del campo unidades
*\param unidades Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidUnidades(int unidades)
{
	int retorno = 0;
	if(unidades >= 0)
	{
		retorno = 1;
	}
	return retorno;
}

/**
*\brief Valida un dato del campo iva
*\param iva Es el dato recibido para validar
*\return Retorna 1 si el dato es valido sino retorna 0
*/
static int isValidIva(float iva)
{
	int retorno = 0;
	if(iva >= 0)
	{
		retorno = 1;
	}
	return retorno;
}


//////////////////PUBLIC//////////////////



/**
*\brief Reserva espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Compra* compra_new()
{
    Compra* this;
    this=malloc(sizeof(Compra));
    if(this != NULL)
    {
      return this;
    }
    else
    {
        return NULL;
    }
}

/**
*\brief Es el constructor del elemento donde se reserva memoria y se setean los campos
*\param COMPLETAR
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/
Compra* compra_constructor(char* nombreCliente,int id,float precio,int unidades,float iva)
{
	Compra* this = compra_new();
    Compra* retorno = NULL;

	if(this != NULL)
	{
		if(	!compra_setNombreCliente(this,nombreCliente) &&
			!compra_setId(this,id) &&
			!compra_setPrecio(this,precio) &&
			!compra_setUnidades(this,unidades) &&
			!compra_setIva(this,iva)
			)
		{
			retorno =  this;
		}
		else
		{
			compra_destructor(this);
			retorno = NULL;
		}
	}
    return retorno;
}

/**
*\brief Es el destructor del elemento que funciona para liberar memoria reservada
*\param this Es el elemento para eliminar
*\return Retorna 0 si logra eliminar elemento sino retorna -1
*/
int compra_destructor(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Es el setter del campo nombreCliente del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param nombreCliente Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setNombreCliente(Compra* this,char* nombreCliente)
{
	int retorno = -1;
	if(this != NULL && nombreCliente != NULL && isValidNombreCliente(nombreCliente))
	{
		strcpy(this->nombreCliente,nombreCliente);
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Es el setter del campo id del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param id Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setId(Compra* this,int id)
{
	int retorno = -1;
	if(this != NULL && isValidId(id))
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Es el setter del campo precio del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param precio Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setPrecio(Compra* this,float precio)
{
	int retorno = -1;
	if(this != NULL && isValidPrecio(precio))
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Es el setter del campo unidades del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param unidades Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setUnidades(Compra* this,int unidades)
{
	int retorno = -1;
	if(this != NULL && isValidUnidades(unidades))
	{
		this->unidades = unidades;
		retorno = 0;
	}
	return retorno;
}

/**
*\brief Es el setter del campo iva del elemento
*\param this Es el elemento que se recibe para setear un campo
*\param iva Es el dato recibido para setear el campo
*\return Retorna 0 si el elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_setIva(Compra* this,float iva)
{
	int retorno = -1;
	if(this != NULL && isValidIva(iva))
	{
		this->iva = iva;
		retorno = 0;
	}
	return retorno;
}


int compra_setTotal(Compra* this,float precio)
{
	int retorno = -1;
	if(this != NULL && isValidPrecio(precio))
	{
		this->precioTotal = precio;
		retorno = 0;
	}
	return retorno;
}


/**
*\brief Es el getter del campo nombreCliente del elemento
*\param this Es el elemento del cual se obtiene el dato nombreCliente
*\return Retorna el dato del elemento existe y si el dato es valido sino retorna COMPLETAR
*/
char* compra_getNombreCliente(Compra* this)
{
	char* retorno = malloc(sizeof(char));
	if(this != NULL)
	{
		retorno = this->nombreCliente;
	}
	return retorno;
}

/**
*\brief Es el getter del campo id del elemento
*\param this Es el elemento del cual se obtiene el dato id
*\return Retorna el dato del elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_getId(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}
	return retorno;
}

/**
*\brief Es el getter del campo precio del elemento
*\param this Es el elemento del cual se obtiene el dato precio
*\return Retorna el dato del elemento existe y si el dato es valido sino retorna COMPLETAR
*/
float compra_getPrecio(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->precio;
	}
	return retorno;
}

/**
*\brief Es el getter del campo unidades del elemento
*\param this Es el elemento del cual se obtiene el dato unidades
*\return Retorna el dato del elemento existe y si el dato es valido sino retorna COMPLETAR
*/
int compra_getUnidades(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->unidades;
	}
	return retorno;
}

/**
*\brief Es el getter del campo iva del elemento
*\param this Es el elemento del cual se obtiene el dato iva
*\return Retorna el dato del elemento existe y si el dato es valido sino retorna COMPLETAR
*/
float compra_getIva(Compra* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->iva;
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato nombreCliente ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param nombreCliente Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByNombreCliente(LinkedList* pArray,char* nombreCliente)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidNombreCliente(nombreCliente))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(strcmp(nombreCliente,compra_getNombreCliente(aux))==0)
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato id ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param id Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getById(LinkedList* pArray,int id)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidId(id))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(id == compra_getId(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato precio ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param precio Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByPrecio(LinkedList* pArray,float precio)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidPrecio(precio))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(precio == compra_getPrecio(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato unidades ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param unidades Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByUnidades(LinkedList* pArray,int unidades)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidUnidades(unidades))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(unidades == compra_getUnidades(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Retorna un elemento segun el dato iva ingresado
*\param pArray Es el puntero a LinkedList recibido para buscar elemento
*\param iva Es el dato que se recibe para encontrar el elemento
*\return Retorna el elemento si lo encuentra sino retorna NULL
*/
Compra* compra_getByIva(LinkedList* pArray,float iva)
{
	int i;
	Compra* aux;
	Compra* retorno=NULL;

	if(pArray != NULL && isValidIva(iva))
	{
		for(i=0;i<ll_len(pArray);i++)
		{
			aux = ll_get(pArray,i);
			if(iva == compra_getIva(aux))
			{
				retorno = aux;
				break;
			}
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo nombreCliente
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByNombreCliente(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		retorno = strcmp(compra_getNombreCliente(thisA),compra_getNombreCliente(thisB));
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo id
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareById(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getId(thisA) > compra_getId(thisB))
		{
				retorno = 1;
		}
		else if(compra_getId(thisA) < compra_getId(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo precio
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByPrecio(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getPrecio(thisA) > compra_getPrecio(thisB))
		{
				retorno = 1;
		}
		else if(compra_getPrecio(thisA) < compra_getPrecio(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo unidades
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByUnidades(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getUnidades(thisA) > compra_getUnidades(thisB))
		{
				retorno = 1;
		}
		else if(compra_getUnidades(thisA) < compra_getUnidades(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Compara dos elementos por su campo iva
*\param thisA Es el puntero al primer elemento a comparar
*\param thisB Es el puntero al segundo elemento a comparar
*\return Retorna 0 si ambos campos son iguales
		Retorna 1 si el campo del primer elemento es mayor al segundo
		Retorna -1 si el campo del segundo elemento es mayor al primero
*/
int compra_compareByIva(void* thisA ,void* thisB)
{
	int retorno = 0;

	if(thisA != NULL && thisB != NULL)
	{
		if(compra_getIva(thisA) > compra_getIva(thisB))
		{
				retorno = 1;
		}
		else if(compra_getIva(thisA) < compra_getIva(thisB))
		{
			retorno = -1;
		}
	}
	return retorno;
}

/**
*\brief Muestra los datos de un elemento
*\param this Es el elemento que recibe para mostrar
*\return Retorna 0 si el elemento existe sino retorna -1
*/
int compra_show(Compra* this)
{
    int retorno = -1;

	if(this != NULL)
	{
		printf("\nNombreCliente -- %s",compra_getNombreCliente(this));
		printf("\nId -- %d",compra_getId(this));
		printf("\nPrecio -- %f",compra_getPrecio(this));
		printf("\nUnidades -- %d",compra_getUnidades(this));
		printf("\nIva -- %f",compra_getIva(this));
		retorno = 0;
	}
	return retorno;
}

int compra_calculoPrecio(void* this)
{
    int retorno = -1;
    int unidades;
    float precio;
    float iva;
    float precioTotal = 0;

    if(this != NULL)
    {
        unidades = compra_getUnidades(this);
        precio = compra_getPrecio(this);
        iva = compra_getIva(this);
        precioTotal = unidades * precio;
        precioTotal += (precioTotal * iva) / 100;
        compra_setTotal(this,precioTotal);
        retorno = 0;
    }
    return retorno;
}



int compra_findById(void* this,int id)
{
    int retorno = -1;

	if(this != NULL && isValidId(id))
	{
        if(id == compra_getId(this))
        {
            retorno = 0;
        }
	}
	return retorno;
}
