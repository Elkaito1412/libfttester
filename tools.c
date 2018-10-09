/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiri <abiri@1337.MA>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:40:47 by abiri             #+#    #+#             */
/*   Updated: 2018/10/07 18:21:36 by abiri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "header.h"

void	startc(int color)
{
	printf("\e[%dm", color);
}

void	endc(void)
{
	startc(39);
}