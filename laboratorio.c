/*********************************************************************************************
* FILE: laboratorio.c
*
* DESCRIPTION: Simulate the transition function of an DFA
*
* AUTHOR: Brady Cardenas - David Sanhueza Andréus
*
* UNIVERSIDAD DE SANTIAGO DE CHILE
*
*********************************************************************************************/



/*************************************************************************
*								USAGE
* To compile: gcc laboratorio.c -o laboratorio
* To ejecute: ./laboratorio [X]
* where: 
*			X = Number of States of DFA
* Example: DFA of 10 States
* ./laboratorio 10
*************************************************************************/



#include <stdio.h>
#include <stdlib.h>


// Función Que imprime los datos en formato latex
int imprimir(int **matriz, int *entrada, int largo){
	int cont = 0, i, j;
	int estadoactual = matriz[1][0]; // Se posiciona en el Estado Inicial (1)
	printf("\n$");
	for(i = 0; i < largo; i++){
		for(j = 0; j < largo; j++){
			// Posiciona el Estado actual junto al String de Entrada
			if(cont == j){
				printf("q_%d", estadoactual);				
			}
			printf("%d", entrada[j]);
		}
		cont++;
		printf(" \\vdash " );
		// Cambia de Estados dependiendo del String de Entrada (0,1)
		if(entrada[i] == 0){	
			estadoactual = matriz[estadoactual][1];
		}
		else{
			estadoactual = matriz[estadoactual][2];
		}
	}
	return estadoactual;
}



int main(int argc, char **argv){
	int j; // for
	int i; // for
	int k; // for
	int **matriz; // Matriz de la función de transición
	int n; // número de estados
	int numeroestadosfinales; // Número de estados finales, se genera random
	int *estadosfinales; // Arreglo que contiene todos los estados finales
	int numeroentrada; // Largo del string
	int *entrada; // String de entrada
	int estado; // Guarda el Resultado de la Función Para Imprimir
	int aux; // Guardamos el largo 
	n = atoi(argv[1]); // Ingreos del número de Estados desde la Terminal

	
	numeroestadosfinales = rand() % (n) + 1; // Se genera un número aleatorio y se guarda, que es el número de estados finales entre 1 y n
	estadosfinales=(int*) malloc(numeroestadosfinales*sizeof(int)); // Se genera el arreglo para guardar los estados finales
	i = 0;
	while(i < numeroestadosfinales){ 
		 aux = rand() % (n) + 1; // se guardan los estados finales
		 k=0;
		for(j = 0; j < i; j++){
			if(aux == estadosfinales[j]){
				k++;
			}
		}
		if(k == 0){
			estadosfinales[i] = aux;
			i++;
		}else{
			numeroestadosfinales--;	
		}
		
	}




	matriz=(int**) malloc((n+1)*sizeof(int*)); // se genera el arreglo [columna] de la matriz
	for(i = 0; i < n+1; i++){
		matriz[i]=(int*) malloc(3*sizeof(int));  // genera el arreglo [fila] de la matriz
	}

	for(i = 1; i < n+1; i++){
		for(k = 1; k < 3; k++){
			matriz[i][k] = rand() % (n) + 1; // Se ingresan los datos aleatorio a la matriz
		}
	}

	for(i = 0; i < n+1; i++){
		matriz[i][0] = i; // llena los estados 
	}

	printf("\n");
	printf(" δ |  0 |  1 \n");
	for(i = 1; i < n+1; i++){
		for(k = 0; k < 3; k++){
			printf(" %d  ", matriz[i][k]); // muestra toda la matriz
		}
		printf("\n");
	}

	printf("\nNúmero de Estados Finales : %d \n", numeroestadosfinales);
	printf("Estados Finales : ");
	for(i = 0; i < numeroestadosfinales; i++){ 
		printf("q_%d ",estadosfinales[i] ); // se muestran los estados finales
	}

	numeroentrada = rand() % (11) + 1; // Se genera un número aleatorio y se guarda, que es el largo del string de entrada



	printf("\n\nCantidad de Números del String de Entrada : ");
	printf("%d\n", numeroentrada );
	entrada = (int*) malloc(numeroentrada*(sizeof(int))); // Se genera el arreglo del string de entrada

	for(i = 0; i < numeroentrada; i++){
		entrada[i] =rand() % 2; // Se ingresa los strings de entrada
	}

	printf("String de Entrada : ");
	for (i = 0; i < numeroentrada; ++i){
		printf("%d", entrada[i]); // muestra el string de entrada
	}

	printf("\n\nFormato Latex\n");
	estado = imprimir(matriz, entrada, numeroentrada); // Se Guarda el resultado de la Función imprimir
	printf("$\n");
	printf("\nÚltimo Estado: q_%d\n", estado);	
	k = 0;
	// Realiza la Comparación entre el último elemento de String de entrada y lo compara con los Estados Finales
	for(i = 0; i < numeroestadosfinales; i++){
		if(estado == estadosfinales[i]){
			k = 1;
		}
	}
	if(k == 1){
		printf("\nSTRING ACEPTADO\n");
	}
	else{
		printf("\nSTRING NO ACEPTADO\n");
	}
	return 0;
}