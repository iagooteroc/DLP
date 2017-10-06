/*
* Authors:
*   Iago Otero Coto - iago.oteroc
*   Jorge Viteri Letamendia - j.viteri.letamendia
* Emails:
*   iago.oteroc@udc.es
*   j.viteri.letamendia@udc.es
 */


#include "Abb_functions.h"
#include <stdio.h>



/*
 *
 */

void preorder(Node* tree) {
    printf("(");
    if (! isEmptyTree(tree)) {
        if (! isEmptyTree(tree->right) || ! isEmptyTree(tree->left)) {
            printf(" %d ", tree->key);
            preorder(tree->left);
            printf(" ");
            preorder(tree->right);
        }else{
            printf(" %d ",tree->key);
        }
    }
    printf(")");
}

int main(int argc, char** argv) {

    Node* tree = NULL;

    printf("Insert...\n");
    insertKey(&tree,4);
    insertKey(&tree,4);
    insertKey(&tree,2);
    insertKey(&tree,6);
    insertKey(&tree,1);
    insertKey(&tree,3);
    insertKey(&tree,5);
    insertKey(&tree,7);
    printf("\n");


    printf("Preorden\n");
    preorder(tree);
    printf("\n");

    printf("Search\n");
    printf("search 1... %d\n", (searchKey(tree,1))->key);
    printf("search 2... %d\n", (searchKey(tree,2))->key);
    printf("search 3... %d\n", (searchKey(tree,3))->key);
    printf("search 4... %d\n", (searchKey(tree,4))->key);
    printf("search 5... %d\n", (searchKey(tree,5))->key);
    printf("search 6... %d\n", (searchKey(tree,6))->key);
    printf("search 7... %d\n", (searchKey(tree,7))->key);
    printf("\n");

    printf("Delete\n");
    printf("delete 5...");
    deleteKey(&tree,5);
    preorder(tree);
    printf("\n");

    printf("delete 6...");
    deleteKey(&tree,6);
    preorder(tree);
    printf("\n");

    printf("delete 4...");
    deleteKey(&tree,4);
    preorder(tree);
    printf("\n");

    printf("delete 2...");
    deleteKey(&tree,2);
    preorder(tree);
    printf("\n");
}
