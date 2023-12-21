#include <stdio.h>
#include<stdlib.h>

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

Root* add(Root* root, int value)
{
    if(root == NULL)
    {   
        Root* new = (Root*)malloc(sizeof(Root));
        new->value = value;
        new->height = 1;
        new->left = new->right = NULL;
        return new;
    }
    
    if(root->value >= value)
    {
        root->left = add(root->left, value);
    }
    else
    {
        root->right = add(root->right, value);
    }
    
    return rebalance(root);
}

void printInorder(Root* root, FILE* out)
{
    if (root == NULL)
    {
        return;
    }
    // First recur on left child
    printInorder(root->left, out);

    // Then print the data of node
    fwrite(&root->value, sizeof(int), 1, out);
 
    // Now recur on right child
    printInorder(root->right, out);
}
void freeTree(Root* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right != NULL)
    {
        freeTree(root->right);
    }
    else if(root->left != NULL && root->right == NULL)
    {
        freeTree(root->left);
    }
    else if (root->left == NULL && root->right == NULL)
    {
        free(root);
        root = NULL;
    }
    else
    {
        freeTree(root->left);
        freeTree(root->right);
    }
    
}

int main()
{
    FILE *in = fopen("input.bin","rb");
    FILE *out = fopen("output.bin","wb");
    int length;
    fread(&length, sizeof(int), 1, in);
    int* array = (int*)malloc(sizeof(int) * length);
    fread(array, sizeof(int), length, in);
    Root* root = NULL;
    for(int step = 0; step < length; step++)
    {
        root = add(root, array[step]);
    }
    printInorder(root, out);
	free(array);
    freeTree(root);
	fclose(in);
	fclose(out);
    return 0;
}