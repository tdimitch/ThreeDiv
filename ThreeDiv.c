#include <stdio.h>
#include <stdlib.h>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))



int minimo(int A, int B, int C) {
	return  MIN(MIN(A,B),C);
}

int evaluar(int* coeficientes, int* variables) {
	int resultado = 0;
	int i;
	for (i=0; i < 3; i++) {
		resultado += coeficientes[i]*variables[i];
	}
	return resultado + coeficientes[3];
}

int comparacion(const void* elemento1, const void* elemento2) {
	int* elem1 = (int*) elemento1;
	int* elem2 = (int*) elemento2;

	return (elem1[3] < elem2[3]) ? 1:-1;
}

int main() {
	int polinomio1[4] = {352,528,1056,880};
	int polinomio2[4] = {308,462,1155,1001};
	int polinomio3[4] = {336,560,1008,896};
	int MonomioGen[90][4];
	int counter = 0;
	int a,b,c,d;
	d=1;
	//printf("%d\n",minimo(1,2,3));

//a<9,b<5,c<2
for (a=0; a <9; a++) {
	for (b=0; b < 5; b++) {
		for (c=0; c <2; c++) {
				MonomioGen[counter][0] = a;
				MonomioGen[counter][1] = b;
				MonomioGen[counter][2] = c;
				MonomioGen[counter][3] = minimo(evaluar(polinomio1, MonomioGen[counter]),evaluar(polinomio2,MonomioGen[counter]),evaluar(polinomio3,MonomioGen[counter]));
				counter++;	
		}
	}
}

	
	qsort(MonomioGen,90,sizeof(int)*4,comparacion);

	for (counter=0; counter < 90; counter++) 
	{
	    if(MonomioGen[counter][3] < 3696)
	    {
		printf("The monomial x^%d y^%d z^%d generates the jumping number %d /3696\n", MonomioGen[counter][0],MonomioGen[counter][1],MonomioGen[counter][2],MonomioGen[counter][3]);
	    }
	}

	return 0;
}