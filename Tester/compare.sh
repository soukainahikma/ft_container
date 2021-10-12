clang++ -Wall -Wextra -Werror duplicated.cpp -o dup
clang++ -Wall -Wextra -Werror original.cpp -o origin
./dup > duplicated
./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin