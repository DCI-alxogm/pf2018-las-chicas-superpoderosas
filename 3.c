#include<stdio.h>
#include<stdlib.h>

int main(){
	float xi,yi,zi,h;
	int i,n=0;
	float *x= (float*)malloc(n*sizeof(float));
	float *y= (float*)malloc(n*sizeof(float));
	float *z= (float*)malloc(n*sizeof(float));
	FILE *in;

	printf("Introduce el valor del tamaño de la matriz: \n");
	scanf("%i",&n);
	printf("Escribe el valor de h: \n");
	scanf("%f",&h);
	printf("Introduce el valor de los valores de las masas en x,y,z: \n");
	scanf("%f",&x[0]);
	y[0]=x[0];
	z[0]=x[0];

	in=fopen("malla3.txt","w");

	for(i=0;i<n;i++){
		x[i]=x[0];
		y[i]=x[i];
		z[i]=x[i];
		fprintf(in,"%d \t x: %f, \t y: %f, \t  z: %f, \n",i,x[i],y[i],z[i]);
	}
		fclose(in);
return 0;
}
