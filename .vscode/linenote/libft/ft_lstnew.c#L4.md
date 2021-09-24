Crea una nueva lista utilizando como argumento el valor que recibió `cmd` en calloc, que es lo que ocuparía una estructura del tipo `t_cmd`

<br>

---

<br>


```c
t_list	*node;
```
Crea una nueva estructura llamada `*node` de tipo `t_list`
<br><br>

```c
node = malloc(sizeof(t_list));
```
Reserva memoria del tamaño del tipo `t_list` y se lo asigna a node
<br><br>

```c
if (!node)
	return (NULL);
```
Si la asignación de memoría falla, devuelve NULL
<br><br>

```c
node->content = content;
```
Le asigna el valor que recibe la función por parámetro, al nodo de la lista.
<br><br>

```c
node->next = NULL;
```
Apunta el nodo de la lista a NULL para indicar que es el final.
<br><br>

```c
return (node);
```
Devuelve el nodo de la lista. En este caso solo tenemos un nodo. 
<br><br>