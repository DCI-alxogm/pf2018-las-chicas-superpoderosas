
/*Funcion void del proyecto final de programación*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//cambiar a void
int main(){
	int f1=1000,f2=f1,f3=f1;
	int a[i],b[i],c[i];
	int x,y,z;
	float masas,d,e=1,fuerza,rho;//d es la distancia entre dos puntos y es un puntero ya que es un valor diferente para cada partícula
	//float G=4*(pow(pi,2));
        FILE *datos;
        FILE *parametros;
	FILE *malla;


//formula de fuerza, formula de distancia entre dos puntos, formula de Lennard-Jones

//e, rho entran desde el archivo de parametros

	malla=fopen("malla3.txt","r");
	for(i=0;i>5;i++){
	fscanf("%i\t %i\t %i",&x,&y,&z);
	a[i]=x;
	b[i]=y;
	c[i]=z;
	}
printf(" %i \t %i \t %i \t",a,b,c);

/*for(i=0;i=n;i++)//Se hace hasta n por que n definie el numero de datos dentro de la malla 
	{
	 for(j=0,j=n;j++){
		for(k=0;k=n;k++){
		d=sqrt((pow(T[i+1]-T[i],2))+(pow(T[j+1]-T[j],2))+(pow(T[k+1]-T[k],2)))
			}
		}
	}

for(i=0;i=n;i++)
{for(j=0;j=n;j++){
for(k=0;k=n;k++){
T[i][j][k]=4*e((12*(pow(rho,12))/(pow(d[i][j][k],13))-((6*(pow(rho,6)/(
pow(d[i][j][k],7))
}}}

for(i=0;i=n;i++)
{ for(j=0,j=n;j++){
for(k=0;k=n;k++){
vx[i]=T[i]*d[i]
vx[j]=T[j]*d[j]
vx[k]=T[k]*d[k]
}}}

for(i=0;i=n;i++)
{ for(j=0,j=n;j++){
for(k=0;k=n;k++){
vx[i]=T[i]*d[i]
vx[j]=T[j]*d[j]
vx[k]=T[k]*d[k]
}}}

for(i=0;i=n;i++)
{ for(j=0,j=n;j++){
for(k=0;k=n;k++){
x[i]=vx[i]*d[i]
x[j]=vx[j]*d[j]
x[k]=vx[k]*d[k]
}}}*/

return 0;
}
