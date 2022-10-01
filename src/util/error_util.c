/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:02:50 by seheo             #+#    #+#             */
/*   Updated: 2022/10/01 14:42:55 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "error_util.h"

static int	_get_err_code(int err_code, bool set_err_code)
{
	static int	static_err_code = 0;

	if (set_err_code)
		static_err_code = err_code;
	return (static_err_code);
}

void	set_err_code(int err_code)
{
	static bool	last_cmd_ctrl_c = false;

	if (last_cmd_ctrl_c)
	{
		last_cmd_ctrl_c = false;
		return ;
	}
	if (err_code == 130)
		last_cmd_ctrl_c = true;
	_get_err_code(err_code, true);
}

int	get_err_code(void)
{
	return (_get_err_code(0, false));
}
