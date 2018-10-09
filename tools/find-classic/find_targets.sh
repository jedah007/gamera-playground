#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Usage: find.sh GAMERA_FOLDER OUTPUT_FILE"
    exit 1
fi

GAMERA_FOLDER=$1
OUTPUT_FILE=$2

python extract_changes.py

#
# Find matches
#

while read change; do
    grep --include=\*.py -rno "$GAMERA_FOLDER" -e "$change" >> "$OUTPUT_FILE"
done <classic-items.txt

#grep --include=\*.py -rno "$GAMERA_FOLDER" -e "[A-Z]+[a-z]+[A-Za-z]*\_[A-Z]+[a-z]+[A-Za-z]*" >> "$OUTPUT_FILE"


#
# Clean-up
#

rm classic-items.txt
# Remove path to file from entries in output-file
sed -i -E "s/\/?([A-Za-z0-9]+\/)+//g" $OUTPUT_FILE
