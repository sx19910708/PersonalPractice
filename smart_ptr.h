#ifndef SMART_PTR_H
#define SMART_PTR_H

#include <map>
#include <iostream>

template <typename _Tr>
class smart_ptr
{
public:

    typedef _Tr* pointType;

    // 利用现有地址构造
    smart_ptr(_Tr *ptr)
    {
        Increase((long)ptr);

        this->ptr_ = ptr;
    }

    smart_ptr(const smart_ptr &other)
    {
        if(other.ptr_)
        {
            Increase((long)other.ptr_);

            this->ptr_ = other.ptr_;
        }
    }

     // 空初始化
    smart_ptr()
    {
        this->ptr_ = NULL;
    }

    // 释放
    ~smart_ptr()
    {
        ReleasePtr();
    }

public:

    // 拷贝（递减原有计数、增加新计数）
    smart_ptr &operator = (const smart_ptr &other)
    {
        this->ReleasePtr();

        if(other.ptr_)
        {
            Increase((long)other.ptr_);

            this->ptr_ = other.ptr_;
        }

        return *this;
    }

    // 解引
    _Tr operator *()
    {
        //assert(this->ptr_);

        return *this->ptr_;
    }

    // 模拟指针调用
    pointType operator ->()
    {
        return this->ptr_;
    }

private:

    // 递增计数，并且返回计数
    int Increase(long address)
    {
        int count = 0;

        if(addressContainer_.find(address) != addressContainer_.end())
        {
            count = ++addressContainer_[address];
        }
        else
        {
            addressContainer_[address] = 1;

            count = 1;
        }
#ifdef PTR_DEBUG
        std::cout << "address:" << address << " count:" << count << std::endl;
#endif

        return count;
    }


    // 递减计数，并且返回计数
    int Degression(long address)
    {
        int count = 0;

        if(addressContainer_.find(address) != addressContainer_.end())
        {
            count = --addressContainer_[address];

            if(count <= 0)
            {
                addressContainer_.erase(address);
            }

#ifdef PTR_DEBUG
        std::cout << "address:" << address << " count:" << count << std::endl;
#endif
        }

        return count;
    }

    void ReleasePtr()
    {
        int count = 0;

        if(this->ptr_)
        {
            count = Degression((long)this->ptr_);

            // 引用计数递减至0
            if(!count)
            {
                delete this->ptr_;
#ifdef PTR_DEBUG
        std::cout << "The address:" << (long)this->ptr_ << " has been delete!" << std::endl;
#endif
                this->ptr_ = NULL;
            }
        }
    }

    // 地址容器（key：地址、value：被引用次数）
    static std::map<long, int> addressContainer_;

    pointType ptr_;
};

template <typename _Tr>
std::map<long, int> smart_ptr<_Tr>::addressContainer_;

#endif // SMART_PTR_H
