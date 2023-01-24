mkdir build
cd build
cmake -G "MinGW Makefiles" .
make
make test
@REM make memcheck // this is not avaliable in windows
