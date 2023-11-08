#include <stdlib.h>
#include <stdio.h>

typedef struct s_node {
	int value;
	struct s_node *next;
} t_node;

void print_list(t_node *head)
{
	t_node *tmp = head;

	while(tmp != NULL)
	{
		printf("%d - ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

// function that creates new nodes for us

t_node *create_new_node(int value)
{
	// allocates memory for a new t_node using malloc
	t_node *result = malloc(sizeof(t_node));
	// sets the value of the new node to the provided value
	result->value = value;
	// sets the next pointer of the new node to NULL
	result->next = NULL;
	// returns a pointer to the newly created node
	return (result);
}

//a list that grows to whatever size we need it to be

int main()
{
	// declares two new_node pointers
	t_node	*head = NULL;
	t_node	*tmp;
	int i = 0;
	/*
	// creates a new node with value of 32 and assign it to tmp
	tmp = create_new_node(10);
	// sets the head pointer to point to the newly created node
	head = tmp;
	tmp = create_new_node(8);
	tmp->next = head;
	head = tmp;
	tmp = create_new_node(50);
	tmp->next = head;
	head = tmp;
	*/
	while (i < 12)
	{
		// create a new node with the value of 'i'
		tmp = create_new_node(i);
		// set the next pointer of the new node to the current head of the list
		tmp->next = head;
		// update the head of the list to point to the newly created node
		head = tmp;
		i++;
	}
	// prints the entire linked list starting from te head
	print_list(head);
	return (0);
}

/*
int main()
{
	t_node	n1, n2, n3;
	t_node	*head;

	n1.value = 10;
	n2.value = 9;
	n3.value = 8;

	//link them up
	head = &n1;
	n3.next = NULL;
	n2.next = &n3;
	n1.next = &n2;; //so we know when to stop

	t_node n4;
	n4.value = 13;
	n4.next = &n3;
	n2.next = &n4;

	//remove first value by pointing head to the next one
	head = head->next;

	print_list(head);
	return (0);
}*/
