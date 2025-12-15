# run by   bash s.sh

for((i = 1; i<=100 ; ++i)); do
    echo $i
    ./gen $i > int
    diff -w <(./a< int) <(./brute < int) || break
done





