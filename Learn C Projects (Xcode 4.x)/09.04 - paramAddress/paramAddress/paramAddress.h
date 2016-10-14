/***********/
/* Defines */
/***********/
#define kMaxDVDs			300
#define kMaxTitleLength     50
#define kMaxCommentLength	50


/***********************/
/* Struct Declarations */
/***********************/
struct DVDInfo
{
	char	rating;
	char	title[ kMaxTitleLength + 1 ];
	char	comment[ kMaxCommentLength + 1 ];
};


/***********************/
/* Function Prototypes */
/***********************/
void	PrintParamInfo( struct DVDInfo *myDVDPtr,
				struct DVDInfo myDVDCopy );