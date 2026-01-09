#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include<Windows.h>
#include <stdio.h >
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DOUBLE nWidth = 335;
DOUBLE nHeight = 568;
INT xPos = GetSystemMetrics(SM_CXSCREEN) / 8;
INT yPos = GetSystemMetrics(SM_CYSCREEN) / 8;
CHAR nAme_Base_Window[256] = {"Calculator"};
CHAR Input[256] = {};
DOUBLE Numbers[256] = {};
CHAR Symbol[256] = {};
INT Counter_Numbers = 0;
INT Counter_Symbol = 0;
INT Counter_Input = 0;
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
	wClass.lpszClassName = nAme_Base_Window;
	wClass.lpfnWndProc = WndProc;
	if (!RegisterClassEx(&wClass))
	{
		MessageBox(NULL, "Class registration failed", NULL, MB_OK | MB_ICONERROR);
		return 0;
	}
	HWND hwnd = CreateWindowEx
	(
		NULL,
		nAme_Base_Window,
		nAme_Base_Window,
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
LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
	{
		CreateWindowEx
		(
			NULL,
			"Static",
			"0",
			WS_CHILD | WS_VISIBLE,
			10, 100,
			300, 50,
			hwnd,
			(HMENU)1000,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"C",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			85, 240,
			75, 50,
			hwnd,
			(HMENU)1001,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"<--",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 240,
			75, 50,
			hwnd,
			(HMENU)1002,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"/",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			235, 240,
			75, 50,
			hwnd,
			(HMENU)1003,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"7",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 290,
			75, 50,
			hwnd,
			(HMENU)1004,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"8",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			85, 290,
			75, 50,
			hwnd,
			(HMENU)1005,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"9",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 290,
			75, 50,
			hwnd,
			(HMENU)1006,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"X",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			235, 290,
			75, 50,
			hwnd,
			(HMENU)1007,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"4",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 340,
			75, 50,
			hwnd,
			(HMENU)1008,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"5",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			85, 340,
			75, 50,
			hwnd,
			(HMENU)1009,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"6",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 340,
			75, 50,
			hwnd,
			(HMENU)1010,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"--",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			235, 340,
			75, 50,
			hwnd,
			(HMENU)1011,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"1",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 390,
			75, 50,
			hwnd,
			(HMENU)1012,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"2",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			85, 390,
			75, 50,
			hwnd,
			(HMENU)1013,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"3",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 390,
			75, 50,
			hwnd,
			(HMENU)1014,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"+",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			235, 390,
			75, 50,
			hwnd,
			(HMENU)1015,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"+ / --",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			10, 440,
			75, 50,
			hwnd,
			(HMENU)1016,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"0",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			85, 440,
			75, 50,
			hwnd,
			(HMENU)1017,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			",",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			160, 440,
			75, 50,
			hwnd,
			(HMENU)1018,
			GetModuleHandle(NULL),
			NULL
		);
		CreateWindowEx
		(
			NULL,
			"Button",
			"=",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			235, 440,
			75, 50,
			hwnd,
			(HMENU)1019,
			GetModuleHandle(NULL),
			NULL
		);
	}
	break;
	case WM_MOVE:
		break;
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 1004:
		{
			INT number = 7;
			Input[Counter_Input] = '7';
			Counter_Input++;
			Numbers[Counter_Numbers] = 7;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1005:
		{
			INT number = 8;
			Input[Counter_Input] = '8';
			Counter_Input++;
			Numbers[Counter_Numbers] = 8;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1006:
		{
			INT number = 9;
			Input[Counter_Input] = '9';
			Counter_Input++;
			Numbers[Counter_Numbers] = 9;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1008:
		{
			INT number = 4;
			Input[Counter_Input] = '4';
			Counter_Input++;
			Numbers[Counter_Numbers] = 4;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1009:
		{
			INT number = 5;
			Input[Counter_Input] = '5';
			Counter_Input++;
			Numbers[Counter_Numbers] = 5;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1010:
		{
			INT number = 6;
			Input[Counter_Input] = '6';
			Counter_Input++;
			Numbers[Counter_Numbers] = 6;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1012:
		{
			INT number = 1;
			Input[Counter_Input] = '1';
			Counter_Input++;
			Numbers[Counter_Numbers] = 1;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1013:
		{
			INT number = 2;
			Input[Counter_Input] = '2';
			Counter_Input++;
			Numbers[Counter_Numbers] = 2;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1014:
		{
			INT number = 3;
			Input[Counter_Input] = '3';
			Counter_Input++;
			Numbers[Counter_Numbers] = 3;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1017:
		{
			INT number = 0;
			Input[Counter_Input] = '0';
			Counter_Input++;
			Numbers[Counter_Numbers] = 0;
			Counter_Numbers++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1016:
		{
			INT number = Numbers[Counter_Numbers - 1];
			if (number > 0)
			{
				number -= number * 2;
				Input[Counter_Input - 1] = '-';
				if (number == -7)
					Input[Counter_Input] = '7';
				if (number == -8)
					Input[Counter_Input] = '8';
				if (number == -9)
					Input[Counter_Input] = '9';
				if (number == -4)
					Input[Counter_Input] = '4';
				if (number == -5)
					Input[Counter_Input] = '5';
				if (number == -6)
					Input[Counter_Input] = '6';
				if (number == -1)
					Input[Counter_Input] = '1';
				if (number == -2)
					Input[Counter_Input] = '2';
				if (number == -3)
					Input[Counter_Input] = '3';
			}
			else
			{
				number += number * 2;
				Input[Counter_Input] = NULL;
				Counter_Input--;
				if (number == 7)
					Input[Counter_Input] = '7';
				if (number == 8)
					Input[Counter_Input] = '8';
				if (number == 9)
					Input[Counter_Input] = '9';
				if (number == 4)
					Input[Counter_Input] = '4';
				if (number == 5)
					Input[Counter_Input] = '5';
				if (number == 6)
					Input[Counter_Input] = '6';
				if (number == 1)
					Input[Counter_Input] = '1';
				if (number == 2)
					Input[Counter_Input] = '2';
				if (number == 3)
					Input[Counter_Input] = '3';
			}
			Numbers[Counter_Numbers - 1] = number;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1015:
		{
			Input[Counter_Input] = '+';
			Counter_Input++;
			Symbol[Counter_Symbol] = '+';
			Counter_Symbol++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1011:
		{
			Input[Counter_Input] = '-';
			Counter_Input++;
			Symbol[Counter_Symbol] = '-';
			Counter_Symbol++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1007:
		{
			Input[Counter_Input] = '*';
			Counter_Input++;
			Symbol[Counter_Symbol] = '*';
			Counter_Symbol++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1003:
		{
			Input[Counter_Input] = '/';
			Counter_Input++;
			Symbol[Counter_Symbol] = '/';
			Counter_Symbol++;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1002:
		{
			Input[Counter_Input] = NULL;
			if (Input[Counter_Input - 1] == '+' || Input[Counter_Input - 1] == '-' || Input[Counter_Input - 1] == '*' || Input[Counter_Input - 1] == '/')
			{
				Symbol[Counter_Symbol] = NULL;
				Symbol[Counter_Symbol - 1] = NULL;
				Counter_Symbol--;
			}
			if (Input[Counter_Input - 1] == '9' || Input[Counter_Input - 1] == '8' || Input[Counter_Input - 1] == '7' || Input[Counter_Input - 1] == '6' || Input[Counter_Input - 1] == '5' || Input[Counter_Input - 1] == '4' || Input[Counter_Input - 1] == '3' || Input[Counter_Input - 1] == '2' || Input[Counter_Input - 1] == '1')
			{
				Numbers[Counter_Numbers] = NULL;
				Numbers[Counter_Numbers - 1] = NULL;
				Counter_Numbers--;
			}
			Input[Counter_Input - 1] = NULL;
			Counter_Input--;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1001:
		{
			ZeroMemory(&Input, 256);
			Counter_Input = 0;
			ZeroMemory(&Symbol, 256);
			Counter_Symbol = 0;
			HWND hStatic = GetDlgItem(hwnd, 1000);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
		case 1019:
		{
			INT Result = 0;
			if (Symbol[Counter_Symbol - 1] == '+')
			{
				Result = Numbers[Counter_Numbers - 1] + Numbers[Counter_Numbers - 2];
				ZeroMemory(&Input, 256);
				Counter_Input = 0;
				ZeroMemory(&Symbol, 256);
				Counter_Symbol = 0;
			}
			if (Symbol[Counter_Symbol - 1] == '-')
			{
				Result = Numbers[Counter_Numbers - 2] - Numbers[Counter_Numbers - 1];
				ZeroMemory(&Input, 256);
				Counter_Input = 0;
				ZeroMemory(&Symbol, 256);
				Counter_Symbol = 0;
			}
			if (Symbol[Counter_Symbol - 1] == '*')
			{
				Result = Numbers[Counter_Numbers - 1] * Numbers[Counter_Numbers - 2];
				ZeroMemory(&Input, 256);
				Counter_Input = 0;
				ZeroMemory(&Symbol, 256);
				Counter_Symbol = 0;
			}
			if (Symbol[Counter_Symbol - 1] == '/')
			{
				Result = Numbers[Counter_Numbers - 2] / Numbers[Counter_Numbers - 1];
				ZeroMemory(&Input, 256);
				Counter_Input = 0;
				ZeroMemory(&Symbol, 256);
				Counter_Symbol = 0;
			}
			HWND hStatic = GetDlgItem(hwnd, 1000);
			sprintf(Input, "= %d", Result);
			SendMessage(hStatic, WM_SETTEXT, 0, (LPARAM)Input);
		}
		break;
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
}