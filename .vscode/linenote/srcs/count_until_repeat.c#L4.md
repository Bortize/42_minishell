
`count_until_repeat(char *line)` -> Esta recibiendo el valor del índice donde se encuentra el iterador de la línea.

	char	*end;	-> va a recibir el valor de lo que hay despues de \
	char	c;		-> recibe el valor del iterador de la linea
	char	aux;	-> recibe el valor de lo que hay despues de \

El puntero del iterador de la linea, osea el contenido, se lo asigna a "c"...

... el iterador de la linea avanza una posicion y le asigna la dirección de memoria a "line" ...

... ahora le asigna el contenido de end a "aux"


En el while esta diciendo que mientras que no se encuentre con un caracter de escape '\' vaya avanzando una posición y asigne a aux el contenido de las posiciones que vaya avanzando.


Si en algun momento del avance se encuentra con que no hay nada que leer porque esta vacio, entonces devuelve 1

Devuelve la longitud del string que ha leido despues del caracger de escape.

