/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:05:29 by chbuerge          #+#    #+#             */
/*   Updated: 2023/11/06 11:13:11 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// atoi
#include <stdlib.h>
// write
#include <unistd.h>
// printf
#include <stdio.h>
#include <string.h>
// lets check the input

// argc > 2 means the arguments are multiple chars
    // atoi


//check for duplicates within the argument values____________________________________________________________
// **arg because I need to have all args to compare to eachother
int check_for_dup(char **arg)
{
    int i;
    int j;

    i = 1;
    while(arg[i])
    {
        j = 1;
            while (arg[j])
            {
                // WRONG COMPARE FUNCTION; NOT ALLOWED
                if (i != j && strcmp(arg[i], arg[j]) == 0)
                {
                    write(1, "Error dup\n", 10);
                    return (0);
                }
                else
					//printf("i: %d\n", i);
					//printf("j: %d\n", j);
                    j++;
            }
        i++;
    }
    //printf("%s\n", arg[1]);
    return (0);
}
//___________________________________________________________________________________________________________


//check if all argument values are integer___________________________________________________________________

int is_int(char *arg)
{
    int i;

    i = 0;
    if (arg[i] == '-' && arg[i + 1] || arg[i] == '+' && arg[i + 1])
    {
        i++;
    }
    while(arg[i])
    {
                if (arg[i] < '0' || arg[i] > '9')
                {
                    write (1, "Error\n", 6);
                    // why does it keep running after this?! and does not exit not with return nor exit or does it??
                    // had to add (1);
                    exit (1);
                }
            //printf("%c \n", arg[i]);
            i++;
    }
    return (0);
}

//check if already sorted___________________________________________________________________________

int	is_sorted(char **arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i + 1])
	{
		// NOT ALLOWED FUNCTION
		// meaning its not sorted
		if (strcmp(arg[i], arg[i + 1]) > 0)
// stop here how??
			exit (1);
			// meaning its sorted
		else
			i++;
			printf("arg[i]: %s\n", arg[i]);
			printf("i: %d\n", i);
	}
	return (0);
}


//___________________________________________________________________________





int main(int argc, char **argv)
{
    int i;
    //int number;

    i = 1;
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
    else if (argc > 2)
    {
        while (argv[i])
        {
           // number = atoi(argv[i]);
            is_int(argv[i]);

           // printf("%d \n", number);
            // printf("%s \n", argv[i]);

            i++;
        }
        check_for_dup(argv);
		is_sorted(argv);
    }

    /*jamie says i dont need this?!
    Théo gaslights but is wrong
    else if (argc == 2)
        while (argv[i])
        {
            is_int_string(argv[i]);
            i++;
        }
    */
    return (0);
}







// jamie says I dont need this??________________________________________________________________
/*
int is_int_string(char *arg)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (arg[i] == '-' || arg[i] == '+' || arg[i] == ' ' || (arg[i] >= '0' && arg[i] <= '9'))
        {
            write(1, &arg[i], 1);
            write(1, "\n", 1);
            i++;
        }
        else
            write(1, "nope\n", 5);
            return (0);
    }
    return (1);
}
*/
//___________________________________________________________________________
