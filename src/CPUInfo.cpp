#include "CPUInfo.hpp"

CPUInfo::CPUInfo() {
	setModuleName("CPU Info");
	setModuleValue(checkValue());
	setCPULoadValue(CPUGetLoad());
	this->concurentThreadsSupported =  std::thread::hardware_concurrency();
}

CPUInfo::~CPUInfo() {
}

CPUInfo::CPUInfo(CPUInfo &) {

}

CPUInfo &CPUInfo::operator=(CPUInfo &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string CPUInfo::checkValue() {
	char ret[BUFFSIZE];
	size_t bufferlen = BUFFSIZE;
	sysctlbyname("machdep.cpu.brand_string",&ret,&bufferlen,NULL,0);
	return ret;
}

std::string CPUInfo::CPUGetLoad() {
	FILE *fp;
	int status;
	char path[BUFFSIZE];

	fp = popen("top -l 1 | grep -E \"^CPU\"", "r");
	if (fp == NULL)
		throw std::exception();
	while (fgets(path, BUFFSIZE, fp) != NULL)
		;
	status = pclose(fp);
	if (status == -1)
		throw std::exception();
	return path;
}

std::string CPUInfo::getCPULoadValue(){
	return CPULoadValue;
}

void CPUInfo::setCPULoadValue(std::string CPULoadValue) {
	CPUInfo::CPULoadValue = CPULoadValue;
}

unsigned int CPUInfo::getConcurentThreadsSupported(){
	return concurentThreadsSupported;
}

void CPUInfo::setConcurentThreadsSupported(unsigned int concurentThreadsSupported) {
	CPUInfo::concurentThreadsSupported = concurentThreadsSupported;
}