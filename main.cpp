#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > n(8, vector<int>());




void insert(int N);

bool calculate(int j, int number);

int pluss(int m, int n);

int minuss(int m, int n);

int multiplee(int m, int n);

int dividee(int m, int n);



void isThisNew(int tem, int T);


int solution(int N, int number) {
  int answer = -1;
  insert(N); //벡터에 각 n의 최대값 넣음
  int min;  //최소값(answer은 무조건 이 값 이상)
  for(min = 0; min<8; min++){
    if(number < n[min].back()) goto jump;
  }

  return answer;    //위에서 조건에 맞는 경우가 없었다면 무조건 -1

  jump:
  
  for(int T=min; T<8;T++){
    if(calculate(T, number)){
      return answer = T;
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








void insert(int N){ //1,11,111 등의 값을 각 배열 첫번째에 넣음
  int num;
  for(int i=0; i<8; i++){
    num = 0;
    for(int j=0; j<i; j++){
      num += pow(10, j) * N;
    }
    n[i].push_back(num);
  }
}


bool calculate(int T, int number){

  for(int k=0; k<T; k++){
    int K = T-k;
    for(int i=0; i < n[K].size(); i++){
      for(int j=0; j<n[T-K].size();j++){
        int tem = pluss(n[K][i], n[T-K][j]);
        if(tem == -1) goto notnew;
        else if(number == tem){
          return 1;
        }
        isThisNew(tem, T);

        notnew:
        tem = minuss(n[K][i], n[T-K][j]);
        if(number == tem){
          return 1;
        }
        isThisNew(tem, T);

        tem = multiplee(n[K][i], n[T-K][j]);
        if(number == tem){
          return 1;
        }
        isThisNew(tem, T);

        tem = dividee(n[K][i], n[T-K][j]);
        if(number == tem){
          return 1;
        }
        isThisNew(tem, T);


      }
    }
  }
  return 0;
}




int pluss(int m, int n){
  return m+n;
}

int minuss(int m, int n){
  if(m-n <= 0) return -1;
  else return m-n;
}

int multiplee(int m, int n){
  return m * n;
}

int divdee(int m, int n){
  if(m % n == 0) return m/n;
  else return -1;
}


void isThisNew(int tem, int T){

  for(int i=0; i<T; i++){
    for(int j=0; j<n[i].capacity();j++){
      if(tem == n[i][j]){
        break;
      }
    }
  }
  n[T].push_back(tem);
}



