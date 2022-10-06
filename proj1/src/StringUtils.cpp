#include "StringUtils.h"
#include <string>

namespace StringUtils{


std::string Slice(const std::string &str, int start, int end) noexcept{
    int len = str.length();
    if (start < 0){
        start += len;
    }
    if (end <= 0){
        end += len;
    }
    if (end > len){
        end = len;
    }

    if (start >= end || start < 0 || start >= len){
        return "";
    }
    std::string res = "";
    for(int i = start; i < end; i++){
        res += str[i];
    }
    return res;
}

char upper(const char in){
    char res = in;
    if(in - 'a' >= 0 && in - 'a' <= 25){
            res = in - 'a' + 'A';
    }
    return res;
}

char lower(const char in){
    char res = in;
    if(in - 'A' >= 0 && in - 'A' <= 25){
            res = in - 'A' + 'a';
    }
    return res;
}

std::string Capitalize(const std::string &str) noexcept{
    std::string res = str;
    res[0] = upper(str[0]);
    for(int i = 1; i < str.length(); i++){
        res[i] = lower(str[i]);
    }
    return res;
}

std::string Upper(const std::string &str) noexcept{
    std::string res = str;
    for(int i = 0; i < str.length(); i++){
        res[i] = upper(str[i]);
    }
    return res;
}

std::string Lower(const std::string &str) noexcept{
    std::string res = str;
    for(int i = 0; i < str.length(); i++){
        res[i] = lower(str[i]);
    }
    return res;
}

std::string LStrip(const std::string &str) noexcept{
    int p1 = 0;
    while (isspace(str[p1])){
        p1 ++;
    }
    return Slice(str,p1,str.length());
}

std::string RStrip(const std::string &str) noexcept{
    int p2 = str.length()-1;
    while (isspace(str[p2])){
        p2 --;
    }
    return Slice(str,0,p2+1);
}

std::string Strip(const std::string &str) noexcept{
    std::string res = LStrip(str);
    return RStrip(res);
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width){
        return str;
    }
    int space = width - str.length();
    int left = space / 2;
    int right = space - left;
    std::string res = "";
    for(int i = 0; i < left; i++){
        res += fill;
    }
    res += str;
    for(int i = 0; i < right; i++){
        res += fill;
    }
    return res;
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width){
        return str;
    }
    int space = width - str.length();
    std::string res = "";
    res += str;
    for(int i = 0; i < space; i++){
        res += fill;
    }
    return res;
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    if (str.length() >= width){
        return str;
    }
    int space = width - str.length();
    std::string res = "";
    for(int i = 0; i < space; i++){
        res += fill;
    }
    res += str;
    return res;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    std::string res = "";
    int oldlen = old.length();
    int p = 0;
    while(p < str.length()){
        if (p <= str.length() - oldlen && Slice(str,p,p+oldlen) == old){
            res += rep;
            p += oldlen;
        }
        else{
            res += str[p];
            p ++;
        }
    }
    return res;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    std::vector<std::string> res;
    int p1 = 0;
    int p2 = 0;
    if (splt == ""){
        while (p2 < str.length()){
            if (isspace(str[p2])){
                res.push_back(Slice(str,p1,p2));
                p2 ++;
                p1 = p2;
            }
            else{
                p2 ++;
            }
        }
        res.push_back(Slice(str,p1,p2));
    }else{
        while (p2 < str.length()){
            if (p2 <= str.length() - splt.length() && Slice(str,p2,p2 + splt.length()) == splt){
                res.push_back(Slice(str,p1,p2));
                p2 += splt.length();
                p1 = p2;
            }else{
                p2 ++;
            }
        }
        res.push_back(Slice(str,p1,p2));
    }

    return res;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string res = vect[0];
    for(int i = 1; i < vect.size(); i++){
        res += str;
        res += vect[i];
    }
    return res;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string rep = "";
    for(; tabsize > 0; tabsize--){
        rep += " ";
    }
    return Replace(str,"\t",rep);
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    int l = left.length();
    int r = right.length();
    if (l * r == 0){
        return l+r;
    }

    std::vector<int> dp(l+1,0);
    for(int i = 0; i <= l; i++){
        dp[i] = i;
    }

    for(int i = 1; i <= r; i++){
        std::vector<int> temp(l+1,0);
        temp[0] = i;
        for(int j = 1; j <= l; j++){
            int last = temp[j-1] + 1;
            int down = dp[j] + 1;
            int lastdown = dp[j-1];

            if ((!ignorecase && right[i-1] != left[j-1]) || (ignorecase && upper(right[i-1]) != upper(left[j-1]))){
                lastdown ++;
            }
            temp[j] = std::min(last,down);
            temp[j] = std::min(temp[j],lastdown);
        }
        dp = temp;
    }

    return dp[l];
}

};