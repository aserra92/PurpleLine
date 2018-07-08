#pragma once
#include "../CommonTypes.h"

#define LOG_LEVEL_FATAL 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_INFO 3

namespace PurpleLine{namespace Internal{

	void PlatformLogMessage(unsigned int level, const char* message);

	static char toStringBuffer[1024 * 10];
	static char sprintfBuffer[1024 * 10];

	template <class T>
	struct HasIterator
	{
		template<class U> static char(&test(typename U::iterator const*))[1];
		template<class U> static char(&test(...))[2];
		static const bool value = (sizeof(test<T>(0)) == 1);
	};

	template <typename T>
	static String ToString(const T& t)
	{
		return ToStringInternal<T>(t, std::integral_constant<bool, HasIterator<T>::value>());
	}

	template <>
	static String ToString<char>(const char& t)
	{
		return &t;
	}

	template <>
	static String ToString<char*>(char* const& t)
	{
		return t;
	}

	template <>
	static String ToString<unsigned char const*>(unsigned char const* const& t)
	{
		return (const char*)t;
	}

	template <>
	static String ToString<unsigned int>(const unsigned int& i)
	{
		return std::to_string(i);
	}

	template <>
	static String ToString<wchar_t*>(wchar_t* const& t)
	{
		size_t i;
		wcstombs_s(&i, sprintfBuffer, t, 1024 * 10);
		return sprintfBuffer;
	}

	template<>
	static String ToString<const wchar_t*>(const wchar_t* const& t)
	{
		size_t i;
		wcstombs_s(&i, sprintfBuffer, t, 1024 * 10);
		return sprintfBuffer;
	}

	template <>
	static String ToString<const char*>(const char* const& t)
	{
		return t;
	}

	template <>
	static String ToString<String>(const String& t)
	{
		return t.c_str();
	}

	template <>
	static String ToString<bool>(const bool& t)
	{
		return t ? "true" : "false";
	}

	template <typename X, typename Y>
	static String ToString(const std::pair<typename X, typename Y>& pair)
	{
		sprintf(toStringBuffer, "(Key: %s, Value: %s)", ToString(pair.first), ToString(pair.second));
		return toStringBuffer;
	}

	template<typename T>
	static String FormatIterators(T& begin, T& end)
	{
		String result;
		bool first = true;
		while (begin != end)
		{
			if (!first)
			{
				resut += ", ";
			}
			result += ToStringInternal(*begin);
			first = false;
			begin++;
		}
		return result;
	}

	template<typename T>
	static String ToStringInternal(const T& t, const std::true_type& ignored)
	{
		sprintf(toStringBuffer, "Container of size: %d, contents: %s", t.size(), FormatIterators(v.begin(), v.end()).c_str());
		return toStringBuffer;
	}

	template<typename T>
	static String ToStringInternal(const T& t, const std::false_type& ignored)
	{
		String x = ToString(t);
		strcpy_s(toStringBuffer, x.c_str());
		return toStringBuffer;
	}

	template <>
	static String ToStringInternal<const char*>(const char* const& t, const std::false_type& ignored)
	{
		return t;
	}

	template <typename FirstType>
	static void PrintLog(char* buffer, int32_t& position, FirstType&& firstType)
	{
		String formatFirst = ToString<FirstType>(firstType);
		int32_t lengthFormatFirst = strlen(formatFirst.c_str());
		memcpy(&buffer[position], formatFirst.c_str(), lengthFormatFirst);
		position += lengthFormatFirst;
	}

	template <typename FirstType, typename... Args>
	static void PrintLog(char* buffer, int32_t& position, FirstType&& firstType, Args&&... args)
	{
		PrintLog(buffer, position, firstType);
		if (sizeof...(Args))
		{
			PrintLog(buffer, position, std::forward<Args>(args)...);
		}
	}

	template <typename... Args>
	static void LogMessage(int32_t level, bool newLine, Args... args)
	{
		char buffer[1024 * 10];
		int32_t position = 0;
		PrintLog(buffer, position, std::forward<Args>(args)...);
		if (newLine)
		{
			buffer[position++] = '\n';
		}
		buffer[position] = 0;
		PlatformLogMessage(level, buffer);
	}

#define LOG_FATAL(...) Internal::LogMessage(LOG_LEVEL_FATAL, true, "PurpleLine:    ", __VA_ARGS__)
#define LOG_ERROR(...) Internal::LogMessage(LOG_LEVEL_ERROR, true, "PurpleLine:    ", __VA_ARGS__)
#define LOG_WARNING(...) Internal::LogMessage(LOG_LEVEL_WARN, true, "PurpleLine:    ", __VA_ARGS__)
#define LOG_INFO(...) Internal::LogMessage(LOG_LEVEL_INFO, true, "PurpleLine:    ", __VA_ARGS__)

} }