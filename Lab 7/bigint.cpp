#include "bigint.h"
using namespace std;
BigInt::BigInt(string s){
  for(int i=0;i<s.length();i++){
    char temp= s[s.length()-1-i];
    result.push_back((int)(temp)-48);
  }
}
string BigInt::to_string(){
  string s;
  for(int i=result.size()-1;i>=0;i--){
    s+=std::to_string(result[i]);
  }
  return s;
}
void BigInt::add(BigInt b){
  if((b.result).size()>result.size()){
    for(int i=0;i<b.result.size()-result.size();i++){
      result.push_back(0);
    }
  }else if((b.result).size()<result.size()){
    for(int i=0;i<result.size()-b.result.size();i++){
      (b.result).push_back(0);
    }
  }
  int carry=0;
  for(unsigned int i=0;i<result.size();i++){
    int temp=result[i]+(b.result)[i]+carry;
    if(temp>9){
      carry=1;
      temp-=10;
    }else{
      carry=0;
    }
    result[i]=temp;
  }
  if(carry>0)
	{
		result.push_back(carry);
	}
}