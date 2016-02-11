#ifndef BINPP_BINARYREADER
#define BINPP_BINARYREADER
#include "binpptypes.hpp"
#include <string>
#include <fstream>

namespace binpp
{
	class BinaryReader
	{
	public:
		BinaryReader();
		BinaryReader(std::string filename);
		~BinaryReader();
		void Open(std::string filename);
		bool IsOpen();

		template<typename T>
		void Read(size_t offset, T *outVar)
		{
			*outVar = 0;
			*outVar |= this->data[offset];
			for (size_t i = offset + 1; i < offset + sizeof(T); ++i)
			{
				*outVar <<= 8;
				*outVar |= this->data[i];
			}
		}

		template<typename T>
		void Read(size_t offset, T *outArray, size_t count)
		{
			size_t typeSize = sizeof(T);
			this->Read(offset, &outArray[0]);
			for (size_t i = 1; i < count; ++i)
			{
				this->Read(offset + (i * typeSize), &outArray[i]);
			}
		}

	private:
		byte *data;
		size_t sz;
		void init();
	};
}

#endif // BINPP_BINARYREADER