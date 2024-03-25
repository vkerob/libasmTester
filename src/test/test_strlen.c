#include "../../include/tester.h"

static void	basic_string_test()
{

	const char	*str = "qwertyuiop";

	printf("Testing with string: \"%s\"\n", str);
	if (ft_strlen(str) != strlen(str))
		printf("%sError: ft_strlen(\"%s\") returned %zu, expected %zu%s\n", RED, str, ft_strlen(str), strlen(str), RESET);
	else
		printf("%sTest passed for a normal string%s\n", GREEN, RESET);

}

static void	empty_string_test()
{

	const char	*str = "";

	printf("Testing with string: \"%s\"\n", str);
	if (ft_strlen(str) != strlen(str))
		printf("%sError: ft_strlen(\"%s\") returned %zu, expected %zu%s\n", RED, str, ft_strlen(str), strlen(str), RESET);
	else
		printf("%sTest passed for an empty string%s\n", GREEN, RESET);

}

static void	null_string_test()
{

	const char	*str = NULL;
	pid_t		pid = fork();

	printf("Testing with string: \"%s\"\n", str);
	if (pid == 0) {
		ft_strlen(str);
		exit(0);
	} else {
		int status;
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			printf("%sTest passed for a NULL string (caused a segmentation fault as expected)%s\n", GREEN, RESET);
		else
			printf("%sError: ft_strlen(NULL) did not cause a segmentation fault%s\n", RED, RESET);
	}

}

void test_ft_strlen() 
{

	printf("\n%sFT_STRLEN%s\n", BLUE, RESET);
	
	basic_string_test();
	empty_string_test();
	null_string_test();

}