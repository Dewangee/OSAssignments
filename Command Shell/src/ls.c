
#undef _POSIX_SOURCE
#define _POSIX_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include<sys/stat.h>
#include<dirent.h> 
#include<time.h>

int main(int argc , char *argv[])
{
    char *curr_dir ;
    DIR *dp , *dp1, *dp2;
    struct dirent *dptr ;
	struct dirent *dptr1, *dptr2 ;
    unsigned int count,count1, count2 ;
    
    if(argv[0] == NULL)
    {
        printf("Working directory not found.\n");
        return -1;
    }
	dp = opendir(argv[0]);
    if(dp == NULL)
    {
        printf("Working directory could not be found.\n");
        return -1;
    }
	//ls 
	if (argc==2)
	{
		for(count = 0; (dptr = readdir(dp)) != NULL ; count++)
    {
        printf("%s\n",dptr->d_name);
    }   
	}
     
    if (argc==3)
    {
    	if (strcmp(argv[2],"-Q")==0)
    	{
    		//ls -Q : Enclosing entries in quotes
    	dp1 = opendir(argv[0]);
    	for(count1 = 0; (dptr1 = readdir(dp1)) != NULL ; count1++)
    	{
        printf("'%s'\n",dptr1->d_name);
    	}   
		}
		
		else if (strcmp(argv[2],"-l")==0)
		{
			//ls -l : Details of entries 
    	dp2 = opendir(argv[0]);
    
   		 for(count1 = 0; (dptr2 = readdir(dp2)) != NULL ; count2++)
    	{
        		printf("%s\t",dptr2->d_name);
            
           
            	struct stat check;
            	stat (dptr2->d_name,&check);
                printf("\t%d",check.st_size);
                printf("\t%s\n",ctime(&check.st_ctime));
            
   		 }
    
  
		}
		
	
	}
    
    
    
    
    
    return 0;
}









