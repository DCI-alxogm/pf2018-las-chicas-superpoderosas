#include<stdio.h>
#include<stdlib.h>


int main(){ 
//Malla para las masas iniciales y posiciones

        //Variables
	float h,m,G;
	int i,x0,y0,z0,n=0;
	int *x = (int*)malloc(n*sizeof(float));
        
	int *y = (int*)malloc(n*sizeof(float));
        
	int *z = (int*)malloc(n*sizeof(float));
        
        
	FILE *in;
	FILE *datos;

        //abro mi archivo donde se encuentran los valores de las variables y lo escaneo
	datos=fopen("datos.txt","r");
        fscanf(datos,"%i %f %i %i %i %f %f",&n,&m,&x0,&y0,&z0,&h,&G);
        fclose(datos);
        
	
	
        //abro un archivo de tipo write en el cual se encontraran los resultados de la malla
	in=fopen("malla.txt","w");
        
        x[0]=x0;
	y[0]=y0;
        z[0]=z0;

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



