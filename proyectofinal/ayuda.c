#include<stdio.h>
#include<math.h>
#include "main.h"
#include<stdio.h>


void proyecto()
{
//Se definen las variables que se van a utilizar durante el programa
float G=430000,h0,m=1;
int n,c,i,j,t,tf;
float x0,y0,z0,vx0,vy0,vz0;
char name[100];
FILE *planeta;
FILE *resultados;
//se 
printf("Hola, este programa calcula los movimientos de los planetas entorno al sol y a las fuerzas que ejercen entre ellos\n");
printf("Escribe el número de planetas que quieres: \n");//se escribe el número de planetas que se van a utiliza
scanf("%i",&n);
printf("Escribe el número de iteraciones que quieres que se realice\n");//se pide el número de iteraciones que se van a realizar que son la cantidad de pasos que daran los planetas.
scanf("%i",&tf);

float h[n],x[n],y[n],z[n],rx[n],ry[n],rz[n],vx[n],vy[n],vz[n],fx[n],fy[n],fz[n]; //se declaran las variables donde se ira guardando la informacion de las nuevas posiciones, velocidades y fuerzas.

	planeta=fopen("iniciales.txt","r");//se abre el archivo de lectura con los datos iniciales de los planetas (posiciones en x,y,z y velocidades en x,y,z)
	for(j=0;j<n;j++){ 
	fscanf(planeta,"%f %f %f %f %f %f %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h0); //leer los datos del documento con terminacion .txt--------------escribir el tiempo y la masa de los planetas que es 1
//	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",x0,y0,z0,vx0,vy0,vz0,h0);//se guardan los datos en las variables
	x[j]=x0;
	y[j]=y0;//-------------------------------Se indica que los valores escaneados son los valores iniciales 
	z[j]=z0;
	vx[j]=vx0;
	vy[j]=vy0;
	vz[j]=vz0;
	h[j]=h0;
	printf("x %f\t y %f\t z %f\t vx %f\t vy %f\t vz %f\t h %f\n",x[j],y[j],z[j],vx[j],vy[j],vz[j],h[j]); // se realiza un aprieba



}
fclose(planeta);//se cierra el archivo de lectura
	for(i=0;i<n;i++){
		fx[i]=0;//-------------------se indica que la sumatoria de las fuerzas en los distintos ejes es igual a 0.
		fy[i]=0;
		fz[i]=0;
		}



printf("Escribe el nombre del archivo donde se guardaran los nuevos datos, (debe de terminar en '.txt')\n");//se pide el nombre del archivo donde se van a guardar las nuevas posiciones.
scanf("%s",name);
resultados=fopen(name,"w");//se crea archivo

	for(t=1;t<tf;t++){
		printf("El tiempo es de %d\n",t); //se indican los valores del tiempo y de las iteraciones realizadas
		fprintf(resultados,"Iteracion no.:%d\n",t);
		fprintf(resultados,"x\t y\t z\n");
		for(j=0;j<n;j++){ //ciclos anidados
			for(i=0;i<n;i++){
				if(i!=j){
				//DISTANCIA ENTRE PLANETAS
				printf("i=%d\tj=%d\n",i,j);
				rx[j]=sqrt(pow(fabs(x[j]-x[i]),2));
				ry[j]=sqrt(pow(fabs(y[j]-y[i]),2));//-----------------operaciones de las distancias entre los planetas
				rz[j]=sqrt(pow(fabs(z[j]-z[i]),2));
				printf("fx=%f\t G=%f\t m1=%f\t m2=%f\n",fx[j],G,m,m);
				//FUERZA
				fx[j]=fx[j]+G*(m*m)/rx[j];
				fy[j]=fy[j]+G*(m*m)/ry[j];//---------------------operaciones para calcular las fuerzas 
				fz[j]=fz[j]+G*(m*m)/rz[j];
			
				printf("rx %f\t ry %f\t rz %f\n",rx[j],ry[j],rz[j]);//se imprimen las distancias entre los planetas
				printf("fx %f\t fy %f\t fz %f\n",fx[i],fy[i],fz[i]);//se imprimen las fuerzas 
				//POSICIONES
			
			
			
				}
				x[j]=x[j]+(vx[j]*h[j])+(0.5*fx[j]*pow(h[j],2));
				y[j]=y[j]+(vy[j]*h[j])+(0.5*fy[j]*pow(h[j],2));//---------------operaciones para las nuevas distancias
				z[j]=z[j]+(vz[j]*h[j])+(0.5*fz[j]*pow(h[j],2));
				h[j]++;
		}
	printf("nueva posicion del planeta\n");	
//	printf("x %f\t y %f\t z %f\n",x[j],y[j],z[j]);
	fprintf(resultados,"%f\t %f\t %f\n",x[j],y[j],z[j]);//se imprimen los resultados obtenidos dentro del nuevo archivo creado 
	printf("fin\n");
	}
}

fclose(resultados);// se cierra el archivo de resultados 
//	return 0;


/*	planeta=fopen("","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Tx[0]=a;
	Ty[0]=b;
	Tz[0]=c;
	Tvx[0]=d;
	Tvy[0]=e;
	Tvz[0]=f;
	Th=h;
	
	planeta=fopen("venus.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Vx[0]=a;
	Vy[0]=b;
	Vz[0]=c;
	Vvx[0]=d;
	Vvy[0]=e;
	Vvz[0]=f;
	Vh=h;
	
	planeta=fopen("marte.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Max[0]=a;
	May[0]=b;
	Maz[0]=c;
	Mavx[0]=d;
	Mavy[0]=e;
	Mavz[0]=f;
	Mah=h;

	planeta=fopen("neptuno.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Nx[0]=a;
	Ny[0]=b;
	Nz[0]=c;
	Nvx[0]=d;
	Nvy[0]=e;
	Nvz[0]=f;
	Nh=h;

	planeta=fopen("pluton.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Px[0]=a;
	Py[0]=b;
	Pz[0]=c;
	Pvx[0]=d;
	Pvy[0]=e;
	Pvz[0]=f;
	Ph=h;

	planeta=fopen("saturno.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Sx[0]=a;
	Sy[0]=b;
	Sz[0]=c;
	Svx[0]=d;
	Svy[0]=e;
	Svz[0]=f;
	Sh=h;

	planeta=fopen("urano.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Ux[0]=a;
	Uy[0]=b;
	Uz[0]=c;
	Uvx[0]=d;
	Uvy[0]=e;
	Uvz[0]=f;
	Uh=h;

	planeta=fopen("mercurio.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f ",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Mx[0]=a;
	My[0]=b;
	Mz[0]=c;
	Mvx[0]=d;
	Mvy[0]=e;
	Mvz[0]=f;
	Mh=h;

	resultados=fopen("resultadosjupiterchidos.txt","w"); 
		for(i=1;i<=n;i++) 
	{	

	   
	    dx=Jx[i-1]-Tx[i-1];
	    dy=Jy[i-1]-Ty[i-1];
	    dz=Jz[i-1]-Tz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Jx[i-1]-Vx[i-1];
	    dy2=Jy[i-1]-Vy[i-1];
	    dz2=Jz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Jx[i-1]-Max[i-1];
	    dy3=Jy[i-1]-May[i-1];
	    dz3=Jz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Jx[i-1]-Nx[i-1];
	    dy4=Jy[i-1]-Ny[i-1];
	    dz4=Jz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Jx[i-1]-Px[i-1];
	    dy5=Jy[i-1]-Py[i-1];
	    dz5=Jz[i-1]-Pz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Jx[i-1]-Sx[i-1];
	    dy6=Jy[i-1]-Sy[i-1];
	    dz6=Jz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Jx[i-1]-Ux[i-1];
	    dy7=Jy[i-1]-Uy[i-1];
	    dz7=Jz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Jx[i-1]-Mx[i-1];
	    dy8=Jy[i-1]-My[i-1];
	    dz8=Jz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Jx[i]=Jx[i-1]+(Jvx[i-1]*Jh)+(1/2*F*(pow(Jh,2)));
	    Jy[i]=Jy[i-1]+(Jvy[i-1]*Jh)+(1/2*F*(pow(Jh,2)));
	    Jz[i]=Jz[i-1]+(Jvz[i-1]*Jh)+(1/2*F*(pow(Jh,2)));
	    Jvx[i]=Jvx[i-1]+((1/2)*(Jh*(F*1+F*Jh)));
	    Jvy[i]=Jvy[i-1]+((1/2)*(Jh*(F*1+F*Jh)));
	    Jvz[i]=Jvz[i-1]+((1/2)*(Jh*(F*1+F*Jh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Jx[i],Jy[i],Jz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadostierra.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Tx[i-1]-Jx[i-1];
	    dy=Ty[i-1]-Jy[i-1];
	    dz=Tz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Tx[i-1]-Vx[i-1];
	    dy2=Ty[i-1]-Vy[i-1];
	    dz2=Tz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Tx[i-1]-Max[i-1];
	    dy3=Ty[i-1]-May[i-1];
	    dz3=Tz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Tx[i-1]-Nx[i-1];
	    dy4=Ty[i-1]-Ny[i-1];
	    dz4=Tz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Tx[i-1]-Px[i-1];
	    dy5=Ty[i-1]-Py[i-1];
	    dz5=Tz[i-1]-Pz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Tx[i-1]-Sx[i-1];
	    dy6=Ty[i-1]-Sy[i-1];
	    dz6=Tz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Tx[i-1]-Ux[i-1];
	    dy7=Ty[i-1]-Uy[i-1];
	    dz7=Tz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Tx[i-1]-Mx[i-1];
	    dy8=Ty[i-1]-My[i-1];
	    dz8=Tz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Tx[i]=Tx[i-1]+(Tvx[i-1]*Th)+(1/2*F*(pow(Th,2)));
	    Ty[i]=Ty[i-1]+(Tvy[i-1]*Th)+(1/2*F*(pow(Th,2)));
	    Tz[i]=Tz[i-1]+(Tvz[i-1]*Th)+(1/2*F*(pow(Th,2)));
	    Tvx[i]=Tvx[i-1]+((1/2)*(Th*(F*1+F*Th)));
	    Tvy[i]=Tvy[i-1]+((1/2)*(Th*(F*1+F*Th)));
	    Tvz[i]=Tvz[i-1]+((1/2)*(Th*(F*1+F*Th)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Tx[i],Ty[i],Tz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadosvenus.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Vx[i-1]-Jx[i-1];
	    dy=Vy[i-1]-Jy[i-1];
	    dz=Vz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Vx[i-1]-Tx[i-1];
	    dy2=Vy[i-1]-Ty[i-1];
	    dz2=Vz[i-1]-Tz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Vx[i-1]-Max[i-1];
	    dy3=Vy[i-1]-May[i-1];
	    dz3=Vz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Vx[i-1]-Nx[i-1];
	    dy4=Vy[i-1]-Ny[i-1];
	    dz4=Vz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Vx[i-1]-Px[i-1];
	    dy5=Vy[i-1]-Py[i-1];
	    dz5=Vz[i-1]-Pz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Vx[i-1]-Sx[i-1];
	    dy6=Vy[i-1]-Sy[i-1];
	    dz6=Vz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Vx[i-1]-Ux[i-1];
	    dy7=Vy[i-1]-Uy[i-1];
	    dz7=Vz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Vx[i-1]-Mx[i-1];
	    dy8=Vy[i-1]-My[i-1];
	    dz8=Vz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Vx[i]=Vx[i-1]+(Vvx[i-1]*Vh)+(1/2*F*(pow(Vh,2)));
	    Vy[i]=Vy[i-1]+(Vvy[i-1]*Vh)+(1/2*F*(pow(Vh,2)));
	    Vz[i]=Vz[i-1]+(Vvz[i-1]*Vh)+(1/2*F*(pow(Vh,2)));
	    Vvx[i]=Vvx[i-1]+((1/2)*(Vh*(F*1+F*Vh)));
	    Vvy[i]=Vvy[i-1]+((1/2)*(Vh*(F*1+F*Vh)));
	    Vvz[i]=Vvz[i-1]+((1/2)*(Vh*(F*1+F*Vh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Vx[i],Vy[i],Vz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadosmarte.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Max[i-1]-Jx[i-1];
	    dy=May[i-1]-Jy[i-1];
	    dz=Maz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Max[i-1]-Vx[i-1];
	    dy2=May[i-1]-Vy[i-1];
	    dz2=Maz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Max[i-1]-Tx[i-1];
	    dy3=May[i-1]-Ty[i-1];
	    dz3=Maz[i-1]-Tz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Max[i-1]-Nx[i-1];
	    dy4=May[i-1]-Ny[i-1];
	    dz4=Maz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Max[i-1]-Px[i-1];
	    dy5=May[i-1]-Py[i-1];
	    dz5=Maz[i-1]-Pz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Max[i-1]-Sx[i-1];
	    dy6=May[i-1]-Sy[i-1];
	    dz6=Maz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Max[i-1]-Ux[i-1];
	    dy7=May[i-1]-Uy[i-1];
	    dz7=Maz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Max[i-1]-Mx[i-1];
	    dy8=May[i-1]-My[i-1];
	    dz8=Maz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Max[i]=Max[i-1]+(Mavx[i-1]*Mah)+(1/2*F*(pow(Mah,2)));
	    May[i]=May[i-1]+(Mavy[i-1]*Mah)+(1/2*F*(pow(Mah,2)));
	    Maz[i]=Maz[i-1]+(Mavz[i-1]*Mah)+(1/2*F*(pow(Mah,2)));
	    Mavx[i]=Mavx[i-1]+((1/2)*(Mah*(F*1+F*Mah)));
	    Mavy[i]=Mavy[i-1]+((1/2)*(Mah*(F*1+F*Mah)));
	    Mavz[i]=Mavz[i-1]+((1/2)*(Mah*(F*1+F*Mah)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Max[i],May[i],Maz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadosneptuno.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Nx[i-1]-Jx[i-1];
	    dy=Ny[i-1]-Jy[i-1];
	    dz=Nz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Nx[i-1]-Vx[i-1];
	    dy2=Ny[i-1]-Vy[i-1];
	    dz2=Nz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Nx[i-1]-Max[i-1];
	    dy3=Ny[i-1]-May[i-1];
	    dz3=Nz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Nx[i-1]-Tx[i-1];
	    dy4=Ny[i-1]-Ty[i-1];
	    dz4=Nz[i-1]-Tz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Nx[i-1]-Px[i-1];
	    dy5=Ny[i-1]-Py[i-1];
	    dz5=Nz[i-1]-Pz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Nx[i-1]-Sx[i-1];
	    dy6=Ny[i-1]-Sy[i-1];
	    dz6=Nz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Nx[i-1]-Ux[i-1];
	    dy7=Ny[i-1]-Uy[i-1];
	    dz7=Nz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Nx[i-1]-Mx[i-1];
	    dy8=Ny[i-1]-My[i-1];
	    dz8=Nz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Nx[i]=Nx[i-1]+(Nvx[i-1]*Nh)+(1/2*F*(pow(Nh,2)));
	    Ny[i]=Ny[i-1]+(Nvy[i-1]*Nh)+(1/2*F*(pow(Nh,2)));
	    Nz[i]=Nz[i-1]+(Nvz[i-1]*Nh)+(1/2*F*(pow(Nh,2)));
	    Nvx[i]=Nvx[i-1]+((1/2)*(Nh*(F*1+F*Nh)));
	    Nvy[i]=Nvy[i-1]+((1/2)*(Nh*(F*1+F*Nh)));
	    Nvz[i]=Nvz[i-1]+((1/2)*(Nh*(F*1+F*Nh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Nx[i],Ny[i],Nz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadospluton.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Px[i-1]-Jx[i-1];
	    dy=Py[i-1]-Jy[i-1];
	    dz=Pz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Px[i-1]-Vx[i-1];
	    dy2=Py[i-1]-Vy[i-1];
	    dz2=Pz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Px[i-1]-Max[i-1];
	    dy3=Py[i-1]-May[i-1];
	    dz3=Pz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Px[i-1]-Nx[i-1];
	    dy4=Py[i-1]-Ny[i-1];
	    dz4=Pz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Px[i-1]-Tx[i-1];
	    dy5=Py[i-1]-Ty[i-1];
	    dz5=Pz[i-1]-Tz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Px[i-1]-Sx[i-1];
	    dy6=Py[i-1]-Sy[i-1];
	    dz6=Pz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Px[i-1]-Ux[i-1];
	    dy7=Py[i-1]-Uy[i-1];
	    dz7=Pz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Px[i-1]-Mx[i-1];
	    dy8=Py[i-1]-My[i-1];
	    dz8=Pz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Px[i]=Px[i-1]+(Pvx[i-1]*Ph)+(1/2*F*(pow(Ph,2)));
	    Py[i]=Py[i-1]+(Pvy[i-1]*Ph)+(1/2*F*(pow(Ph,2)));
	    Pz[i]=Pz[i-1]+(Pvz[i-1]*Ph)+(1/2*F*(pow(Ph,2)));
	    Pvx[i]=Pvx[i-1]+((1/2)*(Ph*(F*1+F*Ph)));
	    Pvy[i]=Pvy[i-1]+((1/2)*(Ph*(F*1+F*Ph)));
	    Pvz[i]=Pvz[i-1]+((1/2)*(Ph*(F*1+F*Ph)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Px[i],Py[i],Pz[i]);
	}
	    fclose(resultados);

	

	resultados=fopen("resultadossaturno.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Sx[i-1]-Jx[i-1];
	    dy=Sy[i-1]-Jy[i-1];
	    dz=Sz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Sx[i-1]-Vx[i-1];
	    dy2=Sy[i-1]-Vy[i-1];
	    dz2=Sz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Sx[i-1]-Max[i-1];
	    dy3=Sy[i-1]-May[i-1];
	    dz3=Sz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Sx[i-1]-Nx[i-1];
	    dy4=Sy[i-1]-Ny[i-1];
	    dz4=Sz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Sx[i-1]-Tx[i-1];
	    dy5=Sy[i-1]-Ty[i-1];
	    dz5=Sz[i-1]-Tz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Sx[i-1]-Px[i-1];
	    dy6=Sy[i-1]-Py[i-1];
	    dz6=Sz[i-1]-Pz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Sx[i-1]-Ux[i-1];
	    dy7=Sy[i-1]-Uy[i-1];
	    dz7=Sz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Sx[i-1]-Mx[i-1];
	    dy8=Sy[i-1]-My[i-1];
	    dz8=Sz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Sx[i]=Sx[i-1]+(Svx[i-1]*Sh)+(1/2*F*(pow(Sh,2)));
	    Sy[i]=Sy[i-1]+(Svy[i-1]*Sh)+(1/2*F*(pow(Sh,2)));
	    Sz[i]=Sz[i-1]+(Svz[i-1]*Sh)+(1/2*F*(pow(Sh,2)));
	    Svx[i]=Svx[i-1]+((1/2)*(Sh*(F*1+F*Sh)));
	    Svy[i]=Svy[i-1]+((1/2)*(Sh*(F*1+F*Sh)));
	    Svz[i]=Svz[i-1]+((1/2)*(Sh*(F*1+F*Sh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Sx[i],Sy[i],Sz[i]);
	}
	    fclose(resultados);
	

	

	resultados=fopen("resultadosurano.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Ux[i-1]-Jx[i-1];
	    dy=Uy[i-1]-Jy[i-1];
	    dz=Uz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Ux[i-1]-Vx[i-1];
	    dy2=Uy[i-1]-Vy[i-1];
	    dz2=Uz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Ux[i-1]-Max[i-1];
	    dy3=Uy[i-1]-May[i-1];
	    dz3=Uz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Ux[i-1]-Nx[i-1];
	    dy4=Uy[i-1]-Ny[i-1];
	    dz4=Uz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Ux[i-1]-Tx[i-1];
	    dy5=Uy[i-1]-Ty[i-1];
	    dz5=Uz[i-1]-Tz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Ux[i-1]-Sx[i-1];
	    dy6=Uy[i-1]-Sy[i-1];
	    dz6=Uz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Ux[i-1]-Px[i-1];
	    dy7=Uy[i-1]-Py[i-1];
	    dz7=Uz[i-1]-Pz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Ux[i-1]-Mx[i-1];
	    dy8=Uy[i-1]-My[i-1];
	    dz8=Uz[i-1]-Mz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Ux[i]=Ux[i-1]+(Uvx[i-1]*Uh)+(1/2*F*(pow(Uh,2)));
	    Uy[i]=Uy[i-1]+(Uvy[i-1]*Uh)+(1/2*F*(pow(Uh,2)));
	    Uz[i]=Uz[i-1]+(Uvz[i-1]*Uh)+(1/2*F*(pow(Uh,2)));
	    Uvx[i]=Uvx[i-1]+((1/2)*(Uh*(F*1+F*Uh)));
	    Uvy[i]=Uvy[i-1]+((1/2)*(Uh*(F*1+F*Uh)));
	    Uvz[i]=Uvz[i-1]+((1/2)*(Uh*(F*1+F*Uh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Ux[i],Uy[i],Uz[i]);
	}
	    fclose(resultados);
	

	

	resultados=fopen("resultadosmercurio.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    dx=Mx[i-1]-Jx[i-1];
	    dy=My[i-1]-Jy[i-1];
	    dz=Mz[i-1]-Jz[i-1];
  	    r1=sqrt((dx,2)+pow(dy,2)+pow(dz,2));
	    dx2=Mx[i-1]-Vx[i-1];
	    dy2=My[i-1]-Vy[i-1];
	    dz2=Mz[i-1]-Vz[i-1];
	    r2=sqrt((dx2,2)+pow(dy2,2)+pow(dz2,2));	
	    dx3=Mx[i-1]-Max[i-1];
	    dy3=My[i-1]-May[i-1];
	    dz3=Mz[i-1]-Maz[i-1];
	    r3=sqrt((dx3,2)+pow(dy3,2)+pow(dz3,2));	
	    dx4=Mx[i-1]-Nx[i-1];
	    dy4=My[i-1]-Ny[i-1];
	    dz4=Mz[i-1]-Nz[i-1];
	    r4=sqrt((dx4,2)+pow(dy4,2)+pow(dz4,2));
	    dx5=Mx[i-1]-Tx[i-1];
	    dy5=My[i-1]-Ty[i-1];
	    dz5=Mz[i-1]-Tz[i-1];
	    r5=sqrt((dx5,2)+pow(dy5,2)+pow(dz5,2));	
	    dx6=Mx[i-1]-Sx[i-1];
	    dy6=My[i-1]-Sy[i-1];
	    dz6=Mz[i-1]-Sz[i-1];
	    r6=sqrt((dx6,2)+pow(dy6,2)+pow(dz6,2));
	    dx7=Mx[i-1]-Ux[i-1];
	    dy7=My[i-1]-Uy[i-1];
	    dz7=Mz[i-1]-Uz[i-1];
	    r7=sqrt((dx7,2)+pow(dy7,2)+pow(dz7,2));
	    dx8=Mx[i-1]-Px[i-1];
	    dy8=My[i-1]-Py[i-1];
	    dz8=Mz[i-1]-Pz[i-1];
	    r8=sqrt((dx8,2)+pow(dy8,2)+pow(dz8,2));

	    F=G*((1/(pow(r1,3)))+(1/(pow(r2,3)))+(1/(pow(r3,3)))+(1/(pow(r4,3)))+(1/(pow(r5,3)))+(1/(pow(r6,3)))+(1/(pow(r7,3)))+(1/(pow(r8,3))));   
	    Mx[i]=Mx[i-1]+(Mvx[i-1]*Mh)+(1/2*F*(pow(Mh,2)));
	    My[i]=My[i-1]+(Mvy[i-1]*Mh)+(1/2*F*(pow(Mh,2)));
	    Mz[i]=Mz[i-1]+(Mvz[i-1]*Mh)+(1/2*F*(pow(Mh,2)));
	    Mvx[i]=Mvx[i-1]+((1/2)*(Mh*(F*1+F*Mh)));
	    Mvy[i]=Mvy[i-1]+((1/2)*(Mh*(F*1+F*Mh)));
	    Mvz[i]=Mvz[i-1]+((1/2)*(Mh*(F*1+F*Mh)));

	    fprintf(resultados," %lf\t %lf\t %lf \n ",Mx[i],My[i],Mz[i]);
	}
	    fclose(resultados);
	

*/
}
// termina el programa
