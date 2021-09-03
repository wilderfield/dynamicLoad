# dynamicLoad

This repo demonstrates how to use a C++ plugin library  
  
With GNU GCC Linux support, and MSVC Microsoft support  
  
The test executable will import a creator function from the Spell plugin library.  
  
Because the test executable understands the interface "Phrase" it will be able to call it.

# Build & Run Linux
```
mkdir build
cd build
cmake ..
cmake --build .
./test
```

# Build & Run Windows
```
mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" ..
cmake --build .
test.exe
```
