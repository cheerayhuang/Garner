#include <iostream>
#include <fstream>
#include <string>

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <unordered_map>
#include <cassert>

#include "rw_guard.hpp"

using namespace std;

struct Content {
    string id;
    string gid;

    float value;

    Content() = default;
    Content(const string& id, const string& gid, const float& value):id(id), gid(gid), value(value) {}
    //Content(const Content&) = default;

    Content(Content && c) {
        value = std::move(c.value);
        id = std::move(c.id);
        gid = std::move(c.gid);
        cout << "move" << endl;
    }
};

class Result {
private:
   RWGuard *rw_lock;

   unordered_map<string, Content> res;

public:
    Result() noexcept {
       rw_lock = new RWGuard();
    }

    Result(const Result&) = delete;
    Result(Result && other) noexcept {
        rw_lock = other.rw_lock;
        other.rw_lock = nullptr;

        res = std::move(other.res);
    }

    void set(Content& c) noexcept {
        rw_lock->lock();
        res.emplace(make_pair<string, Content>(std::move(c.gid), std::move(c)));
        rw_lock->unlock();
    }

    void set(Content&& c) noexcept {
        rw_lock->lock();
        res.emplace(make_pair<string, Content>(std::move(c.gid), std::move(c)));
        rw_lock->unlock();
    }

    const Content& get(const string& gid) noexcept {
        rw_lock->r_lock();
        const auto& r = res[gid];
        rw_lock->r_unlock();

        return r;
    }

    const Content& operator[](const string& gid) noexcept {
        rw_lock->r_lock();
        const auto& r = res[gid];
        rw_lock->r_unlock();

        return r;
    }

    ~Result() noexcept {
        delete rw_lock;
    }
};

class Reader {


public:
    void Run() {

    }



private:
    sem_t threads_pool;

    Result result;

    static const int POOL_MAX_COUNT = 10;
};

Content func(unordered_map<int, Content>& m) {
//    return m[1];
    return Content();
}

Content func(Content c) {
    return c;
}


int main() {

    Content c;
    c.id = "abc";
    c.gid = "def";
    c.value = 0.1f;

    //func(m);

    //func(std::move(c));
    //
    //cout << m[1].id << endl;
    //cout << m[1].gid << endl;
    //
    Result r;
    r.set(c);

    cout << r["def"].value << endl;

    //r.set(Content{"x", "y", 0.2});

    //cout << r["y"].value << endl;
    //

    int m , n;
    cin >> m >> n;
    int arr[m][n];

    return 0;
}
