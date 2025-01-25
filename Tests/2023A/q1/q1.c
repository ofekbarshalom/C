#include<stdio.h>

char get_char(){
    static int i=0;
    i++;
    char c='a';
    return c+i;
}

void print_char(char c) {
    printf("%c ",c);
}

void print_two_chars(char c1,char c2) {
    printf("%c %c ",c1,c2);
}

int main() {
    char c1 = get_char();
    char c2 = get_char();
    printf("1: \n");
    print_two_chars(c1,c2); 
    printf("\n");
    printf("2: \n");
    print_two_chars(get_char(),get_char());
    printf("\n");
    printf("3: \n");

    if (get_char()>'d' || get_char()<'q') {
        print_char(get_char()); 
        print_char(get_char()); 
    }
    printf("\n");
    printf("4: \n");

    if (get_char()>'d' && get_char()<'q') {
        print_char(get_char()); 
        print_char(get_char()); 
    }
    printf("\n");
    
    return 0;
}