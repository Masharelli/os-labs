#!/bin/bash
direc='/home/oscreader/linux-source-3.16/*'
list='/home/oscreader/os-labs/Lab1.5/linux_source_structure.txt'

for dir in $direc; do
    if [ -d "$dir" ]; then
        echo 'Directory: '$dir >> $list
        echo 'Files with .c' >> $list
        cd $dir && find | grep '\.c$' >> $list
        echo 'Files with .h'  >> $list
        cd $dir && find | grep '\.h$' >> $list
    fi
done
