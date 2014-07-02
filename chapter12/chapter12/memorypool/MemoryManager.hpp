#ifndef MEMORY_MANAGER_HPP
#define MEMORY_MANAGER_HPP


class MemoryManager
{
    public:
        typedef unsigned long size_type;
        typedef unsigned char *ptr_type;

        MemoryManager();
        ~MemoryManager() = default;

        MemoryManager(const MemoryManager &other) = delete;
        MemoryManager &operator = (const MemoryManager &other) = delete;

        MemoryManager(MemoryManager &&other) = delete;
        MemoryManager &operator = (MemoryManager &&other) = delete;

        bool Empty() const
        {
            return m_free_chunk_list == nullptr;
        }

        size_type TotalChunks() const
        {
            return m_total_chunks;
        }

        size_type UsedChunks() const
        {
            return m_used_chunks;
        }

        size_type FreeChunks() const
        {
            return m_total_chunks - m_used_chunks;
        }

    protected:
        ptr_type Alloc();
        void Free(ptr_type chunk);

        bool Alloc(ptr_type chunk_arr[], size_type length);
        void Free(ptr_type chunk_arr[], size_type length);

        void AddBlock(ptr_type block, size_type block_size, size_type chunk_size);
        void ForEachChunkInBlock(ptr_type block, size_type block_size,
            size_type chunk_size, void (*func)(ptr_type chunk));

        virtual void OnInitChunk(ptr_type /* chunk */){ }

    private:
        ptr_type &NextOfChunk(ptr_type chunk);

        size_type m_total_chunks;
        size_type m_used_chunks;

        ptr_type m_free_chunk_list;
};

#endif
