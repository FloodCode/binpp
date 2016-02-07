#include "binaryreader.hpp"
#include "binarywriter.hpp"
#include <iostream>

using namespace std;
using namespace binpp;

int main()
{
	binpp::BinaryWriter writer;
	// Creating sample int array to write in file
	int data[4] = { 228, 1337, 322, 123 };
	
	// Appending int array to BinaryWriter
	writer.Append(data, 4);

	// Saving BinaryWriter data to "foo.bin" file
	writer.Save("foo.bin");

	// Reading all bytes in BinaryReader class from "foo.bin" file
	binpp::BinaryReader reader("foo.bin");
	int result[4];

	// Reading data in int array
	reader.Read(0, result, 4);

	// Array output
	for (int i = 0; i < 4; i++)
	{
		cout << "result[" << i << "]: " << result[i] << endl;
	}

	// Output:
	// 
	// result[0]: 228
	// result[1] : 1337
	// result[2] : 322
	// result[3] : 123
	// 

	return 0;
}
