#pragma once
#include <string>
#include <vector>

namespace SCC_R
{
	struct ShaserProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
	};

	struct ShaserProgramSourceArray
	{
		std::vector<std::string> VertexSource;
		std::vector<std::string> FragmentSource;
	};
}