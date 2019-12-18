/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proj_iso.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tvarnier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/18 18:03:24 by tvarnier     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/18 18:03:57 by tvarnier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

float		iso_x(float x, float y, float z)
{
	float	xx;
	float	yy;

	(void)z;
	xx = (float)y * -1.0f;
	yy = (float)x * -1.0f;
	return (((sqrt(2.0f) / 2.0f) * (xx - yy)));
}

float		iso_y(float x, float y, float z)
{
	float	xx;
	float	yy;
	float	zz;

	xx = (float)x * -1.0f;
	yy = (float)y * -1.0f;
	zz = (float)z * -1.0f;
	return ((sqrt(2.0f / 3.0f) * zz) - ((1.0f / sqrt(6.0f)) * (xx + yy)));
}
