#pragma once
#include<list>

template<typename T>
class BaseRepository
{
public:

	virtual std::list<T> getAll() = 0;
	virtual T getById(int id) = 0;
	virtual T save(T data) = 0;
	virtual bool deleteById(int id) = 0;
};


