#!/bin/bash

FILE=`ruby -e 'pos = ARGV.find_index("-f"); if pos then puts ARGV[pos+1] end' -- $*`

if [ -n "$FILE" ]; then
    sed -i -e 's/ \+//g' "$FILE"
fi

exec java -jar $(dirname $0)/libexec/tweetysolver-v1.1.1.jar $*
