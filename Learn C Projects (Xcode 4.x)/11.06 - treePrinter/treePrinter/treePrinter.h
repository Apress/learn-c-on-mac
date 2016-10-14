/***********/
/* Defines */
/***********/
#define kNumbersFileName	"../../../../../treePrinter numbers"


/***********************/
/* Struct Declarations */
/***********************/
struct Node {
	int				number;
	struct Node		*left, *right;
};


/***********************/
/* Global Declarations */
/***********************/
 extern struct Node	*gRootNodePtr;


/********************************/
/* Function Prototypes - main.c */
/********************************/
void	BuildTree( void );
int		GetNumberFromFile( int *numPtr, FILE *fp );
void	DoError( char *message );


/*********************************/
/* Function Prototypes - tree.c */
/*********************************/
void	AddNumberToTree( int num );
void	AddNodeToTree( struct Node *newNodePtr, struct Node **curNodePtrPtr );
void	DescendTreePreorder( struct Node *nodePtr );
void	DescendTreeInorder( struct Node *nodePtr );
void	DescendTreePostorder( struct Node *nodePtr );
void	VisitNode( struct Node *nodePtr );