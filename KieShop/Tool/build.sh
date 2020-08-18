if [ ! -d "release" ]; then
mkdir release
fi
cd release &&
cmake -DCMAKE_BUILD_TYPE=Release .. &&
make &&
rm -rf logs &&
mkdir logs&&
nohup Tool >> logs/logs.txt