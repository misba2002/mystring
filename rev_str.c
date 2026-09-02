#include<stdio.h>
#include<string.h>

void reverse(char *);

int main()
{
    char str[20];

    printf("Enter the string : ");
    scanf("%[^\n]", str);

    reverse(str);

    printf("Reversed string is :%s", str);
}

void reverse(char * str)
{
    int len = strlen(str);
    printf("length is :%d\n",len);
    int left=0, right=len-1;
    if(str[left] == '\0')
    {
        printf("Cant reverse an empty string\n");
        return ;

    }
    while(left < right)
    {
        int temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

}