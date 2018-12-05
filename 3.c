#include<stdio.h>
#include<stdlib.h>

int main(){
	float h,m;
	int i,xi,yi,zi,n=0;
	int *x= (int*)malloc(n*sizeof(float));
	int *y= (int*)malloc(n*sizeof(float));
	int *z= (int*)malloc(n*sizeof(float));
	FILE *in;

	printf("Introduce el valor del tamaño de la matriz: \n");
	scanf("%i",&n);
	printf("Escribe el valor de h: \n");
	scanf("%f",&h);
	printf("Introduce el valor de los valores de las masas: \n");
	scanf("%f",&m);
	printf("Introduce la posicion en x,y,z \n");
	scanf("%i %i %i",&x[0],&y[0],&z[0]);
	
	in=fopen("malla3.txt","w");

	for(i=0;i<n;i++){
		x[i]=x[0];
		y[i]=y[0];
		z[i]=z[0];
		fprintf(in,"%d \t x: %i, \t y: %i, \t  z: %i, \t \n",i,x[i],y[i],z[i]);
	}
		fclose(in);
	free (x);
	free (y);
	free (z);
return 0;
}
