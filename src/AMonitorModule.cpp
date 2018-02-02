#include "AMonitorModule.hpp"

std::string	AMonitorModule::getModuleName(){
	return this->moduleName;
}

void AMonitorModule::setModuleName(const std::string &value) {
	this->moduleName = value;
}

std::string AMonitorModule::getModuleValue() {
	return this->moduleValue;
}

void AMonitorModule::setModuleValue(const std::string &value) {
	this->moduleValue = value;
}
