#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* right;
    struct Node* left;
} Node;

Node* CreateTree(int data){
    Node* tree = (Node*)malloc(sizeof(Node));
    if(tree == NULL) return NULL;

    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void add(Node* root, int num){
    if(root == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return;

    newNode->data = num;
    newNode->right = NULL;
    newNode->left = NULL;
    
    Node* current = root;

    while(current){
        if(current->data <= num){
            if(current->right == NULL){
                current->right = newNode;
                break;
            } else{
                current = current->right;
            }
            
        } else{
            if(current->left == NULL){
                current->left = newNode;
                break;
            } else{
                current = current->left;
            }
        }
    }
}

int max(int a, int b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
}

int height(Node* root){
    if(root == NULL) return 0;

    return max(height(root->left), height(root->right)) + 1;
}

void printTree(Node* root) {
    if (root == NULL) return;

    printTree(root->left);  // Recursively print left subtree
    printf("%d ", root->data);  // Print the root node
    printTree(root->right);  // Recursively print right subtree
}

int main(){
    Node* root = CreateTree(3);
    
    add(root,6);
    add(root,1);
    add(root,4);

    printf("Tree in-order traversal: ");
    printTree(root);
    printf("\n");

    int heights = height(root);

    printf("height: %d", heights);

    return 0;
}