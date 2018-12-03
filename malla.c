#include<stdio.h>
#include<stdlib.h>

int main(){
	
	float xi,xf,yi,yf,zi,zf,h;
	int i,num=0;
	float *x = (float*)malloc(num*sizeof(float));
	float *y = (float*)malloc(num*sizeof(float));
	float *z = (float*)malloc(num*sizeof(float));
	FILE *fp;

		
		printf("Escribe los valores de xi,yi,zi: \n");
		scanf("%f",&x[0]);
		y[0]=x[0];
		z[0]=x[0];
		fp=fopen("datos.txt","w");
		
		//Aqui se pondria todo lo demas que se quiere hacer y/o escribir un archivo..
	for(i=1;i<num;i++){
		x[i]=(float)i;
		y[i]=x[i];
		z[i]=x[i];
		fprintf(fp,"%d \t x: %f, \t y: %f, \t  z: %f, \n",i,x[i],y[i],z[i]);
	}
		fclose(fp);

	
	return 0;
	}

