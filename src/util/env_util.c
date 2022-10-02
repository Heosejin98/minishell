/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:49:12 by seheo             #+#    #+#             */
/*   Updated: 2022/10/02 18:12:28 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_util.h"

/*
* 	어따 쓰는지 모르겠음 없어도 돌아감
	아마 위치 바꾸면 사용되나?

static void	get_env_var_value_utils(t_env *envv, char *var, char **value, int i)
{
	if (ft_strlen(*value) == 0 && ft_strcmp(var, "PWD") == 0) //value \0 and var PWD 
	{
		if (ft_strlen(envv->pwd) == 0) // 
			*value = ft_calloc(1, sizeof (char));
		else
			*value = ft_strdup(envv->pwd); 
	}
	else if (ft_strlen(*value) == 0 && ft_strcmp(var, "OLDPWD") == 0) //NULL
	{
		if (ft_strlen(envv->oldpwd) == 0)
			*value = ft_calloc(1, sizeof (char));
		else
			*value = ft_strdup(envv->oldpwd);
	}
	else if (envv->env_var[i] == NULL && *value == NULL)
		*value = ft_calloc(1, sizeof(char));
}
*/

/*
* value 크기 만큼 초기화만
*/
char	*get_env_var_value(t_env *envv, char *var)
{
	int		i;
	char	*value;

	value = NULL;
	i = 0;
	while (envv && envv->env_var && envv->env_var[i] != NULL)
	{
		if (ft_strcmp(envv->env_var[i], var) == '=') // var(PWD or OLDPWD) 다음이 '=' 이면 
		{
			value = ft_strchr(envv->env_var[i++], '=') + 1; // = 다음 포인터 리턴
			if (ft_strlen(value) == 0) 
				value = ft_calloc(1, sizeof (char));
			else
				value = ft_strdup(value); // =이후로 초기화
			break ;
		}
		else if (ft_strcmp(var, envv->env_var[i++]) == 0) //PWD에 아무 경로가 없음
		{
			value = ft_calloc(1, sizeof (char));
			break ;
		}
	}
	//get_env_var_value_utils(envv, var, &value, i);
	return (value);
}

t_env	*init_envv(char **envp)
{
	t_env	*envv;

	envv = ft_calloc(1, sizeof(t_env));
	if (envv != NULL && envp != NULL && *envp != NULL)
	{
		envv->envp = envp;
		envv->env_var = ft_double_strdup(envp);
		envv->pwd = get_env_var_value(envv, "PWD");
		envv->oldpwd = get_env_var_value(envv, "OLDPWD");
		if (envv->env_var != NULL && envv->pwd != NULL && envv->oldpwd != NULL)
			return (envv);
	}
	return (NULL);
}