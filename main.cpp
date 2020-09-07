#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > n(8, vector<int>());




void insert(int N);

bool calculate(int j, int number);

int solution(int N, int number) {
  int answer = -1;
  insert(N); //벡터에 각 n의 최대값 넣음
  int min;  //최소값(answer은 무조건 이 값 이상)
  for(min = 0; min<8; min++){
    if(number < n[min].back()) goto jump;
  }

  return answer;    //위에서 조건에 맞는 경우가 없었다면 무조건 -1

  jump:
  
  for(int j=min; j<8;j++){
    if(calculate(j, number)){
      return answer = j;
    }
  }

  return answer;
}









int main(){
  
  n[3].push_back(1);
  n[3].push_back(2);
  n[3].push_back(3);
  n[3].push_back(4);

  for(int i=0; i<5; i++){
  printf("%d", n[3][i]);
  }
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}








void insert(int N){
  int num;
  for(int i=0; i<8; i++){
    num = 0;
    for(int j=0; j<i; j++){
      num += pow(10, j) * N;
    }
    n[i].push_back(num);
  }
}


bool calculate(int j, int number){


  
  
}






