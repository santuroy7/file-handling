#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char file_name[25], ch;
    FILE *fptr;
    printf("Enter file name: ");
    scanf("%s", file_name);
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("Error! File is not found...");
        fclose(fptr);
        return 1;
    }
    FILE *tmp;
    tmp = fopen("temp.txt", "w");
    if (tmp == NULL)
    {
        printf("Error! Unable to creat a temp File...");
        return 1;
    }


me:
    ch = fgetc(fptr);
    while (ch != EOF)
    {
        if (ch != ' ')
        {
            fputc(ch, tmp);
        }
        
        goto me;
    }

    fclose(fptr);
    fclose(tmp);
    remove(file_name);
    rename("temp.txt",file_name);
    printf("All blank spaces are removed...\n");

    return 0;
}