\mainpage

![Data-Structures-and-Algorithms](https://socialify.git.ci/arghadeep25/Data-Structures-and-Algorithms/image?description=1&font=Inter&forks=1&language=1&name=1&owner=1&pattern=Charlie%20Brown&stargazers=1&theme=Dark)


## Content

| Content                                                                                  | Status                                          |
|------------------------------------------------------------------------------------------|-------------------------------------------------|
| Array                                                                                    | &check;                                         |
| Singly Linked List                                                                       | &check;                                         |
| Doubly Linked List                                                                       | &check;                                         |
| Sorting<br/> - Bubble Sort<br/> - Insertion Sort<br/> - Merge Sort<br/> - Selection Sort | <br/>&check;<br/>&check;<br/>&check;<br/>&check; |
| Binary Tree                                                                              | -                                               |
| Stacks                                                                                   | &cross;                                         |
| Queues                                                                                   | &cross;                                         |
| Hashing                                                                                  | &cross;                                         |



## Usage

```
git clone git@github.com:arghadeep25/Data_Structure_Cpp.git
cd Data_Structure_Cpp
git submodule update --init --recursive 
```


#### Build Script (Recommended)
Build Helper
```
Usage: ./build.sh -b CMAKE_BUILD_TYPE -e BUILD_EXAMPLE
	-b CMAKE_BUILD_TYPE: Release | Debug
	-e BUILD_EXAMPLE: ON | OFF
```
```
./build.sh -b Release -e OFF
```


#### Build Manually
```
mkdir build && cd build
cmake .. -DBUILD_EXAMPLE=ON -DCMAKE_BUILD_TYPE=Release
make -j4
```

Turning ON and OFF the examples might need to remove the build folder manually.

## Documentation
The documentation is done using Doxygen. If you don't have doxygen installed, use the following command.
```
sudo apt install doxygen
```

To get the documentation, use the following command

```
doxygen Doxygen.in
```

Use your favorite browser, to see the documentation

```
google-chrome documentation/html/index.html
firefox documentation/html/index.html
```
