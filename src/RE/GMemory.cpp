#include "RE/GMemory.h"

#include "skse64_common/Relocation.h"  // RelocAddr

#include "RE/GMemoryHeap.h"  // GMemoryHeap
#include "RE/Offsets.h"


namespace RE
{
	void GMemory::SetGlobalHeap(GMemoryHeap* a_heap)
	{
		GetGlobalHeapRef() = a_heap;
	}


	GMemoryHeap* GMemory::GetGlobalHeap()
	{
		return GetGlobalHeapRef();
	}


	void GMemory::CreateArena(UPInt a_arena, GSysAllocPaged* a_sysAlloc)
	{
		GetGlobalHeapRef()->CreateArena(a_arena, a_sysAlloc);
	}


	void GMemory::DestroyArena(UPInt a_arena)
	{
		GetGlobalHeapRef()->DestroyArena(a_arena);
	}


	bool GMemory::ArenaIsEmpty(UPInt a_arena)
	{
		return GetGlobalHeapRef()->ArenaIsEmpty(a_arena);
	}


	void* GMemory::Alloc(UPInt a_count)
	{
		return GetGlobalHeapRef()->Alloc(a_count);
	}


	void* GMemory::Alloc(UPInt a_count, UPInt a_al)
	{
		return GetGlobalHeapRef()->Alloc(a_count, a_al);
	}


	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_count)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_count);
	}

	void* GMemory::AllocAutoHeap(const void* a_ptr, UPInt a_count, UPInt a_al)
	{
		return GetGlobalHeapRef()->AllocAutoHeap(a_ptr, a_count, a_al);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_count)
	{
		return a_heap->Alloc(a_count);
	}


	void* GMemory::AllocInHeap(GMemoryHeap* a_heap, UPInt a_count, UPInt a_al)
	{
		return a_heap->Alloc(a_count, a_al);
	}


	void* GMemory::Realloc(void* a_ptr, UPInt a_newCount)
	{
		return GetGlobalHeapRef()->Realloc(a_ptr, a_newCount);
	}


	void GMemory::Free(void* a_ptr)
	{
		if (a_ptr) {
			return GetGlobalHeapRef()->Free(a_ptr);
		}
	}


	GMemoryHeap* GMemory::GetHeapByAddress(const void* a_ptr)
	{
		return GetGlobalHeapRef()->GetAllocHeap(a_ptr);
	}


	bool GMemory::DetectMemoryLeaks()
	{
		return GetGlobalHeapRef()->DumpMemoryLeaks();
	}


	GMemoryHeap*& GMemory::GetGlobalHeapRef()
	{
		RelocPtr<GMemoryHeap*> globalHeap(SCALEFORM_GLOBAL_HEAP);
		return *globalHeap.GetPtr();
	}
}