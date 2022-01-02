
#include <Termanex.h>

int main() {
	class App : public Termanex::Application
	{
	public:
		App(LPCTSTR name)
			: Termanex::Application(name)
		{

		}

		virtual void OnUpdate() override
		{
			Begin();
			Fill("A", Application::Color::PINK);
			End();
		}
	};
	
	App app(L"Test App");
	app.Run();
}