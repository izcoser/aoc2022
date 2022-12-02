#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int max = 0;
    int cur = 0;
    while((read = getline(&line, &len, stdin)) != -1){
        if(!strcmp(line, "\n")){
            max = cur > max ? cur : max;
            cur = 0;
            continue;
        }
        cur += atoi(line);
    }
    printf("%d\n", max);
    return 0;
}