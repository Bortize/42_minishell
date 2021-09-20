El proposito de esta funcion es seccionar la linea que recibe del usuairo por terminal para ir recogiendo valores y guardarlos en una lista para poder trabajar luego con ella.

La idea es avanzar hasta cada pipe y eso como identifica que es un comnad, lo parte

** Recorre toda la linea que nos pasa el usuario para tokenizarla **

<br>

-----------------------------------------------------------------------------------------

<br>


```c
split_in_cmds(char *line, t_list **last_cmd)
```
La función recibe como primer argumento la línea que ha introducido el usuario en la terminal y como segundo argumento una lista para poder guardar valores que vamos a seccionar de esta lista.

	t_list	*cmd_node;	->
	t_cmd	*cmd;		->
	char	*tmp;		->
	size_t	cmd_len;	->

```c
cmd_len = 0
```
es el iterador que voy a utilizar para recorrer el while que va a recorrer la línea de la terminal.
<br><br>

```c
while (line[cmd_len] && line[cmd_len] != '|')
```

En este while queremos recorrer la linea que ha introducido el usuario por la terminal para buscar caractrers. Lo que estamos diciendo es que mientras exista la linea o que no encontremos ningun pipe por el camino, entonces ejecutamos el codigo de su interiro:

```c
if (line[cmd_len] == '\'' || line[cmd_len] == '\"')
			cmd_len += count_until_repeat(line + cmd_len);
else
	cmd_len++;
```
Si el carácter que se encuentra es sigual a (\\') o (\\"), quire decir que es una barra de escape y el carácter que le sigue se va a comportar de una manera diferente. 	Entonces, va a ejeuctar la función `count_until_repeat(line + cmd_len)` que 		devuelve la longitud que hay desde despues del caracter de escape hasta el final de la cadena o hasta que encuentra otro caracter de escape.

Sino, avanza una posicón en el iterador de la línea.

<br><br>

```c
tmp = ft_strndup(line, cmd_len);
```
Hace una copia de la línea que ha leído y se la asigna a `tmp`. Entoces, tmp va a contener o toda la cadena si no ha encontrado ningún pipe, o el trozo de la cadena hasta que encuentra un pipe, por lo que si es este segundo caso, aun nos quedará cadena por leer.
<br><br>

```c
cmd = ft_calloc(1, sizeof(t_cmd));
```
Reserva memoria del tamaño de una estructura de tipo `t_cmd` y la inicializa a 0 que es lo que hace calloc. calloc devuelve un puntero del resultado de esta asignación de memoría y se lo asigna a `cmd`
<br><br>

```c
cmd_node = ft_lstnew(cmd);
```
Crea una estructura (que será el comienzo de una lista) y se lo asigna a `cmd_node`
<br><br>

```c
if (!cmd || !cmd_node)
		exit(1);
```
Si la asignación de memoria fallo para `cmd` o para `cmd_node` entonces sale
<br><br>

```c
tokenize_cmd(tmp, cmd);
```
Esta función recibe `tmp` que es el trozo de linea que ha recogido hasta que encuentra un pipe o llega al final de la línea leída.
Como segundo parámetro recibe `cmd` que es un puntero a un nodo vacio el cuál se reservo memoría anteriormente.
<br><br>

```c
ft_lstadd_back(last_cmd, cmd_node);
```

<br><br>


```c
free(tmp);
```

<br><br>


```c
if (line[cmd_len])
		return (split_in_cmds(line + cmd_len + 1, &(*last_cmd)->next));
```

<br><br>

