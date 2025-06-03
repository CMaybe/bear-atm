# Bear ATM

## Overview

Bear ATM is a simplified ATM simulation system that allows users to perform basic banking operations such as inserting a card, verifying a PIN, selecting an account, and performing transactions like balance inquiry, deposit, and withdrawal. 

## Features

- **Insert Card**: Simulates inserting a card into the ATM.
- **PIN Verification**: Verifies the user's PIN without exposing it.
- **Account Selection**: Allows users to select an account associated with their card.
- **Transactions**:
  - Check account balance.
  - Deposit money (integer values only, representing 1-dollar bills).
  - Withdraw money (integer values only, representing 1-dollar bills).


## Prerequisites

Before you get started, make sure you have the following installed:

- **Docker**: For building and running the application in a containerized environment.
- **Git**: To clone the repository.
- **CMake**: To build the project.
- **C++17**: The project uses modern C++ features and requires a compiler that supports C++17.
- **GoogleTest**: Unit tests are implemented using the GoogleTest framework.


## Getting Started on Devcontainer
This repository is configured with a `devcontainer` for Visual Studio Code, allowing you to quickly set up and use the development environment using Docker.

### 1. Clone the Repository
```bash
git clone https://github.com/CMaybe/bear-atm.git
cd bear-atm
code .
```
### 2. Open in VSCode

Open the cloned repository in Visual Studio Code. VSCode will detect the devcontainer configuration and prompt you to reopen the folder in the container.

### 3. Reopen in Container

Follow the prompt to reopen the repository in the Docker container. VSCode will build and start the container as defined in the .devcontainer directory, setting up the development environment according to the configuratio.

#### Option: Access the Container Directly
If you prefer to access the container directly, you can use the following command:

```bash
docker exec -it dev-bear-atm /bin/bash
```

### Build and install 
If you are using the provided Dockerfile or Devcontainer, all dependencies will be installed automatically.

**Build**  
```bash
mkdir bear_atm/build && cd bear_atm/build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```
**Install**
```bash
sudo make install # default prefix is /usr/local
```

### Examples
An example for visualize trajecotry is included in the repository. You can find it in the `example` directory:
```bash
cd example
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j
# run
./atm_example 
```

### 4. how to run TestCode
```bash
cmake -S ./bear_atm -Bbuild -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug
cd build
ctest -C Debug --output-on-failure --verbose
```



GitHub Actions for CI
This project uses GitHub Actions to automate building and testing the project on each push or pull request to the main branch.

The workflow file is located at .github/workflows/ci.yml. It will:

Build the project using Docker.
Run the tests in the Docker container.
You can view the status of the CI workflow in the Actions tab of the GitHub repository.

Project Structure
The directory structure is as follows:

```
bear-atm/
├── .github/
│   └── workflows/
│       └── ci.yml          # GitHub Actions CI configuration
├── Dockerfile              # Docker configuration for building and running the project
├── CMakeLists.txt          # CMake build configuration
├── bear_atm  				
│	├── src/ 				# Main C++ Core 
│	└── test/				# Google Test-based test case
└── example 				# The main application source code that uses bearATM.
```


This project is licensed under the MIT License - see the LICENSE file for details.



