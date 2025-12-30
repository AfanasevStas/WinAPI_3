#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include<Windows.h>
#include <stdio.h >
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DOUBLE nWidth = 75 * (GetSystemMetrics(SM_CXSCREEN) / 100);
DOUBLE nHeight = 75 * (GetSystemMetrics(SM_CYSCREEN) / 100);
INT xPos = GetSystemMetrics(SM_CXSCREEN) / 8;
INT yPos = GetSystemMetrics(SM_CYSCREEN) / 8;

CHAR g_SZ_CLASS_NAME[256] = {};

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	sprintf(g_SZ_CLASS_NAME, "Main Window PV_522           Ширина: %f, Высота: %f, X: %d, Y: %d", nWidth, nHeight, xPos, yPos);
	WNDCLASSEX wClass;
	ZeroMemory(&wClass, sizeof(wClass));
	wClass.style = NULL;
	wClass.cbSize = sizeof(wClass);
	wClass.cbClsExtra = 0;
	wClass.cbClsExtra = 0;
	wClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wClass.hInstance = hInstance;
	wClass.lpszMenuName = NULL;
	wClass.lpszClassName = g_SZ_CLASS_NAME;
	wClass.lpfnWndProc = WndProc;
	if (!RegisterClassEx(&wClass))
	{
		MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}
	HWND hwnd = CreateWindowEx
	(
		NULL,
		g_SZ_CLASS_NAME,
		g_SZ_CLASS_NAME,
		WS_OVERLAPPEDWINDOW,
		xPos, yPos,
		nWidth, nHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window create failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		HWND hStatic = CreateWindowEx
		(
			NULL,
			"Static",
			"Этот текст создан функцией CreateWindowEx()",
			WS_CHILD | WS_VISIBLE,
			10, 10,
			500, 25,
			hwnd,
			(HMENU)1000,
			GetModuleHandle(NULL),
			NULL
		);
		HWND hEdit = CreateWindowEx
		(
			NULL,
			"Edit",
			"",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			10, 40,
			500, 22,
			hwnd,
			(HMENU)1001,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"Применить",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			410,70,
			100,25,
			hwnd,
			(HMENU)1002,
			GetModuleHandle(NULL),
			NULL
		);
	}
		break;
	case WM_SIZE:
	case WM_MOVE:
	{
		INT xPos = { (int)LOWORD(lParam) };
		INT yPos = { (int)HIWORD(lParam) };
		ZeroMemory(&g_SZ_CLASS_NAME, 256);
		sprintf(g_SZ_CLASS_NAME, "Main Window PV_522           Ширина: %f, Высота: %f, X: %d, Y: %d", nWidth, nHeight, xPos, yPos);
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)g_SZ_CLASS_NAME);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 1002: 
			CHAR sz_buffer[MAX_PATH] = {};
			HWND hStatic = GetDlgItem(hwnd, 1000);
			HWND hEdit = GetDlgItem(hwnd, 1001);
			SendMessage(hEdit, WM_GETTEXT, MAX_PATH, (LPARAM)sz_buffer);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)sz_buffer);
			
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}
