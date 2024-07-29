#!/bin/bash
# Compiles and runs the program given in $1 based on its file extension

silent_mode=0

for arg in "$@"; do
  if [[ "$arg" == "-s" ]]; then
    silent_mode=1
  fi
done

extension="${1##*.}"
executable_name="program"

if [[ $silent_mode -eq 0 ]]; then
  echo "Determining the compiler required for the file: $1"
fi

case $extension in
  c)
    if [[ $silent_mode -eq 0 ]]; then
      echo "Determined file type: ${bold}C${normal}"
      echo "Compiling C program..."
    fi
    gcc $1 -o $executable_name
    ;;
  cpp)
    if [[ $silent_mode -eq 0 ]]; then
      echo "Determined file type: ${bold}C++${normal}"
      echo "Compiling C++ program..."
    fi
    g++ $1 -o $executable_name
    ;;
  java)
    if [[ $silent_mode -eq 0 ]]; then
      echo "Determined file type: ${bold}Java${normal}"
      echo "Compiling Java program..."
    fi
    javac $1
    executable_name="${1%.*}"
    ;;
  *)
    if [[ $silent_mode -eq 0 ]]; then
      echo "Error: Unsupported file type, cannot autocompile. Please compile and run manually."
    fi
    exit 1
    ;;
esac

if [[ $silent_mode -eq 0 ]]; then
  echo "Running the program..."
fi

if [[ $extension == "java" ]]; then
  java $executable_name
else
  ./$executable_name
fi
