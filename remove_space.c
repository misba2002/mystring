#include<stdio.h>
void removespace_pointer(char str[])
{
    int read=0, write=0, space=0;

    while(str[read]!='\0')
    {
        if(str[read] == ' ' || str[read] == '\t')
        {
            space++;
            read++;
        }
        else
        {
            if(space > 0 )
            {
                if(write > 0)
                {
                str[write++] = ' ';
                
                }
                space = 0;
                
            }
           
            
                str[write++] = str[read++];
            
        }
       
    }
     str[write] = '\0';
     

    printf("After removing space your input is :%s\n", str);
    

}
int main()
{
    char name[50]={0};
    int count=0;
    do
    {
        name[0] = 0;
        printf("Enter name:");
        if( scanf("%[^\n]", name) == 0)
        {
            getchar();
        }
        else  getchar();
        count++;
       
        removespace_pointer(name);

    }while(count <3);
}