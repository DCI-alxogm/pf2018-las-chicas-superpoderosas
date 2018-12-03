#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	float **T;
	int i,j,k,x,n=0;
	float a=1,s=1,d=1,w=1;	

	FILE *fp;


	printf("Define el tamaño de la matriz\n");
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
