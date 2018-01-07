# vtable #

Данный пример показывает способ обхода отсутствия нормально реализованных интерфейсов на некоторых языках программирования без поддержки vtable по нулевому смещению (в примере это Free Pascal Compiler под Linux).

This example shows how to bypass the lack of normally implemented interfaces in some programming languages without vtable support for zero offset (in the example this is Free Pascal Compiler for Linux).

### Для чего этот репозиторий? ###

* Для того что бы не забыть.
* Version 1.0

### Как использовать? ###

* Compile: make
* Configuration:
* Dependencies: Linux or Cigwin or ..., fpc, g++
* Run: LD_LIBRARY_PATH=./ ./vtable
