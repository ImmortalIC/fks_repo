#pragma once
#pragma once
#include "stdafx.h"
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
	HINSTANCE hInst;								// ������� ���������
	int nCmdShow;
	TCHAR szTitle[100];					// ����� ������ ���������
	TCHAR szWindowClass[100];			// ��� ������ �������� ����
	ATOM MyRegisterClass(HINSTANCE hInstance);
	LRESULT ProcessMessages(HWND, UINT, WPARAM, LPARAM);

};


