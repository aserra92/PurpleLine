#pragma once
#include "../CommonTypes.h"

namespace PurpleLine{ namespace FileUtils{

	String ReadFile(String filePath)
	{
		FILE* file;
		fopen_s(&file, filePath.c_str(), "rt");
		fseek(file, 0, SEEK_END);
		unsigned long length = ftell(file);
		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, length, file);
		fclose(file);
		String result(data);
		delete[] data;
		return result;
	}
} }