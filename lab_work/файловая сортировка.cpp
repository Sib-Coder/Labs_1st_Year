#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bit(int p){
    int test = 0;
    int x;
    int i, j;
    FILE *A;//указатели для работы с файлами
    FILE *B;//указатели для работы с файлами
    FILE *C;//указатели для работы с файлами
    A = fopen("file1.txt", "r");//открытие файла 1
    B = fopen("file2.txt", "w");//открытие файла 2
    C = fopen("file3.txt", "w");//открытие файла 3
    fscanf(A, "%d", &x);//считывание из файла1
    while(!feof(A)){
        i=0;
        j=0;
        while(!feof(A) && i<p){//цикл записи в файл 2
            fprintf(B, "%d ", x);
            fscanf(A, "%d", &x);
            i++;
        }
        while(!feof(A) && j<p){//цикл записи в файл 3
            fprintf(C, "%d ", x);
            fscanf(A, "%d", &x);
            j++;
        }
    }
    fcloseall();//закрытие файлов

}
int merge(int p){
    FILE *A;
    FILE *B;
    FILE *C;
    A = fopen("file1.txt", "w");//открытие файла 1
    B = fopen("file2.txt", "r");//открытие файла 2
    C = fopen("file3.txt", "r");//открытие файла 3
    int x;
    int y;
    if (!feof(C)){
        fscanf(B, "%d", &x);//считывание информации из файла 2
        fscanf(C, "%d", &y);//считывание информации из файла 3
        while(!feof(B) && !feof(C)){//проверяется достижение конца файла
            int i =0, j=0;
            while(!feof(B) && !feof(C) && i<p && j<p){//этап сборки из 2 файлов один
                if(x<y){//проверка условий записи
                    fprintf(A, "%d ", x);
                    fscanf(B, "%d", &x);
                    i++;
                }
                else{
                    fprintf(A, "%d ", y);
                    fscanf(C, "%d", &y);
                    j++;
                }
            }
            while(!feof(B) && i<p){
                fprintf(A, "%d ", x);
                fscanf(B, "%d", &x);
                i++;
            }
            while(!feof(C) && j<p){
                    fprintf(A, "%d ", y);
                    fscanf(C, "%d", &y);
                    j++;
            }
        }
        while(!feof(B)){//проверка окончания файла 2
                fprintf(A, "%d ", x);
                fscanf(B, "%d", &x);

            }
        while(!feof(C)){//проверка окончания файла 3
                fprintf(A, "%d ", y);
                fscanf(C, "%d", &y);
        }
        fcloseall();//закрытие файлов
        return 0;
    }
    else{
        return 1;
    }
}
int main (){//основная функция работы
    int p = 1;
    int C_end =0;
    int x=0;
    bit(p);
    while(C_end == 0){
        C_end = merge(p);
        p = 2*p;
        bit(p);
    }
}
