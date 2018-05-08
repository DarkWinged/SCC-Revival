#include <Ship.h>
#include <MathLib.h> // Thinking about it more... not sure why i put thi- oh right, derp

//Game game;
Ship::Ship(SDL_Renderer *rendererArg) {
	//TODO: Ship Initialization code here (make sure to initialize every single value!).
	Shell = 750;
	ShellRegen = 5;
	MaxShell = 750;

	Core = 250;
	CoreRegen = 0;
	MaxCore = 250;

	Energy = 500;
	EnergyRegen = 5;
	MaxEnergy = 500;

	xPos = 30;
	yPos = 30;
	
	xTarPos = 0;
	yTarPos = 0;

	xVel = 0;
	yVel = 0;

	Speed = 5;
	Acceleration = .1;
	Manuverability = .5;

	Rotation = 0;
	TargetRotation = 0;

	Parts = std::vector<std::shared_ptr<ShipPart>>();

	renderer = rendererArg;
}

Ship::~Ship() {
	Parts.~vector();
}

void Ship::Update() {
	// Update Rotation
	if (TargetRotation != Rotation && (xTarPos != 0 || yTarPos != 0)) {
		// Acceleration is Rotation Speed

		int shortest_angle = ((((TargetRotation - Rotation) % 360) + 540) % 360) - 180;
		if (SDL_abs(shortest_angle) < Acceleration * 10)
		{
			Rotation = TargetRotation;
		}

		if(shortest_angle > 0 && Rotation != TargetRotation)
		{
			Rotation += Manuverability * 10;
		}
		if (shortest_angle < 0 && Rotation != TargetRotation)
		{
			Rotation -= Manuverability * 10;
		}
	}
	//3.141592653589793238463 is PI
	if (xTarPos != 0 || yTarPos != 0)
	{
		int rotPos = SDL_floor(SDL_atan2(yTarPos, xTarPos) * (180.0 / MathLib::PI()));
		SetTargetRotation(MathLib::grid(rotPos + 90, 5));
	}

	xPos += xVel;
	yPos += yVel;
}

void Ship::Render() {
	for (int index = 0, size = Parts.size(); index < size; ++index) {
		// Iterate through every part in the part list and draw them.
		std::weak_ptr<ShipPart> part = Parts[index];

		SDL_Rect *rect = new SDL_Rect();

		//SDL_floor(MathLib::grid(Rotation, 5))
		double radRot = Rotation * MathLib::PI() / 180; // i do not know how to name these variables... so heh :P

		rect->x = int((part.lock()->xPos * SDL_cos(radRot)) - (part.lock()->yPos * SDL_sin(radRot)) + xPos - (part.lock()->partImage.lock()->xSize/2));
		rect->y = int((part.lock()->xPos * SDL_sin(radRot)) + (part.lock()->yPos * SDL_cos(radRot)) + yPos - (part.lock()->partImage.lock()->ySize/2));

		rect->h = part.lock()->partImage.lock()->ySize;
		rect->w = part.lock()->partImage.lock()->xSize;
		
		SDL_RenderCopyEx(renderer, part.lock()->partImage.lock()->image,
			NULL, rect,
			MathLib::grid(Rotation + part.lock()->Rotation, 5), NULL,
			(part.lock()->HorizontallyFlipped == true? SDL_RendererFlip::SDL_FLIP_HORIZONTAL : SDL_RendererFlip::SDL_FLIP_NONE));
	}
}

void Ship::SetTargetRotation(int rot) {
	TargetRotation = rot - MathLib::grid(rot, 360);
}

bool Ship::addSection(int x, int y, int rot, bool horizontalflip, SCC_R::AssetManager* assets, unsigned int index, SCC_R::AssetManager::assetType type)
{
	Parts.push_back(std::shared_ptr<ShipPart>(new ShipPart(x, y, rot, horizontalflip)));
	//checks if section was sucessfully created
	if (Parts[Parts.size() - 1]->initialize(assets, index, type))
		return true;
	else
	{
		Parts.erase(Parts.end() - 1);
		return false;
	}
}
