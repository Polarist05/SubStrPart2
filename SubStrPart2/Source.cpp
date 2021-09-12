#include<iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector<int> v;
	v.push_back(0);
	string s;
	cin >> s;
	int i = 1;
	for (; i < s.size(); ) {
		if (s[0] == s[i]) {
			int k = 0;
			for (; s[k] == s[i + k]; k++);
			v.push_back(k);
			//printf("(1) %d %c\n",k,s[v.size()-1]);
			for (int l = 1; l < k; l++) {
				if (v[l] + l > v[i]) {
					v.push_back(v[i] - l);
					//printf("(2) %d %c\n", v[i]-l,s[v.size()-1]);
				}
				else if (v[l] + l < v[i]) {
					v.push_back(v[l]);
					//printf("(3) %d %c\n",v[l], s[v.size() - 1]);
				}
				else {
					//printf("++++++++++++++++++++++++\n");
					i += l;
					k -= l;
					l = 0;
					for (; s[k] == s[i + k]; k++);
					v.push_back(k);
					//printf("(4) %d %c\n", k, s[v.size() - 1]);
				}
			}
			i = v.size();
			//printf("*******************\n");
		}
		else {
			i++;
			v.push_back(0);
			//printf("(5) 0 %c\n", s[v.size() - 1]);
			//printf("----------------\n");
		}
	}	
	for (i = 0; i < v.size(); i++) {
		if (v[i] == s.size()/2) {
			printf("%d",i);
			return 0;
		}
	}
}
//abcabcdabcabddd
//abcaabcabcaabcabca