#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	
	char str[200];
   	strcpy(str, argv[2]);
   	
   	char cwd[256];
	getcwd(cwd, sizeof(cwd));
	
   	char newString[10][10]={0};
   	
   	int j=0,ctr=0,i=0;
   	for (i=0;i<(strlen(str)); i++)
   	{
   		if(str[i]==' '||str[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  
            j=0;    
        }
        else
        {
            newString[ctr][j]=str[i];
            j++;
        }
	}
	

	int k=0;
	int flag = 0;
	for (k=0; k<=ctr && flag==0;k++)
	{
		
		if (strcmp(newString[k],">")==0)
		{
			FILE *fpp;
   			fpp=fopen(newString[k+1],"w");
   			if(fpp==NULL)
	   		{
			printf("Error");
			exit(1);
			}			
			char asd[200];
			int j=0;
			for (j=0; j<k ;j++)
			{
				FILE *fptr1;
   				fptr1 = fopen(newString[j],"r");

   				if (fptr1 == NULL)
		    	{
       			printf("Error in opening %s",newString[j]);
       			exit(1);
   				}	

				char ch = fgetc(fptr1);
    			while (ch != EOF)
    			{
        		fprintf(fpp,"%c",ch);
        		ch = fgetc(fptr1);
    			}
    			fclose(fptr1);
			}
			

   			fclose(fpp);
   			flag =1;
				
   		}
   		
		
		else if (strcmp(newString[k],">>")==0)
		{
			FILE *fpp;
   			fpp=fopen(newString[k+1],"a");
   			if(fpp==NULL)
	   		{
			printf("Error");
			exit(1);
			}		
			fprintf(fpp,"\n");	
			char asd[200];
			int j=0;
			for (j=0; j<k ;j++)
			{
				FILE *fptr1;
   				fptr1 = fopen(newString[j],"r");

   				if (fptr1 == NULL)
		    	{
       			printf("Error in opening %s",newString[j]);
       			exit(1);
   				}	

				char ch = fgetc(fptr1);
    			while (ch != EOF)
    			{
        		fprintf(fpp,"%c",ch);
        		ch = fgetc(fptr1);
    			}
    			fclose(fptr1);
			}
			

   			fclose(fpp);
			flag =1;	
		}
		
	 
	}
	
	char* position = strchr(str, '>');
	char* position1 = strchr(str, '>>');
	
	if (position == NULL && position1 == NULL)
	{
		int l=0;
		for (l=0; l<=ctr ; l++)
		{
			FILE *fptr1;
   			fptr1 = fopen(newString[l],"r");

   			if (fptr1 == NULL)
		    {
       		printf("Error in opening file");
       		exit(1);
   			}	

			char ch = fgetc(fptr1);
    		while (ch != EOF)
    		{
        	printf("%c", ch);
        	ch = fgetc(fptr1);
    		}
    		fclose(fptr1);
		}
	}
	
	return 0;
	
}
