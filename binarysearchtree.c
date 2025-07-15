#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
};
struct node* insert(struct node *ptr, int ikey)
{
    if (ptr == NULL)
    {
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->info = ikey;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (ikey < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, ikey);
    }
    else if (ikey > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, ikey);
    }
    else
    {
        printf("DUPLICATE KEY\n");
    }
    return ptr;
}
struct node* search(struct node *ptr, int skey)
{
    while (ptr != NULL)
    {
        if (skey < ptr->info)
        {
            ptr = ptr->lchild;
        }
        else if (skey > ptr->info)
        {
            ptr = ptr->rchild;
        }
        else
        {
            return ptr; // Key found
        }
    }
    return NULL; // Key not found
}
struct node* min(struct node *ptr)
{
    if (ptr == NULL)
        return NULL;
    while (ptr->lchild != NULL)
    {
        ptr = ptr->lchild;
    }
    return ptr;
}

struct node* max(struct node *ptr)
{
    if (ptr == NULL)
        return NULL;
    while (ptr->rchild != NULL)
    {
        ptr = ptr->rchild;
    }
    return ptr;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;

    if (key < root->info)
        root->lchild = deleteNode(root->lchild, key);
    else if (key > root->info)
        root->rchild = deleteNode(root->rchild, key);
    else
    {
        // Node with only one child or no child
        if (root->lchild == NULL)
        {
            struct node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node* temp = root->lchild;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = min(root->rchild);
        root->info = temp->info; // Copy the inorder successor's content to this node
        root->rchild = deleteNode(root->rchild, temp->info); // Delete the inorder successor
    }
    return root;
}
void inorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%d ", ptr->info);
        inorder(ptr->rchild);
    }
}
void preorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        printf("%d ", ptr->info);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}
void postorder(struct node *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ", ptr->info);
    }
}

int main()
{
    struct node* root = NULL;
    int choice, key;

    do
    {
        printf("\nMENU:\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. DELETE\n");
        printf("4. FIND MINIMUM\n");
        printf("5. FIND MAXIMUM\n");
        printf("6. IN-ORDER TRAVERSAL\n");
        printf("7. PRE-ORDER TRAVERSAL\n");
        printf("8. POST-ORDER TRAVERSAL\n");
        printf("9. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER KEY TO INSERT: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("ENTER KEY TO SEARCH: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
            {
                printf("KEY %d FOUND IN THE TREE.\n", key);
            }
            else
            {
                printf("KEY %d NOT FOUND IN THE TREE.\n", key);
            }
            break;
        case 3:
            printf("ENTER KEY TO DELETE: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("KEY %d DELETED FROM THE TREE.\n", key);
            break;
        case 4:
        {
            struct node* minNode = min(root);
            if (minNode != NULL)
            {
                printf("MINIMUM KEY: %d\n", minNode->info);
            }
            else
            {
                printf("THE TREE IS EMPTY.\n");
            }
        }
        break;
        case 5:
        {
            struct node* maxNode = max(root);
            if (maxNode != NULL)
            {
                printf("MAXIMUM KEY: %d\n", maxNode->info);
            }
            else
            {
                printf("THE TREE IS EMPTY.\n");
            }
        }
        break;
        case 6:
            printf("IN-ORDER TRAVERSAL: ");
            inorder(root);
            printf("\n");
            break;
        case 7:
            printf("PRE-ORDER TRAVERSAL: ");
            preorder(root);
            printf("\n");
            break;
        case 8:
            printf("POST-ORDER TRAVERSAL: ");
            postorder(root);
            printf("\n");
            break;
        case 9:
            printf("EXITING...\n");
            break;
        default:
            printf("INVALID CHOICE! PLEASE TRY AGAIN.\n");
        }
    }
    while (choice != 9);
    return 0;
}
