#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main ()
{
    FILE *source,*coping;
    char s_file[25], c_file[25];
    char ch;
    printf("Enter source file name: ");
    scanf("%s",s_file);
    printf("\nEnter coping file name: ");
    scanf("%s",c_file);
    source=fopen(s_file,"r");
    coping=fopen(c_file,"w");
    if (source== NULL)
    {
        printf("Error! Source File is not found...");
        fclose(source);
        return 1;
    }
    if (coping== NULL)
    {
        printf("Unable to creat.....");
        fclose(source);
        return 1;
    }
    printf("Coping .....\n");
    ch=fgetc(source);
    while(ch!=EOF)
    {
        fputc(ch,coping);
        ch=fgetc(source);

    }
    printf("File Copied.\n");
    fclose(source);
    fclose(coping);
    return 0;




}