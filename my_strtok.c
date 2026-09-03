#include<stdio.h>
char * my_strtok(char * r_str, char *delim)
{
    static int i=0;
    static int  start_index=0;
    static char * str;
    
    if(r_str != NULL)
    {
        str = r_str;
        start_index=0;
        i=0;
        
    }
    

  if(str == NULL)
    return NULL;

   
   char *token;

   
  while(str[i]!='\0')
  {
    int flag=0;
    for(int j=0; delim[j]!='\0'; j++)
    {
        if(str[i]==delim[j])
        {
            flag=1;
            break;
        }
       
    }
    if(flag==0)
    {
        i++;
    }
    else
    {
        str[i]='\0';
        if(i == start_index)
        {
            i++;
            start_index = i;

        }
        else
        {
            token = &str[start_index];
            i++;
            start_index=i;
            return token;
        }
       
        
    }
  }

  if(start_index != -1 && str[start_index] != '\0')
  {
    token = &str[start_index];
    start_index = -1;
    return token;
  }
  else
  {
    start_index = -1;
    return NULL;
  } 
   
  
  
   
  
}
int main()
{
    char str[50];
    
    printf("Enter the string  : ");
    scanf("%[^\n]", str);
    
    char delim[50];
 
    printf("Enter the delimeter : ");
    scanf("\n%[^\n]", delim);
   
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}