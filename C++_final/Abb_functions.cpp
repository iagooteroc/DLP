/*
 * Authors: 
 *   Iago Otero Coto - iago.oteroc
 *   Jorge Viteri Letamendia - j.viteri.letamendia
 * Emails:
 *   iago.oteroc@udc.es
 *   j.viteri.letamendia@udc.es
 */


#include "Node.h"
#include <stdio.h>
#include <stdlib.h> 

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
            Node*& left = (*abb)->left;
            insertNode_r(&left, data);
        } else if (data > c_key) {
            Node*& right = (*abb)->right;
            insertNode_r(&right, data);
        }
    }
}

void insertNode_i(Node** abb, int data) {
    Node *nuevo, *padre, *hijo;
    nuevo = new Node;
    createNodeA(&nuevo);
    nuevo->key = data;
    nuevo->left = NULL;
    nuevo->right = NULL;


    if ((*abb) == NULL) {
        (*abb) = nuevo;
    } else {
        padre = NULL;
        hijo = (*abb);
        while ((hijo != NULL) and (hijo->key != data)) {
            padre = hijo;
            if (data < hijo->key)
                hijo = hijo->left;
            else
                hijo = hijo->right;
        };
        if (hijo == NULL) {
            if (data < padre->key)
                padre->left = nuevo;
            else
                padre->right = nuevo;
        }
    }
}

void insertKey(Node** abb, int newKey) {
    insertNode_r(abb, newKey);
}

/**************************************************************************/
bool isEmptyTree(Node* abb) {
    return abb == NULL;
}

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
    while (((node) != NULL) and ((node)->key != key)) {
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
            Node*& left = (*abb)->left;
            delete_r(&left, key);
        } else {
            if (key > (*abb)->key) {
                Node*& right = (*abb)->right;
                delete_r(&right, key);
            } else {
                aux = (*abb); 
                if ((*abb)->left == NULL)
                    (*abb) = (*abb)->right;
                else if ((*abb)->right == NULL)
                    (*abb) = (*abb)->left;
                else {
                    Node*& left2 = (*abb)->left;
                    sup2(&left2, &aux);
                }
                free(aux);
            }
        }
    }
}

void delete_i(Node** abb, int key) {
    int numHijos;
    Node *sup, *pSup, *hijoNoVacio, *sucIzMax;

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
        numHijos = 0;
        if (sup->left != NULL)
            numHijos++;
        if (sup->right != NULL)
            numHijos++;
        switch (numHijos) {
            case 0:
            {
                if (pSup == NULL)
                    numHijos == 0;
                else if (pSup->left == sup)
                    pSup->left = (NULL);
                else
                    pSup->right = (NULL);
                break;

            };
            case 1:
            {
                if (sup->left == NULL)
                    hijoNoVacio = sup->right;
                else
                    hijoNoVacio = sup->left;

                if (pSup == NULL)
                    sup = hijoNoVacio; //EL THIS TINH
                else if (pSup->left == sup)
                    pSup->left = hijoNoVacio;
                else
                    pSup->right = hijoNoVacio;
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
    delete_r(abb, key);
}
