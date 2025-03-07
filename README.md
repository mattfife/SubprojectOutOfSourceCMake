# Out Of Source with Subprojects CMake Example for Windows and Linux 

## Introduction
The topic of out of source builds is often not explained simply and examples tend to get overly complex quickly. I have tried to create the most minimal out of source CMake 'hello world' example in my BasicOutOfSourceCMake. 

This version expands that work by compiling sub-directories in the source into subprojects. Those subprojects load into Visual Stuidio as seperate solutions. It also sets up dependencies between sub-solutions and the main build project. It does this by compiling the sub-projects into static libs. This gives several benefits such as being able to compile just that sub-project independent of all the other code. This is much more like what a real development environment would work like. This example works with both Visual Studio and Linux. 


## Out of Source Builds
In case you're not familiar with out of source builds, traditional build systems tend to compile their intermediate binary files (obj files, libs, executables, dlls, etc) right next to their source files. This means binary and source files are mixed all over in the source tree. Out of source builds, however, put all binary and intermediate files in their own directory (often a bin/ directory) and keep them all out of the source (often src/) directory.  
![image](https://user-images.githubusercontent.com/11483217/118408935-c5ef0100-b63c-11eb-9bcc-49f0666f5c02.png)

As builds become complex, out of source builds have serious advantages. Some of them are:
1. Source control is made easier - especially for git. No need for complex .gitignore rules to avoid intermediate files and accidently miss key resource/source files.
2. It is very easy to clean up intermediate files and track down build issues by simply deleting the binary output directory and starting over.
3. Text and binary searches in the source tree go faster because they are only searching the source files and don't have false hits on binary files.
4. Creating different builds (cross-compiling, 64/32 bit, debug/release, etc) is cleaner and less error prone.
5. Easier to generate output packages that don't accidently include sources.
6. Incremental builds become faster.

There are many other more subtle benefits. Due to all these, out of source builds have become industry standard and the benefits really pay off as your project grows.


## Instructions for Windows/Visual Studio 2022
1. Ensure you have Visual Studio 2022 along with the "Desktop development with C++" package installed. You can install that in the Visual Studio Installer and ensure the package is selected:
![image](https://user-images.githubusercontent.com/11483217/118386182-71ab3900-b5ca-11eb-854f-85b6a7d57f69.png)

2. From the start menu, open the Developer Command Prompt for VS2022
3. Download this source to a convenient local directory and cd into that directory
4. You can either run `build-debug.bat`/`build-release.bat` (or use the command line `cmake -H. -Bbin` if you are using Cmake 3.13 or later).
![image](https://user-images.githubusercontent.com/11483217/118386271-26ddf100-b5cb-11eb-95d9-0447ae697b2b.png)
If you opt for `cmake -H. -Bbin`, `-H.` tells cmake where to find CMakeLists.txt (current directory in this case) and `-Bbin' tells it to put the generated files in `.\bin`
![noscript](https://user-images.githubusercontent.com/11483217/131198934-6757c56f-2324-4ba0-9c63-42840a169813.png)

5. This builds the project executables in `...\bin\` and make files in `...\build\`. To build the actual project/binaries, you have 3 options:

### Build binaries with cmake
6. After the projects are created in ...\build\, you can  run this command from the ...\build\ directory where the project files were created from step 4 to rebuild
7. `cmake --build . --target ALL_BUILD --config Release -- /nologo /verbosity:minimal /maxcpucount`
![cmake2](https://user-images.githubusercontent.com/11483217/131196407-ffc079e4-0b4e-4cbd-b539-d9040923f187.png)

### Build binaries using msbuild
6. In the Developer Command Prompt for VS2022 window, in the ...\build\ directory, run: `msbuild helloworld.sln`
7. msbuild will build the debug version of helloworld.exe in `...\bin\Debug\`
8. Read up on [msbuild command line options](https://docs.microsoft.com/en-us/visualstudio/msbuild/walkthrough-using-msbuild?view=vs-2019#build-the-target) for building different configurations (debug/release, x64/x32, etc)
![msbuild](https://user-images.githubusercontent.com/11483217/131196449-9be9d9de-1925-414b-9138-b1a8f20972f4.png)

### Building in Visual Studio
6. Open Visual Studio 2022
7. Open the newly created helloworld.sln found in the build/ directory. 
8. Build from the top menu like normal

### Visual Studio project notes
- Windows CMake automatically makes 2 additional projects in your solution: ALL_BUILD and ZERO_CHECK.
  - ALL_BUILD will build all projects in the solution (except itself and ZERO_CHECK)
  - ZERO_CHECK will re-run CMAKE and generate all new vproj and sln files. This is handy if you change your CMakeFiles and need to re-run CMake.
  - CMAKE cannot generate a solution without an ALL_BUILD project, but you can prevent CMake from adding the ZERO_CHECK project by adding this line to your top-level CMakeLists.txt: `set(CMAKE_SUPPRESS_REGENERATION true)`

## Instructions for Linux
1. Ensure that you have CMake, git, gcc, and other build tools you'd like. Installing the build-essential package contains most key build tools.
2. Open a terminal and download the source to a convinient local directory. 
3. run `./build-debug.sh` in the source directory
  or
3. `mkdir bin/`
4. `cd bin/`
4. `../build/make`
![image](https://user-images.githubusercontent.com/11483217/118386467-7ffa5480-b5cc-11eb-84d9-9b85937e7919.png)

## Optimizations
- Versions of CMake past 3.13 support parameters that can help you make out-of-source builds more directly (without using the build script) by using the flags:
`cmake -H. -Bbuild`

