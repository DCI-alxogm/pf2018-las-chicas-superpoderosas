#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
//Se introducen las variables
float G=43000,h,masap,masasol;
int n=10000,i,j;
double x0,y0,z0,vx0,vy0,vz0;
double mx[n],my[n],mz[n],mvx[n],mvy[n],mvz[n],mfx[n],mfy[n],mfx[n],r1;
FILE *datos;
FILE *resultados;


datos=fopen("mercurio.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&mx0,&my0,&mz0,&mvx0,&mvy0,&mvz0,&h);
fclose(datos);

datos=fopen("venus.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&vx0,&vy0,&vz0,&vvx0,&vvy0,&vvz0,&h);
fclose(datos);

datos=fopen("tierra.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&tx0,&ty0,&tz0,&tvx0,&tvy0,&tvz0,&h);
fclose(datos);

datos=fopen("marte.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&mmx0,&mmy0,&mmz0,&mmvx0,&mmvy0,&mmvz0,&h);
fclose(datos);

datos=fopen("jupiter.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&jx0,&jy0,&jz0,&jvx0,&jvy0,&jvz0,&h);
fclose(datos);

datos=fopen("saturno.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&sx0,&sy0,&sz0,&svx0,&svy0,&svz0,&h);
fclose(datos);

datos=fopen("urano.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&ux0,&uy0,&uz0,&uvx0,&uvy0,&uvz0,&h);
fclose(datos);

datos=fopen("neptuno.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&ux0,&uy0,&uz0,&uvx0,&uvy0,&uvz0,&h);
fclose(datos);

datos=fopen("pluton.txt","r"); //Se abre el archivo que contiene los datos del planeta
fscanf(datos,"%lf %lf %lf %lf %lf %lf %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h);
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
for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			 x[i]=x(1)+h*(vx[i-1]*1+(1/2)*fx[i-1]*(h*h);
			y[i]=y(1)+h*(vy[i-1]*1+(1/2)*fy[i-1]*(h*h);
			z[i]=z(1)+h*(vz[i-1]*1+(1/2)*fz[i-1]*(h*h);
			r1=sqrt(pow(x[i-1],2.0)+pow(y[i-1],2.0)+pow(z[i-1],2.0));

			fx[i]=-(G/(pow(r,3.0))*r1;
			fy[i]=-(G/(pow(r,3.0))*r2;
			fz[i]=-(G/(pow(r,3.0))*r3;
			fx[i]=-(G/(pow(r,3.0))*r4;
			fx[i]=-(G/(pow(r,3.0))*r5;
			fx[i]=-(G/(pow(r,3.0))*r6;
			fx[i]=-(G/(pow(r,3.0))*r7;
			fx[i]=-(G/(pow(r,3.0))*r8;
		

			vx[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;
			vy[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;
			vz[i+h]=vx(1)+(1/2)*(f[i]*1+f[i](1.0001))*h;
			v=sqrt(pow(vx[i-1],2.0)+pow(vy[i-1],2.0)+pow(vz[i-1],2.0));	
//Se imprimen los resultados en otro archivo de texto.
    fprintf(resultados," %lf\t %lf\t %lf\n",x[i],y[i],z[i]);
  
}


fclose(resultados);
}

    	
//Se cierra el programa. 
return 0;
}

