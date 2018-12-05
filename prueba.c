#include<stdio.h>
#include<stdlib.h>


int main(){
   


	float e,w=1;
	int N,n,i,j;
	float left,right,up,down,t;


	FILE *first;
	FILE *results;
	FILE *in;	


	first=fopen("datosprueba.txt","r");
	fscanf(first,"%f %f %f %f %f %i",&left,&right,&up,&down,&e,&n);

	fclose(first);
//T es la matriz

	double **T = (double**)malloc(n*sizeof(float*));

	for(i=0;i<=n;i++){
	   T[i]=(double*)malloc(n*sizeof(float));
	}	

	in=fopen("resultadosprueba.txt","w");
	
	for(i=0;i<n;i++){
			for(j=0;j<n;j++){

				if(i==0){
				T[i][j]=left;
				//printf("%i %i",i,j);
				}else if(i==(n-1)){
				T[i][j]=right;
				//printf("%i %i",i,j);
				}else if(j==0){
				T[i][j]=up;
				//printf("%i %i",i,j);
				}else if(j==(n-1)){
				T[i][j]=down;
				//printf("%i %i",i,j);
				}else{
				T[i][j]=((T[i+1][j])+(T[i-1][j])+(T[i][j+1])+(T[i][j-1]))/4;

			}fprintf(in,"%3.3lf \t",T[i][j]);
			}
		fprintf(in,"\n");
		}
fclose(in);
N=n*n;

return 0;
}

