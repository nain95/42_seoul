/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 05:26:21 by ijeon          #+#    #+#             */
/*   Updated: 2021/10/25 05:26:23 by ijeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_pwd(char **args)
{
	char	buf[1000];

	(void)args;
	getcwd(buf, 1000);
	printf("%s\n", buf);
	return (0);
}
