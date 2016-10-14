/***********/
/* Defines */
/***********/
#define kMaxLineLength		200
#define kDVDFileName			"../../../../../dvdData"


/***********************/
/* Struct Declarations */
/***********************/
struct DVDInfo {
	char			rating;
	char			*title;
	char			*comment;
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
void			Flush( void );
char			*MallocAndCopy( char *line );
void			ZeroLine( char *line );


/*********************************/
/* Function Prototypes - files.c */
/*********************************/
void	WriteFile( void );
void	ReadFile( void );
char	ReadStructFromFile( FILE *fp, struct DVDInfo *infoPtr );