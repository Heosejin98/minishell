/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:19:16 by seheo             #+#    #+#             */
/*   Updated: 2022/10/02 18:13:03 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTIL_H
# define ENV_UTIL_H

typedef struct s_env
{
	char	**envp;
	char	**env_var;
	char	*pwd;
	char	*oldpwd;
}			t_env;

//env_util
t_env	*init_envv(char **envp);
char	*get_env_var_value(t_env *envv, char *var);
//void	free_envv(t_env *envv);
//int		reinit_env_var(t_env *envv, char **argv);

//env_controller
void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);


#endif