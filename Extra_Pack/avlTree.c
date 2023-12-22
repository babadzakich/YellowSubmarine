#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define minimal 1000000001

typedef struct Tree
{
    struct Tree *left, *right;
    int value;
    int height;
}Root;

Root* rotateLeft(Root* root)
{
    Root* temp = root->right;
    root->right = root->right->left;
    temp->left = root;
    return temp;
}

Root* rotateRight(Root* root)
{
    Root* temp = root->left;
    root->left = root->left->right;
    temp->right = root;
    return temp;
}

void updateHeight(Root* root)
{
    int height = 0;
    
    if (root->left != NULL)
    {
        height = height > root->left->height ? height : root->left->height;
    }
    
    if(root->right != NULL)
    {
        height = height > root->right->height ? height : root->right->height;
    }
    
    root->height = height + 1;
}

Root* rebalance(Root* root)
{
    int heightLeft, heightRight;
    heightLeft = root->left == NULL ? 0 : root->left->height;
    heightRight = root->right == NULL ? 0 : root->right->height;

    if (abs(heightLeft - heightRight) <= 1)
    {
        updateHeight(root);
        return root;
    }

    if (heightRight > heightLeft)
    {
        int heightRightLeft, heightRightRight;
        heightRightLeft = root->right->left == NULL ? 0 : root->right->left->height;
        heightRightRight = root->right->right == NULL ? 0 : root->right->right->height;
        
        if (heightRightLeft == heightRightRight + 1)
        {
            root->right = rotateRight(root->right);
        }

        root = rotateLeft(root);
        updateHeight(root->left);
        updateHeight(root);
    }
    else
    {
        int heightLeftLeft, heightLeftRight;
        heightLeftLeft = root->left->left == NULL ? 0 : root->left->left->height;
        heightLeftRight = root->left->right == NULL ? 0 : root->left->right->height;

        if(heightLeftRight == heightLeftLeft + 1)
        {
            root->left = rotateLeft(root->left);
        }

        root = rotateRight(root);
        updateHeight(root->right);
        updateHeight(root);
    }
    return root;
}

void lower_bound(Root* root, int value, int* minimum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->value >= value)
    {
        if(root->value < *minimum)
        {
            *minimum = root->value;
        }
        lower_bound(root->left, value, minimum);
    }
    else
    {
        lower_bound(root->right, value, minimum);
    }
}

Root* delete(Root* root, int value)
{
    if(root == NULL)
    {
        printf("miss\n");
        return root;
    }
    if(root->value > value)
    {
        root->left = delete(root->left, value);
    }
    else if (root->value < value)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        if(root->left == NULL)
        {
            Root* temp = root->right;
            free(root);
            printf("removed\n");
            return temp;
        }
        else if (root->right == NULL)
        {
            Root* temp = root->left;
            free(root);
            printf("removed\n");
            return temp;
        }
        Root* step = root->right;
        while (step->left != NULL)
        {
            step = step->left;
        }
        root->value = step->value;
        root->right = delete(root->right, step->value);
    }
    return rebalance(root); 
}


Root* add(Root* root, int value)
{
    if(root == NULL)
    {   
        Root* new = (Root*)malloc(sizeof(Root));
        new->value = value;
        new->height = 0;
        new->left = new->right = NULL;
        printf("added\n");
        return new;
    }
    
    if(root->value > value)
    {
        root->left = add(root->left, value);
    }
    else if (root->value < value)
    {
        root->right = add(root->right, value);
    }
    else
    {
        printf("dupe\n");
        return root;
    }
    
    return rebalance(root);
}

void freeTree(Root* root)
{
    if (root == NULL)
    {
        return;
    }
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int length;
    scanf("%d", &length);
    Root* root = NULL;
    for(int step = 0; step < length; step++)
    {
        int minimum = minimal;
        char operation[7];
        int number;
        scanf("%s", operation);
        scanf("%d", &number);
        if (strcmp(operation, "add") == 0)
        {
            root = add(root, number);
        }
        else if(strcmp(operation, "remove") == 0)
        {
            root = delete(root, number);
        }
        else if(strcmp(operation, "lower") == 0)
        {
            lower_bound(root, number, &minimum);
            if (minimum == minimal)
            {
                printf("###\n");
            }
            else
            {
                printf("%d\n", minimum);
            }
        }
    }
    //printInorder(root);
    freeTree(root);
    return 0;
}