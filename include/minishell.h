/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seheo <seheo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 11:19:24 by seheo             #+#    #+#             */
/*   Updated: 2022/10/02 18:25:06 by seheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include "../lib/libft.h"
# include "error_util.h"
# include "env_util.h"
# include "decoder.h"
# include <readline/readline.h>
# include <readline/history.h>

void	signals_handler(void);

#endif