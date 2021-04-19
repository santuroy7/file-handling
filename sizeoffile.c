// find size of a file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char file_name[25], ch;
    FILE *fptr;
    printf("\nEnter file name: ");
    scanf("%s", file_name);
    fptr = fopen(file_name, "r");
    if (fptr == NULL)
    {
        printf("\nError! File is not found...");
        fclose(fptr);
        return 1;
    }
    long long int count = 0;
    //    count no of char present in a file
    for (ch = getc(fptr); ch != EOF; ch = getc(fptr))
    {

        // Increment count for this character
        count = count + 1;
    }
    printf("\nSize of given file is %lld byte.", count);
    fclose(fptr);
    return 0;
}
