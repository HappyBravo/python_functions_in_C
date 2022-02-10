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

// %%%%%%%%%%%%%% ADDING ELEMENT AT THE END OF ARRAY %%%%%%%%%%%%%%
node* python_append(node *start, int data)
{
	node *p,*tmp;
	tmp = (node *)malloc(sizeof(node));
	tmp->data = data;
	p=start;
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
	while(p->next->next != NULL)
		p = p->next;
    free(p->next);
    p->next = NULL;

    return start;
}


// %%%%%%%%%%%%%% INSERTING ELEMENT AT GIVEN INDEX IN ARRAY %%%%%%%%%%%%%%
node* python_insert(node *head, int value, int index)
{
    node* temp, *newNode;
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
