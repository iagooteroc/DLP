/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Node.h"
#include <stdio.h>
#include <stdlib.h> 

void crearNodoA(Node** n) {
    (*n) = (Node*) malloc(sizeof (Node));
    if ((*n) == NULL)
        perror("  *** abb.crearNodoA: no hay memoria");
}

//************************************************************************

void insertNode_r(Node** abb, int data) {
    if ((*abb) == NULL) {
        crearNodoA(abb);
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
    crearNodoA(&nuevo);
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

void insertarClave(Node** abb, int newKey) {
    insertNode_i(abb, newKey);
}

/**************************************************************************/
bool esArbolvacio(Node* abb) {
    return abb == NULL;
}

Node* buscar_r(Node* abb, int key) {
    if ((abb) == NULL)
        return NULL;
    else if ((abb)->key == key)
        return abb;
    else if (key < (abb)->key) {
        Node* left = (abb)->left;
        buscar_r(left, key);
    } else {
        Node* right = (abb)->right;
        buscar_r(right, key);
    }

}

Node* buscar_i(Node* abb, int key) {
    Node* node = abb;
    while (((node) != NULL) and ((node)->key != key)) {
        if (key < (node)->key)
            (node) = (node)->left;
        else
            (node) = (node)->right;
    }
    return node;
}

Node* buscarClave(Node* abb, int key) {
    return buscar_i(abb, key);
}



//************************************************************************

void sup2(Node** b, Node** aux) {
    if ((*b)->right != NULL)
        sup2(&(*b)->right,aux);
    else {
        (*aux)->key = ((*b)->key);
        (*aux) = (*b);
        (*b) = (*b)->left;
    }
}

void eliminar_r(Node** abb, int key) {
    Node* aux;
    if ((*abb) != NULL) {
        if (key < (*abb)->key) {
            Node*& left = (*abb)->left;
            eliminar_r(&left, key);
        } else {
            if (key > (*abb)->key) {
                Node*& right = (*abb)->right;
                eliminar_r(&right, key);
            } else {
                aux = (*abb); //el porblema de arbol y Node
                if ((*abb)->left == NULL)
                    (*abb) = (*abb)->right;
                else if ((*abb)->right == NULL)
                    (*abb) = (*abb)->left;
                else {
                    Node*& left2 = (*abb)->left;
                    sup2(&left2,&aux);
                }
                free(aux);
            }
        }
    }
}

/*
void Node::eliminar_i(int key) {
    int numHijos;
    Node *sup, *pSup, *hijoNoVacio, *sucIzMax, *root;
    root = this;

    pSup = NULL;
    sup = this;
    while ((sup != NULL) && (sup->getKey() != key)) {
        pSup = sup;
        if (key < sup->getKey())
            sup = sup->getLeft();
        else
            sup = sup->getRight();
    }

    if (sup != NULL) {
        numHijos = 0;
        if (sup->getLeft() != NULL)
            numHijos++;
        if (sup->getRight() != NULL)
            numHijos++;
        switch (numHijos) {
            case 0:
                if (pSup == NULL)
                    numHijos == 0;
                else if (pSup->getLeft() == sup)
                    pSup->setLeft(NULL);
                else
                    pSup->setRight(NULL);


            case 1:
            {
                if (sup->getLeft() == NULL)
                    hijoNoVacio = sup->getRight();
                else
                    hijoNoVacio = sup->getLeft();

                if (pSup == NULL)
                    sup = hijoNoVacio; //EL THIS TINH
                else if (pSup->getLeft() == sup)
                    pSup->setLeft(hijoNoVacio);
                else
                    pSup->setRight(hijoNoVacio);
            }

            case 2:
            {
                pSup = sup;
                sucIzMax = sup->getLeft();
                while (sucIzMax->getRight() != NULL) {
                    pSup = sucIzMax;
                    sucIzMax = sucIzMax->getRight();
                }
                sup->setKey(sucIzMax->getKey());
                if (pSup == sup)
                    pSup->setLeft(sucIzMax->getLeft());
                else
                    pSup->setRight(sucIzMax->getLeft());
                sup = sucIzMax;
            }
        }
        delete sup;
    }
}*/

void eliminar_Clave(Node** abb, int key) {
    eliminar_r(abb, key);
}