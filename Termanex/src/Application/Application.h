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
		enum Color {
			NAVY, GREEN, TEAL, MAROON, PURPLE,
			OLIVE, SILVER, GRAY, BLUE, LIME,
			AQUA, RED, PINK, YELLOW, WHITE
		};

		Application();
		Application(LPCTSTR name);
		void Run();
		void Fill();
		void Fill(const char* symbol, Color color);

		void Output(std::string out);
		void Clear();
		void Pause();

		void Begin();
		void End();

		virtual void OnUpdate() = 0;
		int ColorToInt(Color color)
		{
			switch (color)
			{
			case Color::NAVY:
				return 0x01;
				break;
			case Color::GREEN:
				return 0x02;
				break;
			case Color::TEAL:
				return 0x03;
				break;
			case Color::MAROON:
				return 0x04;
				break;
			case Color::PURPLE:
				return 0x05;
				break;
			case Color::OLIVE:
				return 0x06;
				break;
			case Color::SILVER:
				return 0x07;
				break;
			case Color::GRAY:
				return 0x08;
				break;
			case Color::BLUE:
				return 0x09;
				break;
			case Color::LIME:
				return 0x0A;
				break;
			case Color::AQUA:
				return 0x0B;
				break;
			case Color::RED:
				return 0x0C;
				break;
			case Color::PINK:
				return 0x0D;
				break;
			case Color::YELLOW:
				return 0x0E;
				break;
			case Color::WHITE:
				return 0x0F;
				break;
			default:
				break;
			}
		}
	private:

		std::string GetLastErrorAsString();
		ConsoleSize GetConsoleSize();

		ConsoleSize m_ConsoleSize = {0,0};
		HWND m_ConsoleWindow;
		LPCTSTR m_Name;

		bool m_Running = true;
	};
}