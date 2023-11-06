#include <unistd.h>
 // printf
 #include <stdio.h>
 // atoi
 #include <stdlib.h>
 // exit
 #include <stdlib.h>

// check if sorted already
// check if int
// check if too big

// ft_split
void    ft_check_string(char *input)
{
    // check if all arguments are integers -2,147,483,648 to 2,147,483,647
    // or long int?
    int num;

    num = 0;
    // ACHTUNG FALSCHE ATOI
    num = atoi(input);
    printf("num: %d %d\n", num, atoi(input));

    // safe in malloc?
    // then send the ints to ft_check_int function

}
/*
void    ft_check_int(int *input)
{
    if (input == ' ')
        return ;
    else if (input >= -2147483648 && input <= 2147483647)
        return ;
    else
    {
        write(1, "Error\n", 6);
        exit ;
    }
}*/
void    ft_check_argv(char *input)
{
    write(1, "hello\n", 6);
    // check if all arguments are integers -2,147,483,648 to 2,147,483,647
    // or long int?

    // check for duplicates
    // check if bigger than int
}

int ft_push_swap(int argc, char **argv)
{
    int i;
    i = 0;
    // check if argc > 2 otherwise error
    if (argc < 2)
    {
        write(1, "Error\n", 6);
        exit ;
    }
    // check if argc == 2 meaning argument is like -> "1 2 -50"
    else if (argc == 2)
    {
        // ft_check_string(argv[1]);
            while (argv[i])
            {
                printf("argv[%d]: %s\n", i, argv[i]);
                i++;
            }
    }
    // else meaning argc > 2 meaning argument is like -> ./a.out 1 2 -50 ...
    else
    {
        // code here...
        // check if int
        if(ft_check_int() == 0)
        {
            write(1, "Error\n", 6);
            exit (1);
        }
        // check if too big
        // check if sorted already??
    }
    return (0);
}

int main(int argc, char **argv)
{
    ft_push_swap(argc, argv);
    return (0);
}
