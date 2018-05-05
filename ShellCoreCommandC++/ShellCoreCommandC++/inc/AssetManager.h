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
		//loads images asstes into memeory 
		void initalize(SDL_Renderer *ren, std::string basePath);
		enum assetType{CORE, SECTION, MODULE};

		//returns specified asset if it exists
		std::weak_ptr<Image> get(unsigned int index, assetType type);


	private:
		std::vector<std::shared_ptr<Image>> cores;
		std::vector<std::shared_ptr<Image>> sections;
		std::vector<std::shared_ptr<Image>> modules;
	};

}