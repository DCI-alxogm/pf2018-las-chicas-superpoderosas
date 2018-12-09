#include<stdio.h>
#include<math.h>

int main()
{
float G=430000,h,F;
int n=10000,i,o;
double a,b,c,d,e,f;
double dx,dy,dz,dx2,dy2,dz2,dx3,dy3,dz3,dx4,dy4,dz4,dx5,dy5,dz5,dx6,dy6,dz6,dx7,dy7,dz7,dx8,dy8,dz8;
double r1,r2,r3,r4,r5,r6,r7,r8;
double Jx[n],Jy[n],Jz[n],Jvx[n],Jvy[n],Jvz[n],Jh,N[n],P[n];
double Tx[n],Ty[n],Tz[n],Tvx[n],Tvy[n],Tvz[n],Th;
double Vx[n],Vy[n],Vz[n],Vvx[n],Vvy[n],Vvz[n],Vh;
double Max[n],May[n],Maz[n],Mavx[n],Mavy[n],Mavz[n],Mah;
double Nx[n],Ny[n],Nz[n],Nvx[n],Nvy[n],Nvz[n],Nh;
double Px[n],Py[n],Pz[n],Pvx[n],Pvy[n],Pvz[n],Ph;
double Sx[n],Sy[n],Sz[n],Svx[n],Svy[n],Svz[n],Sh;
double Ux[n],Uy[n],Uz[n],Uvx[n],Uvy[n],Uvz[n],Uh;
double Mx[n],My[n],Mz[n],Mvx[n],Mvy[n],Mvz[n],Mh;

FILE *planeta;
FILE *resultados;
printf("Hola, este programa calcula la orbita de diferentes planetas entorno al sol\n");
	planeta=fopen("jupiter.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);
	Jx[0]=a;
	Jy[0]=b;
	Jz[0]=c;
	Jvx[0]=d;
	Jvy[0]=e;
	Jvz[0]=f;
	Jh=h;

	planeta=fopen("tierra.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
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
		for(i=1;i<=10000;i++) 
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
	






return 0;
}
// termina el programa
