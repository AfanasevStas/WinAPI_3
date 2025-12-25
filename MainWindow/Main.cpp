#undef UNICODE
#include<Windows.h>

CONST CHAR g_SZ_CLASS_NAME[] = "Main Window PV_522";
LRESULT WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
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
			CW_USEDEFAULT,CW_USEDEFAULT,
			CW_USEDEFAULT,CW_USEDEFAULT,
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
		break;
	case WM_DESTROY:
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return FALSE;
}
