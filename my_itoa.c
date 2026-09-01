#include<stdio.h>
int length(char *str)
{
    int i=0, count=0;
    while(str[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

void my_itoa(int num, char *str)
{
    int i=0, start=0;
    char c;

    if(num == 0)
    {
    str[0] = '0';
    str[1] = '\0';
    return;
    }


    if(num < 0)
    {
        str[i] = '-';
        num = -1 * num;
        i++;
    }
   

    while(num >0 )  //12345abcd
    {
        int l_d = num % 10;
        c = l_d + '0';
        str[i] = c;
        i++;
        num = num/10; 
    }
    str[i]='\0';

    int len = length(str);


    if(str[0] == '-')
    {
        start=1;
    }
    else start =0;

    int right = len -1;
    int left  = start; 

    while( left < right )
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left ++;
        right --;
    }

    








}

int main()
{
    char str[20];
    int num;
    scanf("%d", &num);

    my_itoa(num, str);

    printf("%s", str);

   
}