# include "../../include/tester.h"


static void equal_strings_test(const char *s1, const char *s2)
{

	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	if (ft_strcmp(s1, s2) != strcmp(s1, s2))
		printf("%sError: ft_strcmp(\"%s\", \"%s\") returned %d, expected %d%s\n", RED, s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2), RESET);
	else
		printf("%sTest passed for equal strings%s\n", GREEN, RESET);

}

static void s1_greater_than_s2_test(const char *s1)
{

	const char	*s2 = "012345678";
	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	if (ft_strcmp(s1, s2) != strcmp(s1, s2))
		printf("%sError: ft_strcmp(\"%s\", \"%s\") returned %d, expected %d%s\n", RED, s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2), RESET);
	else
		printf("%sTest passed for s1 greater than s2%s\n", GREEN, RESET);

}

static void	s2_greater_than_s1_test(const char *s2)
{

	const char	*s1 = "012345678";
	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	if (ft_strcmp(s1, s2) != strcmp(s1, s2))
		printf("%sError: ft_strcmp(\"%s\", \"%s\") returned %d, expected %d%s\n", RED, s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2), RESET);
	else
		printf("%sTest passed for s1 less than s2%s\n", GREEN, RESET);

}

static void empty_strings_test()
{

	const char	*s1 = "";
	const char	*s2 = "";

	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	if (ft_strcmp(s1, s2) != strcmp(s1, s2))
		printf("%sError: ft_strcmp(\"%s\", \"%s\") returned %d, expected %d%s\n", RED, s1, s2, ft_strcmp(s1, s2), strcmp(s1, s2), RESET);
	else
		printf("%sTest passed for empty strings%s\n", GREEN, RESET);

}

static void null_strings_test()
{
	const char	*s1 = NULL;
	const char	*s2 = NULL;
	int			status;
	pid_t		pid;

	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	pid = fork();
	if (pid == 0)
	{
		if (ft_strcmp(s1, s2) != strcmp(s1, s2))
			exit(1);
		else
			exit(0);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
			printf("%sError: ft_strcmp(\"%s\", \"%s\") did not cause a segmentation fault%s\n", RED, s1, s2, RESET);
		} else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
			printf("%sTest passed for NULL strings (caused a segmentation fault as expected at the comparaison)%s\n", GREEN, RESET);
		} else {
			printf("%sTest passed for NULL strings%s\n", GREEN, RESET);
		}
	}
}

static void s1_null_test(const char *s2)
{

	const char	*s1 = NULL;
	int			status;
	pid_t		pid;

	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	pid = fork();
	if (pid == 0)
	{
		ft_strcmp(s1, s2);
		exit(0);
	}
	else 
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			printf("%sTest passed for NULL s1 (caused a segmentation fault as expected)%s\n", GREEN, RESET);
		else
			printf("%sError: ft_strcmp(NULL, \"%s\") did not cause a segmentation fault%s\n", RED, s2, RESET);
	}

}

static void s2_null_test(const char *s1)
{

	const char	*s2 = NULL;

	printf("Testing with strings: \"%s\", \"%s\"\n", s1, s2);
	pid_t		pid = fork();
	if (pid == 0)
	{
		ft_strcmp(s1, s2);
		exit(0);
	}
	else 
	{
		int status;
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			printf("%sTest passed for NULL s2 (caused a segmentation fault as expected)%s\n", GREEN, RESET);
		else
			printf("%sError: ft_strcmp(\"%s\", NULL) did not cause a segmentation fault%s\n", RED, s1, RESET);
	}
}

void test_ft_strcmp()
{

	const char	*s1 = "0123456789";
	const char	*s2 = "0123456789";

	printf("\n%sFT_STRCMP%s\n", BLUE, RESET);
	
	equal_strings_test(s1, s2);
	s1_greater_than_s2_test(s1);
	s2_greater_than_s1_test(s2);
	empty_strings_test();
	null_strings_test();
	s1_null_test(s2);
	s2_null_test(s1);

}