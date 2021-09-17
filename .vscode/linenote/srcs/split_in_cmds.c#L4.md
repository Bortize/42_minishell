El proposito de esta funcion es seccionar la linea que recibe del usuairo por terminal para ir recogiendo valores y guardarlos en una lista para poder trabajar luego con ella.

-----------------------------------------------------------------------------------------




`split_in_cmds(char *line, t_list **last_cmd)` -> La función recibe como primer argumento la línea que ha introducido el usuario en la terminal y como segundo argumento una lista para poder guardar valores que vamos a seccionar de esta lista.

	t_list	*cmd_node;	->
	t_cmd	*cmd;		->
	char	*tmp;		->
	size_t	cmd_len;	->


	cmd_len = 0 -> es el iterador que voy a utilizar para recorrer el while que va a recorrer la línea de la terminal.

En este while queremos recorrer la linea que ha introducido el usuario por la terminal para buscar caractrers. Lo que estamos diciendo es que mientras exista la linea o que no encontremos ningun pipe por el camino, entonces ejecutamos el codigo de su interiro:

	Si el carácter que se encuentra es sigual a \' o \", lo que quire decir que es una barra de escape y el carácter que le sigue se va a comportar de una manera diferente. 	Entonces va a ejeuctar la función `count_until_repeat(line + cmd_len);` que 		devuelve la longitud que hay desde despues del caracter de escape hasta que no 		hay nada o encuentra otro caracter de escape.

		Sino, avanza una posicón en el iterador de la línea.


`tmp = ft_strndup(line, cmd_len);` -> Hace una copia de la línea que ha leído y se la asigna a `tmp`

`cmd = ft_calloc(1, sizeof(t_cmd));` -> Reserva memoria del tamaño de una estructura de tipo `t_cmd` y la inicializa a 0 que es lo que hace calloc. calloc devuelve un puntero del resultado de esta asignacio y se lo asigna a `cmd`