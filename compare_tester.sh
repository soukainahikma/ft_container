clang++  -D NS=ft main.cpp -o dup
clang++  -D NS=std main.cpp -o origin
echo "duplicated:" ; time ./dup > duplicated
echo "\noriginal:" ; time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin