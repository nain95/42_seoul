/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijeon <ijeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 03:10:37 by ijeon             #+#    #+#             */
/*   Updated: 2020/11/26 03:10:52 by ijeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void *ft_print_memory(void *addr, unsigned int size);

int	main(void)
{
	char test[100] = "asduhfa ashjad a\t\tadajsdjw \tadwio";
	ft_print_memory(test, 100);
}
