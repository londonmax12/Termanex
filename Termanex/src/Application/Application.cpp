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
	}
	Application::Application(LPCTSTR name)
		: m_Name(name)
	{
		m_ConsoleWindow = GetConsoleWindow();
		SetConsoleTitle(m_Name);
	}
	void Application::Run()
	{
		while(m_Running)
		{
			OnUpdate();
		}
	}
	void Application::Fill()
	{
		Fill("A", Color::WHITE);
	}
	void Application::Fill(const char* symbol, Color color)
	{
		HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE)
		{
			printf("Invalid handle");
		}

		for (int row = 0; row < m_ConsoleSize.Rows; row++)
		{
			for (int column = 0; column < m_ConsoleSize.Columns; column++)
			{
				ConsoleCommand::WriteSymbol(hStdOut, column, row, symbol, ColorToInt(color));
			}
		}
	}
	void Application::Output(std::string out)
	{
		std::cout << out << "\n" << std::flush;
	}

	void Application::Clear()
	{
		system("CLS");
	}

	void Application::Pause()
	{
		system("PAUSE");
	}
	void Application::Begin()
	{
		m_ConsoleSize = GetConsoleSize();
		//Fill();
	}
	void Application::End()
	{
	}
	std::string Application::GetLastErrorAsString()
	{
		//Get the error message ID, if any.
		DWORD errorMessageID = ::GetLastError();
		if (errorMessageID == 0) {
			return std::string(); //No error message has been recorded
		}

		LPSTR messageBuffer = nullptr;

		//Ask Win32 to give us the string version of that message ID.
		//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
		size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

		//Copy the error message into a std::string.
		std::string message(messageBuffer, size);

		//Free the Win32's string's buffer.
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
}