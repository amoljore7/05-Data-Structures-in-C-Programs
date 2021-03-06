//////////////////////////////////////////////////////////////////////////////////////////
//
//			Implementation of Queue using Linked List
//
//////////////////////////////////////////////////////////////////////////////////////////

/*
-----------------------------------------------------------------------------------
Queue is abstract data types (ADT)
Queue is a FIFO data structure. First-in-ﬁrst-out.
We can implement Queue in two ways
	1.Arrays
	2.Linked lists

Basic operations on Queue:
	enqueue(element): Add element to the end of the queue
	dequeue() Returns the element from the front of the queue, removing it
	isEmpty() Returns true if queue empty
	isFull() Returns true if queue full

Applications of Queues :
	Waiting lists
	Access to shared resources (e.g., printer)
	Multiprogramming
-----------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<malloc.h>

# define MAX 10

struct Queue
{
	int data;
	struct Queue *next;
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//
//	Description:
//		This function acounts number of elements in queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
int Count(struct Queue *head)
{
	int no = 0;
	
	while(head != NULL)
	{
		++no;
		head = head -> next;
	}
	return no;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsQueueEmpty
//
//	Description:
//		This function checks whether queue is empty or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsQueueEmpty(struct Queue *head)
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	IsQueueFull
//
//	Description:
//		This function checks whether queue is full or not.
//
///////////////////////////////////////////////////////////////////////////////////////////
int IsQueueFull(struct Queue *head)
{
	if(Count(head) == MAX)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//
//	Description:
//		This function displays contents of queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
void Display( struct Queue *head )
{
	if(head == NULL)
	{
		return;
	}
	while(head)
	{
		printf(" -> |%d| ", head->data);
		head = head -> next;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	dequeue
//
//	Description:
//		This function remove element from queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
int dequeue(struct Queue **head)
{
	int no;
	struct Queue *temp;
	temp = ( *head );
	if(IsQueueEmpty(*head))
	{
		return -1;
	}
	else
	{
		(*head) = temp->next;
		no = temp -> data;
		free(temp);
	}
	return no;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	enqueue
//
//	Description:
//		This function add element in queue.
//
///////////////////////////////////////////////////////////////////////////////////////////
void enqueue(struct Queue **head, int no)
{
	struct Queue *temp;
	struct Queue *newn = (struct Queue*)malloc(sizeof(struct Queue));
	newn -> data = no;
	
	temp = (*head);
	
	if(IsQueueFull(*head))
	{
		free(newn);
		return;
	}

	if(*head == NULL)
	{
		newn -> next = NULL;
		(*head) = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp -> next;
		}
		temp -> next = newn;
		newn -> next = NULL;
	}
}


int main(int argc, char *argv[])
{
	struct Queue * first = NULL;

	enqueue(&first,10);
	enqueue(&first,20);
	enqueue(&first,30);
	enqueue(&first,40);

	printf("Contents of Queue are :\n");
	Display(first);

	printf("%d",dequeue(&first));
	printf("%d",dequeue(&first));

	printf("\nContents of Queue are :\n");
	Display(first);

	return 0;
}

/*
	Important points about implementaion of Queue by using Array or LinkedList

	Array
	• Simple and efficient
	• Assume a fixed capacity for array
	• If capacity is too small, can reallocate, but expensive
	• If capacity is too large, space waste

	Linked Lists
	• No size limitation
	• Extra space per element

	When know the maximum number of element, use arrays
*/