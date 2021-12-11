clang++  -D NS=ft just_a_test.cpp -o dup
clang++  -D NS=std just_a_test.cpp -o origin
echo "duplicated:" ; time ./dup > duplicated
echo "\noriginal:" ; time ./origin > Original
diff Duplicated Original
rm -rf duplicated dup 
rm -rf original origin