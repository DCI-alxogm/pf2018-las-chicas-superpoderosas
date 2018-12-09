#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
//declaracion de variables	
float G=43000,h,m;
int n=1000,i,o,t;
double a,b,c,d,e,f;
double x0,y0,z0,vx0,vy0,vz0,r;
FILE *inicial;
FILE *resultados;


int *x= (int*)malloc(n*sizeof(float));
int *y= (int*)malloc(n*sizeof(float));
int *z= (int*)malloc(n*sizeof(float));
int *vx= (int*)malloc(n*sizeof(float));
int *vy= (int*)malloc(n*sizeof(float));
int *vz= (int*)malloc(n*sizeof(float));


//presentacion del programa
printf("Hola, este programa muestra los movimientos de los planetas \n");

	inicial=fopen("iniciales.txt","r");
	//for(i=0;i<10;i++)
	//{ 
	fscanf(inicial,"%lf %lf %lf %lf %lf %lf %f",&x0,&y0,&z0,&vx0,&vy0,&vz0,&h);
	//}
	fclose(inicial);

     //se indican que los valores escaneados del archivo de texto son las posiciones y velocidades iniciales de los planetas en el cubo	x[0]=x0;
	x[0]=x0;
	y[0]=y0;
	z[0]=z0;
	vx[0]=vx0;
	vy[0]=vy0;
	vz[0]=vz0;
	
	
	resultados=fopen("resultadosmercurio.txt","w"); //se abre el archivo donde se van a guardar los resultados
	for(j=0;j<=n;j++){
   			 for(i=0;i<=n;i++){ 

	 //Hacemos las operaciones pertinentes para relación entre planetas con cada uno de los ejes
					fx[j]= ((G*(m*m))) / pow(fabs(rx[i]-rx[i+1]),3) *fabs (rx[i]-rx[i+1]) +fx[j]; //trabajando con el eje x
	
					fy[j]= ((G*(m*m))) / pow(fabs(ry[i]-ry[i+1]),3) *fabs (ry[i]-ry[i+1]) +fy[j]; //trabajando con el eje y
	
					fz[j]= ((G*(m*m))) / pow(fabs(rz[i]-rz[i+1]),3) *fabs (rz[i]-rz[i+1]) +fz[j];  //trabajando con el eje z
					}
	//Se imprimen los resultados en otro archivo de texto.
	//fprintf(resultados,"%lf\t %lf\t %lf\t",x[i],y[i],z[i],h);
}





		for(i=1;i<=n;i++) //se van a hacer 1000 calculos ya que nuestro paso es de 0.001 y el valor de nuestro año es 1
	{
				for(j=1;j<=n;j++){ //se usan las fórmulas para poder calcular las nuevas posiciones y las nuevas velocidades 
					x0[i+h]=x0[i]+h*vx0[i]+1/2*fx*(h*h);
					vx0[i+h]=vx0[i]+1/2*(fx[i+h])*h;
				
					y0[i+h]=y0[i]+h*vy0[i]+1/2*fy*(h*h);
					vy0[i+h]=vy0[i]+1/2*(fy[i+h])*h;
					
					z0[i+h]=z0[i]+h*vz0[i]+1/2*fz*(h*h);
					vz0[i+h]=vz0[i]+1/2*(fz[i+h])*h;
	  //se calcula el radio con los valores de x,y,z de cada planeta, en este caso los de mercurio
	    //se realizan operaciones, se pone i-1 porque tenemos que empezar con los valores iniciados dados en nuestros archivos de texto de los planetas
	   
	   
			}
	}	
	fprint(resultados," %lf\t %lf\t %lf\t",x[i],y[i],z[i]);
	    fclose(resultados); //se cierra la variable de los resultados
//termina nuestro primer if y continuan los demas en caso de que el numero no sea 0, se repiten las mismas acciones en cada if
}

free(x);
free(y);
free(z);
free(vx);
free(vy);
free(vz);





return 0;// termina el programa
}
