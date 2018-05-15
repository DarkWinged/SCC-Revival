#pragma once

#include <GL/glew.h>

#include<Structs.hpp>
#include <Debug.hpp>

#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

namespace SCC_R {
	namespace Graphics {
		class ShaderManager
		{
		public:
			ShaderManager();
			~ShaderManager();

			unsigned int shaderCount;

			enum class ShaderType
			{
				NONE = -1, VERTEX = 0, FRAGMENT = 1
			};

			std::vector<std::string> shaderScources;
			std::vector<unsigned int> vertexShaderIDs;
			std::vector<unsigned int> fragmentShaderIDs;

			unsigned int CreateShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
			unsigned int CompileShader(unsigned int type, const std::string& source);
			ShaserProgramSource ParseShader(const std::string filepath);
		private:
			std::string shaderType(unsigned int);
		};
	}
}