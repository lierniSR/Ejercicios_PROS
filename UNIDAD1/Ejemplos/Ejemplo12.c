//procesozombie.c

#include <unistd.h>
#include <stdio.h>
int var=22;

int main(void) 
{
	pid_t pidC;
	printf("*** proceso PID =%d comienza \n", getpid());
	pidC = fork();
	printf("proceso PID =%d, pidC =  %d  ejecutandose \n", getpid(), pidC);

	if(pidC > 0)
		{var=44; }
	else if(pidC ==0) {
   		 var=33; }
	else /*error*/
		{}
	while(1)
		{ 
    sleep(2);
    printf("proceso PID =%d, var = %d ejecutandose  \n", getpid(), var);
 }
	return 0;
}
