#!/bin/bash

START=$(date +%s)
CURRENT_DIR=$(pwd)
sleep 2
END=$(date +%s)
DIFF=$((END - START))
echo
echo Time elapsed: $DIFF seconds
