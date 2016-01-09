//SYSTEM BASE DATA
#define CLASSNAME				L"Main"
#define WINDOWNAME				L"TAIWAN NO.1"

#define UPDATE_FRAME			30

#define LOGIC_WIDTH				37
#define LOGIC_HEIGHT			25

#define BLOCK_SIZE				32
#define SCREEN_WIDTH			LOGIC_WIDTH * BLOCK_SIZE
#define SCREEN_HEIGHT			LOGIC_HEIGHT * BLOCK_SIZE

#define NEW_GAME				"�s���_�I"
#define LOAD_GAME				"Ū������"
#define EXIT_GAME				"���}�C��"

#define WINDOW_NEWLINE			'\n'
//MAP CONTROL
#define SEPARATE				'#'
#define EXTENSION				".map"

#define BLOCK_SEPARATE			','
#define BLOCK_SIGN				'B'
#define NAME_SIGN				'\"'
#define INDEX_SIGN				'I'
#define PASS_SIGN				'P'
#define LAYER_SIGN				'L'
#define COUNT_SIGN				'*'

#define RESOLVE_WIDTH			0
#define RESOLVE_HEIGHT			1
#define RESOLVE_BLOCK			2
#define RESOLVE_EVENT			3

#define FILE_MAP				"./Data/Map/"
#define FILE_DEFAULT			ios::in | ios::out

#define DATABASE_NAME			"Database.db"
#define DATABASE_ADDRESS		"../CRPG/Data/System/"

#define AUDIO_BGM_ADDRESS		"../CRPG/Data/Audio/BGM/"
#define AUDIO_SE_ADDRESS		"../CRPG/Data/Audio/SE/"
#define GRAPHICS_ADDRESS		"../CRPG/Data/Graphics/Picture/"

#define TITLE_BGM				"title.wav"
#define TITLE_IMAGE				"title.bmp"

#define TITLE_OPTION_IMAGE_A	"new_game.bmp"
#define TITLE_OPTION_IMAGE_B	"continue.bmp"
#define TITLE_OPTION_IMAGE_C	"exit.bmp"