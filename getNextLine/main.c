/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartine <hmartine@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:13:57 by hmartine          #+#    #+#             */
/*   Updated: 2022/06/19 16:41:01 by hmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
//	int		cont;

//	char	*line;

	char	*line1;
	char	*line2;
	char	*line3;
	char	*line4;

//	cont = 1;
	fd = open("test1.txt", O_RDONLY);

	line1 = get_next_line(fd);
	printf("line1: %s", line1);
	line2 = get_next_line(fd);
	printf("line2: %s", line2);
	line3 = get_next_line(fd);
	printf("line3: %s", line3);
	line4 = get_next_line(fd);
	printf("line4: %s", line4);
/*
	while (cont < 5)
	{
		line = get_next_line(fd);
		if (line)
			printf("Linea %i es:%s\n", cont, line);
		else
		{
			break ;
		}
		cont++;
	}
*/
	close(fd);
	return (0);
}
