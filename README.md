# Data Structure and Algorithms

![workflow](https://github.com/arghadeep25/Data-Structures-and-Algorithms/actions/workflows/cmake.yml/badge.svg)
![visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Farghadeep25%2FData-Structures-and-Algorithms&countColor=%23263759)
[![Hits-of-Code](https://hitsofcode.com/github/arghadeep25/Data-Structures-and-Algorithms)](https://hitsofcode.com/github/arghadeep25/Data-Structures-and-Algorithms/view)
![GitHub license](https://badgen.net/github/license/Naereen/Strapdown.js)
![C++](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)
![Data-Structures-and-Algorithms](https://socialify.git.ci/arghadeep25/Data-Structures-and-Algorithms/image?description=1&font=Inter&forks=1&language=1&name=1&owner=1&pattern=Charlie%20Brown&stargazers=1&theme=Dark)


## Content

| Content                                                                                                                          | Status                                          |
|----------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------|
| Array                                                                                                                            | &check;                                         |
| Linked List<br/> - Singly Linked List <br/> - Circular Linked List <br/> - Doubly Linked List <br/> - Doubly Circular Linked List | <br/>&check;<br/>&cross;<br/>&check;<br/>&cross; |
| Stacks                                                                                                                           | &check;                                         |
| Queues                                                                                                                           | &check;                                         |
| Binary Tree                                                                                                                      | &cross;                                                |
| Hashing                                                                                                                          | &cross;                                         |
| Sorting<br/> - Bubble Sort<br/> - Insertion Sort<br/> - Merge Sort<br/> - Selection Sort                                         | <br/>&check;<br/>&check;<br/>&check;<br/>&check; |
| Searching<br/> - Linear Search<br/> - Binary Search<br/> - Interpolation Search<br/> - Jump Search                               | <br/>&cross;<br/>&cross;<br/>&cross;<br/>&cross; |




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