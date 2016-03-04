/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 *
 * @file: page461_ex.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 02-24-2016 14:17:40
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Folder;

class Message {

public:
    explicit Message(const string& str = string());
    Message(const Message& m);
    Message& operator=(const Message& m);
    ~Message();

public:
    void save(Folder&);
    void remove(Folder&);
    void display();

private:
    void add_to_folders();

private:
    string contents;
    set<Folder*> folders;

    friend class Folder;
};

class Folder {

public:
    explicit Folder(const string &str = string());
    Folder(const Folder& f) = delete;
    Folder& operator=(const Folder& f) = delete;
    ~Folder();

public:
    void add_message(Message *m);
    void remove_message(Message *m);
    void display();

private:
    string name;
    set<Message*> messages;

    friend void Message::remove(Folder &);
    friend void Message::display();
};

Message::Message(const string &str)
    : contents(str) {
}

Message::~Message() {
    for (auto f : folders) {
        f->remove_message(this);
    }
    cout << "~Message()" << endl;
}

Message::Message(const Message& m)
    : contents(m.contents), folders(m.folders) {
        add_to_folders();
}

Message& Message::operator=(const Message& m) {
    for (auto f : folders) {
        f->remove_message(this);
    }

    folders = m.folders;
    contents = m.contents;
    add_to_folders();

    return *this;
}

void Message::add_to_folders() {
    for (auto f : folders) {
        f->add_message(this);
    }
}

void Message::save(Folder& f) {
    folders.insert(&f);
    f.add_message(this);
}

void Message::remove(Folder& f) {
    folders.erase(&f);
    cout << "msg: " << contents << " delete folder: " << f.name << endl;

    f.remove_message(this);

}

void Message::display() {
    cout << contents << endl;
    for (auto f : folders) {
        cout << f->name << endl;
    }
    cout << "------" << endl;
}

Folder::Folder(const string &str)
    : name(str) {
}

Folder::~Folder() {
    for (auto m : messages) {
        m->remove(*this);
    }
}

auto Folder::add_message(Message *m) -> void {
    messages.insert(m);
}

void Folder::remove_message(Message *m) {
    messages.erase(m);
    cout  << "folder: " << name << " delete msg: " << m->contents << endl;
}

void Folder::display() {
    cout << name << endl;
    for (auto m : messages) {
        cout << m->contents << endl;
    }
    cout << "------" << endl;
}

int main() {

    Message m1("hello"), m2("hi");
    Folder f1("folder_1");

    m1.save(f1);
    m2.save(f1);

    m1.display();
    m2.display();
    f1.display();

    cout << "------" << endl;

    Message m3 = m1;
    m3.display();
    f1.display();

    return 0;
}
