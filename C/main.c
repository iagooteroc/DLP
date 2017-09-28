/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: jorge
 *
 * Created on 28 de septiembre de 2017, 11:51
 */


#include "Abb_functions.h"
#include <stdio.h>



/*
 *
 */

void preordenParentizado(Node* tree) {
    printf("(");
    if (! esArbolvacio(tree)) {
        if (! esArbolvacio(tree->right) || ! esArbolvacio(tree->left)) {
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

    printf("Insertar...\n");
    insertarClave(&tree,4);
    insertarClave(&tree,4);
    insertarClave(&tree,2);
    insertarClave(&tree,6);
    insertarClave(&tree,1);
    insertarClave(&tree,3);
    insertarClave(&tree,5);
    insertarClave(&tree,7);
    printf("\n");


    printf("Preorden\n");
    preordenParentizado(tree);
    printf("\n");

    printf("Buscar\n");
    printf("buscar 1... %d\n", (buscarClave(tree,1))->key);
    printf("buscar 2... %d\n", (buscarClave(tree,2))->key);
    printf("buscar 3... %d\n", (buscarClave(tree,3))->key);
    printf("buscar 4... %d\n", (buscarClave(tree,4))->key);
    printf("buscar 5... %d\n", (buscarClave(tree,5))->key);
    printf("buscar 6... %d\n", (buscarClave(tree,6))->key);
    printf("buscar 7... %d\n", (buscarClave(tree,7))->key);
    printf("\n");

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
