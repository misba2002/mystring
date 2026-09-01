#include<stdio.h>
int my_atoi(char *str)
{
    int i=0;
    int sign=1;
    int result=0;
    int digit=0;

     while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
    {
        i++;
    }


    if(str[i] ==  '-')
    {
        sign = -1;
        i++;
    }
    else if(str[i] == '+')
    {
        i++;
    }

   
    while(str[i] >= '0' && str[i] <= '9')
    {
        digit = str[i] - '0';
        result = result * 10 + digit;
        i++;

    }

    if(sign == -1)
    {
        result = result * sign;
    }
     return result;




}
int main()
{
    char str[20];

    printf("Enter string :");
    scanf("%s", str);

    int res = my_atoi(str);

    printf("result :%d\n", res);

  



}