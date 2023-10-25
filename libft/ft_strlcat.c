/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsirenko <hsirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:49:14 by hsirenko          #+#    #+#             */
/*   Updated: 2022/12/29 14:59:47 by hsirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size_destbuf)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dst;

	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	if (size_destbuf <= size_dst)
		return (size_src + size_destbuf);
	i = 0;
	while ((size_destbuf - 1) > (size_dst + i) && src[i] != '\0')
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_src + size_dst);
}

/*int main()
{
  char str[] = "tgsgery";
  char strDest[] = "";
  int r = ft_strlcat(strDest, str, 4);
    
  
  printf("%s\n", strDest);
  printf("%d", r);
}*/