#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void put_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

int cd(char **av, int i)
{
	if (i != 2)
	{
		put_error("error: cd: bad arguments\n");
		return 1;
	}
	if (chdir(av[1]) == -1)
	{
		put_error("error: cannot change directory to ");
		put_error(av[1]);
		put_error("\n");
		return 1;
	}
	return 0;
}

void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0] == -1 || close(fd[1]) == -1)))
		put_error("error: fatal\n"), exit(1);
}

int exec_cmd(char **av, int i, char **env)
{
	int status, pid, fd[2];
	int has_pipe = av[i] && !strcmp(av[i], "|");

	if (!has_pipe && !strcmp(*av, "cd"))
		return cd(av, i);
	if (has_pipe && pipe(fd) == -1)
		put_error("error: fatal\n"), exit(1);
	pid = fork();
	if (pid == -1)
		put_error("error: fatal\n"), exit(1);
	if (!pid)
	{
		av[i] = 0;
		set_pipe(has_pipe, fd, 1);
		if (!strcmp(*av, "cd"))
			exit(cd(av, i));
		execve(*av, av, env);
		put_error("error: cannot execute ");
		put_error(*av);
		put_error("\n");
		exit(1);
	}
	waitpid(pid, &status, 0);
	set_pipe(has_pipe, fd, 0);
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **av, char **env)
{
	int status = 0;
	int i = 0;

	while (av[i])
	{
		av += i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (i)
			status = exec_cmd(av, i, env);
	}
	return (status);
}