#include <iostream>

#pragma once

static const std::string GEAR_BOX_TYPE_NAMES[] = {
	"automatic",
	"continuously variable",
	"manual",
	"dual clutch",
};

struct Color {
	float r;
	float g;
	float b;

	float transparent = 1;
};

enum class GearBoxType {
	AUTOMATIC,
	CONTINUOUSLY_VARIABLE,
	MANUAL,
	DUAL_CLUTCH,
};

struct Car {
public:
	double length;
	double suspensionHeigth;
	double wheelSize;

	double engineVolume;
	double enginePower;
	GearBoxType gearBoxType;

	Color bodyColor;
};