#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left;    //pointer to left child
    Node* right;   //pointer to right child
};
Node* createNode(int value)        //Function to create new Node
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
Node* insert(Node* root, int value)        //Function to insert a Node in to BST
{
    //if tree is empty, return a new node
    if (root == nullptr)
    {
        return createNode(value);
    }
    // otherwise recur down the tree
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if(value  > root->data)
    {
        // insert in the right subtree
        root->right = insert(root->right, value);
    }
    return root;
}
void preOrderTraversal(Node* root)
{
    if (root == nullptr) return;         
    cout << root->data <<" ";      
    preOrderTraversal(root->left);         // print the node's value
    preOrderTraversal(root->right);         // visit right subtree
}
int main()
{
  Node* root = nullptr;       // start with an empty tree 
  
  // insert nodes into BST
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  // Display the BST in in-order traversal
  cout << "Pre-order Traversal of the BST : ";
  preOrderTraversal(root);

  return 0;
}