#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{

    char *word;
    struct Node *next;

};

void addWord(struct Node **head, char *word){

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->word = strdup(word);
    newNode->next = NULL;

    if (*head == NULL){

        *head = newNode;
        return;

    }

    struct Node *temp = *head;

    while (temp->next != NULL){

        temp = temp->next;

    }

    temp->next = newNode;

}

void removeWord(struct Node **head){

    if (*head == NULL || (*head)->next == NULL){

        return;

    }

    struct Node *prev = NULL;
    struct Node *lastNode = *head;

    while (lastNode->next != NULL){

        prev = lastNode;
        lastNode = lastNode->next;

    }

    struct Node *current = *head;
    struct Node *prevToMatch = NULL;

    while (current != lastNode){

        if (strcmp(current->word, lastNode->word) == 0){

            if (prevToMatch == NULL){

                *head = current->next;

            } 

            else{

                prevToMatch->next = current->next;

            }

            free(current->word);
            free(current);
            current = (prevToMatch == NULL) ? *head : prevToMatch->next;

        } 

        else{

            prevToMatch = current;
            current = current->next;

        }
    }
}

void freeList(struct Node **head){

    struct Node *temp;

    while (*head != NULL){

        temp = *head;
        *head = (*head)->next;
        free(temp->word);
        free(temp);

    }

}

int main(){

    char input[1000];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    struct Node *head = NULL;

    char *token = strtok(input, " \t\n");
    while (token != NULL){

        addWord(&head, token);
        token = strtok(NULL, " \t\n");

    }

    removeWord(&head);
    struct Node *temp = head;

    while (temp != NULL){

        printf("%s ", temp->word);
        temp = temp->next;

    }

    printf("\n");

    freeList(&head);

    return 0;

}
