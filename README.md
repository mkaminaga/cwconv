Copyright 2016 Mamoru kaminaga<br>

cwconv
====
  Play morse sound from command line string.<br>

## Description
  This tool helps you to practice morse signal decoding.<br>
  Very small and simple to use.<br>

## Demo
  Using cwconv from `cmd.exe`.<br>
  Sound is alos being played with morse simbol text draw.<br>
  ![Demo](doc/cwconv.gif "Demo")

## Features
  * Use cwconv from vim<br>
   `vimplugin/cwconv.vim` enables you to use cwconv from vim, text on on clipboard is passed to args (Only avairable from cigwin)<br>

## Requirement
  * Windows OS<br>
  * Windows SDK<br>
  * DirectSound<br>

## Install
  You can get binary from release page (latest version is `v_1.0.0`).<br>
  If you build from source code, follow the processes below:<br>
  1. Setup build environment<br>
  You have to setup environment for command line build.<br>

  2. Set path<br>
  Set environmental variables (`PATH`, `LIB`, `LIBPATH` and `INCLUDE`) for SDKs.<br>

  3. Fix makefile<br>
  Customize variable `CC` and `LINK` for your environment.<br>

  4. Build this program in command line.<br>
  Be sure `./build` dir exists.

## Usage
  options:<br>
  `-help` Show help<br>
  `-nowindow` Not show output console<br>
  `-nosound` Not play sound<br>
  `-wpm` Set WPM (default is 20)<br>
  `-paris` Set PARIS (default is 20)<br>
  `-s` Set text<br>

## Example
  * Say "Hello world" with 30 WPM<br>
  `cwconv.exe -paris 30 -s Hello world`<br>
  * Show "Hello world" simbol without playing sound<br>
  `cwconv.exe -nosound -s Hello world`<br>
  * Play "Hello world" sound without simbol<br>
  `cwconv.exe -nowindow -s Hello world`<br>
