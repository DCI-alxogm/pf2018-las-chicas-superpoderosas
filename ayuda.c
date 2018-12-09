#include<stdio.h>
#include<math.h>

int main(){
float G=39.47841,h,F;
int n=10000,i,o;
double a,b,c,d,e,f,Jx[n],Jy[n],Jz[n],Jvx[n],Jvy[n],Jvz[n],Jh[n],N[n],P[n];
double dx,dy,dz;
double Tx[n],Ty[n],Tz[n],Tvx[n],Tvy[n],Tvz[n],Th[n];
double x[n],y[n],z[n],vx[n],vy[n],vz[n],r[n];
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
	Jh[0]=h;
	resultados=fopen("resultadosjupiter.txt","w"); 

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
	Th[0]=h;
	resultados=fopen("resultadosprueba.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	
	    F=1;
	    Jx[i]=x[i-1]+Jvx[i-1]*h; 
	    Jy[i]=y[i-1]+Jvy[i-1]*h;
	    Jz[i]=z[i-1]+Jvz[i-1]*h;
	    dx=Jx[i-1]-Tx[i-1];
	    dy=Jy[i-1]-Ty[i-1];
	    dz=Jz[i-1]-Tz[i-1];
  	    r[i]=sqrt((dx,2)+pow(dy,2)+pow(dz,2));	//se calcula el radio cada que cambia x,y,z     
	    F=1/r[i];
	    Jvx[i]=F*Jx[i-1];
	    Jvy[i]=F*Jy[i-1];
	    Jvz[i]=F*Jz[i-1];

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",Jx[i],Jy[i],Jz[i],Jvx[i],Jvy[i],Jvz[i]);
	}
	    fclose(resultados);

	/*planeta=fopen("venus.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosvenus.txt","w"); 
		for(i=1;i<=10000;i++) 
	{     	  
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));
	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}
if(o==2)
{
	planeta=fopen("tierra.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadostierra.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	     	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	 
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));
	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);

}

if(o==3)
{
	planeta=fopen("marte.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosmarte.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}

if(o==4)
{
	planeta=fopen("jupiter.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosjupiter.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}

if(o==5)
{
	planeta=fopen("saturno.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadossaturno.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}

if(o==6)
{
	planeta=fopen("urano.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosurano.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}

if(o==7)
{
	planeta=fopen("neptuno.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosneptuno.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}

if(o==8)
{
	planeta=fopen("pluton.txt","r"); 
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h);
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);
	fclose(planeta);	
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadospluton.txt","w"); 
		for(i=1;i<=10000;i++) 
	{	      	   
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	  
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);
	}
	    fclose(resultados);
}*/

return 0;
}// termina el programa
