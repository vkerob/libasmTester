#include "../../include/tester.h"


static void	basic_string_test()
{

	const char	*str = "0123456789";
	char		*dup = ft_strdup(str);
	char		*dup_real = strdup(str);

	printf("Testing with string: \"%s\"\n", str);
	if (strcmp(dup, dup_real) != 0 || dup == str)
		printf("%sError: ft_strdup(\"%s\") returned \"%s\", expected \"%s\"%s\n", RED, str, dup, dup_real, RESET);
	else
		printf("%sTest passed for a normal string%s\n", GREEN, RESET);

	free(dup);
	free(dup_real);

}

static void	empty_string_test()
{

	const char	*str = "";
	char		*dup = ft_strdup(str);
	char		*dup_real = strdup(str);

	printf("Testing with string: \"%s\"\n", str);
	if (strcmp(dup, dup_real) != 0 || dup == str)
		printf("%sError: ft_strdup(\"%s\") returned \"%s\", expected \"%s\"%s\n", RED, str, dup, dup_real, RESET);
	else
		printf("%sTest passed for an empty string%s\n", GREEN, RESET);
	free(dup);
	free(dup_real);

}

static void	null_string_test()
{

	char		*dup;
	const char	*str = NULL;
	int			status;
	pid_t 		pid;

	printf("Testing with string: \"%s\"\n", str);
	pid = fork();
	if (pid == 0)
	{
		dup = ft_strdup(str);
		free(dup);
		exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			printf("%sError: ft_strdup(NULL) cause a segmentation fault%s\n", RED, RESET);
		else
			printf("%sTest passed for a NULL string%s\n", GREEN, RESET);
	}

}

void test_ft_strdup()
{

	printf("\n%sFT_STRDUP%s\n", BLUE, RESET);
	basic_string_test();
	empty_string_test();
	null_string_test();

}