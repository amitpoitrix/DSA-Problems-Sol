#include<bits/stdc++.h>
using namespace std;

// Robin karp String Matching Algorithm
// It is used to find given substring pattern in given text. It is also known as string matching algorithm.

// Brute Force Approach for String Matching
// TC - O(n^2)
// SC - O(1)
class Solution{
public:
    int stringMatch(string &txt, string &pat){
        int m = txt.size();
        int n = pat.size();
        
        for(int i = 0; i <= m-n; i++){
            int j;
            for(j = 0;j < n; j++){
                if(txt[i+j] != pat[j])
                    break;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};

#define ll long long int
#define primeNo 119

// Calculating hash value till n length string - O(n)
ll createHashValue(string str, int n){
    ll result = 0;
    for(int i = 0; i < n; i++){
        result += (ll)(str[i] * (ll)pow(primeNo, i));
    }
    return result;
}

// Calculating hash value for subsequent string - O(1)
ll recalculateHash(string str, int oldIdx, int newIdx, ll oldHash, int patLength){
    ll newHash = oldHash - str[oldIdx];
    newHash /= primeNo;
    newHash += (ll)(str[newIdx] * (ll)pow(primeNo, patLength-1));
    return newHash;
}

// Checking whether two strings are equal character by character
bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2){
    // First checking length
    if(end1 - start1 != end2 - start2)
        return false;
    
    while(start1 <= end1 && start2 <= end2){
        if(str1[start1++] != str2[start2++])
            return false;
    }

    return true;
}

int rabinKarp(string txt, string pat){
    // First computing hash value of pattern & first substring of pattern.length()
    ll txtHash = createHashValue(txt, pat.size());
    ll patHash = createHashValue(pat, pat.size());

    // Traversing till [0, n-m]
    for(int i = 0; i <= txt.size() - pat.size(); i++){
        // If hash value is same than comparing character by character of both strings
        if(txtHash = patHash && checkEqual(txt, pat, i, i + pat.size()-1, 0, pat.size()-1))
            return i;
        
        // Computing hash value for subsequent string
        if(i < txt.size() - pat.size())
            txtHash = recalculateHash(txt, i, i + pat.size(), txtHash, pat.size());
    }

    return -1;
}

// Another Approach - Using Prefix Hash Array
// TC - O(m + n); O(m * n) in worst case
// SC - O(m); m -> txt.length()
class Solution2{
public:
    bool rabinKarp(string txt, string pat){
        long long mod = 1e9 + 7;
        long long prime = 31;
        long long pow = 1;    // for computing power of prime no., initially its 1

        // First we gonna compute pattern hash value
        long long targetHashVal = 0;
        for(int i = 0; i < pat.length(); i++){
            targetHashVal = (targetHashVal + (pat[i] - 'a' + 1) * pow) % mod;
            pow = (pow * prime) % mod;
        }

        // Now we gonna compute txt hash value for its each character
        vector<long long> pha(txt.length());    // Prefix Hash Array
        vector<long long> pa(txt.length());     // Power Array
        pha[0] = txt[0] - 'a' + 1;
        pa[0] = 1;
        pow = prime;
        for(int i = 1; i < txt.length(); i++){
            pha[i] = (pha[i-1] + (txt[i] - 'a' + 1) * pow);
            pa[i] = pow;
            pow = (pow * prime) % mod;
        }

        // Now we gonna compare hash value of pat & txt substring till pattern length
        int sp = 0, ep = pat.length()-1;
        while(ep < txt.length()){
            long long win = pha[ep];
            // Sliding window - Rolling Hash technique
            if(sp > 0)
                win = (win - pha[sp-1] + mod) % mod;    // Adding mod if win goes negative
            
            if(win == (targetHashVal * pa[sp]) % mod)
                return true;
            
            sp++;
            ep++;
        }

        return false;
    }
};

int main(){
    string txt = "abjhhvfgjfabd";
    string pat = "abd";

    // cout << rabinKarp(txt, pat) << "\n";
    Solution2 obj;
    cout << obj.rabinKarp(txt, pat) << "\n";

    return 0;
}