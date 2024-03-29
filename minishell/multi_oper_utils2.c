/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_oper_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:53:19 by ijeon             #+#    #+#             */
/*   Updated: 2022/01/14 17:53:20 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	operator_exec(t_list *list, t_shell *mini)
{
	t_list	*tlist;
	int		i;

	tlist = list;
	i = 0;
	mini->args = ((t_ops *)(list->content))->args;
	heredoc_chk(list, mini);
	while (tlist)
	{
		oper_norm(mini, &tlist, &i);
		if (((t_ops *)(tlist->content))->type == '|')
		{
			mini->pipe_chk = 1;
			break ;
		}
		tlist = tlist->next;
	}
	mini->i -= 2;
	if (i == -1)
		return ;
	if (tlist)
		operator_pipe(list, mini);
	else
		mini->rv = exec_cmp(mini, mini->args, list);
}
