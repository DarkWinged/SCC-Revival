#include <ShipPart.h>

ShipPart::ShipPart(int x, int y, int rot, bool horizontalflip)
{
	xPos = x;
	yPos = y;
	
	Rotation = rot;
	HorizontallyFlipped = horizontalflip;
}

bool ShipPart::initialize(SCC_R::AssetManager* assets, unsigned int index, SCC_R::AssetManager::assetType type) {

	std::weak_ptr<SCC_R::Image> tempImg(assets->get(index, type));

	//checks if asset exists
	if (tempImg.lock() == NULL)
	{
		printf("Unable to load asset! error: assetType %s%s%s does not exist!\n", std::to_string(type).c_str(), " at index ", std::to_string(index).c_str());
		return false;
	}
	else
	{
		partImage = tempImg;
		return true;
	}
}

ShipPart::~ShipPart()
{

}