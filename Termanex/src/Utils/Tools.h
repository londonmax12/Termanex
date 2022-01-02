#pragma once

#include <Windows.h>

namespace Termanex {
	HWND GetConsole() {
		return GetConsoleWindow();
	}
}