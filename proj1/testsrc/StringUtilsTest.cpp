//#include <gtest/gtest.h>
#include "StringUtils.h"
#include <iostream>

using namespace StringUtils;

void SliceTest(){
    std::cout << "SliceTest:" << "\n";
    std::string str1 = "abcdefg";
    std::string str2 = Slice(str1, 1, 3);
    std::string str3 = Slice(str1, 2);
    if (str2 == "bc"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: bc, result: " << str2 << "\n";
    }

    if (str3 == "cdefg"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: cdefg, result: " << str3 << "\n";
    }
}

void CapitalizeTest(){
    std::cout << "\n --------\n";
    std::cout << "CapitalizeTest:" << "\n";
    std::string str1 = "aBCd";
    std::string str2 = Capitalize(str1);
    std::string str3 = "AbcD";
    std::string str4 = Capitalize(str3);
    if (str2 == "Abcd"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: Abcd, result: " << str2 << "\n";
    }

    if (str4 == "Abcd"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: Abcd, result: " << str4 << "\n";
    }
}

void UpperTest(){
    std::cout << "\n --------\n";
    std::cout << "Upper:" << "\n";
    std::string str1 = "abcde";
    std::string str2 = Upper(str1);
    std::string str3 = "aBCd0123";
    std::string str4 = Upper(str3);
    if (str2 == "ABCDE"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: ABCDE, result: " << str2 << "\n";
    }

    if (str4 == "ABCD0123"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: ABCD0123, result: " << str4 << "\n";
    }
}

void LowerTest(){
    std::cout << "\n --------\n";
    std::cout << "Lower:" << "\n";
    std::string str1 = "ABCDe";
    std::string str2 = Lower(str1);
    std::string str3 = "aBCd0123";
    std::string str4 = Lower(str3);
    if (str2 == "abcde"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: abcde, result: " << str2 << "\n";
    }

    if (str4 == "abcd0123"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: abcd0123, result: " << str4 << "\n";
    }
}

void LStripTest(){
    std::cout << "\n --------\n";
    std::cout << "LStrip:" << "\n";
    std::string str1 = "   abcde";
    std::string str2 = LStrip(str1);
    std::string str3 = "  abc  ";
    std::string str4 = LStrip(str3);
    if (str2 == "abcde"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: abcde, result: " << str2 << "\n";
    }

    if (str4 == "abc  "){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: abc  , result: " << str4 << "\n";
    }
}

void RStripTest(){
    std::cout << "\n --------\n";
    std::cout << "RStrip:" << "\n";
    std::string str1 = " abcde";
    std::string str2 = RStrip(str1);
    std::string str3 = "  abc  ";
    std::string str4 = RStrip(str3);
    if (str2 == " abcde"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected:  abcde, result: " << str2 << "\n";
    }

    if (str4 == "  abc"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected:   abc, result: " << str4 << "\n";
    }
}

void StripTest(){
    std::cout << "\n --------\n";
    std::cout << "Strip:" << "\n";
    std::string str1 = " abcde  ";
    std::string str2 = Strip(str1);
    std::string str3 = "abc";
    std::string str4 = Strip(str3);
    if (str2 == "abcde"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: abcde, result: " << str2 << "\n";
    }

    if (str4 == "abc"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: abc, result: " << str4 << "\n";
    }
}

void CenterTest(){
    std::cout << "\n --------\n";
    std::cout << "Center:" << "\n";
    std::string str1 = "abc";
    std::string str2 = Center(str1, 9);
    std::string str3 = Center(str1, 9, '1');
    std::string str4 = Center(str1, 8, '2');
    if (str2 == "   abc   "){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected:    abc   , result: " << str2 << "\n";
    }

    if (str3 == "111abc111"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: 111abc111, result: " << str3 << "\n";
    }

    if (str4 == "22abc222"){
        std::cout << "Test 3 passed" << "\n";
    }else{
        std::cout << "Test 3 failed, expected: 22abc222, result: " << str4 << "\n";
    }
}

void LJustTest(){
    std::cout << "\n --------\n";
    std::cout << "LJust:" << "\n";
    std::string str1 = "abc";
    std::string str2 = LJust(str1, 5);
    std::string str3 = LJust(str1, 8, '1');
    if (str2 == "abc  "){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: abc  , result: " << str2 << "\n";
    }

    if (str3 == "abc11111"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: abc11111, result: " << str3 << "\n";
    }
}

void RJustTest(){
    std::cout << "\n --------\n";
    std::cout << "RJust:" << "\n";
    std::string str1 = "abc";
    std::string str2 = RJust(str1, 5);
    std::string str3 = RJust(str1, 8, '1');
    if (str2 == "  abc"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected:   abc, result: " << str2 << "\n";
    }

    if (str3 == "11111abc"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: 11111abc, result: " << str3 << "\n";
    }
}

