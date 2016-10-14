#include <stdlib.h>
#include <stdio.h>
#include "treePrinter.h"


/***********************************> AddNumberToTree <*/
void	AddNumberToTree( int num ) {
	struct Node	*nodePtr;
	
	nodePtr = malloc( sizeof( struct Node ) );
	
	if ( nodePtr == NULL )
		DoError( "Could not allocate memory!\n" );
	
	nodePtr->number = num;
	nodePtr->left = NULL;
	nodePtr->right = NULL;
	
	AddNodeToTree( nodePtr, &gRootNodePtr );
}


/***********************************> AddNodeToTree <*/
void	AddNodeToTree( struct Node *newNodePtr, struct Node **curNodePtrPtr ) {
/*
	This recursive function inserts a new tree node (pointed to by newNodePtr)
	into the subtree pointed to by the pointer pointed to by curNodePtr. We use
	two levels of pointer here so we can change the value of the pointer passed
	in. See the call to AddNodeToTree a few lines up.
	
	Here's the algorithm: AddNodeToTree first checks to see if *curNodePtrPtr
	is NULL. If so, this is where the new node belongs: *curNodePtrPtr is
	set to point to the new node and we are done.
	
	If not, we'll check the node *curNodePtrPtr does point to and repeat the
	search in either the left or right child, depending on whether the new
	number being added to the tree is less than or greater than/equal to the
	current node.
	
	To help with the notation, think of:
	
		*curNodePtrPtr
	
	as equivalent to
	
		gRootNodePtr
*/
	if ( *curNodePtrPtr == NULL )
		*curNodePtrPtr = newNodePtr;
	else if ( newNodePtr->number < (*curNodePtrPtr)->number )
		AddNodeToTree( newNodePtr, &( (*curNodePtrPtr)->left ) );
	else
		AddNodeToTree( newNodePtr, &( (*curNodePtrPtr)->right ) );
}


/***********************************> DescendTreePreorder <*/
void	DescendTreePreorder( struct Node *nodePtr ) {
	if ( nodePtr == NULL )
		return;
	
	VisitNode( nodePtr );
	DescendTreePreorder( nodePtr->left );
	DescendTreePreorder( nodePtr->right );
}


/***********************************> DescendTreeInorder <*/
void	DescendTreeInorder( struct Node *nodePtr ) {
	if ( nodePtr == NULL )
		return;
	
	DescendTreeInorder( nodePtr->left );
	VisitNode( nodePtr );
	DescendTreeInorder( nodePtr->right );
}


/***********************************> DescendTreePostorder <*/
void	DescendTreePostorder( struct Node *nodePtr ) {
	if ( nodePtr == NULL )
		return;
	
	DescendTreePostorder( nodePtr->left );
	DescendTreePostorder( nodePtr->right );
	VisitNode( nodePtr );
}


/***********************************> VisitNode <*/
void	VisitNode( struct Node *nodePtr ) {
	printf( "%d, ", nodePtr->number );
}