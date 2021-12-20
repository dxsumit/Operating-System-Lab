// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab1 Question 2. Write a program using file handling function to copy a file. Write a program which converts entire file from lower case to upper case and vice versa. 

#include <stdio.h>
#include <ctype.h>
#include<string.h>

int main() {
    int position;
    FILE *filepointer, *newFile;
    char ch;

    filepointer = fopen("testFile.txt", "r+");
    newFile     = fopen("copiedFile.txt", "w");

    // copying a new file..
    fseek(filepointer, 0L, SEEK_END);           // point to end of file
    position = ftell(filepointer);              // get current position
    fseek(filepointer, 0L, SEEK_SET);           // point to start of file

    while(position--){
        ch = fgetc(filepointer);
        
        // converting to upper/lower case..
        // // isupper(c[i]) ? printf("%c", tolower(c[i])) :  printf("%c", toupper(c[i]));
        if(ch >= 65 && ch <= (65+26)){
            fputc(ch+32, newFile);
        }else if(ch >= 97 && ch <= (97+26)){
            fputc(ch-32, newFile);
        }else{
            fputc(ch, newFile);
        }
    }

    printf("File copied a new file named 'copiedFile.txt' is created...");
    fclose(filepointer);
    fclose(newFile);

    return 0;
}


