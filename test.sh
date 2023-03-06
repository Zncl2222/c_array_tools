mkdir build
cd build
cmake ..
make
make test
make memcheck coverage
