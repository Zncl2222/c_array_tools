mkdir build
cd build
cmake -G "MinGW Makefiles" .
make
%~dp0build/bin/example.out
