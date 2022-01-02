#include <iostream>
#include <atlbase.h>

#include "Application.h"

namespace Termanex {
	Application::Application(HWND consoleWindow)
		: m_ConsoleWindow(consoleWindow)
	{
		m_Name = L"Termanex Application";
		SetConsoleTitle(m_Name);
	}
	Application::Application(HWND consoleWindow, LPCTSTR name)
		: m_ConsoleWindow(consoleWindow), m_Name(name)
	{
		SetConsoleTitle(m_Name);
	}
	void Application::Output(std::string out)
	{
		std::cout << out << "\n";
	}
}