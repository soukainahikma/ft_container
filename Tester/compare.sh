clang++  -Wall -Wextra -Werror -std=c++98 duplicated.cpp -o dup
clang++  -Wall -Wextra -Werror -std=c++98 original.cpp -o origin
echo "duplicated:" ; time ./dup > duplicated
echo "\noriginal:" ; time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin