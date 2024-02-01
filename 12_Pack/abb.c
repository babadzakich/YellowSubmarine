#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define big_boss 1000007

uint32_t hash(const char* str,  int size){
uint32_t res=1;
for(int i=0; i<size; i++)
{
res = res*17%big_boss + (str[i]-'a'+1);
}
return res % big_boss;
}

typedef struct
{
  char name[31];
  int year;
  char country[11];
  struct ActorBio *next;
}ActorBio;

typedef struct
{
  char name[31];
  char movie[21];
}ActorInMovie;

typedef struct   
{
  ActorBio  arr;
}Hash_table;

void init_hash_table(Hash_table * hash_arr)
{
  for (int i = 0; i < big_boss; i++) hash_arr->arr[i] = NULL;
}

void add_an_elem(Hash_table * hash_arr, char* name, char*country, int year)
{
  uint32_t key = hash(name, sizeof(name));
  ActorBio * new = (ActorBio*)malloc(sizeof(ActorBio));
  strcpy(new->country, country);
  strcpy(new->name, name);
  new->year = year;
  new->next = NULL;
  if(hash_arr->arr[key] == NULL)
  {
    hash_arr->arr[key] = new;
  }
  else
  {
    ActorBio * tmp = hash_arr->arr[key];
    while (tmp->next != NULL)
    {
      tmp = tmp->next;
    }
    tmp->next = new;
  }
}

void del(Hash_table * hash_arr, char* name)
{
  uint32_t key = hash(name, sizeof(name));
  ActorBio * now = hash_arr->arr[key];
  if (now != NULL)
  {
    hash_arr->arr[key] = now->next;
    free(now);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  char symb;
  ActorBio * ab = (ActorBio*)malloc(sizeof(ActorBio)*n);
  for(int i = 0; i<n; i++)
  {
    scanf("%c", &symb); // \n
    scanf("%c", &symb); // "
    scanf("%c", &symb); // first elem
    int k = 0;
    while(symb != '"')
    {
      ab[i].name[k] = symb;
      k++;
      scanf("%c", &symb);
    }
    ab[i].name[k] = '\0';
    scanf("%d", &ab[i].year);
    scanf("%c", &symb); // 'пробел'
    scanf("%c", &symb); // "
    scanf("%c", &symb); // first elem
    k = 0;
    while(symb != '"')
    {
      ab[i].country[k] = symb;
      k++;
      scanf("%c", &symb);
    }
    ab[i].country[k] = '\0';
  }
  int m;
  scanf("%d", &m);
  ActorInMovie * aim = (ActorInMovie*)malloc(sizeof(ActorInMovie)*m);
  for(int i = 0; i<m; i++)
  {
    scanf("%c", &symb); // \n
    scanf("%c", &symb); // "
    scanf("%c", &symb); // first elem
    int k = 0;
    while(symb != '"')
    {
      aim[i].name[k] = symb;
      k++;
      scanf("%c", &symb);
    }
    aim[i].name[k] = '\0';
    scanf("%c", &symb); // 'пробел'
    scanf("%c", &symb); // "
    scanf("%c", &symb); // first elem
    k = 0;
    while(symb != '"')
    {
      aim[i].movie[k] = symb;
      k++;
      scanf("%c", &symb);
    }
    aim[i].movie[k] = '\0';
  }
  Hash_table table;
  table.arr = (ActorBio)malloc(sizeof(ActorBio*)*big_boss);
  init_hash_table(&table);
  for(int i = 0; i<n; i++)
  {
    add_an_elem(&table, ab->name, ab->country, ab->year);
  }
  for(int i = 0; i<m; i++)
  {
    uint32_t key = hash(aim[i].name, sizeof(aim[i].name));
    ActorBio * tmp = table.arr[key];
    if(tmp != NULL && (strcmp(aim[i].name, tmp->name) == 0))
    {
      printf("\"%s\" ", tmp->name);
      printf("%d ", tmp->year);
      printf("\"%s\" ", tmp->country);
      printf("\"%s\" ", aim[i].name);
      printf("\"%s\" \n", aim[i].movie);
      del(&table, tmp->name);
    }
    else
    {
      while (tmp != NULL && (strcmp(tmp->name, aim[i].name) != 0))
      {
        tmp = tmp->next;
      }
    }
  }
  free(table.arr);
  free(ab);
  free(aim);
  return 0;
}