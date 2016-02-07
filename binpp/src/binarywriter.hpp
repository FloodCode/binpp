#ifndef BINPP_BINARYWRITER
#define BINPP_BINARYWRITER
#include "binpptypes.hpp"
#include <string>
#include <fstream>

namespace binpp
{
	class BinaryWriter
	{
	public:
		BinaryWriter();
		BinaryWriter(size_t cp);
		~BinaryWriter();
		void Append(byte data);
		void GetBytes(byte *out, size_t count);
		void Clear();
		void Clear(size_t capacity);
		bool Save(std::string filename);
		size_t Size();
		size_t Capacity();

		template<typename T>
		void Append(T data)
		{
			size_t typeSize = sizeof(T);
			if (typeSize <= BINPP_BYTE_SIZE)
			{
				Append(static_cast<byte>(data));
			}
			else
			{
				size_t parts = typeSize / BINPP_BYTE_SIZE;
				for (size_t part = parts; part > 1; --part)
				{
					Append(static_cast<byte>(data >> ((part * 8) - 1)));
				}
				Append(static_cast<byte>(data));
			}
		}

		template<typename T>
		void Append(T *data, size_t sz)
		{
			if (sizeof(T) <= BINPP_BYTE_SIZE)
			{
				for (size_t i = 0; i < sz; ++i)
				{
					Append(static_cast<byte>(data[i]));
				}
			}
			else
			{
				for (size_t i = 0; i < sz; ++i)
				{
					Append(data[i]);
				}
			}
		}

	private:
		static const size_t defaultCapacity = 128;
		byte *data;
		size_t cp;
		size_t sz;
		void increaseCapacity();
	};
}

#endif // BINPP_BINARYWRITER