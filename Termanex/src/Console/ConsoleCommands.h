#pragma once

#include <Windows.h>
#include <iostream>

#include "src/Characters.h"

namespace Termanex {
	enum Color {
		NAVY, GREEN, TEAL, MAROON, PURPLE,
		OLIVE, SILVER, GRAY, BLUE, LIME,
		AQUA, RED, PINK, YELLOW, WHITE
	};

	class ConsoleCommand {
	public:
		static int ColorToInt(Color color)
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
		static void WriteSymbol(HANDLE h, SHORT x, SHORT y, LPCWSTR symbol, WORD color)
		{
			COORD here;
			here.X = x;
			here.Y = y;

			WORD attribute = color;
			DWORD written;
			::WriteConsoleOutputAttribute(h, &attribute, 1, here, &written);
			::WriteConsoleOutputCharacterW(h, symbol, 1, here, &written);
		}
		static void Fill(ConsoleSize consoleSize)
		{
			Fill(FULL_SQUARE, Color::WHITE, consoleSize);
		}
		static void Fill(LPCWSTR symbol, Color color, ConsoleSize consoleSize) 
		{
			HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
			if (hStdOut == INVALID_HANDLE_VALUE)
			{
				printf("Invalid handle");
			}

			for (int row = 0; row < consoleSize.Rows; row++)
			{
				for (int column = 0; column < consoleSize.Columns; column++)
				{
					ConsoleCommand::WriteSymbol(hStdOut, column, row, symbol, ColorToInt(color));
				}
			}
		}
		static void Output(std::string out) {
			std::cout << out << "\n";
		}
		static void Clear() {
			system("CLS");
		}
		static void Pause() {
			system("PAUSE");
		}
		static void SetCharacter(LPCWSTR symbol, Color color, int x, int y) {
			HANDLE hStdOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
			if (hStdOut == INVALID_HANDLE_VALUE)
			{
				printf("Invalid handle");
			}

			ConsoleCommand::WriteSymbol(hStdOut, x, y, symbol, ColorToInt(color));
		}

	};
}