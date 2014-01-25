#include <stdlib.h>
#include <stdio.h>

struct node
{
    int key_value;
    int row;
    node *left;
    node *right;
};

class btree
{
    public:
        btree();
        ~btree();

        void insert(int key);
        node *search(int key);
        void destroy_tree();
        node *root;
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        
};

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

btree::btree()
{
  root=NULL;
}

btree::~btree()
{
  destroy_tree();
}

void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->key_value=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value)
      return leaf;
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->key_value=key;
    root->left=NULL;
    root->right=NULL;
  }
}

node *btree::search(int key)
{
  return search(key, root);
}

void preorderPrint( node *root ) {
    // Print all the items in the tree to which root points.
    // The item in the root is printed first, followed by the
    // items in the left subtree and then the items in the
    // right subtree.
    if ( root != NULL ) {  // (Otherwise, there's nothing to print.)
        printf ( " %d \t", root->key_value );      // Print the root item.
        preorderPrint( root->left );    // Print items in left subtree.
        preorderPrint( root->right );   // Print items in right subtree.
    }
} // end preorderPrint()


int main()
{
    int keys[] = {
        75, 
        95, 64,
        17, 47, 82,
        18, 35, 87, 10,
        20, 4, 82, 47, 65,
        19, 1, 23, 75, 3, 34,
        88, 2, 77, 73, 7, 63, 67,
        99, 65, 4, 28, 06, 16, 70, 92,
        41, 41, 26, 56, 83, 40, 80, 70, 33,
        41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
        53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
        70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
        91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
        63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
        4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23
    };
    int size = (sizeof(keys)/sizeof(*keys));
    printf("size of array = %d \n",size);
    btree *myTree = new btree();

    for(int i=0; i < size; i++){
        myTree->insert(keys[i]);
    }

    printf ("My Binary tree \n");
    preorderPrint(myTree->root);
    return 0;
}
