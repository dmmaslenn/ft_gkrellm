#include "NetworkInfo.hpp"

NetworkInfo::NetworkInfo() {
	setModuleName("Network info");
	setModuleValue(checkValue());
}

NetworkInfo::~NetworkInfo() {

}

NetworkInfo::NetworkInfo(NetworkInfo &) {

}

NetworkInfo &NetworkInfo::operator=(NetworkInfo &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string NetworkInfo::checkValue() {
	FILE *fp;
	int status;
	char path[BUFFSIZE];

	fp = popen("top -l 1 | grep -E \"^Networks\"", "r");
	if (fp == NULL)
		throw std::exception();
	while (fgets(path, BUFFSIZE, fp) != NULL)
		;
	status = pclose(fp);
	if (status == -1)
		throw std::exception();
	return path;
}
