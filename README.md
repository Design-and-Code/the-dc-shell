# The DC Shell
A simple shell for UNIX like operating system. The shell can be used to execute a few basic commaands and mainly is a attempt to demonstrate how to work with C and the POSIX Api
This shell was created as a part of the C Programming workshop hosted by [A.J.Sarmah](https://github.com/A-J-Sarmah) and [Sid](https://github.com/sidwebworks)


### Screenshots
![shell](https://user-images.githubusercontent.com/99042379/198832864-0df47a36-39c3-4025-aaf2-cc89c1f96c79.png)


### Installation Instructions
The shell only works with a UNIX based OS, we can use WSL if we are on windows. Following are the steps to follow to compile the shell
1. For Debain based distros (Debain, Ubuntu, Linux Mint, Kali Linux, Pop OS etc) Run
  > sudo apt-get install cmake
  
  > sudo apt-get install ninja
2. For Arch Based distros (Arch, Arco, Manjaro, Garuda etc) Run
  > pacman -S cmake
  
  > pacman -S ninja
3. Clone the project and navigate to project folder and run 
  > cmake -GNinja -S . -B build/
  
  > cd build
  
  > ninja
  
  > ./the-dc-shell
   
 4. The Shell shall be up and running!
