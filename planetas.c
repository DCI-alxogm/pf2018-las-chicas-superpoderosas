#include<stdio.h>
#include<math.h>

int main(){}

//declaracion de las variables
float G=43000,h;
int n=10000,i,o;
double a,b,c,d,e,f,m[n];
double x[n],y[n],z[n],vx[n],vy[n],vz[n],r;
FILE *inicial;
FILE *resultados;

//presentacion del programa
printf("Este programa calcula la orbita de los planetas en una simulación\n");

	inicial=fopen("iniciales.txt","r");
	fscanf(inicial,"%lf %lf %lf %lf %lf %lf %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h);
	fclose(inicial);
	

	x[0]=x0;
	y[0]=y0;
	z[0]=z0;
	vx[0]=vx0;
	vy[0]=vy0;
	vz[0]=vz0;

	
printf("datos son: %lf",m[n]);
