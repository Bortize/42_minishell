```c
size_t	count_spaces(char *line)
```
Recible el trozo de línea leído
<br><br>

```c
char	*end;
```
Crea un puntero
<br><br>


```c
char	aux;
```
Crea una variable
<br><br>


```c
aux = *line;
```
aux va a contener el primer valor de la dirección a la que apunta *line
<br><br>


```c
end = line;
```

<br><br>


```c
while (aux && is_space(aux))
{
	end++;
	aux = *end;
}
```

<br><br>


```c
return (end - line);
```

<br><br>
