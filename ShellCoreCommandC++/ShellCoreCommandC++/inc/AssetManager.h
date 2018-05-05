#pragma once
#include <vector>
#include <memory>
#include <Image.h>
#include <string>

namespace SCC_R {

	class AssetManager
	{
	public:
		AssetManager();
		~AssetManager();
		void initalize(SDL_Renderer *ren, std::string basePath);

		std::weak_ptr<Image> getCore(unsigned int index);
		std::weak_ptr<Image> getSection(unsigned int index);
		std::weak_ptr<Image> getModule(unsigned int index);


	private:
		std::vector<std::shared_ptr<Image>> cores;
		std::vector<std::shared_ptr<Image>> sections;
		std::vector<std::shared_ptr<Image>> modules;
	};

}