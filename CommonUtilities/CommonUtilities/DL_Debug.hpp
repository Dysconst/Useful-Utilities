#pragma once
#include <string>

namespace DL_Debug
{
	class Debug
	{
	public:
		static Debug& Create(std::string aFileName)
		{
			static Debug ourInstance = Debug();
			return ourInstance;
		}
	private:
		Debug() {}
		std::string myDebugFilename;
	};
}