#ifndef SPUINFO_HPP
#define SPUINFO_HPP

#include	"AMonitorModule.hpp"
#include	<thread>

class CPUInfo : public AMonitorModule {
public:
	CPUInfo();
	~CPUInfo();
	CPUInfo(CPUInfo &);
	std::string	CPUGetLoad();
	CPUInfo &operator=(CPUInfo & src);
	std::string checkValue();
	std::string getCPULoadValue();
	void setCPULoadValue(std::string CPULoadValue);
	unsigned int getConcurentThreadsSupported();
	void setConcurentThreadsSupported(unsigned int concurentThreadsSupported);
protected:
	unsigned concurentThreadsSupported;
	std::string CPULoadValue;

};



#endif


