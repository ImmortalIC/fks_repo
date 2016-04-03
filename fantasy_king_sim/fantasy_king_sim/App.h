#pragma once
#include "stdafx.h"
#include "GameBoard.h"
#include "GDIGraphicSystem.h"
#include "GUISystem.h"
#include "StringManager.h"
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
	void ProcessClick(HWND,LPARAM,BYTE,std::function<void(const POINT&,const BYTE)>);
	std::unique_ptr<IGameBoard> board;
	std::unique_ptr<CGUISystem> gui;
	std::unique_ptr<CGDIGraphicSystem> renderer;
	std::unique_ptr<CStringManager> strings_manager;
};


