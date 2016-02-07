#include "binaryreader.hpp"

binpp::BinaryReader::BinaryReader()
{
	this->init();
}

binpp::BinaryReader::BinaryReader(std::string filename)
{
	this->init();
	this->Open(filename);
}


binpp::BinaryReader::~BinaryReader()
{
	if (data != 0)
	{
		delete[] this->data;
	}
}

void binpp::BinaryReader::Open(std::string filename)
{
	if (this->data != 0)
	{
		delete[] this->data;
		this->init();
	}

	std::ifstream input(filename, std::ios::binary);
	if (!input.is_open())
	{
		return;
	}

	std::streampos begin = input.tellg();
	input.seekg(0, std::ios::end);
	std::streampos end = input.tellg();
	input.seekg(0, std::ios::beg);

	this->sz = end - begin;
	data = new byte[this->sz];
	input.read((char*)this->data, this->sz);
}

bool binpp::BinaryReader::IsOpen()
{
	return this->data != 0;
}

void binpp::BinaryReader::init()
{
	this->data = 0;
	this->sz = 0;
}