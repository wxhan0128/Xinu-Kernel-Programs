#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

#define CMD_SUM 4
#define BUFFER_SIZE 20
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[])
{
	int i;
	char cmd_path[BUFFER_SIZE] = "/bin/";
	char *cmd_str[CMD_SUM] = {"date", "uname", "hostname", "echo"}; /* all cmds */
	char write_args[BUFFER_SIZE];
	char read_args[BUFFER_SIZE];

	int fd[2];
	pid_t pid;
	
	for(i = 0; i < strlen(*cmd_str); i++) /* check input cmds */
	{
		if(strcmp(cmd_str[i], argv[1]) == 0)
		{
			break;
		}
		else
		{
			if(i != (strlen(*cmd_str) - 1))
			{
				continue;
			}
			else
			{
				fprintf(stderr, "%s: arguments invalid\n", argv[0]);
				return 1;
			}
		}
	}

	if (argc < 2)
	{
		fprintf(stderr, "%s: need a argument\n", argv[0]);
		return 1;
	}
	else if (argc ==2)
	{
		strcpy(write_args, argv[1]);

		if (pipe(fd) == -1) /* pipe error */
		{
			fprintf(stderr, "Pipe call failed");
			return 1;
		}

		pid = fork();

		if (pid < 0) /* fork error */
		{
			fprintf(stderr, "Fork call failed");
			return 1;
		}
		else if (pid == 0) /* child process */
		{
			/* get process id */
			printf("Child PID = %d\n", getpid());

			/* close the unused end of the pipe */
			close(fd[WRITE_END]);

			/* read from the pipe */
			read(fd[READ_END], read_args, BUFFER_SIZE);
			strcat(cmd_path, read_args); /* update cmd path */

			/* cmd judge */
			if (strcmp(read_args, "echo") == 0)
			{
				execl(cmd_path, read_args, "Hello World!", NULL);
			}
			else
			{
				execl(cmd_path, read_args, NULL);
			}

			/* close the write end of the pipe */
			close(fd[READ_END]);

			_exit(1);
		}
		else /* parent process */
		{
			/* close the unused end of the pipe */
			close(fd[READ_END]);

			/* write to the pipe */
			write(fd[WRITE_END], write_args, strlen(write_args) + 1);

			/* close the write end of the pipe */
			close(fd[WRITE_END]);

			wait(NULL);
			/* get process id */
			printf("Parent PID = %d\n", getpid());
		}

		return 0;
	}
	else
	{
		fprintf(stderr, "%s: too many arguments\n", argv[0]);
		return 1;
	}
}