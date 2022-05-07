#!/bin/bash

# python만 지원

INPUT_DIR=./inputs/
OUTPUT_DIR=./outputs/
ANSWER_DIR=./answers/
EXECUTE_FILE=../kmp.py

DO_ANSWER_COMPARE=1

# testCase가 들어있는 폴더를 순회
for testCase in `ls $INPUT_DIR`
  do
    cat $INPUT_DIR/$testCase | python $EXECUTE_FILE > $OUTPUT_DIR/$testCase
    
    if [ $DO_ANSWER_COMPARE -eq 1 ]
      then

      if cmp -s $OUTPUT_DIR/$testCase $ANSWER_DIR/$testCase
        then
          echo "[correct]" $testCase
        else
          echo "[wrong]" $testCase

          echo "*** output ***"
          cat $OUTPUT_DIR/$testCase
          echo "" # for new line

          echo "*** answer ***"
          cat $ANSWER_DIR/$testCase
          echo "" # for new line
      fi
    fi
  done

echo "done!"