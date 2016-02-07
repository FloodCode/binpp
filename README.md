# binpp
Lightweight library for reading and writing binary files.
# Install
Just add files from `\binpp\src` to you project and include them.
# BinaryReader class
This class allows you to read binary data from file to any struct or variable.
## void Open(string filename)
Reads all binary data from `filename`.

Usage:
```cpp
BinaryReader reader;
reader.Open("somefile.bin");
```

## void Read(size_t offset, T *outVar)
Writes binary data with `offset` to `*outVar` variable.

Usage:
```cpp
BinaryReader reader("somefile.bin");
long long int someLong;
reader.Read(0, &someLong);
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
