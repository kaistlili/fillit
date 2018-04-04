/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktlili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:39:23 by ktlili            #+#    #+#             */
/*   Updated: 2018/02/04 18:59:16 by ktlili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

/*unsigned short ***/
void	ft_solver(unsigned short tetri[26][13], int start, int end, int *square)
{
	int i;
	int j;

	if (start == end)
	{
		if (ft_square(&tetri[25][1]) <	 *square)
		{
			*square = ft_square(&tetri[25][1]);
			printf("solved! square is: %d!\n", *square);
			ft_printbitmap(&tetri[25][1]);
			printf("\n----------------------------\n");
			ft_printbyorder(tetri);
			
			j = 0;/*
			while(tetri[j][0] != 27)
			{
				ft_sortbitmap(&tetri[j][1]);
				j++;
			}*/
			/*ft_memcpy(&tetri[25][1], &tetri[0][1], 24);
			print all, copy current combination into mallocced array return pointer*/
		}
	}
	else
	{
		i = start;
		while (i <= end)
		{
			printf("swapping %d with %d\n", start, i);
			ft_swapbitmap(tetri[start], tetri[i]);
			
			if (start == 0)
			{
				ft_memcpy(&tetri[25][1], &tetri[start][1], 24);
				ft_sortbitmap(&tetri[25][1]);
			/*	printf("updating bitmap: %d\n***************\n", i);
				ft_printbitmap(&tetri[25][1]);
				ft_printbyorder(tetri);
				ft_putstr("********************\n");*/
			}
			/*ft_sortbitmap(&tetri[start+1][1]);
		*/	printf("calling placenext with index: %d\n", start + 1);
			
			ft_placenext(tetri, start + 1, end, square);
			
			ft_removetetri(&tetri[start][1], &tetri[25][1]);
		/*	printf("placenext return to solver sorting %d\n", start);
			ft_sortbitmap(&tetri[start][1]);*/
			ft_swapbitmap(tetri[start],tetri[i]);
			i++;
		}
	}
	
}



void	ft_sortnextline(unsigned short *tetri)
{
	while (ft_mask(tetri))
		ft_shiftleft(tetri);
	ft_shiftdown(tetri);
}


void ft_placenext(unsigned short tetri[26][13], int index, int end, int *square)
{
	int len;
	int line;
	unsigned short  temp;

	len = ft_length(&tetri[25][1]);	
	line = 0;
	while ((line <= len) & (line < 12))
	{
		while (ft_checkborder(&tetri[index][1]))
		{
			/*if (*square == 5)
			{*/
			printf("**************************\ntrying\n");
			ft_printbitmap(&tetri[index][1]);
			printf("\non bitmap\n");
			ft_printbitmap(&tetri[25][1]);
			printf("\n********************\n");
		/*	}
		*/	if (ft_validbitmap(&tetri[25][1], &tetri[index][1]))
			{
				ft_overlap(&tetri[index][1], &tetri[25][1]);
				if (ft_square(&tetri[25][1]) < *square)
				{
				
					printf("overlapped and solving index:%d\n", index + 1);
					ft_solver(tetri, index, end, square);		
				}
				
			/*	if (ft_square(&tetri[25][1]) < 5)
				{
					printf("removing:\n");
					ft_printbitmap(&tetri[index][1]);
					printf("\nfrom:\n");
					ft_printbitmap(&tetri[25][1]);
					ft_putstr("\n");
				} */
				
				ft_removetetri(&tetri[index][1], &tetri[25][1]);
			}
			ft_shiftright(&tetri[index][1]);
		}
		
		/*printf("incrementing line\n")	;
	*/	line++;
		ft_sortnextline(&tetri[index][1]);
	}
/*
	printf("placenext ended ! sorting %d\n", index);
	ft_printbitmap(&tetri[index][1]);
*/}	


/*
void	ft_placenext(unsigned int *bitmap, unsigned int *tetri, int line. int *square)
{
	
}*/


void    ft_placenexti_1(unsigned short tetri[26][13],int index, int end, int *square)
 {
     int temp;
     int len;
	 int pos;
     int order;
     int lastplace;
     unsigned short save;
 
     g_recursivecalls++; /*global variable to track recursive calls count*/
	 len = ft_length(&tetri[25][1]);
     pos = 0;
	 order = 0;
     lastplace = 2;
	 save = pos;
     while (save > 0)
     {
     	ft_shiftdown(&tetri[index][1]);
     	save--;
     }
	 while ((pos <= len) & (pos < 12))
     {
		/* printf("Main placenext loop on index %d\n", index);
         */         save =  tetri[25][pos + 1];
         lastplace = 2;
         while (((save != 0) | (lastplace >= 0)) & (ft_checkborder(&tetri[index][1])))
         {
            /* printf("trying tetri:%d line:%d position: %d square:%d -\n",index, pos,order, *square);
		 */	if ((index == 1) & (pos == 1) & (order == 0))
			{
				printf("*****\n*****\n*****\n");
				
				ft_printbitmap(&tetri[25][1]);
				printf("\n\n");
				
				ft_printbyorder(tetri);
				
				printf("\n******\n");
			}
			order++;
			/* if ((save & 32768) == 0) 
             {*/
                 /*ft_validbitmap(&tetri[25][1], &tetri[index][1]);*/
                 if (ft_validbitmap(&tetri[25][1], &tetri[index][1])) /*if valid overlap current tetri on bitmap and check square*/
                 {
				 	/*if ((index == 1) & (pos == 1) & (order == 0))
						printf("\nVALID PLACE\n");
                    */ ft_overlap(&tetri[index][1], &tetri[25][1]);
                     if (ft_square(&tetri[25][1]) < *square) /*if current square < prev    ious square explore further (recrusive call) */                    
					 {
					 	printf("overlapped and recursing to index %d\n", index);	
						ft_solver(tetri, index, end, square);
                      }				  
					 ft_removetetri(&tetri[index][1], &tetri[25][1]);
				 }
           /*  }*/
             save = save << 1;
             if (save == 0) /*if current line is 0 iterate one last time*/
                 lastplace--;
             ft_shiftright(&tetri[index][1]);
         }
		 order = 0;
	/*	 ft_putchar('\n');
      */ ft_sortbitmap(&tetri[index][1]);
         pos++;
     }
}

