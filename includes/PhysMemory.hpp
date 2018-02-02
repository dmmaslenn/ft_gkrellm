#ifndef PHYSMEMORY_HPP
#define PHYSMEMORY_HPP

#include "AMonitorModule.hpp"
#include <iomanip>
#include <sstream>


class PhysMemory : public AMonitorModule{
public:
	PhysMemory();
	~PhysMemory();
	PhysMemory(PhysMemory &);
	PhysMemory &operator=(PhysMemory & src);
	std::string checkValue();
};


#endif
