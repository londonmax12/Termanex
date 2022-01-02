#pragma once

#include <Windows.h>

namespace Termanex {
	class ConsoleCommand {
	public:
		static void WriteSymbol(HANDLE h, SHORT x, SHORT y, const char* symbol, WORD color)
		{
			COORD here;
			here.X = x;
			here.Y = y;

			WORD attribute = color;
			DWORD written;
			::WriteConsoleOutputAttribute(h, &attribute, 1, here, &written);
			::WriteConsoleOutputCharacterA(h, symbol, 1, here, &written);
		}
	};
}