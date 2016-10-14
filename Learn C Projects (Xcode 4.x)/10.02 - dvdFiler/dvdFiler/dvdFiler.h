/***********/
/* Defines */
/***********/
#define kMaxTitleLength         256
#define kMaxCommentLength		256

#define kDVDFileName			"../../../../../dvdData"


/***********************/
/* Struct Declarations */
/***********************/
struct DVDInfo {
	char			rating;
	char			title[ kMaxTitleLength ];
	char			comment[ kMaxCommentLength ];
	struct DVDInfo	*next;
};


/***********************/
/* Global Declarations */
/***********************/
 extern struct DVDInfo	*gHeadPtr, *gTailPtr;


/********************************/
/* Function Prototypes - main.c */
/********************************/
char			GetCommand( void );
struct DVDInfo	*ReadStruct( void );
void			AddToList( struct DVDInfo *curPtr );
void			ListDVDs( void );
void            ReplaceReturnAtEndOfString( char *theString );
void			Flush( void );


/*********************************/
/* Function Prototypes - files.c */
/*********************************/
void	WriteFile( void );
void	ReadFile( void );
char	ReadStructFromFile( FILE *fp, struct DVDInfo *infoPtr );