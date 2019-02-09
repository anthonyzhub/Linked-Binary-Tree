//
//  LinkedBinary.cpp
//  Tree Assignment
//
//  Created by Anthony Zamora on 11/1/18.
//  Copyright © 2018 Anthony Zamora. All rights reserved.
//

#include "LinkedBinary.hpp"

// Constructor
LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {}

// Retrieve size
int LinkedBinaryTree::size() const
{
    return n;
}

// Is tree empty?
bool LinkedBinaryTree::empty() const
{
    return size() == 0;
}

// Get tree's root
LinkedBinaryTree::Position LinkedBinaryTree::root() const
{
    return Position(_root);
}

// Add root
void LinkedBinaryTree::addRoot()
{
    _root = new Node;
    n = 1;
}

// Expand external node
void LinkedBinaryTree::expandExternal(const Position& p)
{
    // Get node
    Node* v = p.v;
    
    // Create a new Node from struct on current node's sides
    v->left = new Node;
    v->right = new Node;
    
    // 'v' is the parent of the newly created nodes
    v->left->parentNode = v;
    v->right->parentNode = v;
    
    // Update the number of nodes in Tree
    n = n + 2;
}

// Remove external node
LinkedBinaryTree::Position LinkedBinaryTree::removeAboveExternal(const Position& p)
{
    // Get current node and its parents
    Node* w = p.v;
    Node* v = w->parentNode;
    Node* sib = (w == v->left ? v->right: v->left);
    
    // Is it child of root?
    if (v == _root)
    {
        _root = sib;
        sib->parentNode = NULL;
    } else {
        // Get grandparents of current node
        Node* grandParents = v->parentNode;
        
        // Replace parent by sibling
        if (v == grandParents->left)
        {
            grandParents->left = sib;
        } else {
            grandParents->right = sib;
        }
        sib->parentNode = grandParents;
    }
    
    // Delete removed nodes
    delete w;
    delete v;
    
    // Remove deleted nodes from total nodes in tree
    n = n - 2;
    
    return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const
{
    PositionList pl;
    
    // Preorder traversal
    preorder(_root, pl);
    
    // Return resulting list
    return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const
{
    // Add this node
    pl.push_back(Position(v));
    
    // Traverse left subtree
    if(v->left != NULL)
    {
        preorder(v->left, pl);
    }
    
    // Traverse right subtree
    if (v->right != NULL)
    {
        preorder(v->right, pl);
    }
}
