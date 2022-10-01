/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:19:16 by seheo             #+#    #+#             */
/*   Updated: 2022/10/01 12:21:51 by seheo            ###   ########.fr       */
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

#endif