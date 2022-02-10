#include "DoubleLL.hpp"

int	main() {
	DoubleLL<int>	dll;
	std::cout << dll;
	dll.insertFront(20);
	dll.insertFront(10);
	dll.insertFront(15);
	std::cout << dll;
}