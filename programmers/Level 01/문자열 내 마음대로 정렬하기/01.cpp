#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k;

bool compare(string a, string b){
    if(a[k] == b[k]) return a < b;
        return a[k] < b[k];
}

vector<string> solution(vector<string> strings, int n) {
    k = n;
 
    sort(strings.begin(), strings.end(),compare);
    return strings;
}
