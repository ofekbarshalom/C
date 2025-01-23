#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 3

void q1(){
    int grades[N];
    int grade;
    int sum = 0;

    for(int i = 0; i < N; i++){
        printf("Enter student grade #%d: ", i);
        if(scanf("%d", &grade) != 1){
            printf("Error: you need to enter an Integer");
            return;
        }
        grades[i] = grade;
        sum += grade;
    }

    double avg = sum / N;
    printf("The average is: %.2f\n", avg);

    for(int i = 0; i < N; i++){
        if(grades[i] > avg){
            printf("Student #%d is above average\n", i);
        }
    }
}

unsigned int is_palindrome(char* word){
    int size = strlen(word);

    for(int i = 0; i < size / 2; i++){
        if(word[i] != word[size - i - 1]){
            printf("%s is not a palindrome", word);
            return 0;
        }
    }

    printf("%s is a palindrome", word);
    return 1;
}

void q3(int arr[N][N]){
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    printf("The new matrix:\n");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

bool MagicSlant(int arr[N][N], int sum){
    int slantSum = 0;

    for(int i = 0; i < N; i++){
        slantSum += arr[i][i];
    }
    if(sum != slantSum){
        return false;
    }

    slantSum = 0;

    for(int i = 0; i < N; i++){
        slantSum += arr[i][N - 1 -  i];
    }
    if(sum != slantSum){
        return false;
    }

    return true;
}

bool MagicRow(int arr[N][N], int sum){
    int rowSum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            rowSum += arr[i][j];
        }
        if(rowSum != sum){
            return false;
        }
        rowSum = 0;
    }
    return true;
}

bool MagicCol(int arr[N][N], int sum){
    int colSum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            colSum += arr[j][i];
        }
        if(colSum != sum){
            return false;
        }
        colSum = 0;
    }
    return true;
}

void MagicCheck(int arr[N][N]){
    int sum = 0;

    for(int i = 0; i < N; i++){
        sum += arr[0][i];
    }

    bool checkSlant = MagicSlant(arr, sum);
    bool checkRow = MagicRow(arr, sum);
    bool checkCol = MagicCol(arr, sum);

    if(checkSlant && checkRow && checkCol){
        printf("The given Matrix is a magic Matrix with sum of %d", sum);
    }
    else {
        printf("The given Matrix is not a magic Matrix");
    }
}

void FloydWarshall(int dist[N][N], int start, int end){
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] != 0 && dist[k][j] != 0 &&
                dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if(dist[start][end] == 0){
        printf("There is no path between node %d and node %d.\n", start, end);
    } else {
        printf("The shortest path weight between node %d and node %d is: %d\n", start, end, dist[start][end]);
    }
}

int knapsack(int values[], int weights[], int sackSize, int isSelected[]){
    
}

int main(){
    int qnumber = 5;
    
    switch (qnumber)
    {
    case 1:
        q1();
        break;
    
    case 2:
        char word[100];
        printf("Enter a word: ");
        scanf("%99s", word);
        is_palindrome(word);
        break;

    case 3:
        int arr[N][N];

        printf("Enter a matrix:\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &arr[i][j]);
            }
            printf("\n");
        }

        q3(arr);

    case 4:
        int arr2[N][N];

        printf("Enter a matrix:\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &arr2[i][j]);
            }
            printf("\n");
        }

        MagicCheck(arr2);
    
    case 5:
        int arr3[N][N];
        int start = 0;
        int end = 2;
        printf("Enter a matrix:\n");
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &arr3[i][j]);
            }
            printf("\n");
        }

        FloydWarshall(arr3, start, end);

    default:
        break;
    }

    return 0;
}