# Unit testing in C with Unity

## Unity

- Link to the project: [url](https://github.com/ThrowTheSwitch/Unity)

## Prerequisites

- git
- ruby

### Debian/Ubuntu

```
sudo apt install git   # if not installed already
sudo apt install ruby
```

### MacOS

```
brew install ruby
```

## Steps

- Step 0: Set up the project
- Step 1: Get Unity
- Step 2: Write Makefile
- Step 3: Write tests
- Step 4: Generate test runner & Build
- Step 5: Run tests

## Step 0: Set up the project

Suppose that all `.c` and `.h` files of the project are in the root directory.

- We create a `test` directory in the root directory. There will be 2 files in this directory:
    - `Makefile`: this will create the executable to run the tests. How to write this file? Step 2.
    - `test.c`: this is where we define the tests. How to write this file? Step 3.

```
project_root/
├── add.c
├── add.h
├── concat.c
├── concat.h
├── main.c
├── Makefile      (for the project)
├── mergeSort.c
├── mergeSort.h
└── test/
    ├── Makefile  (for test runner)
    └── test.c    (where the tests go)
```

- Open the project in VS Code.

```sh
cd project_root
code .
```

- Create a configuration file: `Ctrl + Shift + P` => `C/C++: Edit Configurations (JSON)`. Fix some options:
    - Delete the `cppStandard` line.
    - Change `cStandard` to `c99`.

## Step 1: Get Unity

- Clone a **stable version** of the Unity project into the `test` directory.

```
cd test
git clone -b v2.5.1 https://github.com/ThrowTheSwitch/Unity.git
```

## Step 2: Write tests

- Basic structure of the file:

```c
#include "unity.h"

void setUp() {
    // set stuff up here
}

void tearDown() {
    // clean stuff up here
}
```

- All test function name starts with `test_`.
- Available assertions: [url](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)

## Step 3: Write Makefile

- Remember to exclude the `main.c` file of the project (or whichever with the `main()` function).

## Step 4: Build test runner

```
make
```

## Step 5: Run tests



## More Examples

[url](https://github.com/ThrowTheSwitch/Unity/tree/master/examples)

## Extra: Makefile notes

```
https://github.com/nathan-wien/coding-notes/tree/master/C/Makefile
```
