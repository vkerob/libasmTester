#ifndef TESTER_H
# define TESTER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "../../include/libasm.h"

# define RED	"\033[0;31m"
# define BLUE	"\033[0;34m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

void	test_ft_read();
void	test_ft_strcmp();
void	test_ft_strcpy();
void	test_ft_strdup();
void	test_ft_strlen();
void	test_ft_write();

#endif