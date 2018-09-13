#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "Usage: find.sh GAMERA_FOLDER OUTPUT_FILE"
    exit 1
fi

GAMERA_FOLDER=$1
OUTPUT_FILE=$2

python extract_changes.py

while read p; do
    grep --include=\*.py -rnwo "$GAMERA_FOLDER" -e "$p" >> "$OUTPUT_FILE"
done <classic-items.txt

rm classic-items.txt
