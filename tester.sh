clang++ -Wall -Wextra -Werror my_main.cpp  -o my_main
clang++ -Wall -Wextra -Werror vec_main.cpp  -o vec_main
echo "my_main" ; time ./my_main  > my_main_
echo "vec_main" ;time ./vec_main > vec_main_
diff my_main_ vec_main_
rm -rf my_main  my_main_
rm -rf vec_main  vec_main_