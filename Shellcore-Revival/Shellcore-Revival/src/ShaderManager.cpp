#include <ShaderManager.hpp>


namespace SCC_R {
	namespace Graphics {


		ShaderManager::ShaderManager()
		{
		}


		ShaderManager::~ShaderManager()
		{
		}

		unsigned int ShaderManager::CreateShaderProgram(const std::string & vertexShader,
			const std::string & fragmentShader)
		{
			GLDebug(unsigned int program = glCreateProgram());
			GLDebug(unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader));
			GLDebug(unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader));

			GLDebug(glAttachShader(program, vs));
			GLDebug(glAttachShader(program, fs));
			GLDebug(glLinkProgram(program));
			GLDebug(glValidateProgram(program));
			GLDebug(glDeleteShader(vs));
			GLDebug(glDeleteShader(fs));

			return program;
		}

		unsigned int ShaderManager::CompileShader(unsigned int type, const std::string & source)
		{
			GLDebug(unsigned int id = glCreateShader(type));
			const char* src = source.c_str();
			GLDebug(glShaderSource(id, 1, &src, nullptr));
			GLDebug(glCompileShader(id));

			int result;
			GLDebug(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

			if (result == GL_FALSE)
			{
				int length;
				GLDebug(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

				char* message = (char*)alloca(length * sizeof(char));
				GLDebug(glGetShaderInfoLog(id, length, &length, message));

				std::cout << "Failed to compile " << shaderType(type) << " Shader: "
					<< std::endl;
				std::cout << message << std::endl;

				GLDebug(glDeleteShader(id));
				return 0;
			}

			return id;
		}

		ShaserProgramSource ShaderManager::ParseShader(const std::string filepath)
		{
			using namespace std;
			ifstream stream(filepath);

						string line;
			stringstream ss[2];
			ShaderType type = ShaderType::NONE;
			while (getline(stream, line))
			{
				if (line.find("#shader") != string::npos)
				{
					if (line.find("vertex") != string::npos)
					{
						type = ShaderType::VERTEX;
					}
					if (line.find("fragment") != string::npos)
					{
						type = ShaderType::FRAGMENT;
					}

				}
				else
				{
					ss[(int)type] << line << '\n';
				}
			}

			return { ss[0].str(), ss[1].str() };
		}

		std::string ShaderManager::shaderType(unsigned int type)
		{
			std::string result = "";
			switch (type) {
				case GL_VERTEX_SHADER:
					result = "Vertex";
				case GL_FRAGMENT_SHADER:
					result = "Fragment";
			}
			return result;
		}


	}
}