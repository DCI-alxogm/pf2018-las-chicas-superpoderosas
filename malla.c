#include<stdio.h>
#include<stdlib.h>
void malla(){
	float h,m,G;
	int i,xi,yi,zi,n=0;
	int *x= (int*)malloc(n*sizeof(float));
	int *y= (int*)malloc(n*sizeof(float));
	int *z= (int*)malloc(n*sizeof(float));
	

	FILE *in;
	FILE *datos


	datos=fopen("datosprueba.txt","r");
	fscanf("%i %f %i %i %i %f",&n,&m,&x[0],&y[0],&z[0],&h,&G);
	
	fclose(datos);

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


