// Marge two file in a new file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f1, *f2, *fm;
    char f1_name[25], f2_name[25], ch;
    printf("\nEnter file 1: ");
    scanf("%s", f1_name);
    f1 = fopen(f1_name, "r");
    if (f1 == NULL)
    {
        printf("\nError! %s is not found...", f1_name);
        fclose(f1);
        exit(1);
    }
    printf("\nEnter file 2: ");
    scanf("%s", f2_name);
    f2 = fopen(f2_name, "r");
    if (f2 == NULL)
    {
        printf("\nError! %s is not found...", f2_name);
        fclose(f2);
        exit(1);
    }
    fm=fopen("marge.txt","a");
    ch=fgetc(f1);
    while(ch!=EOF)
    {
        fputc(ch,fm);
        ch=fgetc(f1);
        
    }
    ch=fgetc(f2);
    while(ch!=EOF)
    {
        fputc(ch,fm);
        ch=fgetc(f2);

    }
    printf("\nYour files are marged and store in marge.txt.");
    fclose(f1);
    fclose(f2);
    fclose(fm);
    return 0;
}

