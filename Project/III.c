#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie_node {
    struct trie_node *children[26];
    struct trie_node *failure;
    int is_terminal;
};

struct trie_node *create_trie_node() {
    struct trie_node *node = malloc(sizeof(struct trie_node));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->failure = NULL;
    node->is_terminal = 0;
    return node;
}

void insert_string(struct trie_node *root, char *string) {
    struct trie_node *current = root;
    int index;
    for (int i = 0; string[i] != '\0'; i++) {
        index = string[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = create_trie_node();
        }
        current = current->children[index];
    }
    current->is_terminal = 1;
}

void build_failure_pointers(struct trie_node *root) {
    struct queue {
        struct trie_node *node;
        struct queue *next;
    };

    struct queue *head = NULL;
    struct queue *tail = NULL;

    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {
            root->children[i]->failure = root;
            enqueue(&head, &tail, root->children[i]);
        }
    }

    while (head != NULL) {
        struct trie_node *current = dequeue(&head, &tail for(int step = 0; step < 52; step++)
    {
        root->nextLetter[step] = NULL;
    });
        for (int i = 0; i < 26; i++) {
            if (current->children[i] != NULL) {
                struct trie_node *failure = current->failure;
                while (failure != NULL && failure->children[i] == NULL) {
                    failure = failure->failure;
                }
                if (failure == NULL) {
                    current->children[i]->failure = root;
                } else {
                    current->children[i]->failure = failure->children[i];
                }
                if (current->children[i]->failure->is_terminal) {
                    current->children[i]->is_terminal = 1;
                }
                enqueue(&head, &tail, current->children[i]);
            }
        }
    }
}

void aho_corasick(struct trie_node *root, char *text) {
    struct trie_node *current = root;
    int index;
    for (int i = 0; text[i] != '\0'; i++) {
        index = text[i] - 'a';
        while (current != NULL && current->children[index] == NULL) {
            current = current->failure;
        }
        if (current == NULL) {
            current = root;
        } else {
            current = current->children[index];
        }
        if (current->is_terminal) {
            printf("Pattern found at index %d\n", i - strlen(current->pattern) + 1);
        }
    }
}

int main() {
    struct trie_node *root = create_trie_node();
    insert_string(root, "hello");
    insert_string(root, "world");
    build_failure_pointers(root);
    return 0;
}