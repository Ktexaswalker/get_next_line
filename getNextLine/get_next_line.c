/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartine <hmartine@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:30:10 by hmartine          #+#    #+#             */
/*   Updated: 2022/06/19 19:54:44 by hmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include "get_next_line.h"

//Busco hasta el primer \n o \0 y monto un new_str, que solo contenga lo siguiente
char *limpiar_str(char *str)
{
	char	*new_str;
	int		num;
	int		cont;
	int		i;

	i = 0;
	num = 0;
	cont = 0;
	while (str[i])
	{
		if (cont > 0)
			cont++;
		if (str[i] == '\n')
			cont = 1;
		i++;
	}
	i++;
	new_str = (char *)malloc(sizeof(char) * (cont));
	while (str[ i - cont + num] != '\0')
	{
		new_str[num] = str[i - cont + num];
		num++;
	}
	return(new_str);
}

//Leo str hasta encontrar un \n o \0, lo pongo en la linea y devuelvo la linea
char *coger_linea_del_str(char *str)
{
	char	*linea;
	int		cont;
	int		num;

	cont = 0;
	num = 0;
	while (str[cont] != '\n')
		cont++;
	linea = (char *)malloc(sizeof(char) * (cont + 1));
	while (num <= cont)
	{
		linea[num] = str[num];
		num++;
	}
	return (linea);
}
//Leo y lleno el str hasta que encuentra \n o \0 y devuelve el str
char *read_file(int fd, char *str)
{
	char	*buffer;
	int		num_bits;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	num_bits = 1;
	//strchr busca en buffer '\n' y devuelve la cadena a partir de '\n'
	while (!ft_strchr(buffer, '\n') && (num_bits > 0))
	{
		num_bits = read(fd, buffer, BUFFER_SIZE);
		if (num_bits > 0)
		{
			buffer[num_bits] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	if (num_bits == -1)
		free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (!str)
		str = "";
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!str || !ft_strchr(str, '\n'))
		str =  read_file(fd, str);
	if(!str)
		return (NULL);
	line = coger_linea_del_str(str);
	if(!line)
		return (NULL);
	str = limpiar_str(str);
	return (line);
}
