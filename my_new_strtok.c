#include<stdio.h>
char* my_strtok(char str[],const char delim[])
{
  static int i=0;
  static char *ptr;
  if(str!=NULL)
  {
    ptr=str;
    i=0;
  }

  int start=i;
  for(i; ptr[i]!='\0'; i++)
  {
    for(int j=0; delim[j]!='\0'; j++)
    {
        if(ptr[i]==delim[j])
        {
           
            if(i!=0 && ptr[i-1]=='\0')
            {
                ptr[i]='\0';
                start++;
                break;
            }
            else
            {
                if((i==0))
                {
                     ptr[i]='\0';
                    start++;
                    break;
                }
                ptr[i]='\0';
                i++;
                return &ptr[start];
               
            }
          
        }
    }
  }
  if(ptr[start]!='\0')
  {
    return &ptr[start];
  }
  else
  {
      return NULL;
  }





}
int main()
{
    char str[50], delim[50];
    printf("Enter the string:");
    scanf("%49s", str);
    printf("Enter the delimnator:");
    scanf(" %49s", delim);

    char *token = my_strtok(str,delim);
    printf("Tokens:\n");
    while(token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
        
    }
}