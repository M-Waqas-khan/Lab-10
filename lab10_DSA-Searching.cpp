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
bool search(Node* root, int value)
{
    // Base case: the tree is empty ot trhe value in the BST
    if (root == nullptr) return false;
    if (root->data == value) return true;

    if (value< root->data)
    {
        return search(root->left, value); 
    }
    else
    {
        return search(root->right, value); 
    }
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

  int key = 40;
  if( search(root, key))
  {
    cout << key << " Found in the BST.\n";
  }
  else
  {
    cout << key << " not found in the BST.\n";
  }

  return 0;
}