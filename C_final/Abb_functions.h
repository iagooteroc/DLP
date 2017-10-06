/*
* Authors:
*   Iago Otero Coto - iago.oteroc
*   Jorge Viteri Letamendia - j.viteri.letamendia
* Emails:
*   iago.oteroc@udc.es
*   j.viteri.letamendia@udc.es
 */


#include <stdio.h>
#include <stdlib.h>


#ifndef ABB_FUNCTIONS_H
#define ABB_FUNCTIONS_H


typedef struct Node {
  int key;
  struct Node *left,*right;
}Node;

void createNodeA(Node** n);

//************************************************************************

void insertNode_r(Node** abb, int data);

void insertNode_i(Node** abb, int data);

void insertKey(Node** abb, int newKey);


int isEmptyTree(Node* abb);

//**************************************************************************
Node* search_r(Node* abb, int key);

Node* search_i(Node* abb, int key);

Node* searchKey(Node* abb, int key);

//************************************************************************

void sup2(Node** b, Node** aux);

void delete_r(Node** abb, int key);

void delete_i(Node** abb, int key);

void deleteKey(Node** abb, int key);


#endif /* ABB_FUNCTIONS_H */
