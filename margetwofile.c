// marge two file in a one file
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
        return 1;
    }
    printf("\nEnter file 2: ");
    scanf("%s", f2_name);
    f2 = fopen(f2_name, "r");
    if (f2 == NULL)
    {
        printf("\nError! %s is not found...", f2_name);
        fclose(f2);
        return 1;
    }
    fclose(f1);
    fclose(f2);
    int i, n1, n2;
    printf("\nEnter number of element you want to insert in file 1: ");
    scanf("%d", &n1);
    printf("\nEnter number of element you want to insert in file 2: ");
    scanf("%d", &n2);
    f1 = fopen(f1_name, "w");
    printf("\nEnter the %d words for file 1: \n", n1);
    char a[n1], b[n2];
    for (i = 0; i < n1; i++)
    {
        scanf("%s", a);
        fprintf(f1, "%s\n", a);
    }
    fclose(f1);
    f2 = fopen(f2_name, "w");
    printf("\nEnter the %d words for file 2: \n", n2);
    for (i = 0; i < n2; i++)
    {
        scanf("%s", b);
        fprintf(f2, "%s\n", b);
    }
    fclose(f2);
    f1 = fopen(f1_name, "r");
    f2 = fopen(f2_name, "r");
    fm = fopen("f3.txt", "w");
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch, fm);
    }
    while ((ch = fgetc(f2)) != EOF)
    {
        fputc(ch, fm);
    }
    printf("\nWait your files are marging...");
    printf("\nMerged...file1 and file2 into f3.txt");
    fclose(f1);
    fclose(f2);
    fclose(fm);
    return 0;
}