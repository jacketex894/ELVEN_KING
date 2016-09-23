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
	window.style			= CS_HREDRAW | CS_VREDRAW;
	window.hbrBackground	= (HBRUSH)GetStockObject(BLACK_BRUSH);
	window.lpszMenuName		= NULL;
	window.lpszClassName	= CLASSNAME;

	if (!RegisterClassEx(&window)) LOG("Register Failed!");

	hwndWindow = CreateWindow
	(CLASSNAME
	,WINDOWNAME
	,WS_OVERLAPPED
	,SCREEN_LEFT
	,SCREEN_TOP
	,SCREEN_WIDTH
	,SCREEN_HEIGHT
	,NULL
	,NULL
	,hCurrentInstance
	,NULL);

	if(!hwndWindow) LOG("HWND Failed!");

    //Graphics initialize
    graphics.initialize(hwndWindow);

	ShowWindow(hwndWindow, SW_SHOW);
	UpdateWindow(hwndWindow);

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
		stage = new Title(); //To Title
		return 0;
    case WM_TIMER:
    case WM_PAINT:
        if (stage != NULL)
            stage->update();
        if (tempStage != stage)
        {
            //change BGM
            audio.setBGM(stage->bgm);
            graphics.clearScreen();
            tempStage = stage;
        }
        graphics.update();
		return 0;
	case WM_KEYDOWN:
		control.key = wParam;
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