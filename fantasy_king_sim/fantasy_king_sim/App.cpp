#include "App.h"
#include "resource.h"
#include "WorldBoard.h"
#include "SystemLocator.h"
#include <Windowsx.h>
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
	renderer = std::unique_ptr<CGDIGraphicSystem>(new CGDIGraphicSystem(hWnd));
	strings_manager = std::unique_ptr<CStringManager>(new CStringManager(hInstance));
	CSystemLocator::Locate(renderer.get());
	CSystemLocator::Locate(strings_manager.get());
	board = std::unique_ptr<IGameBoard>(new CWorldBoard());
	
	gui = std::unique_ptr<CGUISystem>(new CGUISystem());
	gui->InitTestGUI((CWorldBoard*)board.get());

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

	CGUISystem* gui_ref = gui.get();
	std::function<void(const POINT&, const BYTE)> mdwn = [&](const POINT& point, const BYTE type) {
		gui_ref->ProcessMouseDown(point, type);
	};
	std::function<void(const POINT&, const BYTE)> mup = [&](const POINT& point, const BYTE type) {
		gui_ref->ProcessMouseUp(point, type);
	};
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:

		return DefWindowProc(hWnd, message, wParam, lParam);

		break;
	case WM_LBUTTONDOWN:
		ProcessClick(hWnd,lParam, MBC_LEFT,mdwn);
		break;
	case WM_RBUTTONDOWN:
		ProcessClick(hWnd, lParam, MBC_RIGHT, mdwn);
		break;
	case WM_LBUTTONUP:
		ProcessClick(hWnd, lParam, MBC_LEFT, mup);
		break;
	case WM_RBUTTONUP:
		ProcessClick(hWnd, lParam, MBC_RIGHT, mup);
		break;
	case WM_MBUTTONDOWN:
		ProcessClick(hWnd, lParam, MBC_MIDDLE, mdwn);
		break;
	case WM_MBUTTONUP:
		ProcessClick(hWnd, lParam, MBC_MIDDLE, mup);
		break;
	case WM_XBUTTONDOWN:

		wmEvent = GET_XBUTTON_WPARAM(wParam);
		if (wmEvent == XBUTTON1)
		{
			ProcessClick(hWnd, lParam, MBC_MOUSE4, mdwn);
		}
		if (wmEvent == XBUTTON2)
		{
			ProcessClick(hWnd, lParam, MBC_MOUSE5, mdwn);
		}
		break;
	case WM_XBUTTONUP:
		
		wmEvent = GET_XBUTTON_WPARAM(wParam);
		if (wmEvent == XBUTTON1)
		{
			ProcessClick(hWnd, lParam, MBC_MOUSE4, mup);
		}
		if (wmEvent == XBUTTON2)
		{
			ProcessClick(hWnd, lParam, MBC_MOUSE5, mup);
		}
		break;
	case WM_PAINT:
		renderer->RenderStart();
		board->Iterate();
		gui->Render();

		renderer->RenderEnd();
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


void CApp::ProcessClick(HWND hWnd, LPARAM lParam, BYTE type, std::function<void(const POINT&, const BYTE)> action)
{
	POINT click_point;
	click_point.x = GET_X_LPARAM(lParam);
	click_point.y = GET_Y_LPARAM(lParam);
	action(click_point, type);
	InvalidateRect(hWnd, NULL, true);
	bool asd=UpdateWindow(hWnd);

}

