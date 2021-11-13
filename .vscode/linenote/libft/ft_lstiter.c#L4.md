Aplica la función que recibe por segundo parámetro, en el lugar donde se encuentre el iterador.

Por lo tanto, mientras no termine de recorrer la lista, lo que va a hacer es aplicar la funcion `f(lst->content)` a cada iterador y avanzar a la siguiente posición.

Ojo, cuando utilices esta función tienes que tener presente que aplica la funcion al contenido del nodo directamente, no al nodo en general. Aquí ya he tenido un error antes por no tener claro este concepto.