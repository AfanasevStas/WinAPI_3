#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"resource.h"
#include <stdio.h >
CONST CHAR* g_sz_VALUES[] = {"This", "is", "my", "Combo", "Box"};

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{		
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON2));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
			for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
			{
				SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
			}
		}
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK: 
		{
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			INT iNdex = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			if (iNdex == CB_ERR)
			{
				MessageBox(hwnd, "Выбор не сделан!", "Info", MB_OK | MB_ICONERROR);
				break;
			}
			CHAR Text[40];
			if(iNdex == 0)
			sprintf(Text, "Индекс: %d\nТекст: This", iNdex);
			if (iNdex == 1)
			sprintf(Text, "Индекс: %d\nТекст: is", iNdex);
			if (iNdex == 2)
			sprintf(Text, "Индекс: %d\nТекст: my", iNdex);
			if (iNdex == 3)
			sprintf(Text, "Индекс: %d\nТекст: Combo", iNdex);
			if (iNdex == 4)
			sprintf(Text, "Индекс: %d\nТекст: Box", iNdex);
			MessageBox(hwnd, Text, "Info", MB_OK | MB_ICONINFORMATION);
		}
			break;
		case IDCANCEL: EndDialog(hwnd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}
