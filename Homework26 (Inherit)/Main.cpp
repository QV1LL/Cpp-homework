#include <iostream>

#include "Animal.h"
#include "Dog.h"
#include "Parrot.h"
#include "Cat.h"

#include "ByteString.h"
#include "String.h"

int main() {
	auto parrot = Parrot("Carl", 10.2);
	auto cat = Cat("Starii Bog", 255.5);
	auto dog = Dog("I have no enemys)))", 0);

	ByteString byteString1 = ByteString("00001111");
	ByteString byteString2 = ByteString("00000001");

	std::cout << byteString1 + byteString2;

	return 0;
}