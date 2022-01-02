
#include <Termanex.h>

#include <fcntl.h>
#include <io.h>

using namespace Termanex;

int main() {
	class App : public Termanex::Application
	{
	public:
		int x = 0;
		int y = 0;

		App(LPCTSTR name)
		: Termanex::Application(name)
		{
		}

		virtual void OnUpdate() override
		{
			Begin();
			ConsoleCommand::Fill(FULL_SQUARE, Color::MAROON, GetConsoleSize());
			if (Termanex::Input::IsKeyDown(VK_LEFT))
			{
				x--;
			}
			if (Termanex::Input::IsKeyDown(VK_RIGHT))
			{
				x++;
			}
			if (Termanex::Input::IsKeyDown(VK_UP))
			{
				y--;
			}
			if (Termanex::Input::IsKeyDown(VK_DOWN))
			{
				y++;
			}
			ConsoleCommand::SetCharacter(L"O", Color::BLUE, x, y);
			End();
		}
	};
	
	App app(L"Test App");
	app.Run();
}