set datafile separator comma
set terminal pngcairo size 1000,600 enhanced font "Verdana,10"
set output 'plots/performance.png'

set title "Average Time and Memory Usage of Sorting Algorithms" font "Verdana,14"
set xlabel "Sorting Algorithms" font "Verdana,12"
set ylabel "Time (sec)" font "Verdana,12"
set y2label "Memory (KB)" font "Verdana,12"

set style data histogram
set style histogram clustered gap 1
set style fill solid border -1
set boxwidth 0.4

set grid ytics y2tics
set key outside top center horizontal font "Verdana,10"
set border lw 1.5

set ytics nomirror font "Verdana,10"
set y2tics font "Verdana,10"

# Add smooth colors
set style line 1 lc rgb "#4B8BBE" lt 1 lw 2 pt 5
set style line 2 lc rgb "#FF6F61" lt 1 lw 2 pt 7

# Plot with improved visuals
plot 'results/avg.csv' using 2:xtic(1) title "Time (sec)" ls 1, \
     '' using 3 axes x1y2 title "Memory (KB)" ls 2
