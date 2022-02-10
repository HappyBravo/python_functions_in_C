#include "python_functions.c"

int main()
{
    // char *name;
    // int a = 0;
    // name = python_input("Enter number : ");
    // printf("%s", name);

    node *l, *l2;
    int n = atoi(python_input("Length of nodes : "));
    l = create_list(n);
    printList(l);
    printf("\n\t - - Length of array = %d\n", python_len(l));
/*
    l= python_insert(l, atoi(python_input("Enter Value to be inserted : ")), atoi(python_input("At index : ")));
    printf("\nAfter inserting\n");
    printList(l);
    printf("\n\t - - Length of array = %d\n", python_len(l));

    l = python_remove(l, atoi(python_input("Remove from index : ")));
    printList(l);
    printf("\n\t - - Length of array = %d", python_len(l));
*/
    l = python_reverse(l);
    printList(l);

    // printf("\nDeleting list \n");
    // printList(python_deleteList(l));

    // printf("Clear list");
    // l = python_clearList(l);
    // printList(l);
    
    printf("\nAppending -- \n");
    for (int i = 0; i<3; i++)
    {
        l = python_append(l, 6);
    }
    printList(l);

    printf("\n -- Counting %d", python_count(l, 6));
    printf("\n sorting --- \n");

    l = python_sort(l);
    printList(l);


    printf("\nMaking new list\n");
    // node *l2;
    l2 = create_list(atoi(python_input("Enter length of list : ")));
    printf("\nAppending -- \n");
    for (int i = 0; i<3; i++)
    {
        l2 = python_append(l2, atoi(python_input("Enter a value : ")));
    }
    printf("List 2 : ");printList(l2);
    printf("List 1 : ");printList(l);
    getchar();
    node *l3;
    l3 = concat(l, l2);
    printf("List 1 : ");printList(l);
    printf("List 2 : ");printList(l2);
    printf("List 3 : ");printList(l3);
    
    // printf("\nUnique values ONLY -- \n");
    // l = unique(l);
    // printList(l);
    // printf("Making new list\n");
    // l2 = create_list(6);
    // printList(l);
    // printf("\nNew list");
    // getchar();
    return 0;
}