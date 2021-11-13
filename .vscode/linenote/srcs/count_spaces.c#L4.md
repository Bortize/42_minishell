
La finalidad de esta función es recorrer todos los espacios en blanco y tabulaciones que hay entre token y token.
Devuelve la longitud de iteraciones recorridas.

---

```c
size_t	count_spaces(char *line)
```
Recible el trozo de línea leído
<br><br>

```c
char	*end;
```
Guarda la copia de la cadena desde el punto en el que se encuentra el iterador hasta el final de la linea.
<br><br>


```c
char	aux;
```
Guarda el valor del carácter de la línea donde se encuentra el iterador.
<br><br>


```c
aux = *line;
```
aux va a contener el primer valor de la dirección a la que apunta *line
<br><br>


```c
end = line;
```
Asigna el valor de linea a end. A medida que avance el iterador la cadena ira acortando los caracteres del principio.
<br><br>


```c
while (aux && is_space(aux))
{
	end++;
	aux = *end;
}
```
La primera vez no va a entrar aqui porque la función ft_strtrim elimina los espacios del principio y del final, pero entre token y token habra espacios y una vez localizado el primer token va a necesitar llegar al segundo obviando los espacios y tabulaciones que tiene entre medias. Para eso sirve esta funcion, para poder iterar sin tener presente todos aquellos espacios y tabulaciones entre token y token.
<br><br>


```c
return (end - line);
```
Devuelve el número de iteraciones que ha hecho de espacios y tabulaciones, para poder sumarselas al contador y pegar un gran salto.
<br><br>
