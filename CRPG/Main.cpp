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
	window.hIcon			= LoadIcon(hCurrentInstance, IDI_APPLICATION);
	window.hIconSm			= LoadIcon(hCurrentInstance, IDI_APPLICATION);
	window.hCursor			= LoadCursor(NULL, IDC_ARROW);
	window.style			= CS_SAVEBITS;
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
    Character yangyu(1);

	ShowWindow(hwndWindow, SW_MAXIMIZE);
	UpdateWindow(hwndWindow);

    

<<<<<<< HEAD
	//play tilte music
	//audio.setBGM("title.wav");

	//Update Screen 
=======
    //Update Screen
    SetTimer(hwndWindow, 1, UPDATE_FRAME, (TIMERPROC)update);
>>>>>>> cf33768a0fed3abee05a8bad41d02bed28f3cf75
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
		return 0;
    case WM_TIMER:
    case WM_PAINT:
		graphics.update();
		return 0;
    case WM_KEYDOWN:
        
        switch (wParam)
        {
        case 37: graphics.dx -= 32; return 0;
        case 38: graphics.dy -= 32; return 0;
        case 39: graphics.dx += 32; return 0;
        case 40: graphics.dy += 32; return 0;
        }
        return 0;
	case WM_DESTROY:
        exit(0);
		return 0;
	};
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

TIMERPROC update(HWND hwnd, UINT sMsg, UINT_PTR idEvent, DWORD dwTime) {
	InvalidateRect(hwnd, &graphics.gameScreen, TRUE);
	UpdateWindow(hwnd);
	return 0;
}