#include "Data\Main.h"

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
	window.style			= CS_CLASSDC;
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
	Map no1("ex1");

	ShowWindow(hwndWindow, SW_MAXIMIZE);
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
	//setting paint object
	PAINTSTRUCT pen;
	HDC hDc;
	RECT rect;
	GetClientRect(hwnd, &rect);

	//setting game_screen
	static struct screen
	{
		int left;
		int top;
		int right;
		int bottom;
	} game_screen;
	switch (iMsg) {
	case WM_CREATE:
		game_screen.left = (GetSystemMetrics(SM_CXSCREEN) - SCREEN_WIDTH) / 2;
		game_screen.top = (GetSystemMetrics(SM_CYSCREEN) - SCREEN_HEIGHT) / 2;
		game_screen.right = game_screen.left + SCREEN_WIDTH;
		game_screen.bottom = game_screen.top + SCREEN_HEIGHT;
		return 0;
	case WM_PAINT:
		hDc = BeginPaint(hwnd, &pen);
		Rectangle(hDc,game_screen.left
					 ,game_screen.top
					 ,game_screen.right
					 ,game_screen.bottom);
		EndPaint(hwnd, &pen);
		return 0;
	case WM_DESTROY:
		return 0;
	};
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}