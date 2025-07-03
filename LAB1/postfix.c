
#include <stdio.h>
#include <math.h>
#include<stdlib.h> 
#include <ctype.h>
#include <string.h>

#define Max 5

struct stack
{
  int TOS;
  float data[Max];
};

int isFull(struct stack *s)
{
  return (s->TOS == Max - 1 ? 1 : 0);
}

int isEmpty(struct stack *s)
{
  return (s->TOS == -1 ? 1 : 0);
}

void Push(struct stack *s, float element)
{
  if(isFull(s))
  {
    printf("Stack overflow\n");
    return;
  }
  s->TOS++;
  s->data[s->TOS] = element;
}

float Pop(struct stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow\n");
    return -1; // Return an invalid value or handle error appropriately
  }
  int pop = s->data[s->TOS];
  s->TOS--;
  return pop;
}



int main()
{

  char ch[100];
  char* token;
  float pop2, pop1;
  struct stack s;
  double num, result;
  s.TOS = -1;

  printf("enter the postfix expression separated by space (12 3 4 * +...):\n");
  fgets(ch, sizeof(ch), stdin);
  token = strtok(ch, " \n"); // Tokenize the input string by spaces and newlines
  
while(token!= NULL)
  {
    if ((isdigit(token[0]) )|| (token[0] == '-' && isdigit(token[1])))
    {
     num = (float)atof(token); 
      Push(&s, num); 
    }

    else 
    {
        pop1 = Pop(&s);
        pop2 = Pop(&s);


        switch (token[0])
        {
        case '+':
          result = pop2 + pop1;
          Push(&s, result);
          break;

        case '-':
          result = pop2 - pop1;
          Push(&s, result);
          break;

        case '*':
          result = pop2 * pop1;
          Push(&s, result);
          break;

        case '/':
          result = pop2 / pop1;
          Push(&s, result);
          break;

        case '^':
          result = pow(pop2, pop1);
          Push(&s, result);
          break;
        }
      }
      token = strtok(NULL, " \n"); // Get the next token
  }
  printf("%f", Pop(&s));
}
