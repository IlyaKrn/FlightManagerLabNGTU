#include "BaseRepository.h"

template<typename T>
BaseRepository<T>::BaseRepository(std::string filePath)
{
	_filePath = filePath;
}