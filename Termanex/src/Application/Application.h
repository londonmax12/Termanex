#pragma once

#include <Windows.h>
#include <string>

namespace Termanex {
	class Application {
	public:
		Application(HWND consoleWindow);
		Application(HWND consoleWindow, LPCTSTR name);

		void Output(std::string out);
	private: 
		HWND m_ConsoleWindow;
		LPCTSTR m_Name;
	};
}