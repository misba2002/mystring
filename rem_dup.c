// Remove duplicate elements while preserving the first occurrence.
#include<stdio.h>
#include<stdlib.h>
void rem_dup(int col ,int row, int(*arr)[col], int *cptr)
{
    int count=0;
    for(int i=0; i<row; i++)
    {
        count=0;
        for(int j=0; j<col-count; j++)
        {
            
            for(int k=j+1; k<col-count; )
            {
                if(arr[i][j]==arr[i][k])
                {
                    
                    for(int z=k; z<col-1-count; z++)
                    {
                     arr[i][z]=arr[i][z+1];
                    }
                    count++;
                    
                   
                }
                else
                {
                    k++;
                } 
                
            }
            
            

        }
        cptr[i]=count;
    }
}
void rem_dup_str(char **str,int *cptr, int row)
{
    for(int i=0; i<row; i++)
    {
        int unique=0;
        for(int j=0; str[i][j]!='\0'; j++)
        {
             int seen=0;
            for(int k=0; k<unique; k++)
            {
                if(str[i][j]==str[i][k])
                {
                   
                     seen=1;
                    break;
                }
            }
            if(seen==0)
            {
                str[i][unique++]=str[i][j];
            }
        }
        str[i][unique]='\0';
        cptr[i]=unique;

    }
    
}
int main()
{
   
    int row, col ;
   
    printf("Enter row and col value :\n");
    if(scanf("%d%d", &row, &col)!=2 || row<=0 || col<=0)
    {
        printf("Invalid inputs\n");
        return 0;
    }
    int (*ptr)[col]=(int (*)[col])malloc(row*col*sizeof(int));

    if(ptr==NULL)
    {
        printf("memory not allocated\n");
        return 0;
    }

    printf("Enter %d X %d elements:\n",row,col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if (scanf("%d", &ptr[i][j]) != 1)
            {
                printf("Invalid element\n");
                free(ptr);
                return 0;
            }
        }
    }
    
    
      int arr1[row];
     rem_dup(col, row , ptr, arr1);
     printf("After removing duplicate's\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col-arr1[i]; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
    printf("total no of duplicates in each row is :\n");
    for(int i=0; i<row; i++)
    {
        printf("%d ", arr1[i]);
    }
    free(ptr);

    int strings;
    printf("Enter the num of strings\n");
    if(scanf("%d", &strings)!=1 || strings<=0)
    {
        printf("Invalid input\n");
        return 0;
    }

    char **str=(char **)malloc(strings*sizeof(*str));

    if(str==NULL)
    {
        printf("Memory not allocated\n");
        return 0;
    }
    int col;
    printf("Enter the characters each string should have:\n");
    if(scanf("%d",&col)!=1 || col<=0)
    { 
         printf("Invalid input\n");
        return 0;

    }


    for(int i=0; i<strings; i++)
    {
        str[i]= (char *)malloc((col+1 )* sizeof(*str[i]));
        if(str[i]==NULL)
        {
            printf("Memory allocation failed\n");
            for(int j=0; j<i; j++)
            {
                free(str[j]);
            }
            free(str);
            return 0;
        }
        
    }
    printf("Enter strings:\n");
    for(int i=0; i<strings; i++)
    {
        scanf(" %s", str[i]);
    }
    int cptr[strings];
    rem_dup_str(str,cptr,strings);

    printf("After removing duplicates\n");
    for(int i=0; i<strings; i++)
    {
        
        printf("%s",str[i]);
        printf("    ");

    }
    printf("\n");
    printf("No of duplicates in each sring is\n");
    for(int i=0; i<strings; i++)
    {
        printf("%d ", col-cptr[i]);
    }

     for(int j=0; j<strings; j++)
            {
                free(str[j]);
            }
            free(str);







}