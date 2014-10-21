/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: ex7_23.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-21-2014 11:25:17
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <string>

using namespace std; 

class Screen {

private:

    size_t height, width;
    size_t xPos{0}, yPos{0};
    string contents{""};

    void _Display() noexcept {
        for(string::const_iterator it = contents.cbegin(); it != contents.cend(); ++it) {
            cout << *it << " ";
            if ((it - contents.begin()+1) % width == 0) {
                cout << endl;
            }
        }
    }

public:

    Screen() = default;
    Screen(size_t h, size_t w): height{h}, width{w}, contents(h*w, ' ') {}
    Screen(size_t h, size_t w, char ch): height{h}, width{w}, contents(h*w, ch) {}
    //Screen(initializer_list<char> il) {
    //}

    const Screen& Display() const {
        const_cast<Screen*>(this)->_Display(); 
        return *this;
    }

    Screen& Display() {
        _Display();
        return * this;
    }

    Screen& Set(char ch) {
        contents[xPos*width + yPos] = ch; 

        return *this;
    }

    Screen& Move(size_t x, size_t y) {
        xPos = x; 
        yPos = y;

        return *this;
    }
};

int main() {
    Screen s{5, 5, 'X'};
    s.Move(4, 0).Set('#').Display();

    cout << endl;

    s.Display();

    return 0;
}

