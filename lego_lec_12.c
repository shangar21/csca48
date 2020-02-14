/*
lego ev3:
- 2 motors / wheels
- 1 attached sensor (sonar head)
- runs linux
- remote conrtol via bluetooth

API for robot control 
- independent simple programs via L.L
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct robot_command_struct
{
	int command;
	float length;
	struct robot_command_struct *next;
}commandNode;

commandNode *new_commandNode(void)
{
	commandNode *new_command = (commandNode *)calloc(1, sizeof(commandNode));

	if(new_command == NULL)
	{
		printf("get rekt, ur mom gey \n");
		return NULL;
	}
	new_command->command = -1;
	new_command->length = -1.0;
	new_command->next = NULL;
	return new_command;
}

commandNode *insert_command(commandNode *head, commandNode *new)
{
	while(head -> next != null)
	{
		*head = head -> next;
	}

	head -> next = *new;
}

void updateCommand(commandNode *head, int which)
{
	commandNode *p = *head;
	int c, com;
	float len;

	for (int i = 0; i < which; i++)
	{
		p = p -> next;
	}

	p -> command = c;
	
}

void deletecommand(commandNode *head, int which)
{
	commandNode *p = NULL;
	commandNode *q = NULL;
	int c;

	if(head == null)
	{
		return NULL;
	}

	if (which == 0)
	{
		q = head -> next;
		freespace(head);
		return q;
	}

	p = head;
	c = 0;

	while(p -> next != NULL && c != which - 1)
	{
		p = p -> next;
		c++;
	}

	q = p -> next;
	p -> next = q -> next;
	free(q);
	return head;

}

void deleteCommandList(commandNode *head)
{
	commandNode *p, *q;
	p = head;
	while(p != NULL)
	{
		q = p -> next;
		free(p);
		p = q;
	}
}

int main()
{

}