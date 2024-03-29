#ifdef HASHMAP_EXPORTS
    #define HASHMAP_API "default"
#else
    #define HASHMAP_API "hidden"
#endif
#include <stdint.h>
#include <stddef.h>

 typedef const void * cpvoid ;
 typedef int (* EqualFunc )( cpvoid a , cpvoid b );
 typedef uint32_t (*HashFunc)( cpvoid key );




 typedef struct vector{
    size_t top;
    size_t cap;
    cpvoid * keys;
    cpvoid * values;
}vector;


 typedef struct HashMap{
    size_t size;
    vector * table;
    HashFunc hf;
    EqualFunc ef;
}HashMap;


//creates and returns new hash table wit:
// [ef] –- function which compares keys for equality
// [hf] –- function which produces a hash for a key
// [size] –- prescribed size/capacity of the hash table (number of cells)
 HashMap HM_Init ( EqualFunc ef , HashFunc hf , int size );
//frees memory of hash map [self]
//note: called exactly once for every hash map created by HM_Init
 void HM_Destroy ( HashMap * self );
//returns value corresponding to the specified key [key] in hash map [self]
//if [key] is not present in the map, then returns NULL
 cpvoid HM_Get ( const HashMap * self , cpvoid key );
//sets value [value] for the key [key] in hash map [self]
//if [self] already has some value for [key], it is overwritten
 void HM_Set ( HashMap * self , cpvoid key , cpvoid value );
