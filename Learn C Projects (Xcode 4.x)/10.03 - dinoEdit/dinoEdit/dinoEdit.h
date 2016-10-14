/***********/
/* Defines */
/***********/
#define kDinoRecordSize		20
#define kMaxLineLength		100
#define kDinoFileName		"../../../../../MyDinos"


/********************************/
/* Function Prototypes - main.c */
/********************************/
int		GetNumber( void );
int		GetNumberOfDinos( void );
void	ReadDinoName( int number, char *dinoName );
bool	GetNewDinoName( char *dinoName );
void	WriteDinoName( int number, char *dinoName );
void	Flush( void );
void	DoError( char *message );