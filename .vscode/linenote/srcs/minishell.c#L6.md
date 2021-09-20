

```c
char	*line;
```
Creamos un puntero a char para alojar la linea que escribe el usuario en el prompt
<br><br>


```c
t_list	*cmd_lst;
```
Creamos una estructura del tipo `t_list` llamada `*cmd_lst`. Estamos utilizando el tipo de esctuctura que creamos en el archivo `libft.h` de la librería.
<br>

<br>

--- 

<br><br>

```c
line = readline("minishell> ");
```
Esta función lee lo que introduce el usuario en la terminal y se lo asigna a line.
<br><br>

```c
add_history(line)
```
Añade el historial de los comandos para que podamos verlos haciendo flecha hacia arriba.
<br><br>

```c
cmd_lst = NULL;
``` 
Va a ser una lista que vamos a inicializar en NULL
<br><br>

```c
split_in_cmds(line, &cmd_lst);
```
Divide en una lista de comandos lo que va a encontrar en la linea que recibe del usuario.
<br><br>

```c
system("leaks -q minishell");
```
Función del sistema que utilizamos para ver los leaks
<br><br>

```c
ft_lstiter(cmd_lst, print_cmd);
```
Itera a lo largo de la lista y va aplicando en cada iteración la función que recibe en el segundo parámetro.
<br><br>

```c
ft_lstclear(&cmd_lst, &free_cmd);
```
Recorre la lista de atrás hacia delante, liberando el espacio de cada nodo.
<br><br>

```c
free(line);
```

<br><br>