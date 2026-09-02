#include<stdio.h>
#include<string.h>

void recursive_reverse(char *);

int main()
{
    char str[20];

    printf("Enter the string:");
    scanf("%[^\n]", str);

    recursive_reverse(str);

    printf("Reversed string using recursive is %s\n", str);


}
void recursive_reverse(char *str)
{
    static int left;
    static int right;
    if(str[left]=='\0')
    {
        printf("Cannot reverse an empty string\n");
        return;
    }
    if(!right)
    {
        right = strlen(str)-1;
    }
    if(left < right)
    {
        int temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
        recursive_reverse(str);
    }
    else return;
    

}