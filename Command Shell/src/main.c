#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int flag=0;
	char yo[200]="/home/iiitd/";
	char disp[200]="/home/iiitd/";
	char pres[200]="/home/iiitd/";
	while (flag==0)
	{
	
	printf("%s", disp);
	char str[200];
   	gets(str);
   	
   	
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
	
	char *command ;
	command= newString[0];
	
	

	
	
	char v[1000];
	int ii=0;
	for (ii=1;ii<=ctr;ii++)
	{
		 
		strcat(v,newString[ii]);
		strcat(v," ");
	 
	}
	char v2[1000];
	strcpy(v2,v);
	v2[strlen(v2)-1] ='\0';
	
	FILE *fpp;
   	fpp=fopen("/home/iiitd/HISTFILE.txt","a");
   	if(fpp==NULL)
	   {
		printf("Error");
		exit(1);
	
	   }
	char asd[200];
	strcpy(asd,str);
	
	fprintf(fpp,"%s\n",asd);
   	fclose(fpp);
   	
   	
   	
   	
	if (strcmp(command,"echo") == 0)
	{
		printf("%s",v);
		
		
	}
	else if (strcmp(command,"cd") == 0)
	{	
		if (strcmp(newString[1],"..")==0)
		{
		const char *path=pres;
		int k =chdir(path);
		if (k==0)
		{
			strcpy(disp,pres);
			strcpy(yo,pres);
		}
		
		}
		
		else if (strcmp(newString[1],"-")==0)
		{
		char aaa[200];
		strcpy(aaa,yo);
		aaa[strlen(aaa)-1]='\0';
		char *ptr ;
 		int    ch = '/';
 		ptr = strrchr( aaa, ch );
 		int index = ptr-aaa;
 		char *from = aaa;
  		int kl = 0;
  		kl = strlen(from)-index-1;
  		from[strlen(from)-kl]='\0';
  		
  		const char *path=from;
		chdir(path);

		if (strcmp(from,"/home/")!=0)
		{
			
			strcpy(disp,from);
			strcpy(yo,from);
		}
			
		
		}
		else
		{
		
		char yo1[20]="/";
		strcat(yo,newString[1]);
		strcat(yo,yo1);
		const char *path=yo;
		int k =chdir(path);
		
		if (k==0)
		{
			strcat(disp,newString[1]);
			strcat(disp,yo1);
			
		}
		else if (k==-1)
		
		{
			printf("No such directory found.");
		}
		
		
		strcpy(yo,disp);
		}
	
		
	}
	else if (strcmp(command,"pwd") == 0)
	{
	
		char aa[200];
		strcpy(aa,yo);
		aa[strlen(aa)-1]='\0';
		printf("%s",aa);
		
	}
	else if (strcmp(command,"history") == 0)
	{
		if(strcmp(newString[1],"-c")==0)
		{
		FILE *fptr1;
   		fptr1 = fopen("/home/iiitd/HISTFILE.txt","w");
   		fprintf(fptr1,"%s\n","");
   		fclose(fptr1);
		}
		else{
		
		FILE *fptr1;
   		fptr1 = fopen("/home/iiitd/HISTFILE.txt","r");

   		if (fptr1  == NULL)
		   {
       		printf("Error! opening file");
       		exit(1);
   			}	

		char ch = fgetc(fptr1);
    	while (ch != EOF)
    	{
        printf ("%c", ch);
        ch = fgetc(fptr1);
    	}
    	fclose(fptr1); 
    }
	}
	else if (strcmp(command,"exit") == 0)
	{
		flag=1;
		break;
	}
	else if (strcmp(command,"date") == 0)
	{
	
		pid_t pid;
		pid = fork();
		if (pid==0)
		{
			if (strlen(newString[1])!=0)
			{
				execl("date", yo, "date",newString[1],NULL);
			}
			else
			{	
				execl("date", yo, "date",NULL);
			}
			
		}
		else if (pid<0)
		{
			printf("Fork fail");
		}
		else
		{
			wait(NULL);
		}

	}
	else if (strcmp(command,"ls") == 0)
	{
	
		pid_t pid;
		pid = fork();
		if (pid==0)
		{
			if (strlen(newString[1])!=0)
			{

				execl("ls", yo, "ls",newString[1],NULL);
			}
			else
			{	
				execl("ls", yo, "ls",NULL);
			}
			
		}
		else if (pid<0)
		{
			printf("Fork fail");
		}
		else
		{
			wait(NULL);
		}

	}

	else if (strcmp(command,"mkdir") == 0)
	{
	
		pid_t pid;
		pid = fork();
		if (pid==0)
		{
			
			{	
				execl("mkdir", yo, "mkdir",newString[1],NULL);
			}
			
		}
		else if (pid<0)
		{
			printf("Fork fail");
		}
		else
		{
			wait(NULL);
		}

	}
	else if (strcmp(command,"rm") == 0)
	{
	
		pid_t pid;
		pid = fork();
		if (pid==0)
		{
			if (strlen(newString[1])!=0)
			{
				execl("rm", yo, "rm",newString[1],NULL);
			}
			else
			{	
				execl("rm", yo, "rm",NULL);
			}
			
		}
		else if (pid<0)
		{
			printf("Fork fail");
		}
		else
		{
			wait(NULL);
		}

	}
	else if (strcmp(command,"cat") == 0)
	{
	
		pid_t pid;
		pid = fork();
		if (pid==0)
		{
			
			{	
				
				execl("cat", yo, "cat",v2,NULL);
			}
			
		}
		else if (pid<0)
		{
			printf("Fork fail");
		}
		else
		{
			wait(NULL);
		}

	}


	else
	{
		printf("'%s'is not recognised as an internal or external command." , command);
	}
	strcpy(v,"");
	int kk=0;
	for (kk=0; kk<=ctr;kk++)
	{
		strcpy(newString[kk],"");
		 
	}
	

	printf("\n");
	}
	
	return 0;
}
