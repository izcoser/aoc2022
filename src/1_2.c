#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int max[] = { 0, 0, 0 };
    int cur = 0;
    while((read = getline(&line, &len, stdin)) != -1){
        if(!strcmp(line, "\n")){
            for(int i = 0; i < 3; i++){
                if(cur > max[i]){
                    for(int k = 2 - i; k > 0; k--){
                        max[k] = max[k - 1];
                    }
                    max[i] = cur;
                    break;
                }
            }
            cur = 0;
            continue;
        }
        cur += atoi(line);
    }
    printf("%d\n", max[0] + max[1] + max[2]);
    return 0;
}