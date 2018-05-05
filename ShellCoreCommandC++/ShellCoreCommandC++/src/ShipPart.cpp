#include <ShipPart.h>

ShipPart::ShipPart(int x, int y, int rot, bool horizontalflip, SCC_R::Image * img)
{
	xPos = x;
	yPos = y;
	
	Rotation = rot;
	HorizontallyFlipped = horizontalflip;

	partImage = img;
}

ShipPart::~ShipPart()
{

}