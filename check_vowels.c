#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// CHECK FOR VOWELS IF PRESENT COUNT VOWELS DISPLAY VOWELS NO OF DUPLICATE VOWELS VOWELS WHICH ARE NOT REPEATNG//
// AT WHICH INDEXES VOWELS ARE  PREDENT //
int check_vowels(char str[]);
int main()
{
    int size;

    printf("Enter the size of the string: ");
    scanf("%d", &size);

    if(size<=0)
    {
        printf("Invalid size size cannot be empty or -ve\n");
        return 0;
    }

    char *ptr = (char *) malloc(size);

    if(ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    getchar();
    printf("Enter the string:");
    if((scanf("%[^\n]", ptr)) == 0)
    {
        printf("Empty string, invalid input\n");
        return 0;

    }

    if(strlen(ptr) >= size)
    {
        printf("Invalid input ,String size exceeded!\n");
        return 0;
    }

    
    
    
    int vowels_count = check_vowels(ptr);
    printf("No of vowels are %d\n", vowels_count);

    free(ptr);
    

}
 int check_vowels(char str[])
{
    int i=0, count=0, flag=0;
    printf("finding vowels..........\n");
    while(str[i]!='\0')
    {
        if(str[i]=='A' || str[i]=='E'  || str[i]=='I' || str[i]=='O' || str[i]=='U' ||
           str[i]=='a' || str[i]=='e'  || str[i]=='i' || str[i]=='o' || str[i]=='u')

           {
            count++;
            if(flag !=1)
            {
             printf("vowels are: ");   
            }
            flag=1;
            printf("%c ", str[i]);
           
           

           }
           i++;
    }
    if(flag == 0)
    {
      printf("Vowels not found !\n");
      return 0;
    }
    else
    {
         printf("\nVowels are present\n");
         return count;

    }
    
    

}
