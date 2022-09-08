#include "string"
#include "iostream"
using namespace std;
class Solution {
public:
    string reorderSpaces(string text) {
        string result;
        char string1[100][100];
        int stringwidth= 0;
        int string_length = text.length();
        int spacenum = 0;
        int stringnum = 0;
        int ifprespace = 0;
        int ifpreword = 0;
        for(int i = 0;i < string_length;i++){
            if(text[i]==' ') {   
                ifpreword = 0;
                spacenum++;
            }
            else{
                ifprespace = 0;
                if(ifpreword == 0){
                    stringnum++;
                    stringwidth = 0;
                    ifpreword = 1;
                }
                string1[stringnum-1][stringwidth] = text[i];
                stringwidth++;
            }
        }
        int space = int(spacenum / (stringnum - 1));
        int rest_space = spacenum - space * (stringnum - 1);
        string spacestring;
        string rest_spacestring;
        for(int i = 0;i < space;i++){
            spacestring += ' ';
        }
        for(int i = 0;i < rest_space;i++){
            rest_spacestring += ' ';
        }
        string temp;
        for(int i = 0;i < stringnum;i++){
            temp = string1[i];
            result += temp;
            result += spacestring;
        }
        result +=  rest_spacestring;
        return result;
    }
};

int main(){
    Solution solution;
    string text ="  this   is  a sentence ";//"this   is   a   sentence   ""this   is   a   sentence"
    cout << solution.reorderSpaces(text) << endl;
    return 0;
}