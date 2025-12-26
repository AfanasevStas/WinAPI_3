#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include"resource.h"
#include<stdio.h>
CONST CHAR* g_sz_VALUES[] = {"This", "is","my","List","Box"};
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//BOOL CALLBACK DlgProc_2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, (DLGPROC)DlgProc, 0);
	//DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, (DLGPROC)DlgProc_2, 0);
	return 0;
}
//BOOL CALLBACK DlgProc_2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//	switch (uMsg)
//	{
//	case WM_INITDIALOG:
//	{
//
//	}
//	break;
//	case WM_COMMAND:
//	{
//		switch (LOWORD(wParam))
//		{
//		case IDCANCEL: EndDialog(hwnd, 0); break;
//		}
//	}
//	break;
//	case WM_CLOSE:
//	{
//		EndDialog(hwnd, 0);
//	}
//	break;
//	}
//	return FALSE;
//}
BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST);
			HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
			SendMessage(hwnd, WM_SETICON, 0, (LPARAM)hIcon);
			for (int i = 0; i < sizeof(g_sz_VALUES) / sizeof(g_sz_VALUES[0]); i++)
			{
				SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)g_sz_VALUES[i]);
			}
		}
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL: EndDialog(hwnd, 0); break;
		case IDOK:
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST);
			INT iNdex = SendMessage(hList, LB_GETCURSEL, 0, 0);
			CHAR tExt[256];
			SendMessage(hList, LB_GETTEXT, iNdex, (LPARAM)tExt);
			if (iNdex == CB_ERR)
			{
				MessageBox(hwnd, "Строка не выбрана!", "Info", MB_OK | MB_ICONERROR);
				break;
			}
			CHAR tExt_2[256];
			sprintf(tExt_2, "Индекс: %d\nТекст: %s", iNdex, tExt);
			MessageBox(hwnd, tExt_2, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDC_BUTTON1:
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST);
			CHAR tExt[256];
		}
		break;
		case IDC_BUTTON2:
		{
			HWND hList = GetDlgItem(hwnd, IDC_LIST);
			INT iNdex = SendMessage(hList, LB_GETCURSEL, 0, 0);
			if (iNdex == CB_ERR)
			{
				MessageBox(hwnd, "Строка не выбрана!", "Info", MB_OK | MB_ICONERROR);
				break;
			}
			if (iNdex != CB_ERR)
			{
				SendMessage(hList, LB_DELETESTRING, iNdex, 0);
			}
		}
			break;
		}
	break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
	}
	return FALSE;
}