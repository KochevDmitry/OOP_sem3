#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>


template <class T>
class AllocatorList {
private:
    char *_used_blocks;
    std::list<T*> _free_blocks;

public:
    static constexpr size_t max_count = 500000;
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    AllocatorList() {
        _used_blocks = (char*)malloc(sizeof(T) * max_count);
        for (uint64_t i = 0; i < max_count; i++)
            _free_blocks.push_back(reinterpret_cast<T*>(_used_blocks + i * sizeof(T)));
#ifdef DEBUG
        std::cout << "allocator: memory init" << std::endl;
#endif
    }

    ~AllocatorList() {
#ifdef DEBUG
        if (_free_blocks.size() < max_count)
            std::cout << "allocator: Memory leak?" << std::endl;
        else
            std::cout << "allocator: Memory freed" << std::endl;
#endif

        free(_used_blocks);
        _free_blocks.clear();
    }

    template <class U>
    struct rebind {
        using other = AllocatorList<U>;
    };

    T* allocate(size_t n) {
        T* result = nullptr;
        if (!_free_blocks.empty()) {
            result = _free_blocks.front();
            _free_blocks.pop_front();
#ifdef DEBUG
            std::cout << "allocator: Allocate " << (max_count - _free_blocks.size()) << " of " << max_count << " Address:" << result << std::endl;
#endif
        } else {
            std::cout << "allocator: No memory exception :-)" << std::endl;
        }
        return result;
    }

    void deallocate(T* pointer, size_t) {
#ifdef DEBUG
        std::cout << "allocator: Deallocate block " << std::endl;
#endif

        char* charPointer = reinterpret_cast<char*>(pointer);
        
        if (charPointer >= _used_blocks && charPointer < _used_blocks + sizeof(T) * max_count)
            _free_blocks.push_back(pointer);
        else {
            // Указатель не входит в область выделенной памяти
            // std::cerr << "allocator: Trying to deallocate memory not allocated by this allocator." << std::endl;
            throw std::invalid_argument("allocator: Trying to deallocate memory not allocated by this allocator.");
        }
    }

    template <typename U, typename... Args>
    void construct(U* p, Args&&... args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }
};
