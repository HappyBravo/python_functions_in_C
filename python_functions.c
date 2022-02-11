#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int data;
    struct element *next;
    struct element *prev;
};

typedef struct element node;

// %%%%%%%%%%%%%% TAKING INPUT %%%%%%%%%%%%%%
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

// %%%%%%%%%%%%%% FINDING LENGTH OF ARRAY %%%%%%%%%%%%%%
int python_len(node *start)
{
    int count = 0;
    node* temp;
    temp = start;
    if (start == NULL)
        return 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count += 1;
    }
    return count;
}

// %%%%%%%%%%%%%% BEGIN SORTING AN ARRAY %%%%%%%%%%%%%%
/* sort the array by changing the pointers instead of actual data */
node *sorted_merge(node *a, node *b)
{
    node *result = NULL;
    
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    
    if (a->data <= b->data)
    {
        result = a;
        result->next = sorted_merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = sorted_merge(a, b->next);
    }
    return result;
}

/* makes two sub arrays and return their memory addresses*/
void mid_split(node *start, node **a, node **b)
{
    /* fast-slow pointer method used*/
    node *fast, *slow;
    slow = start;
    fast = start->next;

    /* fast has step size of 2 while slow has step size of 1 */
    while(fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    /* slow is before mid point of list, so from here we split it into 2 sub arrays */
    *a = start;
    *b = slow->next;
    slow->next = NULL;
}

void mergesort(node **head)
{
    node *temp, *a, *b;
    temp = *head;

    if ((temp == NULL) || (temp->next == NULL))
    {
        return;
    }
    mid_split(temp, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *head = sorted_merge(a, b);
    // return head;
}

node *python_sort(node *head)
{
    if (head == NULL)
    {
        printf("List is Empty");
        exit(0);
    }
    mergesort(&head);
    return head;
}
// %%%%%%%%%%%%%% END OF SORTING AN ARRAY %%%%%%%%%%%%%%

// %%%%%%%%%%%%%% COUNTING NUMBER OF OCCURANCES OF GIVEN ELEMENT IN ARRAY %%%%%%%%%%%%%%
int python_count(node *start, int value)
{
    int count = 0;
    node* temp;
    temp = start;
    if (start == NULL)
    {
        printf("List is Empty");
        return 0;
    }
    while(temp!=NULL)
    {
        if (temp->data == value)
        {
            count += 1;
        }
        temp=temp->next;
    }
    return count;

}


// %%%%%%%%%%%%%% FINDING UNIQUE ELEMENTS IN ARRAY %%%%%%%%%%%%%%
node *unique(node *head)
{
    node *temp, *nextNext;
    temp = head;

    if (temp == NULL)
    {
        printf("List is Empty");
        exit(0);
    }
    temp = python_sort(temp);
    while(temp->next!= NULL)
    {
        /* comparing current node with next node's data, deleteing next node if matched */
        if (temp->data == temp->next->data)
        {
            nextNext = temp->next->next;
            free(temp->next);
            temp->next = nextNext;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

// %%%%%%%%%%%%%% ADDING ELEMENT AT THE END OF ARRAY %%%%%%%%%%%%%%
node* python_append(node *start, int value)
{
	node *p,*tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->data = value;
	p = start;
    if (p == NULL)
    {
        // printf("Empty List");
        // ENTERING DATA IN AN EMPTY LIST
        start=tmp;
        tmp->next = NULL;
        return start;
    }
   
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;
	tmp->next=NULL;
	// display(start);
	return start;
}

// %%%%%%%%%%%%%% REMOVING ELEMENT FROM END OF ARRAY %%%%%%%%%%%%%%
node* python_pop(node* start)
{
    node *p;
    p=start;
    if (p == NULL)
    {
        printf("List id empty");
        exit(0);
    }
	while(p->next->next != NULL)
		p = p->next;
    free(p->next);
    p->next = NULL;

    return start;
}


// %%%%%%%%%%%%%% INSERTING ELEMENT AT GIVEN INDEX IN ARRAY %%%%%%%%%%%%%%
node* python_insert(node *head, int value, int index)
{
    node *temp, *newNode;
    index = index-1;
    int index_c = 0;
    if (head == NULL)
    {
        // ERROR MESSAGE
        printf("List is empty");
        exit(0);
    }
    newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    
    if (index == -1)
    {
        // ADDING ELEMENT AT THE BEGINNING
        // printf("Adding at beg");
        newNode->next = head;
        head = newNode;          
    }
    
    temp = head;
    
    while((temp!=NULL))
    {
        if (index == index_c)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
            temp=temp->next;
        index_c +=1;
    }
    if (index == index_c-1) 
    {
        // ADDING VALUE AT THE END
        python_append(head, value);
    }
    if (index >= index_c) 
    {
        // ERROR MESSAGE
        printf("Value not entered as index was greater than Length of array");
    }
    return head;
}

// %%%%%%%%%%%%%% REMOVING ELEMENT FROM GIVEN INDEX IN ARRAY %%%%%%%%%%%%%%
node* python_remove(node* head, int index)
{
    node* temp, *newNode, *newhead;
    index = index-1;
    int index_c = 0;
    
    if (head == NULL)
    {
        // ERROR MESSAGE
        printf("List is empty");
        exit(0);
    }

    newhead = head;
    if (index == -1)
    {
        // printf("Removing from beg");
        // REMOVING ELEMNT FROM THE BEGINNING
        newhead = head->next;
        free(head);
        index_c += 1;          
    }
    
    temp = newhead;
    
    
    while((temp->next->next != NULL))
    {
        if (index == index_c)
        {
            newNode = temp->next->next;
            free(temp->next);
            temp->next = newNode;
        }
        else
            temp=temp->next;
        index_c += 1;
    }
    if (index == index_c) 
    {
        // REMOVING ELEMENT FROM END
        python_pop(head);
    }
    if (index >= index_c) 
    {
        // ERROR MESSAGE
        printf("Value not Removed as index was greater than Length of array");
    }
    return newhead;
}

// %%%%%%%%%%%%%% DELETING ENTIRE ARRAY %%%%%%%%%%%%%%
node* python_deleteList(node* head)
{
    node *temp, *next;
    temp = head;
    
    while(temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    // head->data = NULL;
    // head->next = NULL;
    head = NULL;
    return head;
}

// %%%%%%%%%%%%%% REVERSING ARRAY %%%%%%%%%%%%%%
node* python_reverse(node *head)
{
	node *prev, *temp, *next;
	prev = NULL;
   	temp = head;
	while(temp != NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	head = prev;
    
	return head;
}

// %%%%%%%%%%%%%% CONCATINATES TWO ARRAYS %%%%%%%%%%%%%%
node *concat(node *head1, node *head2)
{
    node *temp;
    if (head1 == NULL)
    {
        head1 = head2;
        return head1;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    temp = head1;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    
    return head1;
}

// %%%%%%%%%%%%%% CREATES NON-EMPTY ARRAY %%%%%%%%%%%%%%
node *create_list(int n)
{
    node *newNode, *temp, *head;
    int data, i;
    
    head = (node*)malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Error in allocating Head");
        exit(0);
    }
    data = atoi(python_input("Enter the data for FIRST node : "));
    
    head->data = data;
    head->next = NULL;

    temp = head;
    for(i = 2; i<=n; i++)
    {
        newNode = (node*)malloc(sizeof(node));
        if (head == NULL)
        {
            printf("Error in allocating memory");
            exit(0);
        }
        data = atoi(python_input("\rEnter data for next node : "));
        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

// %%%%%%%%%%%%%% PRINTING ELEMENTS OF ARRAY %%%%%%%%%%%%%%
void printList(node *head)
{
    node* temp;
    if (head == NULL)
    {
        printf("List is empty");
        exit(0);
        // return;
    }
    temp = head;
    printf("\n[");
    while(temp!=NULL)
    {
        printf("%d, ", temp->data);
        temp=temp->next;
    }
    printf("]\n");
    // printf("NULL\n");
}
