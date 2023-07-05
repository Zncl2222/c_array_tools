mkdir build
cd build
cmake -G "MinGW Makefiles" ..
make
make test
.\test\unittest_double.exe
.\test\unittest_float.exe
.\test\unittest_int.exe
.\test\unittest_long.exe
.\test\unittest_mt.exe
.\test\unittest_short.exe
cd ..
@REM make memcheck // this is not avaliable in windows
