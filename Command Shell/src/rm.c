#include <stdio.h>
#include <dirent.h>
int  main(int argc, char *argv[])
{
        struct dirent *d;
        DIR *dir;
        char buf[256];
        dir = opendir(argv[0]);
        if (argc==2)
        {
        while(d = readdir(dir))
        {       
        		
                sprintf(buf, "%s/%s", argv[0], d->d_name);
                if (unlink(buf)==0)
                {
                	printf("Deleted Successfully.\n");
				}
				else 
				{
					printf("Could not be deleted.\n");
				}
                
        }
	 }
        else if (argc==3)
        {
        	if (unlink(argv[2])==0)
                {
                	printf("Deleted Successfully.\n");
				}
				else 
				{
					printf("Could not be deleted.\n");
				}
		}
		
        
        return 0;

}
