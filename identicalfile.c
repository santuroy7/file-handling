#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char ch1, ch2;
    FILE *f1, *f2;
    char f1_file[25], f2_file[25];
    int flag = 0;
    printf("Enter first filename: ");
    scanf("%s", f1_file);
    printf("Enter second filename: ");
    scanf("%s", f2_file);
    f2 = fopen(f2_file, "r");
    f1 = fopen(f1_file, "r");
    if (f1 == NULL)
    {
        printf("Error! %s is not found!", f1_file);
        fclose(f1);
        return 1;
    }
    if (f2 == NULL)
    {
        printf("Error! %s is not found!", f2_file);
        fclose(f2);
        return 1;
    }
    printf("Reading file content....\n");
    while((fscanf(f1,"%s",f1_file)!=EOF) && (fscanf(f2,"%s",f2_file)!=EOF))
    {
        ch1 = fgetc(f1);
        ch2 = fgetc(f2);
        if (ch1 == ch2)
        {
            continue;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Files are identical.\n");
    }
    else
    {

        printf("Files are not identical.\n");
    }
    fclose(f1);
    fclose(f2);
    return 0;
}