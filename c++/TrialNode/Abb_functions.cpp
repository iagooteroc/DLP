/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include "Node.h"
#include <stdio.h>
#include <stdlib.h> 


void crearNodoA(Node* n) {
    n=(Node*)malloc(sizeof(Node));
    if (n == NULL)
        perror("  *** abb.crearNodoA: no hay memoria");
}

//************************************************************************

void insertNode_r(Node* abb, int data) {
    int c_key = abb->getKey();
    if (abb==NULL) {
        crearNodoA(abb);
        abb->setKey(data);
        abb->setLeft(NULL);
        abb->setRight(NULL);
    } else if (data < c_key) {
        insertNode_r(abb->getLeft(),data);
    } else if (data > c_key) {
        insertNode_r(abb->getRight(),data);
    }
}

void insertNode_i(Node* abb, int data) {
    Node *nuevo, *padre, *hijo;
    nuevo = new Node;
    int h_key;
    crearNodoA(nuevo);
    nuevo->setKey(data);
    nuevo->setLeft(NULL);
    nuevo->setRight(NULL);
    

    if (abb == NULL){
        abb=nuevo;
    }
    else {
        padre = NULL;
        hijo = abb;
        h_key=hijo->getKey();
        while ((hijo != NULL) and (h_key != data)) {
            padre = hijo;
            if (data < h_key)
                hijo = hijo->getLeft();
            else
                hijo = hijo->getRight();
        };
        if (hijo == NULL) {
            if (data < padre->getKey())
                padre->setLeft(nuevo);
            else
                padre->setRight(nuevo);
        }
    }
}

void insertarClave(Node* abb, int newKey) {
    insertNode_r(abb, newKey);
}

/**************************************************************************/
bool esArbolvacio(Node* abb) {
    return abb==NULL;
}






/*
Node* Node::buscar_r(int key) {
    Node* current = this;
    if (current == 0)
        return 0;
    else if (current->getKey() == key)
        return current;
    else if (key < current->getKey())
        this->getLeft()->buscar_r(key);
    else
        this->getRight()->buscar_r(key);

}

Node* Node::buscar_i(int key) {
    Node* Node;
    Node = this;
    while ((Node != 0) and (Node->getKey() != key)) {
        if (key < Node->getKey())
            Node = Node->getLeft();
        else
            Node = Node->getRight();
    }
    return Node;
}

Node* buscarClave(int key) {
    return this->buscar_r(key);
}



//************************************************************************

void sup2(Node* b) {
    Node* aux2;
    if (b->getRight() == 0)
        sup2(b->getRight());
    else {
        aux2->setKey(b->getKey());
        aux2 = b;
        b = b->getLeft();
    }
}

void Node::eliminar_r(int key) {
    Node* aux;
    Node* current = this;
    if (current != 0) {
        if (key < current->getKey())
            this->getLeft()->eliminar_r(key);
        else
            this->getRight()->eliminar_r(key);
    } else {
        aux = current; //el porblema de arbol y Node
        if (current->getLeft() == 0)
            current = current->getRight();
        else if (current->getRight() == 0)
            current = current->getLeft();
        else
            sup2(current->getLeft());
    }

}

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
}

void Node::eliminar_Clave(int key) {
    this->eliminar_r(key);
}*/