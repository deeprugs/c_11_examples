// CPP program to illustrate dup2()  
#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <assert.h>

int main()
{
	int fd = open("out.txt",O_WRONLY|O_APPEND);

	if (fd<0)
	{
		// I was under the impression that 
		// open() would create a file if it does not exist.
		// Doesn't seem like that. So create it using the 
		// creat system call if tthis does not exist.
		printf("Could not open the file\n");

		fd = creat("out.txt", S_IRUSR | S_IWUSR);
		if (fd<0)
		{
			printf("creat error \n");
			assert(0);
		}
	}
		
	
	// This prints on the console.
	printf("Hello World\n");

	// Use dup2 to redirect the printf output into a text file.
	// This dup2 call closes the STDOUT_FILENO because it is open.
	// Now the system calls which were referring to STDOUT_FILENO 
	// will start referring to fd. Hence the output of the printf 
	// gets redirected to fd!
	int rc = dup2(fd, STDOUT_FILENO);
	if ( rc<0)
		assert(0);

	// REDIRECTED printf
	printf("This line goes into text file because stdout file output gets redirected into the fd\n");

	return 0;
}
