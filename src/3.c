#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int sum = 0;
    while((read = getline(&line, &len, stdin)) != -1){
        int found = 0;
        for(int i = 0; i < (read - 1) / 2; i++){
            for(int j = (read - 1) / 2; j < read - 1; j++){
                if(line[i] == line[j]){
                    char same = line[i];
                    if(same >= 'a'){
                        sum += (same - 'a' + 1);
                    }
                    else{
                        sum += (same - 'A' + 27);
                    }
                    found = 1;
                    break;
                }
            }
            if(found){
                break;
            }
        }
    }
    printf("%d\n", sum);
    return 0;
}