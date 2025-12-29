#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include<Windows.h>
#include <stdio.h >
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DOUBLE nWidth = 75 * (GetSystemMetrics(SM_CXSCREEN) / 100);
DOUBLE nHeight = 75 * (GetSystemMetrics(SM_CYSCREEN) / 100);
INT xPos = CW_USEDEFAULT;
INT yPos = CW_USEDEFAULT;

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
	while (GetMessage(&msg, NULL,0,0) > 0)
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
		break;
	case WM_COMMAND:
		switch (uMsg)
		{
		case WM_MOVE:
		{
			INT xPos = { (int)LOWORD(lParam) };
			INT yPos = { (int)HIWORD(lParam) };
			for (int i = 0; i < 256; i++)
			{
				g_SZ_CLASS_NAME[i] = 0;
			}
			sprintf(g_SZ_CLASS_NAME, "Main Window PV_522           Ширина: %f, Высота: %f, X: %d, Y: %d", nWidth, nHeight, xPos, yPos);
		}
		break;
		case IDCANCEL: DestroyWindow(hwnd); break;
		
		}
		break;
	case WM_DESTROY:
		DestroyWindow(hwnd);
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}
