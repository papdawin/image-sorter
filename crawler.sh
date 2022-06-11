#! /bin/bash

`g++ main.cpp -o imgsrtr`

for entry in `find . -name "*.JPG"` ; do (

    dateTaken=`./imgsrtr.exe $entry`

    if [ "${dateTaken:0:1}"=2 ]; then #ok
        year="${dateTaken:0:4}"
        month="${dateTaken:5:2}"
        day="${dateTaken:8:2}"

        echo $entry | grep -oP '\w*\.JPG'
        echo "Moving to $year.$month"

        `mkdir -p "./$year/$month/"`
        `mv $entry ./$year/$month/$picName`

    else #error

        echo $dateTaken
        `mkdir -p "./misc/"`
        `mv $entry ./misc/$picName`
    fi 

    `find . -type d -empty -delete`

) done