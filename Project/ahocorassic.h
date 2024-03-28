typedef struct Node
{
    int nextLetter[52];
    struct Node* parent;
    int isWord;
}Node;
void initTrie(char* str, int strlen);
int isInTrie(char* pattern, int len);