#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fptr;
    int count_w = 0;
    char f_name[25], ch;
    printf("Enter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("Error! File not found...\n");
        exit;
    }
    while (1)
    {
        ch = fgetc(fptr);
        if (ch == EOF)
        {
            count_w++;
            break;
        }
        if (ch == '\n' || ch == ' ' || ch == '\t')
        {
            count_w++;
        }
       
    }
    printf("No of words: %d", count_w);
    fclose(fptr);
    return 0;

}