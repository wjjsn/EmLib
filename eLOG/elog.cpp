#include "elog.hpp"
extern "C" unsigned SEGGER_RTT_Write(unsigned BufferIndex, const void *pBuffer, unsigned NumBytes);
void write(const char *data, size_t len)
{

	SEGGER_RTT_Write(0, reinterpret_cast<const void *>(data), len);
}
char log_buffer[LOG_BUFFER_SZIE];
