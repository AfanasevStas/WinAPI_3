#include<Windows.h>
#include"resource.h"

CONST CHAR g_sz_INVITE[] = "Введите имя пользователя";

BOOL CALLBACK DlgProc(HWND hwd, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc, 0);
	return 0;
}
BOOL CALLBACK DlgProc(HWND hwd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		HWND hEditLogin = GetDlgItem(hwd, IDC_EDIT_LOGIN);
		SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITE);
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_EDIT_LOGIN:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwd, IDC_EDIT_LOGIN);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			if (HIWORD(wParam) == EN_SETFOCUS)
			{
				if (strcmp(sz_buffer, g_sz_INVITE) == 0)
				{
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)"");
				}
			}
			if (HIWORD(wParam) == EN_KILLFOCUS)
			{
				if (strcmp(sz_buffer, "") == 0)
				{
					SendMessage(hEditLogin, WM_SETTEXT, 0, (LPARAM)g_sz_INVITE);
				}
			}
		}
		break;
		case IDC_BUTTON_COPY:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hEditLogin = GetDlgItem(hwd, IDC_EDIT_LOGIN);
			HWND hEditPassword = GetDlgItem(hwd, IDC_EDIT_PASSORD);
			SendMessage(hEditLogin, WM_GETTEXT, SIZE, (LPARAM)sz_buffer);
			SendMessage(hEditPassword, WM_SETTEXT, 0, (LPARAM)sz_buffer);
		}
		break;
		case IDOK: MessageBox(hwd, "Была нажата кнопка OK", "Info", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL: EndDialog(hwd, 0); break;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwd, 0);
	}
	return FALSE;
}