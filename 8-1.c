// Design, Develop and Implement a menu driven Program in C for the following 
// operations on Binary Search Tree (BST) of Integers
// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
// b. Traverse the BST in Inorder, Preorder and Post Order
// c. Search the BST for a given element (KEY) and report the appropriate 
// message
// d. Exit

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

void inorder(struct Node* temp) {
    if (temp == NULL)
        return;

    inorder(temp->left);
    printf("%d\t", temp->data);
    inorder(temp->right);
}

void preorder(struct Node* temp) {
    if (temp == NULL)
        return;

    printf("%d\t", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

void postorder(struct Node* temp) {
    if (temp == NULL)
        return;

    postorder(temp->left);
    postorder(temp->right);
    printf("%d\t", temp->data);
}

int search(struct Node* temp, int key) {
    if (temp == NULL)
        return 0;
    else if (temp->data == key)
        return 1;
    else {
        if (key < temp->data)
            return search(temp->left, key);
        else
            return search(temp->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(keys)/sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, keys[i]);

    int loop = 1;
    while (loop) {
        printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Search\n5. Exit\n");
        int choice, key;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: inorder(root); break;
            case 2: preorder(root); break;
            case 3: postorder(root); break;
            case 4: 
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found\n");
                else
                    printf("Key not found\n");
                break;
            case 5: loop = 0; break;
            default: printf("Invalid choice\n");
        }
    }

    return 0;
}