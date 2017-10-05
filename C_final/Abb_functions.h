/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Abb_functions.h
 * Author: jorge
 *
 * Created on 5 de octubre de 2017, 11:16
 */


#include <stdio.h>
#include <stdlib.h>


#ifndef ABB_FUNCTIONS_H
#define ABB_FUNCTIONS_H


typedef struct Node {
  int key;
  struct Node *left,*right;
}Node;

void crearNodoA(Node** n);

//************************************************************************

void insertNode_r(Node** abb, int data);

void insertNode_i(Node** abb, int data);

void insertarClave(Node** abb, int newKey);


int esArbolvacio(Node* abb);

//**************************************************************************
Node* buscar_r(Node* abb, int key);

Node* buscar_i(Node* abb, int key);

Node* buscarClave(Node* abb, int key);



//************************************************************************

void sup2(Node** b, Node** aux);

void eliminar_r(Node** abb, int key);

void eliminar_i(Node** abb, int key);

void eliminar_Clave(Node** abb, int key);


#endif /* ABB_FUNCTIONS_H */

