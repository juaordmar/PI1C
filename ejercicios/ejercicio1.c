/*
 * main.c
 *
 *  Created on: 1 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio1.h"

list ejercicio1(list * listaListas){
	list r = list_empty(int_type);
	int i = 0;
	while(i<list_size(listaListas)){
		list * aux = ((list*)list_get(listaListas, i)); //convertimos a puntero de tipo lista que es lo que pide list_get
		iterator ite = list_iterable(aux);
		while(iterable_has_next(&ite)){
			int n = *((int*)iterable_next(&ite));
			if(es_primo(n)){
				list_add(&r, &n);
			}
		}i++;
	}return r;
}

