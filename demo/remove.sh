#!/bin/bash
if [[ -z "$1" ]]; then
      echo "Usage: ./remove.sh PATH"
      exit
fi

filename="whitelist"
unset cmd
exec < $filename
#find . -not \( -wholename "./dir2*" -or -wholename "./file2" -or -wholename "./file3.c" -or -wholename "./whitelist" -or -wholename "./test.sh" \) -delete
while read line
do
    if [[ -z "$cmd" ]]; then
       #cmd="find ./wnc -not \( -wholename \"$line\""
       cmd="find $1 -not \( -wholename \"$line\""
    else
       cmd+=" -or -wholename \"$line\""
    fi
done
cmd+=' \) -delete'
#cmd+=' \)'
echo $cmd
sh -c "$cmd"
unset cmd
