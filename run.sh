export DYLD_LIBRARY_PATH=$PWD/Objectivity/11.1/lib

cd ./Objectivity/11.1/samples/cxx/helloWorld

# you also need to put this in ooddlx at the beginning otherwise stdarg.h will not be found /usr/llvm-gcc-4.2/lib/gcc/i686-apple-darwin11/4.2.1/include
make

./helloWorld
