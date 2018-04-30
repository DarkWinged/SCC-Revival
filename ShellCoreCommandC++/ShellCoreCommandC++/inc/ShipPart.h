#pragma once

#include <Image.h>

class ShipPart {

public:
	ShipPart(int x, int y, int rot, bool horizontalflip, Image *img);
	~ShipPart();

	int xPos;
	int yPos;

	int Rotation;
	bool HorizontallyFlipped;

	Image *partImage;
};