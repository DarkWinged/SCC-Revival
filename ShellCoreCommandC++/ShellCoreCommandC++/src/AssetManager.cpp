#include <AssetManager.h>

namespace SCC_R {

	AssetManager::AssetManager()
	{
	}

	AssetManager::~AssetManager()
	{
	}

	void AssetManager::initalize(SDL_Renderer *ren, std::string basePath)
	{
		using namespace std;
		string path = "";
		bool loop = false;
		int index = 0;

		do{
			path = basePath + "Core-" + std::to_string(index);
			path += ".png";
			//string result = index.c_str();

			cores.push_back(shared_ptr<Image>(new Image()));
			if (cores[cores.size() - 1]->setImage(path, ren))
			{
				loop = true;
				index++;
			}
			else {
				cores.erase(cores.end()-1);
				loop = false;
			}
		} while (loop);

		index = 0;

		do {
			path = basePath + "Section-" + std::to_string(index);
			path += ".png";
			//string result = index.c_str();

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
			//string result = index.c_str();

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

	std::weak_ptr<Image> AssetManager::getCore(unsigned int index)
	{
		if (index < cores.size())
			return cores[index];
		else
			return std::shared_ptr<Image>();
	}

	std::weak_ptr<Image> AssetManager::getSection(unsigned int index)
	{
		if (index < sections.size())
			return sections[index];
		else
			return std::shared_ptr<Image>();
	}

	std::weak_ptr<Image> AssetManager::getModule(unsigned int index)
	{
		if (index < modules.size())
			return modules[index];
		else
			return std::shared_ptr<Image>();
	}


}