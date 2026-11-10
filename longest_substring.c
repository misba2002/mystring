#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char* s) {

    int i=0, length=0,found=0,index=0,start_i=0,prev_len=0,start_i_flag=0;
    char substring[strlen(s)+1];
    while(s[i]!='\0')
    {
        found=0;
        for(int j=0; j<index; j++)
        {
            if(s[i]==substring[j])
            {
               found=1;
               break; 
            }
        }
        if(found==0)
        {
            if(start_i_flag==0)
            {
                start_i=i;
                start_i_flag=1;

            }
            substring[index++]=s[i];
            length++;

        }
        if(found==1)
        {
            if(prev_len >= length)
            {
                // dont do anything;
                index=0;
                start_i_flag=0;
                i=start_i+1;
                length=0;
                continue;
            }
            else if(prev_len < length)
            {
                prev_len=length;
                substring[index++]='\0';
                printf("Present subtring is %s\n", substring);
                printf("Preveious length updated to %d\n", length);
                index=0;
                start_i_flag=0;
                i=start_i+1;
                length=0;
                continue;
            }

        }
        i++;

    }

    return (prev_len>length)?prev_len:length;
    
}
int main()
{
    char str[20];
    printf("Enter string\n");
    scanf("%s", str);

    int res = lengthOfLongestSubstring(str);
    printf("Length of the longest substring is %d\n", res);
}