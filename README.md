# matrix_generator
OpenMp를 이용한 matrix generator  

사용법  
make utility를 사용하여 컴파일  
  
matrix_generator <m> <n> <end_number> 형식으로 실행  
m : row(행)  
n : column(열)  
end_number : 0~end_number(행렬을 채울 값의 Max)  
  
ex) ./matrix_generator 10 10 1  
결과   
./result/[m]_by_[n]_matrix.matrix 파일생성  
  
1 0 0 1 1 1 0 0 0 1  
1 0 1 0 1 0 1 0 0 1  
0 1 0 1 1 1 1 1 0 0  
1 1 0 0 1 1 1 1 1 1  
0 1 1 0 1 0 0 0 1 0  
1 1 1 1 0 0 0 1 1 1  
1 1 0 1 1 1 0 0 1 0  
1 1 1 0 1 0 0 1 0 1  
1 1 1 0 0 1 1 0 1 0  
1 0 1 0 0 0 1 0 0 0  
  
위와 같은 결과가 저장됩니다.  
