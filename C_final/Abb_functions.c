/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
  int key;
  struct Node *left,*right;
}Node;

void createNodeA(Node** n) {
    (*n) = (Node*) malloc(sizeof (Node));
    if ((*n) == NULL)
        perror("  *** abb.createNodoA: no hay memoria");
}

//************************************************************************

void insertNode_r(Node** abb, int data) {
    if ((*abb) == NULL) {
        createNodeA(abb);
        (*abb)->key = data;
        (*abb)->left = NULL;
        (*abb)->right = NULL;
    } else {
        int c_key = (*abb)->key;
        if (data < c_key) {
            insertNode_r(&(*abb)->left, data);
        } else if (data > c_key) {
            insertNode_r(&(*abb)->right, data);
        }
    }
}

void insertNode_i(Node** abb, int data) {
    Node *new, *father, *son;
    new = NULL;
    createNodeA(&new);
    new->key = data;
    new->left = NULL;
    new->right = NULL;


    if ((*abb) == NULL) {
        (*abb) = new;
    } else {
        father = NULL;
        son = (*abb);
        while ((son != NULL) && (son->key != data)) {
            father = son;
            if (data < son->key)
                son = son->left;
            else
                son = son->right;
        };
        if (son == NULL) {
            if (data < father->key)
                father->left = new;
            else
                father->right = new;
        }
    }
}

void insertKey(Node** abb, int newKey) {
    insertNode_i(abb, newKey);
}


int isEmptyTree(Node* abb) {
    return abb == NULL;
}

//**************************************************************************
Node* search_r(Node* abb, int key) {
    if ((abb) == NULL)
        return NULL;
    else if ((abb)->key == key)
        return abb;
    else if (key < (abb)->key) {
        Node* left = (abb)->left;
        search_r(left, key);
    } else {
        Node* right = (abb)->right;
        search_r(right, key);
    }

}

Node* search_i(Node* abb, int key) {
    Node* node = abb;
    while (((node) != NULL) && ((node)->key != key)) {
        if (key < (node)->key)
            (node) = (node)->left;
        else
            (node) = (node)->right;
    }
    return node;
}

Node* searchKey(Node* abb, int key) {
    return search_r(abb, key);
}



//************************************************************************

void sup2(Node** b, Node** aux) {
    if ((*b)->right != NULL)
        sup2(&(*b)->right, aux);
    else {
        (*aux)->key = ((*b)->key);
        (*aux) = (*b);
        (*b) = (*b)->left;
    }
}

void delete_r(Node** abb, int key) {
    Node* aux;
    if ((*abb) != NULL) {
        if (key < (*abb)->key) {
            delete_r(&(*abb)->left, key);
        } else {
            if (key > (*abb)->key) {
                delete_r(&(*abb)->right, key);
            } else {
                aux = (*abb);
                if ((*abb)->left == NULL)
                    (*abb) = (*abb)->right;
                else if ((*abb)->right == NULL)
                    (*abb) = (*abb)->left;
                else {
                    Node* left2 = (*abb)->left;
                    sup2(&left2, &aux);
                }
                free(aux);
            }
        }
    }
}

void delete_i(Node** abb, int key) {
    int numsons;
    Node *sup, *pSup, *notEmptySon, *sucIzMax;

    pSup = NULL;
    sup = (*abb);
    while ((sup != NULL) && (sup->key != key)) {
        pSup = sup;
        if (key < sup->key)
            sup = sup->left;
        else
            sup = sup->right;
    }

    if (sup != NULL) {
        numsons = 0;
        if (sup->left != NULL)
            numsons++;
        if (sup->right != NULL)
            numsons++;
        switch (numsons) {
            case 0:
            {
                if (pSup == NULL)
                    numsons == 0;
                else if (pSup->left == sup)
                    pSup->left = (NULL);
                else
                    pSup->right = (NULL);
                break;

            };
            case 1:
            {
                if (sup->left == NULL)
                    notEmptySon = sup->right;
                else
                    notEmptySon = sup->left;

                if (pSup == NULL)
                    sup = notEmptySon; //EL THIS TINH
                else if (pSup->left == sup)
                    pSup->left = notEmptySon;
                else
                    pSup->right = notEmptySon;
                break;
            };

            case 2:
            {
                pSup = sup;
                sucIzMax = sup->left;
                while (sucIzMax->right != NULL) {
                    pSup = sucIzMax;
                    sucIzMax = sucIzMax->right;
                }
                sup->key = (sucIzMax->key);
                if (pSup == sup)
                    pSup->left = sucIzMax->left;
                else
                    pSup->right = sucIzMax->left;
                sup = sucIzMax;
                break;
            };
        }
        free(sup);
    }
}

void deleteKey(Node** abb, int key) {
    delete_i(abb, key);
}
