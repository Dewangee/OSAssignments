#include <string.h>
#include <limits.h>     
#include <sys/stat.h> 
#include <sys/types.h>  
#include <errno.h>

int main(int argc, char *argv[])
{	
	char current[256];
	strcat(current,argv[0]);
	if (argc==3)
	{
			strcat(current,argv[2]);
			printf("%s\n",current );
		
	if (mkdir(current, S_IRWXU)==-1)
	{
		printf("Directory either exits or path specified is incorrect.");
	}
	else
	{
		printf("Directory created succcessfully.");	
	}
	}


	return 0;
}

