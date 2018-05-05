#include <AssetManager.h>

namespace SCC_R {

	AssetManager::AssetManager()
	{
	}

	AssetManager::~AssetManager()
	{
		cores.~vector();
		modules.~vector();
		sections.~vector();
	}

	void AssetManager::initalize(SDL_Renderer *ren, std::string basePath)
	{
		using namespace std;
		bool loop = false;
		string path = "";
		int index = 0;

		do{
			//stes path to next image
			path = basePath + "Core-" + std::to_string(index);
			path += ".png";

			cores.push_back(shared_ptr<Image>(new Image()));
			//checks if image was loaded sucessfully
			if (cores[cores.size() - 1]->setImage(path, ren))
			{
				//loading was sucessful, loop continues
				loop = true;
				index++;
			}
			else {
				//loading failed, removes image & breaks loop
				cores.erase(cores.end()-1);
				loop = false;
			}
		} while (loop);

		index = 0;

		do {
			path = basePath + "Section-" + std::to_string(index);
			path += ".png";

			sections.push_back(shared_ptr<Image>(new Image()));

			if (sections[sections.size() - 1]->setImage(path, ren))
			{
				loop = true;
				index++;
			}
			else {
				sections.erase(sections.end() - 1);
				loop = false;
			}
		} while (loop);

		index = 0;

		do {
			path = basePath + "Module-" + std::to_string(index);
			path += ".png";

			modules.push_back(shared_ptr<Image>(new Image()));

			if (modules[modules.size() - 1]->setImage(path, ren))
			{
				loop = true;
				index++;
			}
			else {
				modules.erase(modules.end() - 1);
				loop = false;
			}
		} while (loop);
	}

	std::weak_ptr<Image> AssetManager::get(unsigned int index, assetType type)
	{
		switch (type)
		{
		case CORE:
			if (index < cores.size())
				return cores[index];
			else
				return std::shared_ptr<Image>();
			break;

		case SECTION:
			if (index < sections.size())
				return sections[index];
			else
				return std::shared_ptr<Image>();
			break;

		case MODULE:
			if (index < modules.size())
				return modules[index];
			else
				return std::shared_ptr<Image>();
			break;
		}
		return std::shared_ptr<Image>();
	}

}