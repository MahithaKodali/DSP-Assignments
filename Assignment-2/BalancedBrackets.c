#include<stdio.h>
#include<string.h>
#define MAX 100
struct stack
{
  char stck[MAX];
  int top;
} s;

void push (char item)
{
  if (s.top == (MAX - 1))
    printf ("Stack is Full\n");

  else
    {
      s.top = s.top + 1;
      s.stck[s.top] = item;

    }

}

void pop ()
{
  if (s.top == -1)
    printf ("Stack is Empty\n");

  else
    s.top = s.top - 1;
}

int main()
{
  char exp[MAX];

  int i = 0;

  s.top = -1;

  printf ("\nEnter the expression : ");
  scanf ("%s", exp);

  for (i = 0; i < strlen (exp); i++)
    {

      if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
	{
	  push (exp[i]);
	  continue;

	}

      else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
	{

	  if (exp[i] == ')')
	    {

	      if (s.stck[s.top] == '(')
		     pop ();

	      else
		  break;
	    }

	  if (exp[i] == ']')
	    {

	      if (s.stck[s.top] == '[')
		    pop ();

	      else
		  break;
	    }

	  if (exp[i] == '}')
	    {

	      if (s.stck[s.top] == '{')
		    pop ();

	      else
		  break;
	    }
	}

    }

  if (s.top == -1)
    printf ("\nTRUE\n");
  else
  	printf("\nFALSE");
}

