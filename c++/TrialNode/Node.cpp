/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: jorge
 * 
 * Created on 17 de septiembre de 2017, 18:14
 */

#include <stdio.h>
#include <cstdlib>
#include "Node.h"


//since C++11

Node::Node() {
    key = 0;
}

int Node::getKey() {
    return this->key;
}

Node* Node::getLeft() {
    return this->left;
}

Node* Node::getRight() {
    return this->right;
}

void Node::setLeft(Node* nl) {
    this->left = nl;
}

void Node::setRight(Node* nr) {
    this->right = nr;
}

void Node::setKey(int k) {
    this->key = k;
}



