#include <iostream>
#include <vector>

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, x;
  std::cin >> n >> x;

  std::vector<int> vec(n);

  for(int i = 0; i < n; ++i){
    std::cin >> vec[i];
  }

  int fast=0, slow=0;
  for(;fast < vec.size(); ++fast){
    if(vec[fast] != x){
      vec[slow++] = vec[fast];
    }
  }

  for(int i = 0; i < slow-1; ++i){
    std::cout << vec[i] << " ";
  }

  std::cout << vec[slow-1];
  return 0;
}
