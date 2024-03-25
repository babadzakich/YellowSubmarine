#define finka(A, B) A ## B
#define nkvd(A, B) finka(A, B)
#define sigma(A) nkvd(NAME, A)
typedef struct {
    int n;
    TYPE *arr; 
    int cap; 
} NAME;
void sigma(_reserve)(NAME *vec , int capacity );
void sigma(_init)(NAME *vec);
void sigma(_destroy)(NAME *vec);
int sigma(_push)(NAME *vec , TYPE value);
TYPE sigma(_pop)(NAME *vec);
void sigma(_resize)(NAME *vec , int newCnt , TYPE fill);
void sigma(_insert)(NAME *vec , int where , TYPE *arr , int num);
void sigma(_erase)(NAME *vec , int where , int num);