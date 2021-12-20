// Name: Sumit Kumar
// Roll No: CED19I028
//  Question: opendir() and readdir()

#include <stdio.h>
#include <dirent.h>
  
int main(void) {
    struct dirent *de; 
  
    DIR *d = opendir("./");    //  ./ is for current directory
  
    if (d == NULL) {
        printf(" Failed to open");
        return 0;
    }
  
    // list all current directory files..
    while((de = readdir(d)) != NULL)
        printf(" %s\n", de->d_name);
  
    closedir(d);    
    return 0;
}