#ifndef AMONITORMODUL_HPP
#define AMONITORMODUL_HPP

#include "IMonitorModul.hpp"
#include <sys/sysctl.h>
#include <unistd.h>
#include <iostream>

class AMonitorModule : public IMonitorModule {
public:
	std::string getModuleName();
	void setModuleName(const std::string &moduleName);
	std::string getModuleValue();
	void setModuleValue(const std::string &moduleValue);
private:
	virtual std::string checkValue() = 0;
	std::string moduleName;
	std::string moduleValue;
};


#endif
