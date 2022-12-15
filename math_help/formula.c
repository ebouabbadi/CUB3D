/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mes-sadk <mes-sadk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:04:25 by mes-sadk          #+#    #+#             */
/*   Updated: 2022/12/12 23:52:06 by mes-sadk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <treD_hndlr.h>

/*
	The function here, have one of the 
	best mathematics relations,
	because we create from it  some derived relation
	like the rectangle formula, and calculate the per cent method ...
*/

double	math_map(double x, t_mapp p)
{
	return ((x - p.min_in) * (p.maxto - p.min_to) \
	/ (p.maxin - p.min_in) + p.min_to);
}

double	math_chasles(int x1, int y1, int x2, int y2)
{
	return (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

double	max(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
