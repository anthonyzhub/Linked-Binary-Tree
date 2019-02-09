//
//  LinkedBinary.hpp
//  Tree Assignment
//
//  Created by Anthony Zamora on 11/1/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//

#ifndef LinkedBinary_hpp
#define LinkedBinary_hpp

#include <stdio.h>
#include <list>

using namespace std;

typedef int Elem;
class LinkedBinaryTree
{
#pragma mark Node structure
protected:
    struct Node
    {
        // Get element
        Elem elt;
        
        // Reference to surround element
        Node* parentNode;
        Node* left;
        Node* right;
        
        // Constructor
        Node() : elt(), parentNode(NULL), left(NULL), right(NULL) {}
    };
    
public:
#pragma mark Position Class
    class Position
    {
    private:
        Node* v;
        
    public:
        
        // Constructor
        Position(Node* _v = NULL) : v(_v) {}
        
        // Retrieve element by overloading * operator
        Elem& operator*()
        {
            return v->elt;
        }
        
        // Get surround elements
        Position left() const
        {
            return Position(v->left);
        }
        
        Position right() const
        {
            return Position(v->right);
        }
        
        Position parent() const
        {
            return Position(v->parentNode);
        }
        
        // Is it root?
        bool isRoot() const
        {
            return v->parentNode == NULL;
        }
        
        // Is it an external node?
        bool isExternal() const
        {
            // Is there a left and right node nearby?
            return (v->left == NULL) && (v->right == NULL);
        }
        
        // Give Tree access
        friend class LinkedBinaryTree;
    };
    
    // List all positions
    typedef list<Position> PositionList;
    
#pragma mark LinkedBinaryTree public data
public:
    
    // Constructor
    LinkedBinaryTree();
    
    // Get size
    int size() const;
    
    // Is it empty?
    bool empty() const;
    
    // Get root and positions of node
    Position root() const;
    PositionList positions() const;
    
    // Add root to empty tree
    void addRoot();
    
    // Expand external node
    void expandExternal(const Position& p);
    
    // Remove the external above
    Position removeAboveExternal(const Position& p);
    
protected:
    
    void preorder(Node* v, PositionList& pl) const;
    
private:
    
    // Pointer to root
    Node* _root;
    
    // Number of nodes
    int n;
};

#endif /* LinkedBinary_hpp */
