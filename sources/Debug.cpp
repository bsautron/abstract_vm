#include <Debug.hpp>

Debug::Debug(void) {}
Debug::~Debug(void) {}

void Debug::Logger(int level, std::string const message) {
	Debug::debugLevel[level].outStream << "\033[" << Debug::debugLevel[level].colorCode << ";" << Debug::debugLevel[level].backCode << "m[" << Debug::debugLevel[level].prefix << "]: " << message << "\033[0m" << std::endl;
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

void Debug::Fatal(std::string const message) {
	Debug::Logger(DLV_FATAL, message);
}

tDebugLevel Debug::debugLevel[] = {
	{"log", 37, 5, std::cout},
	{"info", 34, 5, std::cout},
	{"warning", 33, 5, std::cout},
	{"error", 31, 5, std::cout},
	{"fatal", 31, 1, std::cout}
};
