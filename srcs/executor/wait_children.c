/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicmarti <vicmarti@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:41:08 by vicmarti          #+#    #+#             */
/*   Updated: 2021/11/08 16:06:50 by vicmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stddef.h> //NULL TODO

		//TODO Do we need to do extra work here?
		//TODO How do we get the exit status of the last pid
void	wait_children(size_t cmd_num)
{
	while (cmd_num > 0)
	{
		wait(NULL);
		cmd_num--;
	}
}
