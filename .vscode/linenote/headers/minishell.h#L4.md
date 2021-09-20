```makefile
typedef enum e_behavior
{
	redir_out,
	redir_out_append,
	redir_in,
	here_doc,
	plain
}			t_behavior;
```
La palabra clave enum define un tipo especial llamado enumeración. Las enumeraciones son básicamente valores integrales que tienen nombres como variables pero son objetos de sólo lectura y no pueden ser modificados en tiempo de ejecución.
<br><br>

```makefile
typedef struct s_redirect
{
	char		*text;
	t_behavior	type;
}				t_redirect;
```
Creamos una estructura del tipo `t_redirect` que continen un puntero a char `char *text` y una nueva estructura del tipo `t_behaivor` que contiene valores que no puede sen modificados en tiempo de ejecución.
<br><br>


```makefile
typedef struct s_cmd
{
	char			*cmd;
	char			*arg;
	t_list			*lst_redir_in;
	t_list			*lst_redir_out;
}			t_cmd;
```
Creamos una estructura del tipo `t_cmd` que contiene 2 punteros a char y 2 punteros a listas.
<br><br>


```makefile
int		is_delimiter(char c);
```

<br><br>


```makefile
int		is_space(char c);
```

<br><br>


```makefile
size_t	count_spaces(char *line);
```

<br><br>


```makefile
size_t	count_until_repeat(char *line);
```

<br><br>


```makefile
void	split_in_cmds(char *line, t_list **last_cmd);
```

<br><br>


```makefile
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node);
```

<br><br>


```makefile
void	free_cmd(void *elem);
```

<br><br>


```makefile
void	free_redirect(void *elem);
```

<br><br>


```makefile
void	print_cmd(void *elem);
```

<br><br>


```makefile
void	print_redir(void *elem);
```

<br><br>