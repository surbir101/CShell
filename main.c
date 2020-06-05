// history
// sig function
// list all backgrund jobs in the following order <pid><command name>, in order of creation
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>



#define BUFFER_SIZE 50
char buffer[BUFFER_SIZE] ;
int pidArray[30] ;
int count =0;
char *pidCommands[30];
char *args[100];

void handle_sigint()
{
	write(STDOUT_FILENO,buffer,strlen(buffer));
	exit(0);

}

int setup(int background)
{
  int num_args= 0 ;
  char  line[100];

  gets(line);
    if(strcmp(line, "bye") == 0)
      exit(0);

    args[num_args] = strtok(line, " ");
    while (args[num_args] != NULL)
      {
      num_args++;
      args[num_args] = strtok(NULL, " ");
      }
    num_args--;

	if(strcmp(args[num_args], "&") == 0)
  {
		background = 1;

    // save command name and pid
  }

    printf("About to exec the following: ");
    for (int i = 0; i <= num_args; i++)
      {
      printf(args[i]);
      printf(" ");
      }
    printf("\n");
    printf("\n");
    return background ;

}

 int main (int argc, char *argv[])
  {
	struct sigaction handler;
	handler.sa_handler = handle_sigint;
	sigaction(SIGINT,&handler,NULL);

	strcpy(buffer,"We have caught sigint signal\n");




  int   i;
  int   waitpid;
  pid_t  childpid;
  int   status;
  int background;

  while (1)
    {
    background = 0 ;
    printf("tish>> ");
    background = setup(background);

   childpid = fork();
    if (childpid == 0)
     {

      execvp(args[0], args);
      perror("Exec failed: ");
      exit(0);

      }
     else
     {
       if(background == 0)
       {

      	waitpid = wait(&status);
           printf("parent");
          printf("\n");
        }
        else
        {
           pidArray[count] = childpid;
           pidCommands[count] = args[0];

           count ++ ;

          if(count == 2)
           {
             for(int i =0; i<count; i++)
              {
                 printf("The process id: %d\n",pidArray[i]);
                 printf(" ");
                   printf("Value of names[%d] = %s\n", i, pidCommands[i]);
                 printf("\n");


              }

   }

           }


        }

     }


  return 0;
 }
