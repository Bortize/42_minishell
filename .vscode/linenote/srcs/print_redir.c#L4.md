```c
t_redirect *redir;
```
Declara una nueva estructura del tipo `t_redirect` llamada `*redir`. Recordemos que esta structura contiene un puntero a char y una lista del tipo `t_behavior`.
<br><br>

```c
redir = (t_redirect *)elem;
```
Ahora va a castear el tipo del argumento del parametro de la funcion a `t_redirect` y se lo asigna a `redir`
<br><br>

```c
printf("%s as ->", redir->text);
```
Imprime el valor de la variable `text` de la nueva estructura que ha creado `*redir` de tipo `t_redirect`
<br><br>

```c
print_type(redir->type);
```
type contiene una lista de valores enumerados de solo lectura. Aquí, dependiendo del valor de type, se imprime una cosa u otra.
<br><br>