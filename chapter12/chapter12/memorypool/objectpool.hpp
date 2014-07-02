#ifndef OBJECT_POOL_HPP
#define OBJECT_POOL_HPP

#include "MemoryPool.hpp"


template<
    typename object_type
>
class ObjectPool: public MemoryPool
{
    public:
        typedef object_type ObjectType;

        ObjectPool(): MemoryPool(sizeof(ObjectType) + sizeof(CHUNK_FLAG))
        {

        }

        ~ObjectPool()
        {
            MemoryPool::ForEachChunk(FreeChunk);
        };

        ObjectType *Alloc()
        {
            ptr_type chunk = MemoryPool::Alloc();
            if(chunk){
                FlagOfChunk(chunk) = CHUNK_FLAG::ALLOCATED;
            }

            return reinterpret_cast<ObjectType *>(chunk);
        }

        void Free(ObjectType *&obj)
        {
            if(!MemoryPool::InRange(reinterpret_cast<ptr_type>(obj))){
                return;
            }

            FlagOfChunk(reinterpret_cast<ptr_type>(obj)) = CHUNK_FLAG::FREE;
            MemoryManager::Free(reinterpret_cast<ptr_type>(obj));
        }

        bool Alloc(ObjectType *obj_arr[], size_type length)
        {
            if(!MemoryPool::Alloc(reinterpret_cast<ptr_type *>(obj_arr), length)){
                return false;
            }

            for(size_type i = 0; i < length; ++i){
                FlagOfChunk(obj_arr[i]) = CHUNK_FLAG::ALLOCATED;
            }

            return true;
        }

        void Free(ObjectType *obj_arr[], size_type length)
        {
            for(size_type i = 0; i < length; ++i){
                Free(obj_arr[i]);
            }
        }

        template<typename ... Types>
        ObjectType *Construct(Types ... args)
        {
            ptr_type chunk = MemoryPool::Alloc();
            if(!chunk){
                return nullptr;
            }

            FlagOfChunk(chunk) = CHUNK_FLAG::CONSTRUCTED;
            ObjectType *obj = reinterpret_cast<ObjectType *>(chunk);

            try{
                new (obj) ObjectType(args ...);
            }
            catch(...){
                Free(obj);
            }

            return obj;
        }

        void Destruct(ObjectType *&obj)
        {
            if(obj){
                obj->~ObjectType();
                Free(obj);
            }
        }

        template<typename ... Types>
        bool ConstructArr(ObjectType *obj_arr[], size_type length, Types ... args)
        {
            if(!MemoryPool::Alloc(reinterpret_cast<ptr_type *>(obj_arr), length)){
                return false;
            }

            for(size_type i = 0; i < length; ++i){
                FlagOfChunk(reinterpret_cast<ptr_type>(obj_arr[i])) =
                    CHUNK_FLAG::CONSTRUCTED;

                try{
                    new (obj_arr[i]) ObjectType (args ...);
                }
                catch(...){
                    for(size_type j = 0; j < i; ++j){
                        obj_arr[j]->~ObjectType();
                    }

                    Free(obj_arr, length);
                    return false;
                }
            }

            return true;
        }

        void DestructArr(ObjectType *obj_arr[], size_type length)
        {
            for(size_type i = 0; i < length; ++i){
                Destruct(obj_arr[i]);
            }
        }

    protected:
        using MemoryPool::Alloc;
        using MemoryPool::Free;

    private:
        enum CHUNK_FLAG
        {
            FREE,
            ALLOCATED,
            CONSTRUCTED,
        };

        void OnInitChunk(ptr_type chunk) override
        {
            FlagOfChunk(chunk) = CHUNK_FLAG::FREE;
        }

        static void FreeChunk(ptr_type chunk)
        {
            if(FlagOfChunk(chunk) == CHUNK_FLAG::CONSTRUCTED){
                reinterpret_cast<ObjectType *>(chunk)->~ObjectType();   
            };
        }

        static CHUNK_FLAG &FlagOfChunk(ptr_type chunk)
        {
            return *reinterpret_cast<CHUNK_FLAG *>(chunk + sizeof(ObjectType));
        }
};

#endif
