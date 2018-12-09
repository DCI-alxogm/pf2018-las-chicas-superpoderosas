#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
//Se introducen las variables
float G=43000,h,masap,masasol;
int n=10000,i,j;
double x0,y0,z0,vx0,vy0,vz0,fx,fy,fz;
double x[n],y[n],z[n],vx[n],vy[n],vz[n],fx[n],fy[n],fx[n],r;
FILE *datos;
FILE *resultados;


//Se abre un if para poder elegir cual planeta se quiere elegir


datos=fopen("iniciales.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h;


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
{
		for(j=1;j<=n;j++){
			 x[i]=x(1.0001)+h*(vx[i]*1+(1/2)*fx[i]*(h*h);
			y[i]=y(1.0001)+h*(vy[i]*1+(1/2)*fy[i]*(h*h);
			z[i]=z(1.0001)+h*(vz[i]*1+(1/2)*fz[i]*(h*h);
			r=sqrt(pow(x[i-1],2.0)+pow(y[i-1],2.0)+pow(z[i-1],2.0));

			fx[i]=-(G/(pow(r,3.0))*r;

			vx[i]=vx[i-1]-h*((G*1.0*x[i-1])/pow(r,3.0));
			vy[i]=vy[i-1]-h*((G*1.0*y[i-1])/pow(r,3.0));
			vz[i]=vz[i-1]-h*((G*1.0*z[i-1])/pow(r,3.0));
		}
//Se imprimen los resultados en otro archivo de texto.
    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\n",x[i],y[i],z[i],vx[i],vy[i],vz[i],h);
   // printf("%i\n",i);
}


fclose(resultados);
}

    	
//Se cierra el programa. 
return 0;
}

