cmake_minimum_required(VERSION 3.22)
project(radix_push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(radix_push_swap push_swap.h libft/libft.h libft/ft_putstr_fd.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_strlen.c src/main.c src/utils.c src/utils2.c src/utils3.c src/stacks.c src/stacks2.c src/commands.c src/commands2.c src/commands3.c src/sort_small.c src/sort_large.c libft/ft_strncmp.c libft/ft_memcmp.c src/long_atoi.c src/parse.c src/sort5.c)
