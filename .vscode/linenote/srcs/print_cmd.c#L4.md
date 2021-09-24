Por lo que puedo entender, es una función para mostrar en pantalla varias cosas, por lo que parace que se utiliza a modo de debugueo.


---

<br>


```c
t_cmd	*cmd;
```
Estamos creando una nueva estructura del tipo `t_cmd` que viene declarada en el fichero `minishell.h`. Esta estructura contiene 2 punteros a char y 2 listas.
<br><br>

--- 

<br><br>

```c
cmd = (t_cmd *)elem;
```
Como el parametro de la función es de tipo void (esto quiere decir que podemos escoger el tipo), lo que hacemos ahora es castearlo como tipo puntero de `t_cmd` y el valor de esto se lo asignamos al `cmd`
<br><br>

```c
printf("Command: %s\n", cmd->cmd);
```
Pinta por pantalla el valor de la varible `cmd` de la nueva estructura que acabamos de crear que también se llama `cmd` ---> un poco lioso...
<br><br>

```c
printf("Argument: %s\n", cmd->arg);
```
Pinta por pantalla el valor de la varible `arg` de la nueva estructura que acabamos de crear que se llama `cmd`.
<br><br>

```c
printf("In redirections:\n");
```
Simplemente imprime el texto "In redirections:" seguido de un salto de línea.
<br><br>

```c
ft_lstiter(cmd->lst_redir_in, print_redir);
```
Como primer parámetro, recibe un puntero al primer valor de la lista `lst_redir_in` que viene declaradad en la estructura de tipo `t_cmd`
<br><br>

```c
printf("Out redirections:\n");
```
Simplemente imprime el texto "In redirections:" seguido de un salto de línea.
<br><br>

```c
printf("In redirections:\n");
```
ft_lstiter(cmd->lst_redir_out, print_redir);.
<br><br>