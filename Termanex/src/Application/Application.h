#pragma once

#include <Windows.h>
#include <string>

namespace Termanex {
	struct ConsoleSize
	{
		int Columns;
		int Rows;

		ConsoleSize(int columns, int rows)
			: Columns(columns), Rows(rows)
		{
		}
	};

	class Application {
	public:
		Application();
		Application(LPCTSTR name);
		void Run();

		void Begin();
		void End();

		virtual void OnUpdate() = 0;

		ConsoleSize GetConsoleSize();
	private:
		void RemoveScrollbar();

		std::string GetLastErrorAsString();

		ConsoleSize m_ConsoleSize = {0,0};
		HWND m_ConsoleWindow;
		LPCTSTR m_Name;

		bool m_Running = true;
	};
}