#include "OsInfo.hpp"

OsInfo::OsInfo() {
	setModuleName("OS Info");
	setModuleValue(checkValue());
}

OsInfo::~OsInfo() {

}

OsInfo::OsInfo(OsInfo &) {

}

OsInfo &OsInfo::operator=(OsInfo &src) {
	setModuleName(src.getModuleName());
	setModuleValue(src.getModuleValue());
	return *this;
}

std::string OsInfo::checkValue() {
	char buf[1024];
	unsigned buflen = 0;
	char line[256];
	FILE *sw_vers = popen("sw_vers", "r");
	while (fgets(line, sizeof(line), sw_vers) != NULL) {
		int l = snprintf(buf + buflen, sizeof(buf) - buflen, "\t%s", line);
		buflen += l;
		assert(buflen < sizeof(buf));
	}
	pclose(sw_vers);
	return buf;
}