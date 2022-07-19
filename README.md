### Usage

```asm
git clone git@github.com:arghadeep25/Data_Structure_Cpp.git
cd Data_Structure_Cpp
git submodule update --init --recursive
mkdir build && cd build
cmake 
```
#### Building with Example
```asm
cmake .. -DBUILD_EXAMPLE=ON -DCMAKE_BUILD_TYPE=Release
make -j4
```
#### Building without Example
```asm
cmake .. -DBUILD_EXAMPLE=OFF -DCMAKE_BUILD_TYPE=Release
make -j4
```
