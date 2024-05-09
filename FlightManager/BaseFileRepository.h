#pragma once
#include"BaseRepository.h"
#include<string>


template<typename T>
class BaseFileRepository : BaseRepository<T>
{
protected:
	std::string _filePath;
};

