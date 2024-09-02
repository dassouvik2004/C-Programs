#include<stdio.h>
#include<string.h>

struct stack {
    char list[50];
    int top;
}s;

void push(char c) {
    s.top++;
    s.list[s.top] = c;
}

char pop() {
    char d = s.list[s.top];
    s.top--;
    return d;
}

int main() {
    s.top = -1;  // Initialize the stack

    char str[50], d,i;
    printf("Enter the string:\n");
    fgets(str, 50, stdin);

    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';  // Remove newline character if present
        len--;
    }

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("The reversed string is:\n");
    puts(str);
	
	return 0;
}

