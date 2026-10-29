#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize<=1)
    {
        return NULL;
    }
    char *pre;
    pre = (char *)malloc(50 * sizeof(char));

    strcpy(pre,strs[0]);
   
    for(int i=1; i<strsSize-1; i++)
    {
        
        
       
        int j=0;
          while(pre[j]!='\0' && pre[j]== strs[i][j] && strs[i][j]!='\0')
          {
             j++;
           
          }
         if(j==0)
        {
                return NULL;
        }
         
            pre[j]='\0';

              return pre;
        
            
             
    }
         
         
         

        
      
    
  
    
}
int main()
{
    int size;
    printf("Enter no of strings\n");
    scanf("%d", &size);

    char **str= (char **)malloc(size * sizeof(char *));
    if(str==NULL)return 0;

    
    for(int i=0; i<size; i++)
    {
        str[i]= (char *)malloc(10 * sizeof(char));

    }
    printf("Enter %d strings\n",size);
    for(int i=0; i<size; i++)
    {
        scanf("%s", str[i]);
    }
    char * res = longestCommonPrefix(str, size);

    if(res==NULL)
    {
        printf("result is None\n"); 
    }
    else
    printf("result is %s\n", res);

    free(res);
    for(int i=0; i<size; i++)
    {
        free(str[i]);
    }
    free(str);
}