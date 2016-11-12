#include <Debug.hpp>

Debug::Debug(void) {}
Debug::~Debug(void) {}

void Debug::Logger(int level, std::string const message) {
	Debug::debugLevel[level].outStream << "\033[" << Debug::debugLevel[level].colorCode << "m[" << Debug::debugLevel[level].prefix << "]: " << message << "\033[0m" << std::endl;
}
void Debug::Log(std::string const message) {
	Debug::Logger(DLV_LOG, message);
}

void Debug::Info(std::string const message) {
	Debug::Logger(DLV_INFO, message);
}

void Debug::Warning(std::string const message) {
	Debug::Logger(DLV_WARNING, message);
}

void Debug::Error(std::string const message) {
	Debug::Logger(DLV_ERROR, message);
}

tDebugLevel Debug::debugLevel[4] = {
	{"log", 37, std::cout},
	{"info", 34, std::cout},
	{"warning", 33, std::cout},
	{"error", 31, std::cout}
};
