#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME 100
#define MAX_CHILDREN 100
typedef struct node Node;

struct node{ // tree node
    Node* nodes[MAX_CHILDREN];
    int node_count;
    int size; // -1 if dir else file size.
    char name[MAX_NAME];
};

int main(){
    Node t;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    while((read = getline(&line, &len, stdin)) != -1){

    }
    return 0;
}