#include<stdio.h>
#include<stdlib.h>

int main(){

	float xi,xf,yi,yf,zi,zf,h;
	int i,num=0;
	float *x = (float*)malloc(num*sizeof(float));
	float *y = (float*)malloc(num*sizeof(float));
	float *z = (float*)malloc(num*sizeof(float));
	FILE *fp;

	if(argc==4){
		nombre_archivo=argv[1];
		num=atoi(argv[2]);
		h=atof(argv[3]);
		
		printf("El nombre del archivo a abrir es: %s\n",nombre_archivo);
		printf("Escribe los valores de xi,yi,zi: \n");
		scanf("%f",&x[0]);
		//printf("Escribe los valores de xf,yf,zf: \n");
		//scanf("%f",&xf[num]);
		y[0]=x[0];
		z[0]=x[0];
		printf("Abrir");
		fp=fopen(nombre_archivo,"w+");
		
		//Aqui se pondria todo lo demas que se quiere hacer y/o escribir un archivo..
	for(i=1;i<num;i++){
		x[i]=(float)i;
		y[i]=x[i];
		z[i]=x[i];
		fprintf(fp,"%d \t x: %f, \t y: %f, \t  z: %f, \n",i,x[i],y[i],z[i]);
	}
		fclose(fp);
	}
	else if(argc>4){
	printf("Diste mas argumentos de los necesarios \n");
	}
	else {
	printf("Se requieren 3 argumentos: nombre_archivo, num, h \n");
	}
	return 0;
	}

