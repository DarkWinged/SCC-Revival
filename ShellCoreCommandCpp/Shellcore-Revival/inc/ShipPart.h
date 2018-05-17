#pragma once

#include <Image.h>
#include <memory>
#include <AssetManager.h>

class ShipPart {

public:
	ShipPart(int x, int y, int rot, bool horizontalflip);
	~ShipPart();
	//attempts to find and store a weak_ptr to the asset specified 
	bool ShipPart::initialize(SCC_R::AssetManager* assets, unsigned int index, SCC_R::AssetManager::assetType type);

	int xPos;
	int yPos;

	int Rotation;
	bool HorizontallyFlipped;

	std::weak_ptr<SCC_R::Image> partImage;
};