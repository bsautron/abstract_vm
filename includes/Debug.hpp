#include <iostream>

enum e_debugLevel {
	DLV_LOG,
	DLV_INFO,
	DLV_WARNING,
	DLV_ERROR
};

typedef struct	s_debug_level {
	std::string		prefix;
	int				colorCode;
	std::ostream &	outStream;
}				t_debug_level;

class Debug {
public:
	Debug(void);
	~Debug(void);

	static void Log(std::string const message);
	static void Info(std::string const message);
	static void Warning(std::string const message);
	static void Error(std::string const message);
	static void Logger(int level, std::string const message);


	static t_debug_level debugLevel[4];
};
