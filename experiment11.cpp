#include <iostream>
using namespace std;
struct node
{
    int key;
    node *left;
    node *right;
};
struct node *root=NULL;
class tree
{
public:

    node *createnode(int);
    node *insert_node(node *,int);
    int inorder(node *);
    int printPostorder(node *);
    int printPreorder(node *);
    node *deleteNode(node *,int);
    node *minValueNode(node *);
};
node *tree::minValueNode(node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 
 node *tree::deleteNode(node* root, int key) 
{  
    if (root == NULL) 
	return root; 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
    else
    { 
        if (root->left == NULL) 
        { 
            node *temp = root->right; 
            delete(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            node *temp = root->left; 
            delete(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->key = temp->key;  
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
int tree::inorder(node *root)
{
    if(root==NULL)
        return 0;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
node *tree::createnode(int x)
{
    node *temp=new node;
    temp->key=x;
    temp->left=NULL;
    temp->right=NULL;

}
node *tree::insert_node(node *root,int data)
{
    int ele;
    node *p;
    if(root==NULL)
    {
        root=createnode(data);
        return root;
    }
    else if(data<=root->key)
        root->left=insert_node(root->left,data);
    else
    {
    root->right=insert_node(root->right,data);
    }
}
int tree::printPreorder(node *root)
{
    if (root == NULL)
        return 0;


    cout << root->key << " ";

    printPreorder(root->left);

    printPreorder(root->right);
}
int tree::printPostorder( node *root)
{
    if (root == NULL)
        return 0;

    printPostorder(root->left);

    printPostorder(root->right);
    cout << root->key << " ";
}
int main()
{
    int e;
    int n;
    tree t;
    node *p;
    cout<<"1.Inserting an element"<<endl<<"2.Deleting an existing element"<<endl<<"3.Traversing the tree (a)inorder (b)preorder (c)postorder"<<endl;
    cin>>n;
	while(n!=4)
	{
		switch(n)
		{
			case 1: 
            cin>>e;
            root=t.insert_node(root,e);
            break;
            case 2:
            t.deleteNode(root,root->key);
            break;
            case 3:
            	int b;
            	cout<<"1.Inorder"<<endl<<"2.Preorder"<<endl<<"3.Postorder"<<endl;
            	cin>>b;
            	switch(b)
            	{
//            		cout<<"1.Inorder"<<endl<<"2.Preorder"<<endl<<"3.Postorder"<<endl;
            		case 1:
            		t.inorder(root);
					cout<<endl;
					break;
					case 2:
					t.printPreorder(root);
					cout<<endl;
					break;
					case 3:
					t.printPostorder(root);
					cout<<endl;
					break;	
				}
		}
		cout<<"1.Inserting an element"<<endl<<"2.Deleting an existing element"<<endl<<"3.Traversing the tree (a)inorder (b)preorder (c)postorder"<<endl;
		cin>>n;
   }
    return 0;
}
