# SHAPES PARSER USING USER-DEFINED SHAPESPARSER LIBRARY

## DESCRIPTION
The program introduced in this project is aimed to read shapes information from a text file, parse them into appropriate shapes, sort them by area, and print out all of the shapes after being sorted.

## INSTALLATION

### CLONE GITHUB REPOSITORY
Make sure you have installed the GitHub command-line interface (CLI) on your system. If you haven't, please install it now by following this URL: https://cli.github.com/.

You can clone this GitHub repository on your computer by clicking on the ```<> Code``` button, select ```GitHub CLI```, copy, paste and run ```gh repo clone TheMetaSetter/shapes-parser``` in your system command-line intepreter or terminal emulator.

### OPEN WITH GITHUB DESKTOP
First of all, you need to make sure you have downloaded the GitHub Desktop Application on your system. If you haven't please install it now by following this URL: https://desktop.github.com/.

After setting up your GitHub Desktop App, back to our GitHub repository, click on the ```<> Code``` button and select ```Open with GitHub Desktop```.

## DOCUMENTATION

### BASIC USAGE
Our program is implemented, compiled and run using Visual Studio Code with the help of CMake. For that reason, we will show you the basic usage of this program using VSCode.
Make sure you have installed VSCode on your system.

#### Step 1: Open VSCode and move to the ShapesParser folder
You just need to open VSCode and move to the ShapesParser folder as usual. Notice that you need to move to the **ShapesParser** folder, **not** the **shapes-parser** folder.

#### Step 2: Compile the source code of the library into a dynamic library that is compatible with your system
You need to compile the code inside the Headers and Sources subfolder of the ShapesParser folder into a dynamic library. Then, you need to place the dynamic library outside of the build folder and still inside the Shapes folder as I've already set up the main project to link appropriately with the dynamic library in this way.

You can follow the short video here which I use to show the basic usage of the program.
[C++ SHAPES PARSER | BASIC USAGE](https://youtu.be/zPPWe14iXNU)

#### Step 3: Run the project using CMake
- Move to the shapes-parser folder
- Click the ```Build``` button and click ▶ next to it to run the project

## HOW DO I LINK THE LIBRARY WITH THE PROGRAM?
- To link the library with the program, I need to write 2 CMakeLists.txt file. One is located right inside the ShapesParser folder and the other is located right inside the shapes-parser folder. If you interest with the implementation of these 2 files, just directly read them as I have carefully commented their code.
