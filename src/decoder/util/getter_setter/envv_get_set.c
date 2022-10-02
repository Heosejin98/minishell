/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_get_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:53:28 by toni              #+#    #+#             */
/*   Updated: 2022/10/02 18:19:36 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_util.h"

static t_env	*_get_envv(t_env *envv)
{
	static t_env	*static_envv = NULL;

	if (envv == NULL)
		return (static_envv);
	static_envv = envv;
	return (static_envv);
}

void	set_envv(t_env *envv)
{
	_get_envv(envv);
}

t_env	*get_envv(void)
{
	return (_get_envv(NULL));
}

char	**get_env_var(void)
{
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL)
		return (NULL);
	return (envv->env_var);
}
