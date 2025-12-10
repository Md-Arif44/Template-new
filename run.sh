// compile and run  like run a where a is a cpp file
// first open terminal bash then paste run() enter then source ~/.bashrc enter  
run() {
    code="$1"
    g++ "${code}.cpp" -o "$code" -std=c++20 -g -DDeBuG \
        -Wall -Wshadow -fsanitize=address,undefined \
        && "./$code"
}

source ~/.bashrc

