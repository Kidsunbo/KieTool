rm -rf release &&
mkdir release &&
cd release &&
cmake -DCMAKE_BUILD_TYPE=Release .. &&
make &&
./Tool