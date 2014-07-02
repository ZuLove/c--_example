#ifndef MEMORY_POOL_HPP
#define MEMORY_POOL_HPP

#include "MemoryManager.hpp"


class MemoryPool: public MemoryManager
{
    public:
        MemoryPool(size_type chunk_size, size_type init_block_length = 32);
        ~MemoryPool();

#ifdef DEBUG
        size_type AllocatedBlocks() const
        {
            return m_allocated_blocks;
        }

        size_type TotalSize() const
        {
            return m_total_size;
        }
#endif

        ptr_type Alloc();
        void Free(ptr_type &chunk);

        bool Alloc(ptr_type chunk_arr[], size_type length);
        void Free(ptr_type chunk_arr[], size_type length);

    protected:
        bool InRange(ptr_type chunk);
        void ForEachChunk(void (*func)(ptr_type chunk));

    private:
        bool AddBlock();

        size_type &SizeOfBlock(ptr_type block);
        ptr_type &NextOfBlock(ptr_type block);

        enum
        {
            DEFAULT_ALIGNMENT = sizeof(ptr_type),
            OVERHEAD_SIZE = (sizeof(size_type) + sizeof(ptr_type) +
                DEFAULT_ALIGNMENT - 1) / DEFAULT_ALIGNMENT * DEFAULT_ALIGNMENT
        };

        const size_type m_chunk_size;
        const size_type m_aligned_chunk_size;

#ifdef DEBUG
        size_type m_allocated_blocks;
        size_type m_allocated_size;
#endif

        size_type m_next_block_length;
        ptr_type m_block_list;
};

#endif
