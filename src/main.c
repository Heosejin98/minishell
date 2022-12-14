/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:57:10 by seheo             #+#    #+#             */
/*   Updated: 2022/10/02 20:39:14 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_env	*envv;

	signals_handler();
	envv = init_envv(envp);
	if (!envv)
		return (EXIT_FAILURE);
	set_envp(envp); //static 변수로 저장 get으로 언제든지 부를 수 있도록
	set_envv(envv);
	
}
