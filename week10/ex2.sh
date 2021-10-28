echo zeiin > ../week1/file.txt
link ../week1/file.txt _ex2.txt
ls -i ../week1/file.txt
find -inum 811347
find -inum 811347 -exec rm {} \;
find -inum 811347


