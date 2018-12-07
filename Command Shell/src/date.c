#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	time_t mytime;
    mytime = time(NULL);
	if (argc==2)
	{	
	
    printf("%s\n", ctime(&mytime));
    
	
	}
	char str[200];
    strcpy(str,ctime(&mytime));
    int j=0,ctr=0,i=0;
    char newString[10][10]={0};
    
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
	
    if (argc==3)
    {
    
	if (strcmp(argv[2],"%b")==0)
	{
	//%b gives shortform of month
	char *month ;
	month= newString[1];
	
	printf("Month : %s\n",month);
	}
	else if (strcmp(argv[2],"%X")==0)
	{
	//%X gives time
	char *dat ;
	dat= newString[3];
	
	printf("Time : %s\n",dat);
	}
	else if (strcmp(argv[2],"%C")==0)
	{
	//%C century
	
	char aaa[200];
	strcpy(aaa,newString[4]);
	aaa[strlen(aaa)-3]='\0';
	printf("Century : %s\n",aaa);
	}
	}
    

	


    return 0;
}
