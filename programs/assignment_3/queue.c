#include <stdio.h>
#include <stdlib.h>
#include "dLinkList.h"

dLinkList head = NULL, temp, tail;

void enqueue(int key)
{
	temp = (dLinkList)malloc(sizeof(dLinkNode));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
	{
		head = tail = temp;
		head->prev = NULL;

		return 0;
	}
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
}

int dequeue()
{
	int key;

	if(head == NULL)
		return 0;

	if(head == tail)
	{
		key = head->data;
		free(head);
		head = NULL;
		return key;
	}

	temp = head;
	key = temp->key;
	head = head->next;
	free(temp);

	return key;
}