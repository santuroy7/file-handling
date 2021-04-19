// reverse of all content in a file
#include <stdio.h>
#include <stdlib.h>
long count_char(FILE *f)
{
    fseek(f, -1L, 2);
    long tc = ftell(f);
    tc++;
    return tc;
}

int main()
{
    FILE *fp, *fptr;
    char file_name[25];
    printf("Enter the file name: \n");
    scanf("%s",file_name);
    fp = fopen(file_name, "r");
    fptr = fopen("newfile.txt", "w");
    char c;
    long tc = count_char(fp);
    fseek(fp, -1L, 2);
    long i = 0;
    while (i < tc)
    {
        c = fgetc(fp);
        fputc(c, fptr);
        fseek(fp, -2L, 1);
        i++;
    }
    fclose(fp);
    fclose(fptr);
    printf("Reverse of the given file is store in newfile.txt....\n");
    return 0;

}