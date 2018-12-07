#include<stdio.h>
#include<math.h>
int main(){
//declaracion de variables
float G=39.47841,h;
int n=10000,i,o;
double a,b,c,d,e,f,m[n];
double x[n],y[n],z[n],vx[n],vy[n],vz[n],r;
FILE *inicial;
FILE *resultados;

//presentacion del programa
printf("Hola, este programa calcula la orbita de los planetas entorno al sol\n");

	inicial=fopen("iniciales.txt","r");
	for(i=0;i<10;i++)
	{ 
	fscanf(inicial,"%lf %lf %lf %lf %lf %lf %f",&m[i]);
	}
	fclose(inicial);
	printf("datos son: %lf",m[n]);
	//se asignan los valores a la ṕosición 0 de nuestros arreglos
	/*x[0]=a; 
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
}*/
return 0;// termina el programa
}
