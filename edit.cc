#include<iostream>
#include<vector>

using std::string;
using std::vector;
int editDistance(const string& s1, const string & s2) {
  vector<vector<int> > ED(s1.length()+1, vector<int>(s2.length()+1));
  if (s1.length() == 0) return s2.length();
  if (s2.length() == 0) return s1.length();
  
  if (s1[0] == s2[0]) 
    return editDistance(s1.substr(1), s2.substr(1));
  else 
    return 1 + std::min(editDistance(s1.substr(1), s2), 
      std::min(editDistance(s1.substr(1),s2.substr(1)),editDistance(s1,s2.substr(1))));

  return 0;
}

int main(int argc, char* argv[]) {
  if (argc != 3) return -1;
  string s = argv[1];
  printf("%s : %s : %d\n", argv[1], argv[2], editDistance(argv[1], argv[2]));
  return 0;
}
