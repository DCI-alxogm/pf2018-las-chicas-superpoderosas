#include<stdio.h>
#include<stdlib.h>


int main(){ //malla de masas y posiciones iniciales

	float h,m,G;
	int i,x0,y0,z0,n=0;
	int *x= (int*)malloc(n*sizeof(float));
	int *y= (int*)malloc(n*sizeof(float));
	int *z= (int*)malloc(n*sizeof(float));
	

	FILE *in;
	FILE *datos;


	datos=fopen("datosprueba.txt","r");
	fscanf("%i %f %i %i %i %f",&n,&m,&x0,&y0,&z0,&h,&G);
	fclose(datos);
	
	x[0]=x0;
	y[0]=y0;
	z[0]=z0;
	
	in=fopen("malla3.txt","w");
        fclose(in);

	for(i=0;i<n;i++){
		x[i]=x[0];
		y[i]=y[0];
		z[i]=z[0];
		fprintf(in,"%d \t x: %i, \t y: %i, \t  z: %i, \t \n",i,x[i],y[i],z[i]);
	}
		
	free (x);
	free (y);
	free (z);
return 0;
}



