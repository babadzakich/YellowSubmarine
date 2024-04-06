typedef struct pair
{
    int dist;
    int val;
}pair;

int size;
int P[__INT32_MAX__];
pair heap[10000];

void sieve_up(int n)
{
    while (n > 1)
    {
        if (heap[n].dist >= heap[n/2].dist)
        {
            break;
        }
        swap(&P[heap[n/2].val], &P[heap[n].val]);
        swap(&heap[n], &heap[n/2]);
        n /= 2;
    }
}

void add_heap(pair val)
{
    heap[size++] = val;
    P[val.val] = size;
    sieve_up(size);
}