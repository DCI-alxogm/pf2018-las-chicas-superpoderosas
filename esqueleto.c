#include<stdio.h>
#include<math.h>
#include<stdlib.h>
	
int main()
{
//declaracion de variables	
float G=43000,h;
int n=7,i,j;
double a,b,c,d,e,f,J[n],M[n],V[n],T[n],Ma[n],S[n],U[n],N[n],P[n];
FILE *inicial;
FILE *ju;

//presentacion del programa
printf("Hola, este programa muestra los movimientos de los planetas \n");

	inicial=fopen("jupiter.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	J[0]=a;
	J[1]=b;
	J[2]=c;
	J[3]=d;
	J[4]=e;
	J[5]=f;
	J[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",J[i]);
	}
	
	inicial=fopen("mercurio.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	M[0]=a;
	M[1]=b;
	M[2]=c;
	M[3]=d;
	M[4]=e;
	M[5]=f;
	M[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",M[i]);
	}
	inicial=fopen("venus.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	V[0]=a;
	V[1]=b;
	V[2]=c;
	V[3]=d;
	V[4]=e;
	V[5]=f;
	V[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",V[i]);
	}

	inicial=fopen("tierra.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	T[0]=a;
	T[1]=b;
	T[2]=c;
	T[3]=d;
	T[4]=e;
	T[5]=f;
	T[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",T[i]);
	}

	inicial=fopen("marte.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	Ma[0]=a;
	Ma[1]=b;
	Ma[2]=c;
	Ma[3]=d;
	Ma[4]=e;
	Ma[5]=f;
	Ma[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",Ma[i]);
	}

	inicial=fopen("saturno.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	S[0]=a;
	S[1]=b;
	S[2]=c;
	S[3]=d;
	S[4]=e;
	S[5]=f;
	S[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",S[i]);
	}

	inicial=fopen("urano.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	U[0]=a;
	U[1]=b;
	U[2]=c;
	U[3]=d;
	U[4]=e;
	U[5]=f;
	U[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",U[i]);
	}

	inicial=fopen("neptuno.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	N[0]=a;
	N[1]=b;
	N[2]=c;
	N[3]=d;
	N[4]=e;
	N[5]=f;
	N[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",N[i]);
	}

	inicial=fopen("pluton.txt","r");
	fscanf(inicial,"%lf \t %lf \t %lf \t %lf \t %lf \t %lf \t %f",&a,&b,&c,&d,&e,&f,&h);
	fclose(inicial);
	P[0]=a;
	P[1]=b;
	P[2]=c;
	P[3]=d;
	P[4]=e;
	P[5]=f;
	P[6]=h;
	for(i=0;i<7;i++)
	{
	printf("%lf \t",P[i]);
	}


return 0;// termina el programa
}
