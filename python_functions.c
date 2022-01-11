#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct
// {
//     int length;
//     int elements[];
// }list;


char *python_input(char s[])
{
    FILE *fp = stdin;
    fflush(stdin);
    int size = 10;
    char *str;
    int ch;
    int len = 0;
    str = realloc(NULL, sizeof(*str)*size); //size is start size
    
    printf("%s", s);
    
    if(!str) return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';
    str = realloc(str, sizeof(*str)*len);
    
    return str;
}

// int python_len(int *array[])
// {
//     printf("\nstart %d", array);
//     printf("\nend %d", (*array+1));
    
//     // int count = 0;
//     // int temp[] = {};
//     // printf("\nSize of array : %d", *(&array+1)-array);
//     // for (int i = 0; i<sizeof(*array); i++)
//     // {
//     //     printf("\n- %d ", array[i]);
//     // //     temp[i] = array[i];
//     // //     printf("\n%d", temp[i]);
//     // }

//     return &array[1]-array;
// }

// int python_append(int *list[], int *tobeadded[])
// {
//     return 0;
// }