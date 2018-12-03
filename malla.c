#include<stdio.h>
#include<stdlib.h>

<<<<<<< HEAD
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

=======
int main()
{
	float **T;
	int i,j,k,x,n=0;
	float a=1,s=1,d=1,w=1;	
	FILE *fp;
	printf("¿De qué tamaño quieres la matriz?\n");
	scanf("%i",&x);
	n=x*x;
	T=(float**)malloc(x*sizeof(int*));
	fp=fopen("data.txt","w");
	for(i=0;i<=n;i++){                    
	T[i]=(float*)malloc(x*sizeof(int));}
	for(i=0;i<x;i++)
	{           
		for(j=0;j<x;j++){ 
				if(i==0){
				T[i][j]=a;
				}else if(i==(x-1)){
				T[i][j]=d;
				}else if(j==0){
				T[i][j]=w;
				}else if(j==(x-1)){
				T[i][j]=s;
				}else{
	T[i][j]=((T[i+1][j]+T[i-1][j]+T[i][j+1]+T[i][j-1])/4);
	fprintf(fp,"%2.2f  \t",T[i][j]); 
	}
	}
	fprintf(fp,"\n"); 
}
fclose(fp);	
free(T);
return 0;
}
>>>>>>> 2bf9d6c8d22df06831b8c6fd79d446f142f3ec4f
