#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

typedef struct Node {
struct Node * prev , * next ;
double value ;
} Node ;

//создаёт пустой список
//возвращает указатель на value в голове списка (вспом. узел)
double * initList ()
{
    Node* header = (Node*)malloc(sizeof(Node));
    header->next = header;
    header->prev = header;
    return &header->value;
}
//полностью освобождает память списка
//принимает указатель на value голове списка (вспом. узел)
void freeList ( double * head )
{
    Node* step = head;
    while (step != head)
    {
        Node *temp = step->next;
        free(step);
        step = temp;
    }
    free(head);
    
}
//определяет следующий элемент после заданного
//(для вспом. узла возвращает первый элемент)
double * getNext ( double * curr );
//определяет предыдущий элемент перед заданным
//(для вспом. узла возвращает последний элемент)
double * getPrev ( double * curr );
//создаёт и вставляет узел со значением newval сразу после узла where
double * addAfter ( double * where , double newval );
//создаёт и вставляет узел со значением newval сразу перед узлом where
double * addBefore ( double * where , double newval );
//удаляет и освобождает заданный узел
void erase ( double * what );

int main()
{
    Node nde;
    double* ndd = &nde.value;
    Node currentNode = *((Node*)ndd - offsetof(Node, value));
    return 0;
}