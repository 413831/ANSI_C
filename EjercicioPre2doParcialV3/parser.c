#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Compra.h"
#include "utn.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile Es el puntero a archivo para leer los datos
 * \param pLinkedListCompra Es la LinkedList donde se guardaran los datos
 * \return Retorna 0 si existe el archivo sino retorna -1
 *
 */
int parser_CompraFromText(FILE* pFile , LinkedList* pLinkedListCompra)
{
    int retorno = -1;
    char* nombreStr;
    char* idStr;
    char* precioStr;
    char* unidadesStr;
    char* ivaStr;
    char bufferText[BUFFER];
    Compra* pCompra;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            fgets(bufferText,sizeof(bufferText),pFile);
            if(bufferText != NULL && strlen(bufferText) > 8)
            {
                nombreStr = strtok(bufferText,",");
                idStr = strtok(NULL,",");
                precioStr = strtok(NULL,",");
                unidadesStr = strtok(NULL,",");
                ivaStr = strtok(NULL,"\n");

                printf("\nNOMBRE -- %s",nombreStr);
                printf("\nID -- %s",idStr);
                printf("\nPRECIO -- %s",precioStr);

                pCompra = compra_constructor(nombreStr,atoi(idStr),atof(precioStr),atoi(unidadesStr),atof(ivaStr));
                if(pCompra != NULL)
                {
                    ll_add(pLinkedListCompra,pCompra);//Se agrega ELEMENTO a LINKED LIST
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}



/** \brief Parsea los datos del linked list al archivo data.csv (modo texto).
 *
 * \param pFile Es el puntero a archivo para escribir los datos
 * \param pLinkedListCompra Es la LinkedList de donde se toman los datos
 * \return Retorna 0 si existe el archivo y el LinkedList sino retorna -1
 *
 */
int parser_SaveToText(FILE* pFile , LinkedList* pLinkedListCompra)
{
    int retorno = -1;
    char* nombre;
    int id;
    float precio;
    int unidades;
    float iva;
    float precioTotal;
    Compra* this;
    int len;
    int index;

    if(pFile != NULL && pLinkedListCompra != NULL)
    {
        len = ll_len(pLinkedListCompra);

        for(index=0;index<len;index++)//Recorro todo el array hasta el LEN
        {
            this = ll_get(pLinkedListCompra,index);//Obtengo el elemento del array en posicion index

            nombre = compra_getNombreCliente(this);
            id = compra_getId(this);
            precio = compra_getPrecio(this);
            unidades = compra_getUnidades(this);
            iva = compra_getIva(this);
            precioTotal = this->precioTotal;

            fprintf(pFile,"%s,%d,%.2f,%d,%.2f,%.2f\n",nombre,id,precio,unidades,iva,precioTotal);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Parsea los datos del linked list al archivo data.bin (modo binario).
 *
 * \param pFile Es el puntero a archivo para escribir los datos
 * \param pLinkedListCompra Es la LinkedList de donde se toman los datos
 * \return Retorna 0 si existe el archivo y el LinkedList sino retorna -1
 *
 */
int parser_SaveToBinary(FILE* pFile , LinkedList* pLinkedListCompra)
{
    int retorno = -1;
    int i = 0;
    int len;
    Compra* auxCompra;

    if(pFile != NULL && pLinkedListCompra != NULL)
    {
        len = ll_len(pLinkedListCompra);
        while(i != len)
        {
            auxCompra = ll_get(pLinkedListCompra,i);
            if(auxCompra != NULL)
            {
                fwrite(auxCompra,sizeof(Compra),1,pFile);
            }
            retorno = 0;
            i++;
        }
    }
    return retorno;
}
