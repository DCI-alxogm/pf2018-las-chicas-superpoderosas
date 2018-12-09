	Proyecto final de programación Básica
	     Universidad De Guanajuato
	 División de ciencias en ingenierias
	     Simulación cosmológica
		09/Diciembre/2018
	    
	Diego Ruiz Esparza Flores
	Elizabeth Mercado Ruiz
	Montserat Montes Cruz
	María José Cisneros

	Este programa calcula las diferentes orbitas de
	los planetas que se encuentran en nuestro sistema 
	solar(Mercurio, Venus, Tierra, Marte, Jupiter, 
	Saturno, Urano, Neptuno, Pluton).Cada planeta se 
	ve afectado por las fuerzas gravitacionales de los
	demas planetas, para facilitar los calculos de 
	las fuerzas se tomaron las masas de todos los planetas
	como 1, de esta forma la fórmula de gravitación 
	universal queda de la siguiente forma:
			F=G(1/r³)
	Las unidades que se usan para las distancias son 
	kpc(kiloparsec) es una medida astronómica que es igual
	a 3262 años luz.
	Se creo un archivo con las posiciones y las
	velocidades iniciales de cada planetas, apartir de 
	estos datos es que se empezaron a hacer los calculos 
	para conocer las trayectorias de los planetas.Para 
	el cambio de las posiciones y velocidades se uso el
	método de Leap-frog que sigue la siguiente regla:
		x(t+h)=x(t)+h*vx(t)+1/2*F*h²
		vx(t+h)=vx(t)+1/2*(F(t)+F(t+h))*h
	Estas formulas son usadas para los x,y,z y para vx,vy,vz
	donde h y t son saltos de tiempo, x posicion, vx velocidad
	y F fuerza gravitacional.
	Las graficas se hicieron en python por la facilidad que
	ofrece para los graficos y la animación con una herramienta
	que se puede encontrar en el siguiente link: " ".
