#include "PhysMemory.hpp"

PhysMemory::PhysMemory() {
	setModuleName("Physical Memory");
	setModuleValue(checkValue());
}

PhysMemory::~PhysMemory() {

}

PhysMemory::PhysMemory(PhysMemory &) {

}

PhysMemory &PhysMemory::operator=(PhysMemory &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string PhysMemory::checkValue() {
	FILE *fp;
	int status;
	char path[BUFFSIZE];

	fp = popen("top -l 1 | grep -E \"^PhysMem\"", "r");
	if (fp == NULL)
		throw std::exception();
	while (fgets(path, BUFFSIZE, fp) != NULL)
		;
	status = pclose(fp);
	if (status == -1)
		throw std::exception();
	return path;
}
