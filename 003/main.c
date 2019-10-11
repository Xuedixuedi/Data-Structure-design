#include <stdio.h>
#include <string.h>

int main() {
    const char c[] = "123456";
    char d[12] = " ";
    int i = 6, j;
    while(1){
        for(j = 1;j < i;j++){
            if(c[j] == '.'){
                i++;
            }
            strcpy(d,c)
        }
    }
    return 0;
}