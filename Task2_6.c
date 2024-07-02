#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{

    unsigned int key;
    struct Node* left;
    struct Node* right;
    
} Node;

Node* createNode(unsigned int key){

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL){

        fprintf(stderr, "Ошибка выделения памяти для узла\n");
        exit(EXIT_FAILURE);
        
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;

}

Node* insert(Node* root, unsigned int key){

    if (root == NULL){

        return createNode(key);

    }

    if (key < root->key){

        root->left = insert(root->left, key);

    } 

    else if (key > root->key){

        root->right = insert(root->right, key);

    }

    return root;

}

Node* search(Node* root, unsigned int key){

    if (root == NULL || root->key == key){

        return root;

    }

    if (key < root->key){

        return search(root->left, key);

    }

    return search(root->right, key);

}

Node* deleteNode(Node* root, unsigned int key){

    if (root == NULL){

        return root;

    }

    if (key < root->key){

        root->left = deleteNode(root->left, key);

    }

    else if (key > root->key){

        root->right = deleteNode(root->right, key);

    } 
    else{

        if (root->left == NULL){

            Node* temp = root->right;
            free(root);

            return temp;

        } 

        else if (root->right == NULL){

            Node* temp = root->left;
            free(root);

            return temp;

        }

        Node* temp = root->right;

        while (temp->left != NULL){

            temp = temp->left;

        }

        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);

    }

    return root;

}

void freeTree(Node* root){

    if (root != NULL){

        freeTree(root->left);
        freeTree(root->right);
        free(root);

    }

}

int main(){

    Node* root = NULL;
    char input[10];

    while (scanf("%s", input) != EOF){

        unsigned int key;
        char action;
        sscanf(input, "%c%u", &action, &key);

        switch (action){

            case '+':
                root = insert(root, key);
                break;
            case '-':
                root = deleteNode(root, key);
                break;
            case '?':
                {
                    Node* result = search(root, key);

                    if (result != NULL){

                        printf("%u yes\n", key);

                    } 
                    
                    else{

                        printf("%u no\n", key);

                    }

                }

                break;

        }

    }

    freeTree(root);
    return 0;

}
