#include "App.h"
#include "resource.h"
#include <type_traits>
CApp* self;

CApp::CApp()
{
	self = this;
}


CApp::~CApp()
{
}

ATOM CApp::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = CApp::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszClassName = szWindowClass;
	wcex.lpszMenuName = MAKEINTRESOURCE(0);
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassEx(&wcex);
}

BOOL CApp::InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	this->hInst = hInstance;
	this->nCmdShow = nCmdShow;
	LoadString(hInstance, IDS_APP_TITLE, this->szTitle, 100);
	LoadString(hInstance, IDS_WC, this->szWindowClass, 100);
	this->MyRegisterClass(hInstance);

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}




	ShowWindow(hWnd, this->nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;

}

LRESULT CALLBACK CApp::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return self->ProcessMessages(hWnd, message, wParam, lParam);

}

LRESULT CApp::ProcessMessages(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	RECT* rct;


	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:

		return DefWindowProc(hWnd, message, wParam, lParam);

		break;
	case WM_PAINT:

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_SIZING:
		rct = (RECT*)lParam;
	
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
int CApp::StartCycle()
{
	MSG msg;


	while (GetMessage(&msg, NULL, 0, 0))
	{


		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	return (int)msg.wParam;
}

