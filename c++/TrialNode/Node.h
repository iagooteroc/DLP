/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: jorge
 *
 * Created on 17 de septiembre de 2017, 18:14
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    int getKey();
    void setKey(int k);
    Node* getLeft();
    void setLeft(Node* nl);
    Node* getRight();
    void setRight(Node* nr);
    Node();
    
private:
    int key;
    Node *left, *right;
};

#endif /* NODE_H */

