// replace vowels with z
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

    FILE *fptr, *temp;
    char f_name[25], ch;
    printf("\nEnter the File Name: ");
    scanf("%s", f_name);
    fptr = fopen(f_name, "r");
    if (fptr == NULL)
    {
        printf("\nError! File not found...\n");
        exit(1);
    }

    temp = fopen("temp.txt", "w");
    ch = fgetc(fptr);
    while (ch != EOF)
    {

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            ch='z';
        }
       
            fputc(ch, temp);
            ch = fgetc(fptr);
      
    }
    fclose(fptr);
    fclose(temp);
    remove(f_name);
    rename("temp.txt", f_name);
    printf("\nAll vowels are replaced with 'Z'");
    return 0;
}