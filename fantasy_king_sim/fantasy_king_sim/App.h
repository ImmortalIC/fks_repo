#pragma once
#pragma once
#include "stdafx.h"
#include "GameBoard.h"
#include "GDIGraphicSystem.h"
#define WIDTH 1920
#define HEIGHT 1080


class CApp
{
public:
	CApp();
	~CApp();
	BOOL InitInstance(HINSTANCE, int);
	int StartCycle();
private:
	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
	HINSTANCE hInst;								// текущий экземпляр
	int nCmdShow;
	TCHAR szTitle[100];					// Текст строки заголовка
	TCHAR szWindowClass[100];			// имя класса главного окна
	ATOM MyRegisterClass(HINSTANCE hInstance);
	LRESULT ProcessMessages(HWND, UINT, WPARAM, LPARAM);
	std::unique_ptr<IGameBoard> board;
	std::unique_ptr<CGDIGraphicSystem> renderer;
};


