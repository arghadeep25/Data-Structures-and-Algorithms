# Data Structure and Algorithms

![workflow](https://github.com/arghadeep25/Data-Structures-and-Algorithms/actions/workflows/cmake.yml/badge.svg) 
![lines](https://tokei.rs/b1/github/arghadeep25/Data-Structures-and-Algorithms)
![visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Farghadeep25%2FData-Structures-and-Algorithms&countColor=%23263759)

![Data-Structures-and-Algorithms](https://socialify.git.ci/arghadeep25/Data-Structures-and-Algorithms/image?description=1&font=Inter&forks=1&language=1&name=1&owner=1&pattern=Charlie%20Brown&stargazers=1&theme=Dark)
### Content

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

### Usage

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