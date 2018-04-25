#pragma once

#include <vector>
#include "ShipPart.h"

#include "Game.h"

class Ship {

public:
	Ship(SDL_Renderer *rendererArg);
	~Ship();

	void Update();
	void Render();
	void SetTargetRotation(int rot);

	// Shellcore's current shell, shell regeneration and maximum shell.
	int Shell;
	int ShellRegen;
	int MaxShell;

	// Shellcore's current core, core regeneration and maximum core.
	int Core;
	int CoreRegen;
	int MaxCore;

	// Shellcore's current energy, energy regeneration and maximum energy.
	int Energy;
	int EnergyRegen;
	int MaxEnergy;

	// Shellcore's current position.
	int xPos;
	int yPos;

	// Shellcore's destination position.
	int xTarPos;
	int yTarPos;

	// Shellcore's velocity.
	int xVel;
	int yVel;

	// Shellcore's speed and acceleration.
	int Speed;
	int Acceleration;

	// Shellcore's current rotation.
	int Rotation;

	// Shellcore's destinated rotation.
	int TargetRotation; 
	// DO NOT change TargetRotation directly (e.g. TargetRotation = 5), 
	// use SetTargetRotation(5) instead (where 5 is desired rotation).
	// Rotation range: 0-360

	SDL_Renderer *renderer;

	// Store list of the shellcore's current parts.
	std::vector<ShipPart> Parts;
};