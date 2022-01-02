#include "Input.h"

namespace Termanex {
	bool Input::IsKeyDown(int key)
	{
		SHORT result = GetAsyncKeyState(key);
		return (bool)result;
	}
}