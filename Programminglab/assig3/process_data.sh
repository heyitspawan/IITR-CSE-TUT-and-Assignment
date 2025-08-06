#!/bin/bash

mkdir -p plots

awk -F, '
{
    count[$$1]++;
    time[$$1]+=$$2;
    mem[$$1]+=$$3;
}
END {
    for (a in count)
        print a "," time[a]/count[a] "," mem[a]/count[a];
}' results/raw.csv > results/avg.csv
