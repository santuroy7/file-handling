// write a code to insert string in 15th position in a file 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char file_name[25], ch;
    FILE * fptr, *temp;
    printf("\nEnter the file name: ");
    scanf("%s",file_name);
    fptr=fopen(file_name,"r");
    if(fptr==NULL)
    {
        printf("Error! File is not found....");
        fclose(fptr);
        exit(1);

    }
    temp=fopen("temp.txt","w");

    int count=0;
    char input[6]="string";
    ch=fgetc(fptr);
    while(ch!=EOF)
    {
        if(count==15)
        {
            for(int i=0;i<6;i++)
            {
                fputc(input[i],temp);

            }
        }
        fputc(ch,temp);
        ch=fgetc(fptr);
        
        count++;

    }
    printf("\n'strig' is placed in 15th position in the file.");
    fclose(fptr);
    fclose(temp);
    remove(file_name);
    rename("temp.txt",file_name);
    return 0;

    
}