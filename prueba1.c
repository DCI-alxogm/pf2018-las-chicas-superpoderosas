#include<stdio.h>
#include<math.h>
int main(){
//declaracion de variables
float G=39.47841,h;
int n=10000,i,o;
double a,b,c,d,e,f;
double x[n],y[n],z[n],vx[n],vy[n],vz[n],r;
FILE *planeta;
FILE *resultados;


//presentacion del programa
printf("Hola, este programa calcula la orbita de diferentes planetas entorno al sol\n");
//se pide al usuario que eliga el planeta
printf("Escoge que orbita quieres calcular: \nmercurio[0] \nvenus[1] \ntierra[2] \nmarte[3] \njupiter[4] \nsaturno[5] \nurano[6] \nneptuno[7] \npluton[8]\n");
scanf("%i",&o); //se escanea la variable "o"

if(o==0)
{
	planeta=fopen("mercurio.txt","r"); //dependiendo de la variable seran los datos(en este caso se van a leer los datos de mercurio)
	fscanf(planeta,"%lf %lf %lf %lf %lf %lf %f %i",&a,&b,&c,&d,&e,&f,&h); //leer los datos del documento con terminacion .txt
	printf("Prueba datos iniciales %lf\t %lf\t %lf\t %lf\t %lf\t %lf\t %f\t  \n",a,b,c,d,e,f,h);//se guardan los datos en las variables
	fclose(planeta);//se cierra el archivo de datos del planeta
	//se asignan los valores a la ṕosición 0 de nuestros arreglos
	x[0]=a; 
	y[0]=b;
	z[0]=c;
	vx[0]=d;
	vy[0]=e;
	vz[0]=f;
	resultados=fopen("resultadosmercurio.txt","w"); //se abre el archivo donde se van a guardar los resultados
		for(i=1;i<=10000;i++) //se van a hacer 1000 calculos ya que nuestro paso es de 0.001 y el valor de nuestro año es 1
	{
	  //se calcula el radio con los valores de x,y,z de cada planeta, en este caso los de mercurio
	    //se realizan operaciones, se pone i-1 porque tenemos que empezar con los valores iniciados dados en nuestros archivos de texto de los planetas
	    x[i]=x[i-1]+vx[i-1]*h; 
	    y[i]=y[i-1]+vy[i-1]*h;
	    z[i]=z[i-1]+vz[i-1]*h;
  	    r=sqrt(pow(x[i-1],2)+pow(y[i-1],2)+pow(z[i-1],2));	//se calcula el radio cada que cambia x,y,z     
	    vx[i]=vx[i-1]-h*((G*x[i-1])/pow(r,3));
	    vy[i]=vy[i-1]-h*((G*y[i-1])/pow(r,3));
	    vz[i]=vz[i-1]-h*((G*z[i-1])/pow(r,3));

	    fprintf(resultados," %lf\t %lf\t %lf\t %lf\t %lf\t %lf\n",x[i],y[i],z[i],vx[i],vy[i],vz[i]);//Los resultados se van guardando en cada arreglo
	}
	    fclose(resultados); //se cierra la variable de los resultados
//termina nuestro primer if y continuan los demas en caso de que el numero no sea 0, se repiten las mismas acciones en cada if
}

if(o==1)
{
	planeta=fopen("venus.txt","r"); 
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
}

return 0;// termina el programa
}
