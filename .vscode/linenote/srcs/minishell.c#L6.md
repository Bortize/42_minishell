

`line = readline("minishell> "); ` -> Esta función lee lo que introduce el usuario en la terminal y se lo asigna a line.

`add_history(line)` -> Añade el historial de los comandos para que podamos verlos haciendo flecha hacia arriba.

`cmd_lst = NULL;` -> Va a ser una lista que vamos a inicializar en NULL

`split_in_cmds(line, &cmd_lst);` -> divide en una lista de comandos lo que va a encontrar en la linea que recibe del usuario.