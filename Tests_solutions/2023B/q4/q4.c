#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct STUDENT_ {
    int id;
    char fname[11], lname[11]; 
    char department[2];
    int year;
    int unreturned ;
    int fine;
} student , *pstudent;

typedef struct BOOK_{
    int student_id;
    int book_id;
    char name[21];
    int loandate;
    int fine;
    int asosiated;
} book, *pbook;


void write_total(student s){
    char fname[7] = {0};
    fname[0] = s.department[0];
    fname[1] = s.department[1];
    strcpy(fname+2,".txt");
    FILE* f = fopen(fname,"a+");
    fprintf(f,"total: %04d\n",s.fine);
    fclose(f);
}

int library (FILE* students, FILE* landing) {
    char student_line[34] = {0};
    char book_line[44] = {0};
    book b; b.asosiated=1;
    student s;
    while(!feof(students)) {
        fscanf(students,"%9d%10c%10c%2c%1d",&s.id,s.fname,s.lname,s.department,&s.year);
        
        while(!feof(landing)) {
            if(b.asosiated == 1) {
                fscanf(landing,"%9d%5d%20c%6d%3d",&b.student_id,&b.book_id,b.name,&b.loandate,&b.fine);
            }
            if(b.student_id != s.id) {
                if(s.unreturned == 1) {
                    write_total(s);
                }
                break;
            }
            char fname[7] = {0};
            fname[0] = s.department[0];
            fname[1] = s.department[1];
            strcpy(fname+2,".txt");
            FILE* f = fopen(fname,"a+");
            if(s.unreturned == 0 ) { 
                fprintf(f,"student: %09d %s %s \n",s.id,s.fname,s.lname);
                s.unreturned = 1;
            }
            b.asosiated = 1;
            fprintf(f,"book: %05d %s %06d %03d\n",b.book_id,b.name,b.loandate,b.fine);
            s.fine += b.fine;
            fclose(f);

        }
        if(feof(landing) && s.unreturned==1) write_total(s);
    }
    
    return 0;
}

int main(){
FILE* students_f = fopen("uni.txt","r");
FILE* lib_f = fopen("librery.txt","r");

library(students_f,lib_f);
return 0;
}
