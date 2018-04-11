#include <stdio.h>
#include "libft.h"

void	ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}



void	heappermute(char *str, int size, int n)
{
	int i;

	if (size == 1)
	{
		printf("%s",str);
		return;
	}
	i = 0;
	while (i < size)
	{
		heappermute(str, size - 1, n);

		if (size % 2 == 1)
			ft_swap(&str[0], &str[size-1]);
		else
			ft_swap(&str[i],&str[size-1]);
		i++;
	}
}


void	permute(char *str, int start, int end)
{
	int i;
	int printer;
	int comb;

	comb = 0;
	if (start == end)
	{	
		printf("%s", str);
		/*comb++;*/
	}
	else
	{
		i = start;
		while (i <= end)
		{
			/*printer = start;
			while (printer >= 0)
			{
				ft_putchar('-');
				printer--;
			}*/
		/*	printf("permuting %d with %d\n",start, i);*/
			
			
				ft_swap((str+start), (str+i));
				permute(str, start+1, end);
		/*		printf("|i:%d start:%d end:%d|backtrack",i, start, end);
		*/	
		/*		printf("|Backtrack: permuting back %d with %d\n",start, i);
			*/	ft_swap((str+start), (str+i));
			
			i++;
		}
	}

}

#include <time.h>

int main(int ac, char **av)
{
	int n;
	clock_t t;
	double time_taken;

	n = ft_strlen(av[1]);
	t = clock();
	permute(av[1], 0, n - 1);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nnaive permute took %f seconds\n", time_taken);
	t = clock();
	heappermute(av[1], n, n);
	t = clock() - t;
	time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("\nheap permute took %f seconds\n", time_taken);


}
