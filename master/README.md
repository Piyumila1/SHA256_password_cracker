<h1 align="center">SHA-256 Dictionary Password Cracker</h1>

<p align="center">
  Educational cryptographic analysis tool written in C
</p>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue">
  <img src="https://img.shields.io/badge/library-OpenSSL-green">
  <img src="https://img.shields.io/badge/type-Dictionary%20Attack-red">
</p>

---

## 📌 Overview

+ First to all, this is a very simple project of mine to learn about password cracking. Not a serious tool. Just for learn and fun.

+ This project about very simple CPU based, single threaded SHA-256 password cracker written in C.
  It is specifically designed to run efficiently on low end cloud machines with limited resources (single core, single thread, low RAM).

+ The tool focuses on simplicity, minimal dependencies, cross platform and predictable performance in constrained environments.
  It demonstrates:

  - Cryptographic hashing
  - Hex to byte conversion
  - Dictionary attack mechanics
  - Secure hash comparison

+ This tool is built strictly for educational and cybersecurity research purposes.

---

## ⚙️ Compilation

+ This simple tool can be compile and run on any platform with GCC.

```bash
gcc password_cracker.c <name> cracker -lssl -lcrypto
```

+ Make sure OpenSSL development libraries are installed.

#### On Debian/Ubuntu/Kali linux :

```bash
sudo apt install libssl-dev
```
#### On Windows

+ Since windows is not build for developers natively, it is hard to install dependencies than UNIX systems.

+ I installed MSYS2 and install gcc and OpenSSL development libraries.

    - Goto https://www.msys2.org/ and install MSYS2
    - Open MSYS2 UCRT64 terminal and run :  ```pacman -Syu```
    - Then install GCC : ```pacman -S mingw-w64-ucrt-x86_64-gcc```
    - Finally, install OpenSSL development libraries : ```pacman -S mingw-w64-ucrt-x86_64-openssl```

## 📌 Usage

+ After compiling, run the executable inside a terminal. Simply give a valid Dictionary file path and the SHA256 hash value you want to decrypt. Additional commands :

  - Exit : To exit the program
  - clear : To clean the shell

+ As i said this is very simple tool.


<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue">
  <img src="https://img.shields.io/badge/library-OpenSSL-green">
  <img src="https://img.shields.io/badge/type-Dictionary%20Attack-red">
</p>