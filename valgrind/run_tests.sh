#!/bin/bash

VALGRINDDIR=`dirname ${0}`

BINDIR=`dirname ${VALGRINDDIR}`/../build/dist/Debug/bin

for bin in `ls ${BINDIR}`; do
	echo "Valgrind ${BINDIR}/${bin}..."
	valgrind --log-fd=1 ${BINDIR}/${bin} | grep "==" > ${VALGRINDDIR}/${bin}.txt
done

for f in *.txt; do
	echo $f
	grep "ERROR SUMMARY" $f
done

echo "Done"

