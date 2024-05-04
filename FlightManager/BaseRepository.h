#pragma once
#include<list>
#include<string>

template<typename T>
class BaseRepository
{
protected:
	std::string _filePath;

public:
	BaseRepository(std::string filePath);

	virtual std::list<T> getAll() = 0;
	virtual T getById(int id) = 0;
	virtual bool save(T data) = 0;
	virtual bool deleteById(int id) = 0;
};


