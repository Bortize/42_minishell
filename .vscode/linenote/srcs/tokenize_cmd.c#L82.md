
```c
void	tokenize_cmd(char *cmd_txt, t_cmd *cmd_node)
```
Esta función recibe como primer parámetro el trozo de línea leído del prompt hasta que llega al final o encuentra un pipe y como segundo parámetro un puntero a un nodo (con la idea entiendo, de crear una lista) el cual se reservo memoría.


```c
t_behavior	token_behavior;
```
Declara una estructura de variables enum
<br><br>



```c
size_t		token_len;
```
Una variable que por su descripción, parece que es para medir la longitud de los tokens.
<br><br>



```c
cmd_txt += count_spaces(cmd_txt);
```
Recibe por parámetro el trozo de línea leído.
<br><br>



```c
if (*cmd_txt == 0)
		return ;
```

<br><br>



```c
cmd_txt += read_token_behavior(cmd_txt, &token_behavior);
```

<br><br>



```c
md_txt += count_spaces(cmd_txt);
```

<br><br>



```c
token_len = 0;
```

<br><br>


```c
while (cmd_txt[token_len] && !is_delimiter(cmd_txt[token_len]))
	{
		if (cmd_txt[token_len] == '\'' || cmd_txt[token_len] == '\"')
			token_len += count_until_repeat(cmd_txt + token_len);
		else
			token_len++;
	}
```

<br><br>


```c
save_token(cmd_node, ft_strndup(cmd_txt, token_len), token_behavior);
```

<br><br>



```c
return (tokenize_cmd(cmd_txt + token_len, cmd_node));
```

<br><br>
