/*
 * ejercicio2.c
 *
 *  Created on: 1 nov. 2020
 *      Author: LENOVO
 */

#include "ejercicio2.h"

string ejercicio2(int limit){
	char mem[550];
	string res = string_empty();
	int i = 2;
	while (i <= limit){
		int p = i*i;
		char * p2 = int_tostring(&p, mem);
		string_add_pchar(&res, p2);
		string_add_pchar(&res, "\n");
		i = siguiente_primo(i);
	}return res;
}



