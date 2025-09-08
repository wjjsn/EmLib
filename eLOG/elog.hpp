#pragma once
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstring>

enum class LogLevel
{
	TRACE,
	DBG,
	INFO,
	WARN,
	ERROR,
	CRITICAL,
	DISBALE
};

template <void (*write)(const char *, size_t), LogLevel level, char *buffer, size_t length>
class LOG_
{
	struct color
	{
		static constexpr const char RESET[] = "\x1B[0m"; // Reset to default colors
		static constexpr const char CLEAR[] = "\x1B[2J"; // Clear screen, reposition cursor to top left

		static constexpr const char TEXT_BLACK[]   = "\x1B[2;30m";
		static constexpr const char TEXT_RED[]	   = "\x1B[2;31m";
		static constexpr const char TEXT_GREEN[]   = "\x1B[2;32m";
		static constexpr const char TEXT_YELLOW[]  = "\x1B[2;33m";
		static constexpr const char TEXT_BLUE[]	   = "\x1B[2;34m";
		static constexpr const char TEXT_MAGENTA[] = "\x1B[2;35m";
		static constexpr const char TEXT_CYAN[]	   = "\x1B[2;36m";
		static constexpr const char TEXT_WHITE[]   = "\x1B[2;37m";

		static constexpr const char TEXT_BRIGHT_BLACK[]	  = "\x1B[1;30m";
		static constexpr const char TEXT_BRIGHT_RED[]	  = "\x1B[1;31m";
		static constexpr const char TEXT_BRIGHT_GREEN[]	  = "\x1B[1;32m";
		static constexpr const char TEXT_BRIGHT_YELLOW[]  = "\x1B[1;33m";
		static constexpr const char TEXT_BRIGHT_BLUE[]	  = "\x1B[1;34m";
		static constexpr const char TEXT_BRIGHT_MAGENTA[] = "\x1B[1;35m";
		static constexpr const char TEXT_BRIGHT_CYAN[]	  = "\x1B[1;36m";
		static constexpr const char TEXT_BRIGHT_WHITE[]	  = "\x1B[1;37m";

		static constexpr const char BG_BLACK[]	 = "\x1B[24;40m";
		static constexpr const char BG_RED[]	 = "\x1B[24;41m";
		static constexpr const char BG_GREEN[]	 = "\x1B[24;42m";
		static constexpr const char BG_YELLOW[]	 = "\x1B[24;43m";
		static constexpr const char BG_BLUE[]	 = "\x1B[24;44m";
		static constexpr const char BG_MAGENTA[] = "\x1B[24;45m";
		static constexpr const char BG_CYAN[]	 = "\x1B[24;46m";
		static constexpr const char BG_WHITE[]	 = "\x1B[24;47m";

		static constexpr const char BG_BRIGHT_BLACK[]	= "\x1B[4;40m";
		static constexpr const char BG_BRIGHT_RED[]		= "\x1B[4;41m";
		static constexpr const char BG_BRIGHT_GREEN[]	= "\x1B[4;42m";
		static constexpr const char BG_BRIGHT_YELLOW[]	= "\x1B[4;43m";
		static constexpr const char BG_BRIGHT_BLUE[]	= "\x1B[4;44m";
		static constexpr const char BG_BRIGHT_MAGENTA[] = "\x1B[4;45m";
		static constexpr const char BG_BRIGHT_CYAN[]	= "\x1B[4;46m";
		static constexpr const char BG_BRIGHT_WHITE[]	= "\x1B[4;47m";
	};

public:
	static inline void
	TRACE(const char *format, ...)
	{
		if constexpr (level > LogLevel::TRACE) {}
		else
		{
			va_list args;
			// 初始化 va_list，使其指向 format 后的第一个参数
			va_start(args, format);
			write(color::TEXT_BLACK, sizeof(color::TEXT_BLACK) - 1);
			write("[TRACE] ", sizeof("[TRACE] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
	static inline void DBG(const char *format, ...)
	{
		if constexpr (level > LogLevel::DBG) {}
		else
		{
			va_list args;
			va_start(args, format);
			write(color::TEXT_BLUE, sizeof(color::TEXT_BLUE) - 1);
			write("[DEBUG] ", sizeof("[DEBUG] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
	static inline void INFO(const char *format, ...)
	{
		if constexpr (level > LogLevel::INFO) {}
		else
		{
			va_list args;
			va_start(args, format);
			write(color::TEXT_GREEN, sizeof(color::TEXT_GREEN) - 1);
			write("[INFO] ", sizeof("[INFO] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
	static inline void WARN(const char *format, ...)
	{
		if constexpr (level > LogLevel::WARN) {}
		else
		{
			va_list args;
			va_start(args, format);
			write(color::TEXT_YELLOW, sizeof(color::TEXT_YELLOW) - 1);
			write("[WARN] ", sizeof("[WARN] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
	static inline void ERROR(const char *format, ...)
	{
		if constexpr (level > LogLevel::ERROR) {}
		else
		{
			va_list args;
			va_start(args, format);
			write(color::TEXT_RED, sizeof(color::TEXT_RED) - 1);
			write("[ERROR] ", sizeof("[ERROR] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
	static inline void CRITICAL(const char *format, ...)
	{
		if constexpr (level > LogLevel::CRITICAL) {}
		else
		{
			va_list args;
			va_start(args, format);
			write(color::BG_RED, sizeof(color::BG_RED) - 1);
			write(color::TEXT_WHITE, sizeof(color::TEXT_WHITE) - 1);
			write("[CRITICAL] ", sizeof("[CRITICAL] ") - 1);
			std::snprintf(buffer, length, format, args);
			va_end(args);
			write(buffer, std::strlen(buffer));
			write(color::RESET, sizeof(color::RESET) - 1);
		}
	}
};

constexpr size_t LOG_BUFFER_SZIE = 128;
void write(const char *data, size_t len);
extern char log_buffer[LOG_BUFFER_SZIE];

using LOG = LOG_<write, LogLevel::INFO, log_buffer, sizeof(log_buffer)>;