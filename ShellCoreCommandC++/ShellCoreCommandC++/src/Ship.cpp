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

	Parts = std::vector<ShipPart>();

	renderer = rendererArg;

	ShipPart *Part3 = new ShipPart(-17, 2, 0, false, new SCC_R::Image("assets/images/Section-9.png", renderer));
	Parts.push_back(*Part3); // Add the part to the part list.

	ShipPart *Part2 = new ShipPart(17, 2, 0, true, new SCC_R::Image("assets/images/Section-9.png", renderer));
	Parts.push_back(*Part2); // Add the part to the part list.

	ShipPart *Part1 = new ShipPart(0, -17, 0, true, new SCC_R::Image("assets/images/Section-4.png", renderer));
	Parts.push_back(*Part1); // Add the part to the part list.

	ShipPart *CorePart = new ShipPart(0, 0, 0, false, new SCC_R::Image("assets/images/Core-1.png", renderer));
	Parts.push_back(*CorePart); // Add the part to the part list.
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
		ShipPart part = Parts[index];

		SDL_Rect *rect = new SDL_Rect();

		//SDL_floor(MathLib::grid(Rotation, 5))
		double radRot = Rotation * MathLib::PI() / 180; // i do not know how to name these variables... so heh :P

		rect->x = int((part.xPos * SDL_cos(radRot)) - (part.yPos * SDL_sin(radRot)) + xPos - (part.partImage->xSize/2));
		rect->y = int((part.xPos * SDL_sin(radRot)) + (part.yPos * SDL_cos(radRot)) + yPos - (part.partImage->ySize/2));

		rect->h = part.partImage->ySize;
		rect->w = part.partImage->xSize;
		
		SDL_RenderCopyEx(renderer, part.partImage->image,
			NULL, rect,
			MathLib::grid(Rotation + part.Rotation, 5), NULL,
			(part.HorizontallyFlipped == true? SDL_RendererFlip::SDL_FLIP_HORIZONTAL : SDL_RendererFlip::SDL_FLIP_NONE));
	}
}

void Ship::SetTargetRotation(int rot) {
	TargetRotation = rot - MathLib::grid(rot, 360);
}
