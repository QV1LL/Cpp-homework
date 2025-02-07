#include <iostream>

int main()
{
	// result = z (7y-x) / (3-6x) - 1

	int result;

	int x;
	std::cin >> x;

	int y;
	std::cin >> y;
	
	int z;
	std::cin >> z;

	_asm
	{
		// z (7y - x)
		mov eax, 7
		imul y
		sub eax, x
		imul z
		xchg eax, ebx

		// 3 - 6x
		mov eax, -6
		imul x
		add eax, 3
		xchg eax, ebx

		// z(7y - x) / (3 - 6x) - 1
		cdq
		idiv ebx
		sub eax, 1

		mov result, eax
	}

	std::cout << result;

	return 0;
}