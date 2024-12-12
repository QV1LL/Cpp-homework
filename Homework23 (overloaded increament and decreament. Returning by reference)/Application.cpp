#include <iostream>

#include "Application.h"
#include "Circle.h"
#include "Airplane.h"
#include "Overcoat.h"
#include "Flat.h"

void Application::start() {
	this->testCircles();
	this->testAirplanes();
	this->testOvercoats();
	this->testFlats();
}

void Application::testCircles() {
	Circle circle1{ 22.4 };
	Circle circle2{ 50.6 };

	if (circle1 < circle2)
		circle1 += (50.6 - 22.4);

	if (circle1 == circle2)
		std::cout << "Circles are equal now!" << '\n';
}

void Application::testAirplanes() {
	Airplane airplane1 { AirplaneType::PASSANGER, 500 };
	Airplane airplane2 { AirplaneType::CARGO, 498 };

	if (airplane1 > airplane2)
		std::cout << "Airplane 1 has more passangers than airplane 2" << '\n';

	airplane2++;
	airplane2++;

	std::cout << "Airplanes types are equal: " << (airplane1 == airplane2) << '\n';
}

void Application::testOvercoats() {
	Overcoat coat{ OvercoatType::COAT, 1200 };
	Overcoat jacket{ OvercoatType::JACKET, 4100 };

	std::cout << "Equals of overcoats: " << (coat == jacket) << '\n';
	std::cout << "Coat costs lower than jacket: " << (coat < jacket) << '\n';

	coat = jacket;

	std::cout << "Equals of overcoats: " << (coat == jacket) << '\n';
}

void Application::testFlats() {
	Flat flatInUshhorod{ 120, 120000 };
	Flat flatInKiev{ 24, 11000000 };

	std::cout << "Flats square is equal: " << (flatInKiev == flatInUshhorod) << '\n';
	std::cout << "Flat in Kiev costs more than in Ushhorod: " << (flatInKiev > flatInUshhorod) << '\n';

	flatInUshhorod = flatInKiev;

	std::cout << "Flats square is equal: " << (flatInKiev == flatInUshhorod) << '\n';
}
