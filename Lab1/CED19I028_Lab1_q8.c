// Name:    Sumit Kumar
// Roll No: CED19I028
// Lab1 Question 3. Write a program to read the contents of a file and remove the vowels form the file and display it.


#include<stdio.h>
#include<string.h>

int main() {

    char ch;
    FILE *filepointer;
    filepointer = fopen("testFile.txt", "r+");          // r+ is for both write and read 

    // read contents of file..
    while(1){
        ch = fgetc(filepointer);
        if(ch == EOF){
            printf("\n");
            break;
        }
        ch = (char)ch;
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
 
            fseek(filepointer, -1, SEEK_CUR);           // seek pointer to current position
            fputc(' ', filepointer);
            continue;
        }
        printf("%c", ch);

    }
    printf("\nMain file also has been edited..\n");
    fclose(filepointer);
    return 0;
}