void ReplaceTest(){
    std::cout << "\n --------\n";
    std::cout << "Replace:" << "\n";
    std::string str1 = "a11b1aa12";
    std::string str2 = Replace(str1, "1", "*");
    std::string str3 = Replace(str1, "a", "##");
    std::string str4 = Replace(str1, "1b1", "4444");
    std::string str5 = "\t12";
    std::string str6 = Replace(str5,"\t"," ");
    if (str2 == "a**b*aa*2"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: a**b*aa*2, result: " << str2 << "\n";
    }

    if (str3 == "##11b1####12"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: ##11b1####12, result: " << str3 << "\n";
    }

    if (str4 == "a14444aa12"){
        std::cout << "Test 3 passed" << "\n";
    }else{
        std::cout << "Test 3 failed, expected: a14444aa12, result: " << str4 << "\n";
    }
    if (str6 == " 12"){
        std::cout << "Test 4 passed" << "\n";
    }else{
        std::cout << "Test 4 failed, expected:  12, result: " << str6 << "\n";
    }
}

void SplitTest(){
    std::cout << "\n --------\n";
    std::cout << "Split:" << "\n";
    std::string str1 = "I love banana";
    std::vector<std::string> splt1 = Split(str1);
    std::vector<std::string> splt2 = Split(str1, "a");
    std::vector<std::string> ans1 = {"I","love","banana"};
    std::vector<std::string> ans2 = {"I love b","n","n",""};
    if (splt1 == ans1){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected:\n";
        for (int i = 0; i < ans1.size(); i++){
            std::cout << ans1[i] << "\n";
        }
        std::cout << "Result:\n";
        for (int i = 0; i < splt1.size(); i++){
            std::cout << splt1[i] << "\n";
        }
    }

    if (splt2 == ans2){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected:\n";
        for (int i = 0; i < ans2.size(); i++){
            std::cout << ans2[i] << "\n";
        }
        std::cout << "Result:\n";
        for (int i = 0; i < splt2.size(); i++){
            std::cout << splt2[i] << "\n";
        }
    }
}

void JoinTest(){
    std::cout << "\n --------\n";
    std::cout << "Join:" << "\n";
    std::vector<std::string> vect1 = {"I","love","banana"};
    std::string str1 = Join(" ", vect1);
    std::string str2 = Join("", vect1);
    if (str1 == "I love banana"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: I love banana, result: " << str1 << "\n";
    }

    if (str2 == "Ilovebanana"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: Ilovebanana, result: " << str2 << "\n";
    }
}

void TabsTest(){
    std::cout << "\n --------\n";
    std::cout << "Tabs:" << "\n";
    std::string str1 = "\t1";
    std::string str2 = ExpandTabs(str1, 4);
    std::string str3 = ExpandTabs(str1, 0);
    if (str2 == "    1"){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected:     1, result: " << str2 << "\n";
    }

    if (str3 == "1"){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: 1, result: " << str3 << "\n";
    }
}

void EditDistTest(){
    std::cout << "\n --------\n";
    std::cout << "EditDist:" << "\n";
    std::string str1 = "afeG";
    std::string str2 = "Aegkk";
    int res1 = EditDistance(str1,str2);
    int res2 = EditDistance(str1,str2,true);
    if (res1 == 5){
        std::cout << "Test 1 passed" << "\n";
    }else{
        std::cout << "Test 1 failed, expected: 5, result: " << res1 << "\n";
    }

    if (res2 == 3){
        std::cout << "Test 2 passed" << "\n";
    }else{
        std::cout << "Test 2 failed, expected: 3, result: " << res2 << "\n";
    }
}

int main(){
    SliceTest();
    CapitalizeTest();
    UpperTest();
    LowerTest();
    LStripTest();
    RStripTest();
    StripTest();
    CenterTest();
    LJustTest();
    RJustTest();
    ReplaceTest();
    SplitTest();
    JoinTest();
    TabsTest();
    EditDistTest();
}

// TEST(StringUtilsTest, SliceTest){
    
// }

// TEST(StringUtilsTest, Capitalize){
    
// }

// TEST(StringUtilsTest, Upper){
    
// }

// TEST(StringUtilsTest, Lower){
    
// }

// TEST(StringUtilsTest, LStrip){
    
// }

// TEST(StringUtilsTest, RStrip){
    
// }

// TEST(StringUtilsTest, Strip){
    
// }

// TEST(StringUtilsTest, Center){
    
// }

// TEST(StringUtilsTest, LJust){
    
// }

// TEST(StringUtilsTest, RJust){
    
// }

// TEST(StringUtilsTest, Replace){
    
// }

// TEST(StringUtilsTest, Split){
    
// }

// TEST(StringUtilsTest, Join){
    
// }

// TEST(StringUtilsTest, ExpandTabs){
    
// }

// TEST(StringUtilsTest, EditDistance){
    
// }
