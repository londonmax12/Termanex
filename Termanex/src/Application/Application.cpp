#include <iostream>
#include <atlbase.h>

#include "Application.h"
#include "Console/ConsoleCommands.h"

namespace Termanex {
	Application::Application()
	{
		m_Name = L"Termanex Application";
		m_ConsoleWindow = GetConsoleWindow();
		SetConsoleTitle(m_Name);

		RemoveScrollbar();
		std::cout << std::flush;
	}
	Application::Application(LPCTSTR name)
		: m_Name(name)
	{
		m_ConsoleWindow = GetConsoleWindow();
		SetConsoleTitle(m_Name);

		RemoveScrollbar();
		std::cout << std::flush;
	}
	void Application::Run()
	{
		while(m_Running)
		{
			OnUpdate();
		}
	}
	void Application::Begin()
	{
		m_ConsoleSize = GetConsoleSize();
	}
	void Application::End()
	{
	}
	std::string Application::GetLastErrorAsString()
	{
		DWORD errorMessageID = ::GetLastError();
		if (errorMessageID == 0) {
			return std::string();
		}

		LPSTR messageBuffer = nullptr;

		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

		std::string message(messageBuffer, size);

		LocalFree(messageBuffer);

		return message;
	}
	ConsoleSize Application::GetConsoleSize()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		int columns, rows;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		return ConsoleSize(columns, rows);
	}
	void Application::RemoveScrollbar()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
		GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

		short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
		short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

		short scrBufferWidth = scrBufferInfo.dwSize.X;
		short scrBufferHeight = scrBufferInfo.dwSize.Y;

		COORD newSize;
		newSize.X = scrBufferWidth;
		newSize.Y = winHeight;

		int Status = SetConsoleScreenBufferSize(hOut, newSize);
		if (Status == 0)
		{
			std::cout << "SetConsoleScreenBufferSize() failed: " << GetLastError() << '\n';
			ConsoleCommand::Pause();
		}
	}
}