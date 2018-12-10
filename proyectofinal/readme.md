	Proyecto final de programación Básica
	     Universidad De Guanajuato
	 División de ciencias en ingenierias
	     Simulación cosmológica
		09/Diciembre/2018
	 

	INTEGRANTES:   
	-Diego Ruiz Esparza Flores
	-Elizabeth Mercado Ruiz
	Montserrat Cruz Aguilar
	María José Cisneros Alvarez

	Este programa calcula los movimientos de los planetas
	y sus  orbitas de acuerdo a la fuerza que ejercen 
	entre si, en este caso la constante de gravedad universal
	(G) fue tomada con el valor de 4300;
	tiempo tomado en cuenta fue de 10 Gigaaños. 	 
	Los planetas que se encuentran en nuestro sistema 
	solar(Mercurio, Venus, Tierra, Marte, Jupiter, 
	Saturno, Urano, Neptuno, Pluton).Cada planeta se 
	ve afectado por las fuerzas gravitacionales de los
	demas planetas, para facilitar los cálculos de 
	las fuerzas se tomaron las masas de todos los planetas
	como 1, de esta forma la fórmula de gravitación 
	universal queda de la siguiente forma:
			F=G(1/r³)
	Las unidades que se usan para las distancias son 
	kpc(kiloparsec) es una medida astronómica que es igual
	a 3262 años luz.
	Se creó un archivo con las posiciones y las
	velocidades iniciales de cada planetas, de igual manera
	dentro del archivo incluia h, que es una fraccion del tiempo,
	en el cual los planetas se van moviendo para
	poder completar el tiempo t. Gracias a estos datos 
	es que se empezó a obtener los cálculos para conocer las
	 trayectorias de los planetas.
	Para el cambio de las posiciones y velocidades se uso el
	método de Leap-frog que sigue la siguiente regla:
		x(t+h)=x(t)+h*vx(t)+1/2*F*h²
		vx(t+h)=vx(t)+1/2*(F(t)+F(t+h))*h
	Estas fórmulas son usadas para las posiciones en los ejes
	 x,y,z y para las velocidades, de igual manera en vx,vy,vz
	donde h y t son saltos de tiempo, x posición, vx velocidad
	y F fuerza gravitacional.
	Se obtuvieron varias iteraciones que son los pasos de los planetas
	respecto al tiempo, con estos pasos se obtuvieron diversas gráficas que 
	muestran el movimiento realizado.
	Las gráficas se hicieron en python, en jupyther notebook, por la facilidad que
	ofrece para los gráficos y animación con una herramienta
	que se puede encontrar en el siguiente link: " "

