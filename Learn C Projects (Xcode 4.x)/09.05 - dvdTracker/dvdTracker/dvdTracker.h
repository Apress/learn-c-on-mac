/***********/
/* Defines */
/***********/
#define kMaxTitleLength     256
#define kMaxCommentLength	256


/***********************/
/* Struct Declarations */
/***********************/
struct DVDInfo
{
	char			rating;
	char			title[ kMaxTitleLength ];
	char			comment[ kMaxCommentLength ];
	struct DVDInfo	*next;
} *gHeadPtr, *gTailPtr;


/***********************/
/* Function Prototypes */
/***********************/
char			GetCommand( void );
struct DVDInfo	*ReadStruct( void );
void			AddToList( struct DVDInfo *curPtr );
void			ListDVDs( void );
void            ReplaceReturnAtEndOfString( char *theString );
void			Flush( void );