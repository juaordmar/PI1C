/*
 * ejercicio3.c
 *
 *  Created on: 1 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio3.h"

hash_table ejercicio3(list puntos){
	int i = 0;
	int tam = list_size(&puntos);
	hash_table res = hash_table_empty(int_type, double_type);
	while(i<tam){
		punto p = *((punto*)list_get(&puntos, i));
		Cuadrante c = punto_cuadrante(&p);
		double x = p.x;
		if(hash_table_contains(&res, &c)){
			double value = *((double *)hash_table_get(&res, &c));
			double valuex = value + x;
			hash_table_put(&res, &c, &valuex);
			//hash_table_put(&res, &c, hash_table_get(&res, &c)+x);
		}else{
			hash_table_put(&res, &c, &x);
		}i = i + 1;
	}return res;
}





