# binpp
Lightweight library for reading and writing binary files.
# Install
Just add files from `\binpp\src` to you project and include them.
# BinaryReader class
This class allows you to read binary data from file to any struct or variable.
## void Open(string filename)
Read all binary data from `filename`.

Usage:
```cpp
BinaryReader reader;
reader.Open("somefile.bin");
```

## void Read(offset, outVar)
Write binary data to variable by pointer with `offset`.

Usage:
```cpp
long long int someLong;
reader.Read(0, &someLong);
```

## void Read(offset, outArray[], count);
Write binary data to array with `offset`.

Usage:
```cpp
short int arr[64];
reader.Read(0, arr, 64);
```

## bool IsOpen()
Returns `true` if the file is opened and data is successfully readed.

Usage:
```cpp
BinaryReader reader("somefile.bin");
if (reader.IsOpen())
{
  // Work with binary data
  int someInt;
  reader.Read(0, someInt);
}
{
  // Handle error
  throw "Can't read file";
}
```

# BinaryReader class
This class allows you to write variables to file as binary data.

## void Append(data)
Append variable `data` to be written to file.

Usage:
```cpp
int someInt = 1337;
writer.Append(someInt);
```

##void Append(data[], size)
Append array `data[]` with given `size` to be written to file.

Usage:
```cpp
int someArray[4] = { 228, 1337, 322, 123 };
writer.Append(someArray, 4);
```

## void Clear()
Clear write buffer.

Usage:
```cpp
writer.Clear();
```

## void Save(filename)
Save file to given `filename`.

Usage:
```cpp
writer.Save("somefile.bin");
```

## size_t Size()
Returns amount of bytes in buffer.

Usage:
```cpp
size_t bufferSize = writer.Size();
```

## size_t Capacity()
Returns buffer capacity.

Usage:
```cpp
size_t bufferCapacity = wtiter.Capacity();
```
