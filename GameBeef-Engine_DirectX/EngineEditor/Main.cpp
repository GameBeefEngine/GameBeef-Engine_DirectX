#include "resource.h"
#include <Windows.h>
#include <iostream>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	// Register the window class.
	

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = "MainWindow";

	RegisterClass(&wc);

	// Create the window.

	HWND hwnd = CreateWindowEx(
		0,                              // Optional window styles.
		"MainWindow",                     // Window class
		"",    // Window text
		WS_OVERLAPPEDWINDOW,            // Window style

		// Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,       // Parent window    
		NULL,       // Menu
		hInstance,  // Instance handle
		NULL        // Additional application data
	);

	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	// Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HWND hwndEdit;

	TCHAR templ[] = "// It`s a simple code";

	switch (uMsg)
	{
	case WM_CREATE:
		hwndEdit = CreateWindowEx(
			0, "EDIT",   // predefined class 
			NULL,         // no window title 
			WS_CHILD | WS_VISIBLE | WS_VSCROLL |
			ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
			0, 0, 0, 0,   // set size in WM_SIZE message 
			hwnd,         // parent window 
			(HMENU)ID_MENU_EDIT,   // edit control ID 
			(HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE),
			NULL);        // pointer not needed 



		return 0;

	case WM_COMMAND:

		// Test for the identifier of a command item. 

		switch (LOWORD(wParam))
		{
		case ID_FILE_NEWFILE:
			
			SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM)templ);

		case ID_FILE_NEWPROJECT:
			// DoFileClose();  // application-defined 
			break;
			// Process other menu commands. 

		default:
			break;

	}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	return 0;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

static void FileNewEntr(HWND hwndedit, char *tmplt) {
	
}