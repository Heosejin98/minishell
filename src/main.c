/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:57:10 by seheo             #+#    #+#             */
/*   Updated: 2022/10/01 12:33:43 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;

	signals_handler();
	(void) envp;
	if (!argc && !argv)
		return (0);
	while (1)
	{
		str = readline("minishell$> ");
		if (str == NULL)
			return (1);
	}
}
