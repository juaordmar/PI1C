/*
 * tests.c
 *
 *  Created on: 1 nov. 2020
 *      Author: LENOVO
 */

#include "tests.h"

int main(){
	printf("Test 1:\n----------\n");
	test1("ficheros/PI1Ej1DatosEntrada.txt");
	printf("Test 2:\n----------\n");
	test2("ficheros/PI1Ej2DatosEntrada.txt");
	printf("\nTest 3:\n----------\n");
	test3("ficheros/PI1Ej3DatosEntrada.txt");
}

void test1(char * file){ //pchar
	char mem[500]; //mem es un puntero o posicion de memoria
	list ls = file_to_list_of_list(file);
	list res = ejercicio1(&ls);
	list_tostring(&res, mem);
	printf("%s", mem);
	printf("\n\n");
}

void test2(char * file){
	char mem[500];
	iterator f = file_iterable_pchar(file); //creo iterador sobre el fichero
	while(iterable_has_next(&f)){ //recorro el fichero
		char * linea = (char *)iterable_next(&f);
		strtok(linea, " ");
		char * limit = strtok(NULL, " "); //se pasa NULL mientras quieras seguir dividiendo el char
		int n = int_parse_s(limit);
		printf("Límite %i:\n", n);
		string j = ejercicio2(n);
		char * res = string_tostring(&j, mem);
		iterator it = split_iterable_pchar(res, ",");
		while(iterable_has_next(&it)){
			char * pc = (char *)iterable_next(&it);
			printf("%s", pc);
		}printf("\n========================\n");
	}
}

void test3(char * file){
	char mem[500];
	list puntos = list_empty(punto_type);
	iterator it = file_iterable_pchar(file);
	while (iterable_has_next(&it)){
		char * linea = (char *)iterable_next(&it);
		punto p = punto_parse_s(linea);
		list_add(&puntos, &p);
	}hash_table res = ejercicio3(puntos);
	printf("%s",hash_table_tostring(&res, mem));
}

