Copyright 2016 Mamoru kaminaga<br>

cwconv
====
  Play morse sound from command line string.<br>

## Description
  This toole is created for my morse signal decoding practice.<br>
  I decided to create a small tool to create sound from short text.<br>
  The tool is easily combined with other tools: shell scripts, editors, and so on.<br>

## Demo
  Using cwconv.exe from cmd.exe.
  ![Demo](doc/cwconv.gif "Demo")

## Features
  * vim script: vimplugin/cwconv.vim plays text on clipboard (Currently cigwin only)

## Requirement
  Windows OS.<br>
  Windows SDK.<br>
  DirectSound.<br>

## Install
  You can get binary from release page (current latest version is 1.0.0).<br>
  If you build latest code form source code, follow the processes below:<br>
  1. Setup build environment<br>
  You have to setup environment for command line build.<br>

  2. Set path<br>
  Set environmental variables (PATH, LIB, LIBPATH and INCLUDE) for SDKs.<br>

  3. Fix makefile<br>
  Fix variable "CC" and "LINK" to your environment.<br>

  4. Build this program in command line.<br>
  Build cwconv !

## Usage
  options:<br>
  -help:     Show help<br>
  -nowindow: Not show output console<br>
  -nosound:  Not play sound<br>
  -wpm:      Set WPM, default is 20<br>
  -paris:    Set PARIS, default is 20<br>
  -s:        Input string to be morse signal<br>

## Example
  `cwconv.exe -paris 30 -s this is a pen`<br>
  `_  . . . .  . .  . . .     . .  . . .     . _     . _ _ .  .  _ .`<br>

## Install
  Put cwconv.exe and sin_wave.wav in the same directory.
