```C
ptr = env;
```
Asigno la dirección de `env` a `ptr` para no perder al referencia cuando tenga que liberar memoría.
<br>

```c
nv_count = 0;
while (*ptr != NULL)
{
	env_count++;
	printf("%i\n", env_count);
	ptr++;
}
```
Cuenta el número de líneas que aparece cuando ejecutamos el comando `env`. Para ello, va a ir avanzado sobre ptr que recordemos que apunta a la matriz de env y vamos a ir sumando cada posiciones que avanza.
Necesitamos este contador para luego reservar memoria para la copia de la matriz.

```c
filas = (char **)malloc(env_count * sizeof(char *));
```
Reserva memoria para la matriz. Aquí hacemos uso del número de lineas que ha contado.

```c
ptr = env;
i = 0;
while(i != env_count)
{
	*filas = strdup(*ptr);
	printf("%s\n", *filas);
	ptr++;
	filas++;
	i++;
}
```
Reestablece el puntero ptr a la primera dirección de env para volver a recorrerlo ya que habiamos perdido la referencia antes. 

Ahora, con la funcion strdup, vamos a hacer una copia de cada variable de entorno en la nueva matriz `filas`. Utilizamos un contador y decimos que hasta que no sea igual que las lineas que hemos leido antes, que no salga del buble, así, en cada vuelta va copiando cada línea y avanzando a la siguiente.

En cada vuelta, avanza una posicion `ptr` que es el puntero de las variables de entorno, avanza tambien `filas` para rellenar cada array y avanzamos el contador `i` del while