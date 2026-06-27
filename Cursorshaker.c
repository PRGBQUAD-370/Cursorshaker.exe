#include <Windows.h>

DWORD WINAPI cur(LPVOID lpParam) {
	POINT cursor;
	while (1) {

		HDC hdc = GetDC(HWND_DESKTOP);
		GetCursorPos(&cursor);

		int X = cursor.x + rand() % 3 - 1;
		int Y = cursor.y + rand() % 3 - 1;

		SetCursorPos(X, Y);
		ReleaseDC(0, hdc);

	}

	return(1);

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	if (MessageBoxA(0, "Warning\r\n\This shakes the cursor for 30 seconds\r\n\Still continue", "cursorshaker.exe", MB_YESNO | MB_ICONWARNING) == IDNO) {

		return 0;

	}

	CreateThread(0, 0, cur, 0, 0, 0);

	Sleep(30000);
}