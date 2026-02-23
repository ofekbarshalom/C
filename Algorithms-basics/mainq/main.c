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
    int dp[N + 1][sackSize + 1];
    int i, w;

    for(i = 0; i <= N; i++){
        for(w = 0; w <= sackSize; w++){
            dp[i][w] = 0;
        }
    }

    for(i = 1; i <= N; i++){
        for(w = 0; w <= sackSize; w++){
            if(weights[i - 1] <= w){
                if( values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]){
                    dp[i][w] = dp[i - 1][w];
                }
                else{
                    dp[i][w] = dp[i - 1][w];
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int totleValue = dp[N][sackSize];
    w = sackSize;

    for(i = N; i > 0; i++){
        if (dp[i][w] != dp[i - 1][w]){
            isSelected[i - 1] = 1;
            w -= weights[i - 1];
        } else {
            isSelected[i - 1] = 0;
        }
    }

    return totleValue;
}

int sizeCheck(void* p1, void* p2, int size){
    int sizeOf =  ((char*)p2 - (char*)p1) / size + 1;
    printf("The subarray size between the two given pointers is: %d", sizeOf);
}

void numCheck(int arr[],int size, int target){
    int left = 0;
    int right = size - 1;

    while(left < right){
        if(arr[left] + arr[right] == target){
            printf("Number %d at index %d and number %d at index %d sum is %d as required", arr[left], left, arr[right], right, target);
            return;
        }

        if(arr[left] + arr[right] < target){
            left++;
        }
        else {
            right --;
        }
    }

    printf("No such numbers exist in the given array");
}

int looper(int arr[], int size){
    int loopArr[size];

    for(int i = 0; i < size; i++){
        loopArr[i] = 0;
    }

    int i = 0;

    while(i < size && i >= 0){
        if(loopArr[i] == 1){
            return i;
        }
        loopArr[i] = 1;
        i += arr[i];
    }

    return -1;
}

bool isContained(int A[], int n, int B[], int m, int **start, int **end){
    for(int i = 0; i <= n - m; i++){
            bool match = true;
        for(int j = 0; j < m; j++){
            if(A[i + j] != B[j]){
                match = false;
                break;
            }

            if(match){
                *start = &A[i];
                *end = &A[i + m - 1];
                return true;
            }
        }
    }

    *start = NULL;
    *end = NULL;
    return false;
}


int main(){
    int qnumber = 10;
    
    switch(qnumber)
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
    
    case 7:
        int arr7[5];
        
        int size = sizeof(int);
        void* p1 = &arr7[2];
        void* p2 = &arr7[4];

        sizeCheck(p1, p2, size);
    
    case 8:
        int arr8[5] = {1,2,3,4,5};
        numCheck(arr8, 5, 6);
    
    case 9:
        int size1 = 5;
        int arr9[] = {3,2,0,1,-3};
        int loopStart = looper(arr9, size1);
        printf("The loop start at index %d", loopStart);

    case 10:
        int n = 7;
        int m = 3;
        int A[] = {0,1,2,3,4,5,6};
        int B[] = {3,4,5};

        int* start1 = NULL;
        int* end1 = NULL;

        bool isContain = isContained(A, n, B, m, &start1, &end1);

        if(isContain){
            printf("true");
        } else {
            printf("false");
        }

    default:
        break;
    }

    return 0;
}