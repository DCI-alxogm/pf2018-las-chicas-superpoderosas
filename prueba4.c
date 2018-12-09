#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
//Se introducen las variables
float G=43000,h,masap,masasol;
int n=10000,i,j;
double x0,y0,z0,vx0,vy0,vz0;
double x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fx[n],r;
FILE *datos;
FILE *resultados;


datos=fopen("iniciales.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h);


printf("Prueba datos iniciales  %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\n",x0,y0,z0,vx0,vy0,vz0,h);
fclose(datos);
//Se dan los datos iniciales 
x[0]=x0;
y[0]=y0;
z[0]=z0;
vx[0]=vx0;
vy[0]=vy0;
vz[0]=vz0;



resultados=fopen("resultados1.txt","w");
//Se introducen las ecuaciones con las variables indicadas.
for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			 x[i+h]=x(1)+h*(vx[i]*1+(1/2)*fx[i]*(h*h);
			y[i+h]=y(1)+h*(vy[i]*1+(1/2)*fy[i]*(h*h);
			z[i+h]=z(1)+h*(vz[i]*1+(1/2)*fz[i]*(h*h);
			r=sqrt(pow(x[i-1],2.0)+pow(y[i-1],2.0)+pow(z[i-1],2.0));

			fx[i]=-(G/(pow(r,3.0))*r;
			fy[i]=-(G/(pow(r,3.0))*r;
			fz[i]=-(G/(pow(r,3.0))*r;

			vx[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;
			vy[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;
			vz[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;	
//Se imprimen los resultados en otro archivo de texto.
    fprintf(resultados," %lf\t %lf\t %lf\n",x[i],y[i],z[i]);
  
}


fclose(resultados);
}

    	
//Se cierra el programa. 
return 0;
}

