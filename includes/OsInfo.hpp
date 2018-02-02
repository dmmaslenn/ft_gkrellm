#ifndef OSINFO_HPP
#define OSINFO_HPP

#include "AMonitorModule.hpp"
#include <cassert>

class OsInfo  : public AMonitorModule{
public:
	OsInfo();
	~OsInfo();
	OsInfo(OsInfo &);
	OsInfo &operator=(OsInfo & src);
	std::string checkValue();
};


#endif
