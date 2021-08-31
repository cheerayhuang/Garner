#ifndef __RW_GUARD_HPP__
#define __RW_GUARD_HPP__

#include <semaphore.h>


class RWGuard {

private:
    sem_t lk;
    sem_t r_lk;
    int read_counter;

public:
    RWGuard() noexcept : read_counter(0) {
        sem_init(&lk, 0, 1);
        sem_init(&r_lk, 0, 1);
    }

    void r_lock() noexcept {
        sem_wait(&r_lk);
        if (read_counter <= 0) {
            sem_wait(&lk);
        }
        ++read_counter;
        sem_post(&r_lk);
    }

    void r_unlock() noexcept {
        sem_wait(&r_lk);
        assert(read_counter > 0);
        --read_counter;
        if (read_counter == 0) {
            sem_post(&lk);
        }
        sem_post(&r_lk);
    }

    void lock() noexcept {
        sem_wait(&lk);

    }

    void unlock() noexcept {
        sem_post(&lk);
    }

};
#endif
