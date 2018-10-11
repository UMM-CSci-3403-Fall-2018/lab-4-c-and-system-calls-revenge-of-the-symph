#!/bin/bash

path=$1

directoryCount=$(find $path -type d | wc -l)
echo "There were " $directoryCount " directories." 

fileCount=$(find $path -type f | wc -l) 
echo "There were " $fileCount "regular files."

