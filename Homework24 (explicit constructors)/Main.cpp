#include <iostream>

#include "Reservoir.h"
#include "ReservoirAccounting.h"
#include "DataLoader.h"
#include "DataSaver.h"

int main() 
{
	ReservoirAccounting reservoirAccounting;

	DataLoader* dataLoader = DataLoader::getInstance();
	dataLoader->loadData(reservoirAccounting, "reservoir savings.sav");

	Reservoir reservoir{
		"Black",
		Reservoir::ReservoirType::SEA,
		1200,
		1000,
		2240,
	};

	reservoirAccounting.append(reservoir);

	reservoir = Reservoir("Azovske");

	reservoirAccounting.append(reservoir);

	for (Reservoir reservoir : reservoirAccounting.getReservoirs())
		std::cout << reservoir.toString();

	DataSaver* dataSaver = DataSaver::getInstance();
	dataSaver->saveData(&reservoirAccounting, "reservoir savings.sav");

	return 0;
}