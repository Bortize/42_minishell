```c
size_t	count_spaces(char *line)
```
Recible el trozo de línea leído por parámetro
<br><br>

```c
char	*end;
```

<br><br>


```c
char	aux;
```

<br><br>


```c
aux = *line;
```
Le asigna la dirección del primero contenido de la línea a `aux`
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
