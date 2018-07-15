#pragma once
#include <string>
#include <stdarg.h>

typedef std::string String;

namespace PurpleLine {

#define STRINGFORMAT_BUFFER_SIZE 10 * 1024

	class StringFormat {
	private:
		static char* buffer;
	public:

		template<typename T>
		static String Hex(const T& t)
		{
			memset(buffer, 0, STRINGFORMAT_BUFFER_SIZE);
			sprintf(buffer, "%02x", t);
			return String(buffer);
		}	
	};

	inline const char* operator+(String a, const char* b)
	{
		String s(a);
		s.append(b);
		return s.c_str();
	}	
}