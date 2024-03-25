# include "../../include/tester.h"

static void	basic_string_test(const char *src, char *dest, char *dest_real)
{

	printf("Testing with source string: \"%s\"\n", src);
	if (strcmp(ft_strcpy(dest, src), strcpy(dest_real, src)) != 0) 
		printf("%sError: ft_strcpy(dest, \"%s\") returned %s, expected %s%s\n", RED, src, ft_strcpy(dest, src), strcpy(dest_real, src), RESET);
	 else 
		printf("%sTest passed for normal string%s\n", GREEN, RESET);

}

static void	empty_string_test(char *dest, char *dest_real)
{

	const char	*src = "";

	printf("Testing with source string: \"%s\"\n", src);
	if (strcmp(ft_strcpy(dest, src), strcpy(dest_real, src)) != 0)
		printf("%sError: ft_strcpy(dest, \"%s\") returned %s, expected %s%s\n", RED, src, ft_strcpy(dest, src), strcpy(dest_real, src), RESET);
	else 
		printf("%sTest passed for empty string%s\n", GREEN, RESET);

}

static void	null_string_test()
{

	const char	*src = NULL;
	int			status;
	pid_t 		pid;

	printf("Testing with source string: \"%s\"\n", src);
	pid = fork();
	if (pid == 0) 
	{
		ft_strcpy(NULL, src);
		exit(0);
	} 
	else 
	{
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV)
			printf("%sTest passed for NULL string (caused a segmentation fault as expected)%s\n", GREEN, RESET);
		else
			printf("%sError: ft_strcpy(dest, NULL) did not cause a segmentation fault%s\n", RED, RESET);
	}

}

static void	ptr_test(const char *src, char *dest, char *dest_real)
{

	printf("Testing if return value is pointer to dest\n");
	if (ft_strcpy(dest, src) != dest || strcpy(dest_real, src) != dest_real)
		printf("%sError: ft_strcpy(dest, \"%s\") did not return pointer to dest%s\n", RED, src, RESET);
	else
		printf("%sTest passed for return value being pointer to dest%s\n", GREEN, RESET);

}

void test_ft_strcpy() 
{

	char dest[50];
	char dest_real[50];
	const char *src = "0123456789";

	printf("\n%sFT_STRCPY%s\n", BLUE, RESET);
	
	basic_string_test(src, dest, dest_real);
	empty_string_test(dest, dest_real);
	null_string_test();
	ptr_test(src, dest, dest_real);

	printf("The test with a small destination needs to be done manually because the signal cannot be caught here\n");	//or maybe but I don't know how

}