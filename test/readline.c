# incldue <readline>
int	main(void)
{
	char	*str;

	while (1)
	{
		// signal(SIGINT, sig_non_interactive_ctrl_c);
		str = readline("read> ");
		if (str == NULL)
			break ;
		// printf("str: [%s]\n", str);
		free(str);
	}
}