/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 07:59:53 by ktlili            #+#    #+#             */
/*   Updated: 2018/04/15 08:03:01 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

void	ft_set_n_bit(unsigned short *line, int n)
{
	*line = *line | (1 << ft_abs(n - 15)); 
}

int	ft_tobitflag(char *buffer, unsigned short *flags)
{
	int line;
	int j;
	int count;
	
	line = 0;
	j = 1;
	count = 0;
	while (line < 4)
	{
		while ((j % 5) != 0)
		{
			if (buffer[j - 1] == '.')
				j++;
			else if (buffer[j - 1] == '#')
			{
				count++;
				ft_set_n_bit(&flags[line], j % 5);
				j++;
			}
			else
				return (-1);
		}
		if (buffer[j - 1] != '\n')
			return (-1);
		j++;
		line++;
	}
	if (count != 4) /* replace with function that determines if the tetri we just stored in flags is valid */
		return (-1);
	ft_sortbitmap(flags);
	return (1);
}

int	ft_readnext(char *buffer, unsigned short *tetrimino, int i)
{
	int j;

	j = 1;
	ft_bzero(tetrimino,17*2);
	tetrimino[0] = i + 65;
	if (ft_tobitflag(buffer, &tetrimino[1]) == -1)
		return (0);
	return (1);

}


int ft_parser(int fd, unsigned short tetri[28][17])
{
	char buffer[1024];
	int count;
	int i;

	count = read(fd, &buffer, 1024);
	if (count < 20)
		return (0);
	buffer[count] = '\0';
	i = 0;
	while (i < 26)
	{
		if (!(ft_readnext(buffer, tetri[i], i))) //change i to i + 65 on readnext
			return (0);
		if (buffer[20] == '\n')
			ft_memmove(&buffer[0], &buffer[21], count);
		else if (buffer[20] == '\0')
		{
			tetri[i + 1][0] = 27;
			return (1);
		}
		else
			return (0);
		i++;
	}
	return (1);
}

