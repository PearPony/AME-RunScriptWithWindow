# AME-RunScriptWithWindow
This C++ program will allow you to execute a selected Windows script with a window being shown in AME Wizard (useful for allowing the user to make choices in the script).

## Usage
Change the file name in [main.cpp](https://github.com/PearPony/AME-RunScriptWithWindow/blob/main/main.cpp) accordingly. Then proceed to compile.

## Compilling
MinGW on Windows
```g++ -o AME-Workaround main.cpp -mwindows -static```

## Example of usage in a playbook
In a TASKNAME.yml file:
```
title: Run a script with a visible cmd window
actions:
- !run:
  exe: 'MyScript\AME-Workaround.exe'
  exeDir: true
  wait: true
  runas: currentUserElevated
```
