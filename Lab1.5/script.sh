#!/bin/bash
direc='/Desktop/OS/linux-source-3.18/*'
list='/Desktop/OS/os-labs/Lab1.5/linux_source_structure.txt'

for dir in $direc; do
    if [ -d "$dir" ]; then
        echo 'Directory: '$dir >> $list
        echo 'Files with .c' >> $list
        cd $dir && find | grep '\.c$' >> $list
        echo 'Files with .h'  >> $list
        cd $dir && find | grep '\.h$' >> $list
    fi
done
