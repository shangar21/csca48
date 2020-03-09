#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 2048

typedef struct Restaurant_Score
{
	char restaurant_name[MAX_STRING_LENGTH];
	char restaurant_address[MAX_STRING_LENGTH];
	int score;
}Review;

typedef struct BST_Node_Struct
{
	Review rev;				// Stores one review
	struct BST_Node_Struct *left;	        // A pointer to its left child
	struct BST_Node_Struct *right;	        // and a pointer to its right child
} BST_Node;

BST_Node *new_BST_Node(void)
{
	BST_Node *new_review=NULL;		// Pointer to the new node
					     
	new_review=(BST_Node *)calloc(1, sizeof(BST_Node));	

	// Initialize the new node's content (same as with linked list)
	new_review->rev.score=-1;
	strcpy(new_review->rev.restaurant_name,"");
	strcpy(new_review->rev.restaurant_address,"");
	new_review->left=NULL;
	new_review->right=NULL;
	return new_review;
}

BST_Node *BST_insert(BST_Node *root, BST_Node *new_review)
{	
    // To be completed in lecture

    if(root == NULL)
    {
    	return new_review;
    }

    if(strcmp(new_review -> rev.restaurant_name, root -> rev.restaurant_name) < 0)
    {
    	root -> left = BST_insert(root-> left, new_review);
    }
    else if(strcmp(new_review -> rev.restaurant_name, root -> rev.restaurant_name) > 0)
    {
    	root -> right = BST_insert(root -> right, new_review);
    }

    return root;
}	

BST_Node *BST_search(BST_Node *root, char name[1024])
{	
	// Look up a restaurant review by restaurant name

    // Ro be completed in lecture

    if(root == NULL)
    {
    	return NULL;
    }

    if(strcmp(root -> rev.restaurant_name, name) == 0)
    {
    	return root;
    }

    if(strcmp(root -> rev.restaurant_name, name) > 0)
    {
    	return BST_search(root -> left, name);
    }
    else
    {
    	return BST_search(root -> right, name);
    }
}	

BST_Node *BST_delete(BST_Node *root, char name[1024])
{	
	// Remove a review for a restaurant whose name matches the query
	// Assumes unique restaurant names!

	BST_Node *tmp;

	if (root==NULL)	return NULL;	// Tree or sub-tree is empty

	// Check if this node contains the review we want to delete
	if (strcmp(name,root->rev.restaurant_name)==0) 
	{
		if (root->left==NULL && root->right==NULL) 
		{
			// Case a), no children. The parent will
			// be updated to have NULL instead of this
			// node's address, and we delete this node

                        // To be completed in lecture
						free(root)
                        return root;
                    
                }
		else if (root->right==NULL) 
		{
			// Case b), only one child, left subtree
			// The parent has to be linked to the left
			// child of this node, and we free this node
                    
                        // To be completed in lecture
						tmp = root -> left;
						free(root)
                        return tmp;
		}
		else if (root->left==NULL)
		{
			// Case b), only one child, right subtree
			// The parent has to be linked to the right
			// child of this node, and we free this node
                    
                        tmp = root -> right
                        free(root)
                        return temp;
		}
		else
		{
			// Case c), two children. 
			// You will implement this for your exercise!

                        return root;
		}
	}

	// Not in this node, delete on the corresponding subtree and
	// update the the corresponding link
	if (strcmp(name, root->rev.restaurant_name)<=0)
	{
		root->left=BST_delete(root->left,name);	  
	}	      
	else
	{
		root->right=BST_delete(root->right,name);
	}
}	

void BST_inorder(BST_Node *root)
{
  if (root==NULL) return;
  
  if (root->left!=NULL) BST_inorder(root->left);
   
  printf("*****************\n");
  printf("Name: %s\n",root->rev.restaurant_name);
  printf("Address: %s\n",root->rev.restaurant_address);
  printf("Score: %d\n",root->rev.score);
  
  if (root->right!=NULL) BST_inorder(root->right);
}

void BST_release(BST_Node *root)
{
 
  if (root!=NULL)
  {
    if (root->left!=NULL) BST_release(root->left);
    if (root->right!=NULL) BST_release(root->right);
    free(root);
  }
  
}

/*preordered traversal

in_order(root)
	apply of at root
	traverse left subtree in preorder
	traverse right subtree in preorder

post ordered traversal

in_order(root)
	traverse left subtree at postorder
	traverse right subtree in postorder
	apply op at root
*/

int main(void)
{
    BST_Node *root=NULL;
    int choice;
    BST_Node *new_node;
    char query[1024];
    
    choice=0;
    while(choice<5)
    {
        printf("Please select an option:\n");
        printf("1 - Insert new review\n");
        printf("2 - Search for a review\n");
        printf("3 - Print all reviews in order\n");
        printf("4 - Delete review\n");
        printf("5 - Exit\n");
        scanf("%d",&choice);
        getchar();
        
	if (choice==1)
	{
	  new_node=new_BST_Node();
	  printf("Please enter the restaurant's name:\n");
	  fgets(new_node->rev.restaurant_name,1024,stdin);
	  printf("Please enter the restaurant's address:\n");
	  fgets(new_node->rev.restaurant_address,1024,stdin);
	  printf("Please enter the restaurant's score:\n");
	  scanf("%d",&new_node->rev.score);
	  getchar();
	  root=BST_insert(root,new_node);
	}
	if (choice==2)
	{
	  printf("Please entere the restaurant's name:\n");
	  fgets(query,1024,stdin);
	  new_node=NULL;
	  new_node=BST_search(root,query);
	  if (new_node!=NULL)
	  {
	    printf("Found!\n");
	    printf("Restaurant name: %s\n",new_node->rev.restaurant_name);
	    printf("Restaurant address: %s\n",new_node->rev.restaurant_address);
	    printf("Restaurant score: %d\n",new_node->rev.score);
	  }
	  else
	  {
	    printf("No such restaurant name in the database\n");
	  }	  
	}
	if (choice==3)
	{
	  printf("Current reviews:\n");
	  BST_inorder(root);
	}
	if (choice==4)
	{
	  printf("Please entere the restaurant's name:\n");
	  fgets(query,1024,stdin);
	  root=BST_delete(root,query);
	}
    }
    
    BST_release(root);
    
}