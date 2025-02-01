#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "TextStatisticService.h"
#include "TextStatisticDisplayer.h"

int main()
{
	std::string text = "Lorem ipsum ipsum ipsum dolor sit amet, consectetur consectetur adipiscing elit elit. Lorem lorem lorem ipsum dolor dolor dolor sit sit sit amet amet amet. Sed sed sed do do do eiusmod eiusmod tempor tempor tempor incididunt incididunt incididunt ut ut ut labore labore labore et et et dolore dolore dolore magna magna magna aliqua aliqua aliqua. Ut enim enim enim ad ad ad minim minim minim veniam veniam veniam, quis quis quis nostrud nostrud nostrud exercitation exercitation exercitation ullamco ullamco ullamco laboris laboris laboris nisi nisi nisi ut ut ut aliquip aliquip aliquip ex ex ex ea ea ea commodo commodo commodo consequat consequat consequat.";

	TextStatisticService service;

	service.setTextStatisticFromFile("Data/savingStat.sav");
	std::cout << "Most appeared word: " << service.getMostAppearedWord() << '\n';
	TextStatisticDisplayer::display(service);
	service.saveStatisticToFile("Data/savingStatStat.sav");

	return 0;
}