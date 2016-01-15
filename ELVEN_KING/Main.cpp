#include "Data\System\Main.h"

int WINAPI WinMain
	(HINSTANCE	hCurrentInstance
	,HINSTANCE	hPreviousInstance
	,LPSTR		lpCommandLine
	,int		iCommandState)
{
	WNDCLASSEX window;
	HWND hwndWindow;
	MSG message;

	window.cbSize			= sizeof(window);
	window.cbClsExtra		= 0;
	window.cbWndExtra		= 0;
	window.hInstance		= hCurrentInstance;
	window.lpfnWndProc		= MainProc;
	window.hIcon			= LoadIcon(hCurrentInstance, MAKEINTRESOURCE(IDI_ICON1));
	window.hIconSm			= LoadIcon(hCurrentInstance, IDI_APPLICATION);
	window.hCursor			= LoadCursor(NULL, IDC_ARROW);
	window.style			= CS_NOCLOSE;
	window.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	window.lpszMenuName		= NULL;
	window.lpszClassName	= CLASSNAME;

	if (!RegisterClassEx(&window)) LOG("Register Failed!");

	hwndWindow = CreateWindow
	(CLASSNAME
	,WINDOWNAME
	,WS_POPUP
	,CW_USEDEFAULT
	,CW_USEDEFAULT
	,CW_USEDEFAULT
	,CW_USEDEFAULT
	,NULL
	,NULL
	,hCurrentInstance
	,NULL);

	if(!hwndWindow) LOG("HWND Failed!");

	//Map no1("ex1");
	//database.sql("SELECT * FROM `Item` WHERE `id` = '1'");
	//LOG(database.message[1]);
    //Character yangyu(1);

	ShowWindow(hwndWindow, SW_MAXIMIZE);
	UpdateWindow(hwndWindow);

    //Update Screen
    SetTimer(hwndWindow, 1, 1000/UPDATE_FRAME, (TIMERPROC)update);

	while (GetMessage(&message, NULL, 0, 0)) {
		DispatchMessage(&message);
		TranslateMessage(&message);
	}
	return 0;
}

LRESULT CALLBACK MainProc
(HWND	hwnd
,UINT	iMsg
,WPARAM	wParam
,LPARAM	lParam) {
	switch (iMsg) {
	case WM_CREATE:
        graphics.initialize(hwnd);
		stage = new Title(); //To Title
		return 0;
    case WM_TIMER:
    case WM_PAINT:
		if (stage != NULL) stage->update();
		if (tempStage != stage) {
			//clear screen
			graphics.setClear(true);
            //change BGM
			audio.setBGM(stage->bgm);
            //change Image List
            graphics.image = stage->image;
            graphics.imageCount = stage->imageCount;
			tempStage = stage;
		}
		graphics.update();
		return 0;
	case WM_KEYDOWN:
		control.key = wParam;
		//update now
		InvalidateRect(hwnd, &graphics.gameScreen, FALSE);
		UpdateWindow(hwnd);
		control.key = NULL;
		return 0;
	case WM_DESTROY:
		delete stage;
        exit(0);
		return 0;
	};
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

TIMERPROC update(HWND hwnd, UINT sMsg, UINT_PTR idEvent, DWORD dwTime) {
    extern int enemyX , enemyY, wait ,rWait;
    if (rWait == 0)
    {
        enemyX += rand() * 100 % 3 - 1;
        enemyY += rand() * 100 % 3 - 1;
        rWait = 15;
    }
    else
    {
        rWait--;
    }
    if(wait > 0) wait--; 
	InvalidateRect(hwnd, &graphics.gameScreen, FALSE);
	UpdateWindow(hwnd); 
	return 0;
}