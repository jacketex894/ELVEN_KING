//SYSTEM BASE DATA
#define CLASSNAME				L"Main"
#define WINDOWNAME				L"ELVEN KING"

#define UPDATE_FRAME			30

#define LOGIC_WIDTH				37
#define LOGIC_HEIGHT			25

#define BLOCK_SIZE				32
#define SCREEN_WIDTH			LOGIC_WIDTH * BLOCK_SIZE
#define SCREEN_HEIGHT			LOGIC_HEIGHT * BLOCK_SIZE

#define SCREEN_LEFT				(GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2
#define SCREEN_TOP				(GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2

#define SCREEN                  {SCREEN_LEFT, SCREEN_TOP,\
                                 SCREEN_LEFT + SCREEN_WIDTH, SCREEN_TOP + SCREEN_HEIGHT}

#define CENTER_X(width)			SCREEN_LEFT + (SCREEN_WIDTH - (width))/2
#define CENTER_Y(height)		SCREEN_TOP + (SCREEN_HEIGHT - (height))/2

#define NEW_GAME				"新的冒險"
#define LOAD_GAME				"讀取紀錄"
#define EXIT_GAME				"離開遊戲"

#define WINDOW_NEWLINE			'\n'
//MAP CONTROL
#define SEPARATE				'#'
#define EXTENSION				".map"

#define BLOCK_SEPARATE			','
#define COUNT_SIGN				'*'
#define BLOCK_SIGN				'\''
#define INDEX_SIGN				'I'
#define PASS_SIGN				'P'
#define LAYER_SIGN				'L'


#define RESOLVE_WIDTH			0
#define RESOLVE_HEIGHT			1
#define RESOLVE_BLOCK			2
#define RESOLVE_EVENT			3

#define FILE_MAP				"./Data/Map/"
#define FILE_DEFAULT			ios::in | ios::out

#define DATABASE_NAME			"Database.db"
#define DATABASE_ADDRESS		"../ELVEN_KING/Data/System/"

#define AUDIO_BGM_ADDRESS		"../ELVEN_KING/Data/Audio/BGM/"
#define AUDIO_SE_ADDRESS		"../ELVEN_KING/Data/Audio/SE/"
#define GRAPHICS_ADDRESS		"../ELVEN_KING/Data/Graphics/Picture/"

#define TITLE_BGM				"title.wav"
#define TITLE_IMAGE				"title.bmp"

#define TITLE_OPTION_IMAGE_A	"new_game.bmp"
#define TITLE_OPTION_IMAGE_B	"continue.bmp"
#define TITLE_OPTION_IMAGE_C	"exit.bmp"