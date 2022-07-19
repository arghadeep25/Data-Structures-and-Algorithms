### Usage

```
git clone git@github.com:arghadeep25/Data_Structure_Cpp.git
cd Data_Structure_Cpp
git submodule update --init --recursive 
```

#### Build Manually with Example
```
cmake .. -DBUILD_EXAMPLE=ON -DCMAKE_BUILD_TYPE=Release
make -j4
```

#### Build Manually without Example
```
cmake .. -DBUILD_EXAMPLE=OFF -DCMAKE_BUILD_TYPE=Release
make -j4
```

#### Build from Script
Build Helper
```
Usage: ./build.sh -b CMAKE_BUILD_TYPE -e BUILD_EXAMPLE
	-b CMAKE_BUILD_TYPE: Release | Debug
	-e BUILD_EXAMPLE: ON | OFF
```
```
./build.sh -b Release -e OFF
```
