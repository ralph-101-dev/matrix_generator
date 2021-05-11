# matrix_generator
## OpenMp를 이용한 matrix generator  

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
  
## make_sample.bash 스크립트  
4 by 4 부터 크기는 2의 멱수로 증가하며, 32768 by 32768 크기의 행렬 sample을 생성합니다.  
결과는 ./result에 기록됩니다.  
  
사용법  
./make_sample.bash [end_number]  
end_number를 생략하면 1로 채웁니다.  

