/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex5_12.cpp
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 08-19-2014 10:14:46
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

int main() {
    
    string str{""}; 
    string tmp{""};

    while(getline(cin, tmp)) {
        tmp += "\n";
        str += tmp;
    }

    cout << "str: " << str << endl; 

    unsigned aCnt{0}, eCnt{0}, iCnt{0}, oCnt{0}, uCnt{0};
    unsigned notAlphaCnt{0};
    unsigned ffCnt{0}, flCnt{0}, fiCnt{0};

    char prevCh{'\0'};

    for (auto ch : str) {
        switch(ch) {
            case 'a': 
                ++aCnt;
                break;
            case 'e': 
                ++eCnt; 
                break;
            case 'i':
                ++iCnt; 
                if (prevCh == 'f') {
                    ++fiCnt;
                }
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;

            case '\n': 
            case '\t':
            case ' ' :
                ++notAlphaCnt;
                break;

            default:
                if (prevCh == 'f') {
                    switch(ch) {
                        case 'f': 
                            ++ffCnt;
                            break;
                        case 'l':
                            ++flCnt;
                            break;
                    }
                }

        }    
        prevCh = ch;
    }

    cout << "a :" << aCnt << endl; 
    cout << "e :" << eCnt << endl;
    cout << "i :" << iCnt << endl; 
    cout << "o :" << oCnt << endl; 
    cout << "u :" << uCnt << endl; 

    cout << "notAlpha: " << notAlphaCnt << endl; 
    cout << "ff :" << ffCnt << endl; 
    cout << "fl :" << flCnt << endl;
    cout << "fi :" << fiCnt << endl; 

    return 0;
}


