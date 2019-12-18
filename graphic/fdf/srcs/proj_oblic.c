/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj_oblic.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 18:02:27 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 22:51:59 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

float		oblic_x(float x, float y, float z)
{
	float	xx;
	float	zz;

	(void)y;
	xx = (float)x;
	zz = (float)z;
	return (xx + (1.0f / 2.0f) * zz * cos(M_PI * 270.0f / 180.0f));
}

float		oblic_y(float x, float y, float z)
{
	float	yy;
	float	zz;

	(void)x;
	yy = (float)y;
	zz = (float)z;
	return (yy + (1.0f / 2.0f) * zz * sin(M_PI * 270.0f / 180.0f));
}
