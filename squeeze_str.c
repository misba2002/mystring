#include<stdio.h>
void squeez(char * str, char *dstr)
{
    int i=0;
    int flag;
    while(str[i]!='\0')
    {
        flag=0;
        for(int j=0; dstr[j]!='\0'; j++)
        {
            if(str[i] == dstr[j])
            {
                flag =1;
                break;
            }
        }
        if(flag == 1)
        {
            for(int k=i; str[k]!='\0'; k++)
            {
                str[k] = str[k+1];
            }
        }
        else
        {
            i++;
        }


    }
}
int main()
{
    char str[50],  dstr[50];

    printf("Enter main string :");
    scanf("%[^\n]", str);

    printf("Enter deleting string :");
    scanf("\n%[^\n]", dstr);

    squeez(str, dstr);

    printf("String after squeezing is %s\n", str);


}