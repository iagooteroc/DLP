/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jorge
 *
 * Created on 15 de septiembre de 2017, 15:35
 */

#include <cstdlib>
#include "Node.h"
#include "Abb_functions.h"
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */

void preordenParentizado(Node* tree) {
    printf("(");
    if (not esArbolvacio(tree)) {
        if (not esArbolvacio(tree->right) || not esArbolvacio(tree->left)) {
            printf(" %d ", tree->key);
            preordenParentizado(tree->left);
            printf(" ");
            preordenParentizado(tree->right);
        }else{
            printf(" %d ",tree->key); //no recuerdon pfff
        }
    }
    printf(")");
}

int main(int argc, char** argv) {

    Node* tree = NULL;
    
    /*Node *left = new Node();
    Node *right = new Node(); 
    
    tree->setKey(5);
    left->setKey(7);
    right->setKey(10);
    left->setLeft(0);
    left->setRight(0);
    right->setLeft(0);
    right->setRight(0);
    
    printf("%d\n",tree->getKey());
    tree->setLeft(left);
    tree->setRight(right);
    
    printf("%d\n",tree->getLeft()->getKey());
    printf("%d\n",tree->getRight()->getKey());*/
    
    
    
    printf("Insertar\n");
    insertarClave(&tree,4);
    insertarClave(&tree,4);
    insertarClave(&tree,2);
    insertarClave(&tree,6);
    insertarClave(&tree,1);
    insertarClave(&tree,3);
    insertarClave(&tree,5);
    insertarClave(&tree,7);
    
    
    /*printf("preorden\n");
    preordenParentizado(tree);
    printf("\n");
    
    
    printf("Buscar\n");
    printf("buscar 1... %d\n", (buscarClave(tree,1))->key);
    printf("buscar 2... %d\n", (buscarClave(tree,2))->key);
    printf("buscar 3... %d\n", (buscarClave(tree,3))->key);
    printf("buscar 4... %d\n", (buscarClave(tree,4))->key);
    printf("buscar 5... %d\n", (buscarClave(tree,5))->key);
    printf("buscar 6... %d\n", (buscarClave(tree,6))->key);
    printf("buscar 7... %d\n", (buscarClave(tree,7))->key);*/

    printf("Eliminar\n");
    printf("eliminar 5...");
    eliminar_Clave(&tree,5);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 6...");
    eliminar_Clave(&tree,6);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 4...");
    eliminar_Clave(&tree,4);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 2...");
    eliminar_Clave(&tree,2);
    preordenParentizado(tree);
    printf("\n");
}

