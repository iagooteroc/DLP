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
#include "Abb_functions.cpp"
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * 
 */

void preordenParentizado(Node* tree) {
    printf("(");
    if (not esArbolvacio(tree)) {
        if (not esArbolvacio(tree->getRight()) || not esArbolvacio(tree->getLeft())) {
            printf("HOLAAAAAAAAAAAAAAAAAA");
            printf(" %d ", tree->getKey());
            preordenParentizado(tree->getLeft());
            printf(" ");
            preordenParentizado(tree->getRight());
        }
    } else{
        printf(" RAIZ%d ",tree->getKey()); //no recuerdon pfff
        
    }
    printf(")\n");
}

int main(int argc, char** argv) {

    Node* tree = new Node();
    
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
    insertarClave(tree,4);
    insertarClave(tree,4);
    insertarClave(tree,2);
    insertarClave(tree,6);
    insertarClave(tree,1);
    insertarClave(tree,3);
    insertarClave(tree,5);
    insertarClave(tree,7);
    
    
    printf("preorden\n");
    preordenParentizado(tree);
    printf("\n");
    
    /*
    printf("Buscar\n");
    printf("buscar 1... %d\n", tree->buscarClave(1)->getKey());
    printf("buscar 2... %d\n", tree->buscarClave(2)->getKey());
    printf("buscar 3... %d\n", tree->buscarClave(3)->getKey());
    printf("buscar 4... %d\n", tree->buscarClave(4)->getKey());
    printf("buscar 5... %d\n", tree->buscarClave(5)->getKey());
    printf("buscar 6... %d\n", tree->buscarClave(6)->getKey());
    printf("buscar 7... %d\n", tree->buscarClave(7)->getKey());

    printf("Eliminar\n");
    printf("eliminar 5...");
    tree->eliminar_Clave(5);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 6...");
    tree->eliminar_Clave(6);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 4...");
    tree->eliminar_Clave(4);
    preordenParentizado(tree);
    printf("\n");

    printf("eliminar 2...");
    tree->eliminar_Clave(2);
    preordenParentizado(tree);
    printf("\n");*/
}

