set datafile separator comma
set terminal png size 800,600
set output 'plots/performance.png'
set title "Average Time and Memory Usage of Sorting Algorithms"
set xlabel "Sorting Algorithms"
set style data histograms
set style fill solid
set boxwidth 0.5
set ylabel "Time (sec)"
set y2label "Memory (KB)"
set ytics nomirror
set y2tics

plot 'results/avg.csv' using 2:xtic(1) title "Time (sec)", \
     '' using 3 axes x1y2 title "Memory (KB)"
