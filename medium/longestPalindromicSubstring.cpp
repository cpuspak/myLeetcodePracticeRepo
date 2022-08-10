#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int dp[s.length()+1][s.length()] = {0};
        vector<vector<pair<int, int>>> dpString(s.length()+1, vector<pair<int, int>>(s.length(), make_pair(0,0)));
        
        int leftPointer = 0;
        int rightPointer = 0;
        //cout << s << endl;
        for (int i = 0 ; i < s.length() ; i++) dp[1][i] = 1;
        for (int i = 0 ; i < s.length() ; i++) dpString[1][i] = make_pair(i,1);
        for (int i = 2 ; i < s.length()+1 ; i++){
            for (int j = i-1 ; j < s.length() ; j++){
                if (i == 2){
                    if (s[j] == s[j - (i - 1)]) {
                        dp[i][j] = 2;
                        dpString[i][j] = make_pair(j-1,2);
                    }
                    else {
                        dp[i][j] = 1;
                        dpString[i][j] = make_pair(j,1);
                    }
                }
                else {
                    if (s[j - (i - 1)] == s[j]){
                        if (dp[i-2][j-1] == i - 2) {
                            dp[i][j] = i;
                            dpString[i][j] = make_pair(j - (i - 1), i);
                        }
                        else {
                            int maxEle = max(dp[i-1][j], dp[i-1][j-1]);
                            if (maxEle == dp[i-1][j]){
                                dpString[i][j] = dpString[i-1][j];
                            } else {
                                dpString[i][j] = dpString[i-1][j-1];
                            }
                            dp[i][j] = maxEle;
                        }
                    } else {
                        int maxEle = max(dp[i-1][j], dp[i-1][j-1]);
                        if (maxEle == dp[i-1][j]){
                            dpString[i][j] = dpString[i-1][j];
                        } else {
                            dpString[i][j] = dpString[i-1][j-1];
                        }
                        dp[i][j] = maxEle;
                    }
                }
            }
        }
        for (int i = 0 ; i < s.length()+1 ; i++){
            for (int j = 0 ; j < s.length() ; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        //return dp[s.length() - 1][s.length() - 1];
        cout << dp[s.length() - 1][s.length() - 1];
        return s.substr(dpString[s.length()][s.length() - 1].first, dpString[s.length()][s.length() - 1].second);
    }


int main(){
    string s = "bb";
    cout << longestPalindrome(s);
    return 0;
}



////smaller soln without use of dp using constant space and (O(n**2)) time
/*

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        string longestPalindrome = s.substr(0,1);
        int lenLongestPalindrome = 1;
        for (int i = 0 ; i < s.length() ; i++){
            int left = i;
            int right = i;
            while(right < s.length() && s[left] == s[right]) right ++;
            left --;
            while(left >= 0 && right < s.length() && s[left] == s[right]){
                left--;
                right++;
            }
            if (lenLongestPalindrome < (right - 1) - (left + 1) + 1) {
                lenLongestPalindrome = (right - 1) - (left + 1) + 1;
                longestPalindrome = s.substr(left + 1, lenLongestPalindrome);
            }
        }
        return longestPalindrome;
        
    }
};

*/