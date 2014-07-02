#include "MemoryPool.hpp"


MemoryPool::MemoryPool(size_type chunk_size, size_type init_block_length):
    m_chunk_size(chunk_size),
    m_aligned_chunk_size((m_chunk_size + DEFAULT_ALIGNMENT - 1) /
        DEFAULT_ALIGNMENT * DEFAULT_ALIGNMENT),
#ifdef DEBUG
    m_allocated_blocks(0),
    m_total_size(0),
#endif
    m_next_block_length(init_block_length),
    m_block_list(nullptr)
{

}


MemoryPool::~MemoryPool()
{
    while(m_block_list){
        ptr_type iter = m_block_list;
        m_block_list = NextOfBlock(m_block_list);
        delete[] iter;
    }
}


MemoryPool::ptr_type MemoryPool::Alloc()
{
    return Empty() && !AddBlock() ? nullptr : MemoryManager::Alloc();
}


void MemoryPool::Free(ptr_type &chunk)
{
    if(InRange(chunk)){
        MemoryManager::Free(chunk);
        chunk = nullptr;
    }
}


bool MemoryPool::Alloc(ptr_type chunk_arr[], size_type length)
{
    while(FreeChunks() < length){
        if(!AddBlock()){
            return false;
        }
    }

    return MemoryManager::Alloc(chunk_arr, length);
}


void MemoryPool::Free(ptr_type chunk_arr[], size_type length)
{
    for(size_type i = 0; i < length; ++i){
        Free(chunk_arr[i]);
    }
}


bool MemoryPool::AddBlock()
{
    size_type block_size = OVERHEAD_SIZE +
        m_next_block_length * m_aligned_chunk_size;

    ptr_type block = new unsigned char [block_size];
    if(!block){
        m_next_block_length >>= 1;
        block_size = OVERHEAD_SIZE +
            m_next_block_length * m_aligned_chunk_size;
        block = new unsigned char [block_size];
        if(!block){
            return false;
        }
    }

    SizeOfBlock(block) = block_size;
    NextOfBlock(block) = m_block_list;
    m_block_list = block;
    m_next_block_length <<= 1;

#ifdef DEBUG
    ++ m_allocated_blocks;
    m_total_size += block_size;
#endif

    MemoryManager::AddBlock(block + OVERHEAD_SIZE,
        block_size - OVERHEAD_SIZE, m_aligned_chunk_size);

    return true;
}


bool MemoryPool::InRange(ptr_type chunk)
{
    if(!m_block_list){
        return false;
    }

    ptr_type block = m_block_list;

    do{
        if((block + OVERHEAD_SIZE) <= chunk && chunk < (block + SizeOfBlock(block))){
            return (chunk - (block + OVERHEAD_SIZE)) % m_aligned_chunk_size == 0;
        }
    }while((block = NextOfBlock(block)));

    return false;
}


void MemoryPool::ForEachChunk(void (*func)(ptr_type chunk))
{
    if(!m_block_list){
        return;
    }

    ptr_type block = m_block_list;

    do{
        ForEachChunkInBlock(block + OVERHEAD_SIZE,
            SizeOfBlock(block) - OVERHEAD_SIZE,
            m_aligned_chunk_size, func);
    }while((block = NextOfBlock(block)));
};


MemoryPool::size_type &MemoryPool::SizeOfBlock(ptr_type block)
{
    return *reinterpret_cast<size_type *>(block);
};


MemoryPool::ptr_type &MemoryPool::NextOfBlock(ptr_type block)
{
    return *reinterpret_cast<ptr_type *>(block + sizeof(size_type));
}
