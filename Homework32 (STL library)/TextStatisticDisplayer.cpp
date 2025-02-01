#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

#include "TextStatisticService.h"
#include "TextStatisticDisplayer.h"

void TextStatisticDisplayer::display(const TextStatisticService& service)
{
	for (const auto& [key, value] : service.getStatistic())
		std::cout << key << " appearence: " << value << '\n';
}
